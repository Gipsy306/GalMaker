#include"TachieBox.h"

tachieBox::tachieBox(int box_x,int box_y,int box__x,int box__y) :box_x(box_x), box_y(box_y), box__x(box__x), box__y(box__y) {};

void tachieBox::draw(const char* character) 
{
	IMAGE img;
	loadimage(&img, _T(character), box__x - box_x, box__y - box_y);
	putimage(box_x, box_y,&img);
}