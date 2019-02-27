#include "remenu.h"

int backmenu(void)
{
    Initmouse(0,1024,0,768);
    while(1)
    {
        if(Mouse_above(726,645,917,690))
        {
            Newxy2();
            if(Mouse_press(726,645,917,690))
            {
                Initmouse(0,1024,0,768);//±ØÐë¼Ó
                Putbmp64k(300,300,"bmp\\success.bmp");
                delay(5000);
                Putbmp64k(0,0,"bmp\\zhu.bmp");
                exit (1);
            }
        }
        else
        {
            Newxy();
        }
    }
}