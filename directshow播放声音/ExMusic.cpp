#include "ExMusic.h"


ExMusic::ExMusic(wchar_t* musicfile)
{
	m_musicfile = musicfile;

	CoInitialize(NULL);   //初始化COM
						  //创建各个对象   

	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void**)&pGBuilder);

	pGBuilder->QueryInterface(IID_IMediaControl, (void**)&pMControl);
	pGBuilder->QueryInterface(IID_IMediaPosition, (void**)&pMPos);
	pGBuilder->QueryInterface(IID_IMediaEvent, (void**)&pMEvent);

	pGBuilder->RenderFile(m_musicfile, NULL);   //调入文件   
}


ExMusic::~ExMusic()
{
	//释放对象
	pMControl->Release();
	pMPos->Release();
	pGBuilder->Release();


	CoUninitialize();   //释放COM
}


void ExMusic::PlayAgainWhenEnd()
{
	long event_code, param1, param2;
	if (SUCCEEDED(pMEvent->GetEvent(&event_code, &param1, &param2, 1)))
	{
		pMPos->put_CurrentPosition(0);   //移动到文件头
		pMControl->Run();   //播放
	}
}

void ExMusic::Play(int n)
{
	pMPos->put_CurrentPosition(n);   //移动到文件头
	pMControl->Run();   //播放
}

void ExMusic::Play()
{
	pMControl->Run();   //播放
}

void ExMusic::Pause()
{
	pMControl->Pause();
}

void ExMusic::Stop()
{
	pMControl->Stop();   //停止播放
}