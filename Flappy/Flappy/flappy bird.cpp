#include "fb.h"

void main()
{
	initgraph(640,480);
	bird a;
	guandao b;
	ditu c;
	f = &a;
	f->init();
	f = &b;
	f->init();
	c.began();
	BeginBatchDraw();//开启批量绘图模式
	while (1)
	{
		while (choice == 1)
		{
			cleardevice();
			c.draw();
			a.draw();
			a.move();
			b.move();
			if (c.end())
			{
				break; 
			}
			if (GetAsyncKeyState(VK_ESCAPE))//判断esc键是否按下
			{
				return ;
			}
			FlushBatchDraw();//绘图
			Sleep(80);
		}
		if (c.end() == 1)
		{
			TCHAR s[10];
			_stprintf_s(s, "score:%d", grad());
			outtextxy(240, 120, s);
			outtextxy(240, 220, "游戏结束");
			break;
		}
		while (choice == 2)
		{
			MOUSEMSG ms;
			cleardevice();
			settextstyle(0, 0, "宋体");
			outtextxy(260, 110, "操作说明");
			outtextxy(220, 150, "1.空格键跳跃");
			outtextxy(220, 170, "2.ESC键退出游戏");
			settextstyle(40, 0, "RAVIE");
			outtextxy(240, 220, "开始游戏");
			ms = GetMouseMsg();// 获取鼠标的消息
			switch (ms.uMsg) //获取鼠标信息
			{
			case WM_LBUTTONDOWN:
				if (ms.x >= 240 && ms.x <320 && ms.y >= 220 && ms.y < 260)
				{
					choice = 1;
					break;
				}
			}
			FlushBatchDraw();//绘图
		}
		if (choice == 3)
		{
			return;
		}
	}
	EndBatchDraw();//结束批量绘图
	getchar();
	closegraph();
}