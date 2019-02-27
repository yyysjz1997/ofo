#ifndef _ZHUCE_H_
#define _ZHUCE_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"

typedef struct PERSON
{
    char name[7];            //”√ªß√˚
    char password[7];            //√‹¬Î
    struct PERSON *next;
}PER;

void clear(char *p,int x,int y);
void free_link(PER *head);
void save(PER *head);
void read(PER *head);
int search(PER *info,PER *data,char flag);
void inputs(char *p,int x,int y,int flag);
void zhuce(PER *info,PER *data);
void login(struct mousemsg *mouse,struct system *syst,PER *data);


#endif