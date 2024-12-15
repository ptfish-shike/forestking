#include<graphics.h>
#include<windows.h>
#include "forestking.h"

void welcome();//开始界面

bool PointInRect(int x, int y, RECT& r);//判断是否在r的矩形范围内

bool play();//进行游戏

int main(void) {
	initgraph(swidth,sheight);//搭建画布
	//显示标题logo
	bool is_live = true;
	while (is_live)
	{
		welcome();
		play();
		is_live = play();//使得死亡后可以再次游玩
	}
	return 0;
}


void welcome()
{
	LPCTSTR tplay = _T("开始游戏");
	LPCTSTR texit = _T("退出游戏");

	RECT tplayr, texitr;//设置两个字体所在矩形范围


	IMAGE logo_img;//载入图片
	loadimage(&logo_img, _T("logo.jpg"), 433, 147);
	putimage(100, 20, &logo_img);//显示图片
	//显示“开始游戏，退出游戏”
	setlinecolor(WHITE);//调整线条颜色
	settextstyle(16, 0, _T("宋体"));//定义字体大小

	tplayr.left = swidth / 2 - textwidth(tplay) / 2;
	tplayr.right = tplayr.left + textwidth(tplay);
	tplayr.top = sheight / 5 * 3;
	tplayr.bottom = tplayr.top + textheight(tplay);

	texitr.left = swidth / 2 - textwidth(texit) / 2;
	texitr.right = texitr.left + textwidth(texit);
	texitr.top = sheight / 5 * 3.5;
	texitr.bottom = texitr.top + textheight(texit);
	//设置好文字位置

	outtextxy(tplayr.left, tplayr.top,tplay);
	outtextxy(texitr.left, texitr.top, texit);

	//实现菜单交互

	while (true) {
		ExMessage mouse;//定义接收信息的变量
		getmessage(&mouse, EM_MOUSE);//接收来自鼠标的信息
		
		if (mouse.lbutton)//按下鼠标左键
		{
			if (PointInRect(mouse.x, mouse.y, tplayr))
			{
				return;//返回然后开始游戏
			}
			else if (PointInRect(mouse.x, mouse.y, texitr))
			{
				exit(0);//退出游戏
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
	cleardevice();//修改全部背景色
	bool is_play = true;
	
	IMAGE  enemyimg, bkimg, bulletimg;//创建敌人背景和子弹的图片类型
	IMAGE heroimgs, heroimgr, heroimgn, heroimgl, heroimgv, heroimgd;
	//创建人物各个方向的图片类型

	//加载图片
	loadimage(&bkimg, _T("\\forestking\\草原大王\\地图1.jpg"));
	loadimage(&heroimgs, _T("\\forestking\\草原大王\\角色下.jpg"));
	loadimage(&heroimgn, _T("\\forestking\\草原大王\\角色上.jpg"));
	loadimage(&heroimgl, _T("\\forestking\\草原大王\\角色左.jpg"));
	loadimage(&heroimgr, _T("\\forestking\\草原大王\\角色右.jpg"));
	loadimage(&heroimgv, _T("\\forestking\\草原大王\\角色胜利.jpg"));
	loadimage(&heroimgd, _T("\\forestking\\草原大王\\角色失败.jpg"));

	




	

	BK bk = BK(bkimg);//生成背景类

	Hero hero = Hero(heroimgs);



















	while (is_play)
	{
		BeginBatchDraw();//开始批量绘图
		bk.show();
		hero.show();
		EndBatchDraw();//结束批量绘图
	}

	return 1;
}
