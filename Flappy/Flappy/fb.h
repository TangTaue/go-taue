#include<iostream>
#include<graphics.h>  
#include <conio.h>
#include <time.h>
#include <fstream>  
#include <mmsystem.h>//����������Ҫ
#pragma comment (lib,"winmm.lib")
//#include<windows.h>

using namespace std;
const int width=640;
const int height=480;
const int blank =100 ;//�ܵ���϶��С
const int jiange = 200;//�ܵ�����
const int gw = 30;//�ܵ����
int grade=0;
int choice = 0;

class father
{
public:
	virtual void move() = 0;
	virtual void init() = 0;
	virtual int getlx() = 0;
	virtual int getly() = 0;
protected:
	int lx;
	int ly;
	int rx;
	int ry;	
}*f;


class bird :public father
{
public:
	void init();
	virtual void draw();
	void move();
	int getlx();
	int getly();
protected:
	int h;
	IMAGE bird0, bird0_0,bird1,bird1_1;
};
bird *b = new bird;

class guandao :public father
{
public:
	void init();
	void draw(guandao*);	
	void move();
	void n()
	{
		p = p->next;
	}
	int  getlx();
	int getly();
protected:
	int gl;   //�ܵ�����
	int downgl ; //�·��ܵ��ĳ���
	int downy;  //�·��ܵ���������
	guandao *next;
}*q,*p,*head;
guandao*g =new guandao;
guandao *tail;

class ditu:public bird,public guandao
{
public:	
	void began();
	void draw();
	
	int end();
protected:
	int wall();
	int gd();
	MOUSEMSG msg;
	IMAGE bg;
};

void bird::init()
{
	b->lx = 200;
	b->ly = 200;
}
void bird::draw()
{
	loadimage(&bird0_0, "bird0_0.gif",30,30);//(30,30)ָͼƬ�Ĵ�С��  ��ͼƬ�浽����backImg��
	loadimage(&bird0, "bird0.gif", 30, 30);//(30,30)ָͼƬ�Ĵ�С��  ��ͼƬ�浽����backImg��
	loadimage(&bird1, "bird1.gif", 30, 30);
	loadimage(&bird1_1, "bird1_1.gif", 30, 30);
}

void bird::move()
{
	h = height -b->ly;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		mciSendString("close fei.wav", 0, 0, 0);
		mciSendString("open fei.wav", NULL, 0, NULL);
		mciSendString("play fei.wav", 0, 0, 0);
		putimage(b->lx, b->ly, &bird0_0, NOTSRCERASE);
		putimage(b->lx, b->ly, &bird0, SRCINVERT);
		b->ly-= 20;
	}
	else
	{
		putimage(b->lx, b->ly, &bird1, NOTSRCERASE);
		putimage(b->lx, b->ly, &bird1_1, SRCINVERT);
		b->ly+= 10;
	}
}
int bird::getlx()
{
	int x = b->lx;
	return x;
}
int bird::getly()
{
	int y = b->ly;
	return y;
}

int guandao::getlx()
{
	int x = p->lx;
	return x;
}

int guandao::getly()
{
	int y = p->ly+p->ry;
	return y;
}
void guandao::draw(guandao *p)
{
	int a = rand() % 255;
	int b = rand() % 250;
	int c = rand() % 250;
	setfillcolor(RGB(a,b,c));
	fillrectangle(p->lx, p->ly, p->rx, p->ry);
	fillrectangle(p->lx, downy, p->rx, height);
}

void guandao::init()
{
	head = g;
	srand((unsigned)time(NULL));
	g->lx = 300;
	p =g;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p->lx <= width)
	{
		p->ry = rand() % 100 + 100;
		q = new guandao;
		q->next = NULL;
		p->next = q;
		p->next->lx = p->lx + jiange;
		p = p->next;
	}
	p->ry = rand() % 100 + 100;
}

