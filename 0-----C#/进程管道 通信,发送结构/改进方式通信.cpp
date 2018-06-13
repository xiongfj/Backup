
* Client �ȷ���һ����ʾ model �ֽڴ�С�����ݵ� Server
* Servef ���յ������ʾ model �ֽڴ�С����;
* Client ���� model �б��ֽ���, ���������� model ����
* Server ���� model �ֽڴ�С, ÿ�ζ�ȡһ�� model ����, ֱ����ȡ���


* Server �� -----------------------------------------

	List<Dll.Model.GroupUser> objs = new List<Dll.Model.GroupUser>();
	int modelSize = 0;			// ÿ�� model ����
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

	// ����������ÿ�ζ�ȡ��һ������ model
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
	
	
*Client �� --------------------------------------------------------


// ���л��б�
foreach (TModel model in modelList)
{
	// ������Ҫ����� model
	using (MemoryStream ms = new MemoryStream())
	{
		IFormatter formatter = new BinaryFormatter();
		formatter.Serialize(ms, model);
		byte[] bytes = ms.GetBuffer();
		sendBytes.AddRange(bytes);

		// �ȷ��� 4 �ֽڵĳ���˵��
		if (model_length == 0)
		{
			model_length = bytes.Length;
			byte[] len = BitConverter.GetBytes(model_length);		// 4Byte �� int ����
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

// ���������б��ֽ���
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

				
				
				
				
				


