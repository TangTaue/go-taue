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
	BeginBatchDraw();//����������ͼģʽ
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
			if (GetAsyncKeyState(VK_ESCAPE))//�ж�esc���Ƿ���
			{
				return ;
			}
			FlushBatchDraw();//��ͼ
			Sleep(80);
		}
		if (c.end() == 1)
		{
			TCHAR s[10];
			_stprintf_s(s, "score:%d", grad());
			outtextxy(240, 120, s);
			outtextxy(240, 220, "��Ϸ����");
			break;
		}
		while (choice == 2)
		{
			MOUSEMSG ms;
			cleardevice();
			settextstyle(0, 0, "����");
			outtextxy(260, 110, "����˵��");
			outtextxy(220, 150, "1.�ո����Ծ");
			outtextxy(220, 170, "2.ESC���˳���Ϸ");
			settextstyle(40, 0, "RAVIE");
			outtextxy(240, 220, "��ʼ��Ϸ");
			ms = GetMouseMsg();// ��ȡ������Ϣ
			switch (ms.uMsg) //��ȡ�����Ϣ
			{
			case WM_LBUTTONDOWN:
				if (ms.x >= 240 && ms.x <320 && ms.y >= 220 && ms.y < 260)
				{
					choice = 1;
					break;
				}
			}
			FlushBatchDraw();//��ͼ
		}
		if (choice == 3)
		{
			return;
		}
	}
	EndBatchDraw();//����������ͼ
	getchar();
	closegraph();
}