void guandao::move() 
{
	p =g;
	while (p->next != NULL)
	{
		p = p->next;
	}
	tail = p;
	if (tail->lx + jiange == width)
	{
		q = new guandao;
		q->next = NULL;
		tail->next = q;
		tail->next->lx = tail->lx + jiange;
		tail = tail->next;
		tail->ry = rand() % 400+50;
	}
	if (g->lx + gw == 0)
	{
		//p = g;
		g = g->next;
		//free(p);
	}
	p = g;
	while (p != NULL)
	{
		p->rx = p->lx + gw;
		downy = p->ly + p->ry + blank;
		draw(p);
		p->lx-=5;
		p = p->next;
	}
}

void ditu::draw()
{
	loadimage(&bg, "bg.jpg", 640,480);
	putimage(0, 0, &bg);
}

void ditu::began()
{
	draw();
	setbkmode(TRANSPARENT); //���ñ������Ϊ ͸��
	settextstyle(50, 0, "RAVIE"); //����������
	while (1)
	{
		msg = GetMouseMsg();// ��ȡ������Ϣ
		//����λ��
		if (msg.x >= 255 && msg.x < 420 && msg.y >= 130 && msg.y < 170)
		{
			settextcolor(RGB(222, 0, 0));
			outtextxy(255, 130, "��ʼ��Ϸ");
		}
		else
		{
			settextcolor(RGB(222, 200, 200));//����������ɫ
			outtextxy(255, 130, "��ʼ��Ϸ");//�������
		}
		if (msg.x >= 255 && msg.x < 420 && msg.y >= 180 && msg.y < 220)
		{
			settextcolor(RGB(222, 0, 0));
			outtextxy(255, 180,"��������");
		}
		else
		{
			settextcolor(RGB(222, 200, 200));//����������ɫ
			outtextxy(255, 180, "��������");//�������
		}
		if (msg.x >= 255 && msg.x < 420 && msg.y >= 230 && msg.y < 270)
		{
			settextcolor(RGB(222, 0, 0));
			outtextxy(255, 230, "�˳���Ϸ");
		}
		else
		{
			settextcolor(RGB(222, 200, 200));//����������ɫ
			outtextxy(255, 230, "�˳���Ϸ");//�������
		}
		switch (msg.uMsg) //��ȡ�����Ϣ
		{
		case WM_LBUTTONDOWN:  //�������
			if (msg.x >= 255 && msg.x < 420 && msg.y >= 130 && msg.y < 170)
			{
				choice = 1;
				return;
			}
			if (msg.x >= 255 && msg.x < 420 && msg.y >= 180 && msg.y < 220)
			{
				choice = 2;
				return;
			}
			if (msg.x >= 255 && msg.x < 420 && msg.y >= 230 && msg.y < 270)
			{
				choice = 3;
				return;
			}
		default:
			break;
		}
	}
}

int ditu::wall()
{
	if (b->getly() <= 0 || b->getly() + 10 >= height)
	{
		mciSendString("open zhuang.wav", NULL, 0, NULL);
		mciSendString("play zhuang.wav", 0, 0, 0);
		return 1;
	}
	return 0;
}

int ditu::gd()
{
	p = g;
	while (b->getlx() > p->getlx() + gw)
	{
		p->n();
	}
	if (b->getlx() + 30 >= p->getlx() && b->getlx() <= p->getlx() + gw)
	{
		if (b->getly() <= p->getly() || b->getly() + 15 >= p->getly() + blank)
		{
			mciSendString("open zhuang.wav", NULL, 0, NULL);
			mciSendString("play zhuang.wav", 0, 0, 0);
			return 1;
		}
		return 0;
	}
	return 0;
}

int grad()
{
	p = head;
	ofstream onfile("score.dat");
	while (b->getlx() > p->getlx() + gw)
	{
		p->n();
		grade++;
	}
	onfile << "score:" << grade;
	onfile.close();
	return  grade;
}

int ditu::end()
{

	if (wall() == 1 || gd() == 1)
	{
		cleardevice();
		setcolor(WHITE);
		return 1;
	}
	return 0;
}