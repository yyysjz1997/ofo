#include "graphics.h"
#include <stdio.h>
#include <dos.h>

int main()
{
    int driver=DETECT,modo=DETECT;
    int i=0;
    installuserdriver("Svga64k",DETECT);
    initgraph(&driver,&modo,"c:\\Borlandc\\bgi");
    for(i=0;i<10000;i++)
    {
        setbkcolor((unsigned) i);
        delay(1000);
    }
    line(100,100,200,200);
    return 0;
}