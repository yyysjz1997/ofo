#include "asc.h"
#include "svgamode.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int OutASC(char *string,int size,int color,int x0,int y0,int x1,int y1)
{
    FILE *asc=NULL;
    char *bitmap;
    char ascpath[128];
    int length=strlen(string);
    int x=x0,y=y0;
    int i=0,j=0,k=0;
    int width_byte=((size/2)+6)/8;

    int width=size/2;
    int size_bitmap=width_byte*size;
    long offset=0;
    int pos=0;
    sprintf(ascpath,"ASC\\ASC%d",size);
    if((asc=fopen(ascpath,"rb"))==NULL) return -1;
    if((bitmap=(char *) malloc(sizeof(char)*size_bitmap))==NULL)
    {
        fclose(asc);
        return -2;
    }
    for(pos=0;pos<length;pos++)
    {
        offset=(long) ((long)sizeof(char))*((long) size_bitmap)*((long) string[pos]);
        fseek(asc,offset,SEEK_SET);
        fread(bitmap,sizeof(char),size_bitmap,asc);
        for(i=0;i<size;i++)
        {
            for(j=0;j<width_byte;j++)
            {
                for(k=0;k<8;k++)
                {
                    if(GetBit(k+1,bitmap[i*width_byte+j])==1)
                    {
                        Putpixel64k(x+j*8+k,y+i,color);
                    }
                }
            }
        }
        if(x+2*width>=x1)
        {
            if(y+size*2<=y1)
            {
                x=x0;
                y+=size;
            }
            else
            {
                fclose(asc);
                free(bitmap);
                return pos;
            }
        }
        else
        {

            x+=width;
        }
    }
    fclose(asc);
    free(bitmap);
    return 0;
}

int OutChar(char out,int size,int x,int y,int color)
{
    FILE *asc=NULL;
    char ascpath[128];
    char *bitmap=NULL;
    int width_byte=0,size_bitmap=0;
    int i=0,j=0,k=0;
    long offset=0;
    sprintf(ascpath,"ASC\\ASC%d",size);
    if((asc=fopen(ascpath,"rb"))==NULL) return -1;
    width_byte=((size/2)+6)/8;
    size_bitmap=width_byte*size;
    if((bitmap=(char *) malloc(sizeof(char)*size_bitmap))==NULL)
    {
        fclose(asc);
        return -2;
    }
    offset=(long) ((long)sizeof(char))*((long) size_bitmap)*((long) out);
    fseek(asc,offset,SEEK_SET);
    fread(bitmap,sizeof(char),size_bitmap,asc);
    for(i=0;i<size;i++)
    {
        for(j=0;j<width_byte;j++)
        {
            for(k=0;k<8;k++)
            {
                if(GetBit(k+1,bitmap[i*width_byte+j])==1)
                {
                    Putpixel64k(x+j*8+k,y+i,color);
                }
            }
        }
    }
    fclose(asc);
    free(bitmap);
    return 0;
}


int GetBit(int num,char ch)
{
    int i;
    int temp=1;

    for(i=0;i<8-num;i+=1)
    {
        temp*=2;
    }
    return (temp&ch)&&1;
}