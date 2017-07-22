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

	/*需要循环检测播放完毕与否,然后再重新播放,实现循环播放*/
	void PlayAgainWhenEnd();
	void Play(int n);
	void Play();

	void Pause();

	void Stop();
};

