#pragma once
#include<graphics.h>
#include<windows.h>

const int swidth = 650, sheight = 650;//�������͸���Ϊ����
class BK//������
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