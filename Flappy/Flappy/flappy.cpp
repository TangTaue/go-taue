#include "fb.h"


int wall()
{
	if (b->gety() <= 0 || b->gety() + 10 >= height)
	{
		return 1;
	}
	return 0;
}

int gd()
{
	p = g;
	while (b->getx() > p->getx())
	{
		p->n();
	}
	if (b->getx() + 30 >= p->getx() && b->getx() <= p->getx() + gw)
	{
		if (b->gety() <= p->gety() || b->gety() + 10 >= p->gety() + blank)
		{
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
	while (b->getx() > p->getx() + gw)
	{
		p->n();
		grade++;
	}
	onfile << "score:" << grade;
	onfile.close();
	return  grade;
}

int end()
{

	if (wall() == 1 || gd() == 1)
	{
		cleardevice();
		setcolor(WHITE);
		return 1;
	}
	return 0;
}
void bird::init()
{
	b->lx = 200;
	b->ly = 200;
}
void bird::draw()
{
	loadimage(&bird0_0, "bird0_0.gif", 30, 30);//(30,30)ָͼƬ�Ĵ�С��  ��ͼƬ�浽����backImg��
	putimage(b->lx, b->ly, &bird0_0, NOTSRCERASE);
	loadimage(&bird0, "bird0.gif", 30, 30);//(30,30)ָͼƬ�Ĵ�С��  ��ͼƬ�浽����backImg��
	putimage(b->lx, b->ly, &bird0, SRCINVERT);
}

void bird::move()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		b->ly -= 20;
	}
	else
	{
		b->ly += 10;
	}
}
int bird::getx()
{
	int x = b->lx;
	return x;
}
int bird::gety()
{
	int y = b->ly;
	return y;
}

int guandao::getx()
{
	int x = p->lx;
	return x;
}

int guandao::gety()
{
	int y = p->ly + p->ry;
	return y;
}
void guandao::draw(guandao *p)
{
	int a = rand() % 255;
	int b = rand() % 250;
	int c = rand() % 250;
	setfillcolor(RGB(a, b, c));
	fillrectangle(p->lx, p->ly, p->rx, p->ry);
	fillrectangle(p->lx, downy, p->rx, height);
}

void guandao::init()
{
	head = g;
	srand((unsigned)time(NULL));
	g->lx = 300;
	p = g;
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

void guandao::move()  //��Ҫʵ�ֵĸ�����  ����Ҫ��������
{
	p = g;
	head = g;
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
		tail->ry = rand() % 400 + 50;
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
		p->lx -= 5;
		p = p->next;
	}
}

void ditu::draw()
{
	loadimage(&bg, "bg.jpg", 640, 480);
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
			outtextxy(255, 180, "��������");
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

