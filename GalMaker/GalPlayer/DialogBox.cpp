#include"DialogBox.h"

dialogBox::dialogBox(int box_x, int box_y, int box__x, int box__y, const char* dialogBoxBackground,COLORREF transparentColor,int alpha,
	int nameBox_x, int nameBox_y, int nameBox__x, int nameBox__y, COLORREF NAMECOLOR, const char* NAMETYPEFACE, int nameNHeight,
	int sentenceBox_x, int sentenceBox_y, int sentenceBox__x, int sentenceBox__y, COLORREF SENTENCECOLOR, const char* SENENCETYPEFACE, int sentenceNHeight):
	box_x(box_x),box_y(box_y),box__x(box__x),box__y(box__y),dialogBoxBackground(dialogBoxBackground), transparentColor(transparentColor),alpha(alpha),
	nameBox(nameBox_x, nameBox_y, nameBox__x, nameBox__y, NAMECOLOR, NAMETYPEFACE, nameNHeight),
	sentenceBox(sentenceBox_x, sentenceBox_y, sentenceBox__x, sentenceBox__y, SENTENCECOLOR, SENENCETYPEFACE, sentenceNHeight){}//dialogBox的构造函数

void dialogBox::draw(const char* name, const char* sentence) {
	IMAGE img;
	loadimage(&img, _T(dialogBoxBackground), box__x - box_x, box__y - box_y);
    putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);
	nameBox.draw(name);
	sentenceBox.drawGradually(sentence);
}//绘制姓名为name，语句为sentence的对话框画面

void dialogBox::emerge() {
    IMAGE img;
    loadimage(&img, _T(dialogBoxBackground), box__x - box_x, box__y - box_y);

    //设置超时时间为510毫秒
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int Alpha = 5;

    //在510毫秒内渐变显示背景图，并检测用户输入
    while ((GetTickCount() - startTime < timeout)&&(Alpha<=alpha)) {
        putPictureAlpha(box_x, box_y, &img, transparentColor, Alpha);
        Alpha += 5; //增加背景图不透明度

        //检测用户输入
        //若按enter键
        if (_kbhit() && _getch() == '\r') {
            putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);
            break;
        }

        //如果检测到鼠标左键点击
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN) {
            putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);
            break;
        }

        //暂停10毫秒
        Sleep(10);
    }
    putPictureAlpha(box_x, box_y, &img, transparentColor, alpha);//保证最终绘制出透明度为设定值的背景图
}