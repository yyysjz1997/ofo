#include "login.h"

int loginy()
{
    int flag_login=0;
    PER *data;

	//Initmouse(0,1024,0,768);

	//Putbmp64k(0,0,"bmp\\denglu2.bmp");

	flag_login=login(data);

    return(flag_login);

}

