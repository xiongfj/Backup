
* Client 先发送一个表示 model 字节大小的数据到 Server
* Servef 接收到这个表示 model 字节大小数据;
* Client 发送 model 列表字节流, 里面包含多个 model 数据
* Server 根据 model 字节大小, 每次读取一个 model 出来, 直到读取完毕


* Server 端 -----------------------------------------

	List<Dll.Model.GroupUser> objs = new List<Dll.Model.GroupUser>();
	int modelSize = 0;			// 每个 model 长度
	byte[] modelBuf = new byte[sizeof(int)];
	try {
		_pipe.Read(modelBuf, 0, modelBuf.Length);
		modelSize = BitConverter.ToInt32(modelBuf, 0);// Convert.ToInt32(Encoding.UTF8.GetString(modelBuf));
	}
	catch (Exception e)
	{
		TextLog.WriteLog(DateTime.Now.ToLongDateString() + "ReceiveObjectList exception_1: " + e.Message);
		if (_pipe != null)
			_pipe.Dispose();
		Init();
		return null;
	}

	// 从数据流中每次读取出一个数据 model
	byte[] bytes = new byte[modelSize];
	List<byte> byteSource = new List<byte>();
	do
	{
		try
		{
			_pipe.Read(bytes, 0, bytes.Length);
		}catch(Exception e)
		{
			TextLog.WriteLog(DateTime.Now.ToLongDateString() + "ReceiveObjectList exception_2: " + e.Message);
			if (_pipe != null)
				_pipe.Dispose();
			Init();
			return null;
		}

		using (MemoryStream ms = new MemoryStream(bytes.ToArray()))
		{
			IFormatter formatter = new BinaryFormatter();
			Dll.Model.GroupUser model = (Dll.Model.GroupUser)formatter.Deserialize(ms);
			objs.Add(model);
		}
	} while (_pipe.IsMessageComplete == false);
	
	
*Client 端 --------------------------------------------------------


// 序列化列表
foreach (TModel model in modelList)
{
	// 发送需要插入的 model
	using (MemoryStream ms = new MemoryStream())
	{
		IFormatter formatter = new BinaryFormatter();
		formatter.Serialize(ms, model);
		byte[] bytes = ms.GetBuffer();
		sendBytes.AddRange(bytes);

		// 先发送 4 字节的长度说明
		if (model_length == 0)
		{
			model_length = bytes.Length;
			byte[] len = BitConverter.GetBytes(model_length);		// 4Byte 的 int 数据
			try
			{
				_pipe.Write(len, 0, len.Length);
				_pipe.WaitForPipeDrain();
			}
			catch (Exception e)
			{
				TextLog.WriteLog(DateTime.Now.ToString() + "NamedPipeClient.cs/PostCmdModelList exception_2: " + e.Message);
				DisposePipe();
				return false;
			}
		}
	}
}

// 发送整个列表字节流
try
{
	byte[] temp = sendBytes.ToArray();
	_pipe.Write(temp, 0, sendBytes.ToArray().Length);
}
catch (Exception e)
{
	TextLog.WriteLog(DateTime.Now.ToString() + "NamedPipeClient.cs/PostCmdModelList exception_3: " + e.Message);
	DisposePipe();
	return false;
}

				
				
				
				
				


