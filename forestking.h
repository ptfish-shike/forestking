#pragma once
#include<graphics.h>
#include<windows.h>

const int swidth = 650, sheight = 650;//将界面宽和高设为常量
class BK//背景类
{
public:
	BK(IMAGE& img);
	void show();
private:
	IMAGE& img;
	
};

class Hero
{
public:
	Hero(IMAGE& img);
	void show();



private:
	unsigned int  HP;
	IMAGE& img;
	RECT rect;

};