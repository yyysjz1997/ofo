#include "explain.h"

int explainy()
{
    int temp2;
    Initmouse(0,1024,0,768);//必须加
    Putbmp64k(0,0,"bmp\\shuoming.bmp");
    temp2=Getpixel64k(500,10);
    while(1)
    {
      //Newxy();
      if(Mouse_above(842,648,964,711))
      {
        explain_next();
      }
      if(Mouse_press(842,648,964,711))
      {
          Initmouse(0,1024,0,768);//必须加
          Putbmp64k(0,0,"bmp\\shuomin2.bmp");
          while(1)
          {
               if(Mouse_above(764,657,956,721))
               {
                   explain_return();
               }
               if(Mouse_press(764,657,956,721))
               {
                   Initmouse(0,1024,0,768);//必须加
                   Putbmp64k(0,0,"bmp\\zhu.bmp");
                   return 0;
               }
               if(!Mouse_above(764,657,956,721))
              {
                  Newxy();
                  Linex(764,657,956,657,temp2);
                  Liney(764,657,764,721,temp2);
                  Linex(764,721,956,721,temp2);
                  Liney(956,657,956,721,temp2);
              }
          }
      }
      if(!Mouse_above(842,648,964,711))
      {
        Newxy();
            Linex(842,648,964,648,temp2);
            Liney(842,648,842,711,temp2);
            Linex(842,711,964,711,temp2);
            Liney(964,648,964,711,temp2);
      }
    }
}


int explain_next()
{
     Newxy2();
     Linex(842,648,964,648,60000);
     Liney(842,648,842,711,60000);
     Linex(842,711,964,711,60000);
     Liney(964,648,964,711,60000);
     return 0;
}


int explain_return()
{
    Newxy2();
    Linex(764,657,956,657,60000);
    Liney(764,657,764,721,60000);
    Linex(764,721,956,721,60000);
    Liney(956,657,956,721,60000);
    return 0;
}

