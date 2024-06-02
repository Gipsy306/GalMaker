#include "MainInterface.h"
#include "CG.cpp"
#include "PutPictuerAlpha.cpp"


void background::setgraph() {
    IMAGE img;
    loadimage(&img, _T(MIpicture));
    putPictureAlpha(0, 0, &img, RGB(0, 0, 0), 80);
}

void Title::SetTheTitle() {
    IMAGE img;
    loadimage(&img, _T(Tpicture));
    getimage(&img, x, y, destWidth, destHeight);
}

void











