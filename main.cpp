#include<graphics.h>
#include<windows.h>
#include "forestking.h"

void welcome();//��ʼ����

bool PointInRect(int x, int y, RECT& r);//�ж��Ƿ���r�ľ��η�Χ��

bool play();//������Ϸ

int main(void) {
	initgraph(swidth,sheight);//�����
	//��ʾ����logo
	bool is_live = true;
	while (is_live)
	{
		welcome();
		play();
		is_live = play();//ʹ������������ٴ�����
	}
	return 0;
}


void welcome()
{
	LPCTSTR tplay = _T("��ʼ��Ϸ");
	LPCTSTR texit = _T("�˳���Ϸ");

	RECT tplayr, texitr;//���������������ھ��η�Χ


	IMAGE logo_img;//����ͼƬ
	loadimage(&logo_img, _T("logo.jpg"), 433, 147);
	putimage(100, 20, &logo_img);//��ʾͼƬ
	//��ʾ����ʼ��Ϸ���˳���Ϸ��
	setlinecolor(WHITE);//����������ɫ
	settextstyle(16, 0, _T("����"));//���������С

	tplayr.left = swidth / 2 - textwidth(tplay) / 2;
	tplayr.right = tplayr.left + textwidth(tplay);
	tplayr.top = sheight / 5 * 3;
	tplayr.bottom = tplayr.top + textheight(tplay);

	texitr.left = swidth / 2 - textwidth(texit) / 2;
	texitr.right = texitr.left + textwidth(texit);
	texitr.top = sheight / 5 * 3.5;
	texitr.bottom = texitr.top + textheight(texit);
	//���ú�����λ��

	outtextxy(tplayr.left, tplayr.top,tplay);
	outtextxy(texitr.left, texitr.top, texit);

	//ʵ�ֲ˵�����

	while (true) {
		ExMessage mouse;//���������Ϣ�ı���
		getmessage(&mouse, EM_MOUSE);//��������������Ϣ
		
		if (mouse.lbutton)//����������
		{
			if (PointInRect(mouse.x, mouse.y, tplayr))
			{
				return;//����Ȼ��ʼ��Ϸ
			}
			else if (PointInRect(mouse.x, mouse.y, texitr))
			{
				exit(0);//�˳���Ϸ
			}

		}
	}
}

	bool PointInRect(int x, int y, RECT & r)
	{
		return (r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
	}

bool play()
{
	setbkcolor(WHITE);
	cleardevice();//�޸�ȫ������ɫ
	bool is_play = true;
	
	IMAGE  enemyimg, bkimg, bulletimg;//�������˱������ӵ���ͼƬ����
	IMAGE heroimgs, heroimgr, heroimgn, heroimgl, heroimgv, heroimgd;
	//����������������ͼƬ����

	//����ͼƬ
	loadimage(&bkimg, _T("\\forestking\\��ԭ����\\��ͼ1.jpg"));
	loadimage(&heroimgs, _T("\\forestking\\��ԭ����\\��ɫ��.jpg"));
	loadimage(&heroimgn, _T("\\forestking\\��ԭ����\\��ɫ��.jpg"));
	loadimage(&heroimgl, _T("\\forestking\\��ԭ����\\��ɫ��.jpg"));
	loadimage(&heroimgr, _T("\\forestking\\��ԭ����\\��ɫ��.jpg"));
	loadimage(&heroimgv, _T("\\forestking\\��ԭ����\\��ɫʤ��.jpg"));
	loadimage(&heroimgd, _T("\\forestking\\��ԭ����\\��ɫʧ��.jpg"));

	




	

	BK bk = BK(bkimg);//���ɱ�����

	Hero hero = Hero(heroimgs);



















	while (is_play)
	{
		BeginBatchDraw();//��ʼ������ͼ
		bk.show();
		hero.show();
		EndBatchDraw();//����������ͼ
	}

	return 1;
}
