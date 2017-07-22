#include "ExMusic.h"


ExMusic::ExMusic(wchar_t* musicfile)
{
	m_musicfile = musicfile;

	CoInitialize(NULL);   //��ʼ��COM
						  //������������   

	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void**)&pGBuilder);

	pGBuilder->QueryInterface(IID_IMediaControl, (void**)&pMControl);
	pGBuilder->QueryInterface(IID_IMediaPosition, (void**)&pMPos);
	pGBuilder->QueryInterface(IID_IMediaEvent, (void**)&pMEvent);

	pGBuilder->RenderFile(m_musicfile, NULL);   //�����ļ�   
}


ExMusic::~ExMusic()
{
	//�ͷŶ���
	pMControl->Release();
	pMPos->Release();
	pGBuilder->Release();


	CoUninitialize();   //�ͷ�COM
}


void ExMusic::PlayAgainWhenEnd()
{
	long event_code, param1, param2;
	if (SUCCEEDED(pMEvent->GetEvent(&event_code, &param1, &param2, 1)))
	{
		pMPos->put_CurrentPosition(0);   //�ƶ����ļ�ͷ
		pMControl->Run();   //����
	}
}

void ExMusic::Play(int n)
{
	pMPos->put_CurrentPosition(n);   //�ƶ����ļ�ͷ
	pMControl->Run();   //����
}

void ExMusic::Play()
{
	pMControl->Run();   //����
}

void ExMusic::Pause()
{
	pMControl->Pause();
}

void ExMusic::Stop()
{
	pMControl->Stop();   //ֹͣ����
}