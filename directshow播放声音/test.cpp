// test.cpp : Defines the entry point for the console application.
//
#include "ExMusic.h"
#include "./easyx/graphics.h"
#include <conio.h>



int main()
{
	ExMusic m1(L".\\sound\\bk.mid");
	ExMusic m2(L".\\sound\\shoot.wav");
	ExMusic m3(L".\\sound\\bin.wav");

	initgraph(400, 400);
	int x = 0;
	setcolor(WHITE);
	BeginBatchDraw();
	
	m3.Play(0);
	bool b_m1 = false; 

	while (_kbhit() != 27)
	{
		cleardevice();
		x = x + 1 < 400 ? x + 1 : 0;
		circle(x, 100, 50);

		m3.PlayAgainWhenEnd();		// 需要实时检测循环!?!?

		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				m2.Play(0);
			}
			else if (m.uMsg == WM_LBUTTONUP)
			{
				m3.Play(0);
			}
			else if (m.uMsg == WM_RBUTTONDOWN)
			{
				if (b_m1)	
					m1.Pause(); 
				else
					m1.Play();

				b_m1 = !b_m1;
			}

		}
		FlushBatchDraw();
		Sleep(5);
	}
	

	_getch();
    return 0;
}

