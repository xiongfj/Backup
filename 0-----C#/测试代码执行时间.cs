static void ListTest()
{
	List<byte> byteSource = new List<byte>();
	byteSource.Add(11);
	Stopwatch sw = new Stopwatch();
	sw.Start();
	for (int i = 0; i < RunCount; i++)
	{
		byte[] newData = new byte[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		byteSource.AddRange(newData);
	}
	byte[] data = byteSource.ToArray();
	//byte[] subData = byteSource.Take(100).ToArray();//��ȡǰ100���ֽ�  
	//byteSource.RemoveRange(0, 100);//ȡ����ɾ��  
	//byteSource.GetRange(100, 100);//���±�100��ʼȡ100���ֽ�  
	sw.Stop();
	Console.WriteLine("ListTest " + sw.ElapsedMilliseconds + " ����,���鳤�ȣ�" + data.Length);
}