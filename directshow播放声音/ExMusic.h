#pragma once
#include <dshow.h>
#pragma comment (lib, "strmiids.lib")


class ExMusic
{
private:
	wchar_t* m_musicfile;
	IGraphBuilder*   pGBuilder;
	IMediaControl*   pMControl;
	IMediaPosition*   pMPos;
	IMediaEvent*	pMEvent;

public:
	ExMusic(wchar_t* musicfile);
	~ExMusic();

	/*��Ҫѭ����ⲥ��������,Ȼ�������²���,ʵ��ѭ������*/
	void PlayAgainWhenEnd();
	void Play(int n);
	void Play();

	void Pause();

	void Stop();
};

