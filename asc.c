#include "asc.h"



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
int OutChinese(char *string,int color,int x0,int y0,int x1,int y1,int size)
//int OutChinese(char *string,int color,Area position,int size)
{
    FILE *hzk;
    int size_read=0;
    unsigned char *bitmap;
    long offset;
    char hzk_file[128];
    int num_chinese;
    //Coordinate current_position;
    int i=0;
    unsigned char qh=0,wh=0;
    int x=x0;
    //current_position.x=position.lt.x;
    int y=y0;
    //current_position.y=position.lt.y;
    if(size%4!=0&&size<=8)
    {
        return 1;
    }
    else
    {
        size_read=((size+4)/8)*size;
    }
    sprintf(hzk_file,"hzk\\HZK%d",size);
    if((hzk=fopen(hzk_file,"rb"))==NULL)
    {
        return 2;
    }
    if((bitmap=(char *) malloc(sizeof(char)*size_read))==NULL)
    {
        fclose(hzk);
        return 3;
    }
    if(strlen(string)%2!=0)
    {
        fclose(hzk);
        free(bitmap);
        return 4;
    }
    else
    {
        num_chinese=strlen(string)/2;
    }
   for(i=0;i<num_chinese;i+=1)
   {
        qh=string[i*2]-0xa0;
        wh=string[i*2+1]-0xa0;
        offset=(long) (94*((int) qh-1)+((int) wh-1))*size_read;
        fseek(hzk,offset,SEEK_SET);
        fread(bitmap,sizeof(char),size_read,hzk);
        OutChineseByBitmap(bitmap,x,y,color,size);
        if(x+size*2<=x1)
        {
            x+=size;
        }
        else
        {
            x=x1;
            if(y+size*2<=y1)
            {
                y+=size;
            }
            else
            {
                fclose(hzk);
                free(bitmap);
                return 5;
            }
        }
   }
   free(bitmap);
   fclose(hzk);
   return 0;
}

int OutChineseByBitmap(char *bitmap,int x0,int y0,int color,int size)
{
    int i=0,j=0,k=0;
    int x=x0;
    int y=y0;
    int width_byte=0;
    if(size%4!=0&&size>=8)
    {
        return 1;
    }
    else
    {
        width_byte=(size+4)/8;
    }
    for(i=0;i<size;i+=1)
    {
        for(j=0;j<width_byte;j+=1)
        {
            for(k=0;k<8;k+=1)
            {
                if(GetBit(k+1,bitmap[i*width_byte+j])==1)
                {
                    Putpixel64k(x+j*8+k,y+i,color);
                }
            }
        }
    }
    return 0;
}