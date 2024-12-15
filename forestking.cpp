#include "forestking.h"

BK::BK(IMAGE& img): img(img)
{
}

void BK::show()
{
	putimage(0, 0, &img);
}

Hero::Hero(IMAGE& img)
	:img(img), HP(3)
{//将角色放在中心位置
	rect.left = swidth / 2 - img.getwidth() / 2;
	rect.right= swidth / 2 + img.getwidth() / 2;
	rect.top = sheight / 2 - img.getheight() / 2;
	rect.bottom = sheight / 2 + img.getheight() / 2;
}

void Hero::show()
{
	putimage(rect.left, rect.top, &img);

}
