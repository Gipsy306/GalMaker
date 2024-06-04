#include"CG.h"

void cg::setCGPicture(const char* cgpicture)
{
    cgPicture = (char*)cgpicture;
}

<<<<<<< HEAD
=======

>>>>>>> fcc3626466b9e19a507ddbdba22b547ac89eb2e2
void cg::draw() {
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());
	putimage( 0, 0,&img);
}

void cg::CGdrawGradually() 
{
	IMAGE img;
	loadimage(&img, _T(cgPicture), getwidth(), getheight());

    //è®¾ç½®è¶…æ—¶æ—¶é—´ä¸º510æ¯«ç§’
    DWORD startTime = GetTickCount();
    DWORD timeout = 510;

    int alpha = 5;

<<<<<<< HEAD
    //ÔÚ510ºÁÃëÄÚ½¥±äÏÔÊ¾CG£¬²¢¼ì²âÓÃ»§ÊäÈë
    while (GetTickCount() - startTime < timeout)
    {
        putPictureAlpha(0, 0, &img, RGB(0, 0, 0), alpha);
        alpha += 5; //Ôö¼ÓCG²»Í¸Ã÷¶È

        //¼ì²âÓÃ»§ÊäÈë
        //Èô°´enter¼ü
        if (_kbhit() && _getch() == '\r') 
        {
=======
    //åœ¨510æ¯«ç§’å†…æ¸å˜æ˜¾ç¤ºCGï¼Œå¹¶æ£€æµ‹ç”¨æˆ·è¾“å…¥
    while (GetTickCount() - startTime < timeout) {
        putPictureAlpha(0,0,&img,RGB(0,0,0),alpha);
        alpha += 5; //å¢åŠ CGä¸é€æ˜åº¦

        //æ£€æµ‹ç”¨æˆ·è¾“å…¥
        //è‹¥æŒ‰enteré”®
        if (_kbhit() && _getch() == '\r') {
>>>>>>> fcc3626466b9e19a507ddbdba22b547ac89eb2e2
            putimage(0, 0, &img);
            break;
        }

        //å¦‚æœæ£€æµ‹åˆ°é¼ æ ‡å·¦é”®ç‚¹å‡»
        ExMessage msg;
        if (peekmessage(&msg, EM_MOUSE) && msg.message == WM_LBUTTONDOWN)
        {
            putimage(0, 0, &img);
            break;
        }

        //æš‚åœ10æ¯«ç§’
        Sleep(10);
    }
    putimage(0, 0, &img);//ä¿è¯æœ€ç»ˆç»˜åˆ¶ä¸€å¼ ä¸é€æ˜çš„CG
}
