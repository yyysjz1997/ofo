#include"music.h"

/**********************************************************
下面定义了：各个声音频率的数值，各个停顿时间的长短
**********************************************************/

#define LL1 131    //低低音dou
#define LL1S  139  //低低音#dou
#define LL2 147
#define LL2S 156
#define LL3 165
#define LL4 175
#define LL4S 185
#define LL5   196
#define LL5S  208
#define LL6 220
#define LL6S  233
#define LL7 247
#define L1  262    //低音dou
#define L1S 277    //低音#dou
#define L2  294
#define L2S 311
#define L3  330
#define L4  349
#define L4S 370
#define L5  392
#define L5S 415
#define L6  440
#define L6S 466
#define L7  494
#define M1  523     //中音dou
#define M1S 554     //中音#dou
#define M2  587
#define M2S 622
#define M3  659
#define M4  698
#define M4S 740
#define M5  784
#define M5S 831
#define M6  880
#define M6S 932
#define M7  988
#define H1  1046       //高音dou
#define H1S 1109       //高音#dou
#define H2  1175
#define H2S 1245
#define H3  1318
#define H4  1397
#define H4S 1480
#define H5  1568
#define H5S 1661
#define H6  1760
#define H6S 1865
#define H7  1976
#define HH1 2093       //高高音dou
#define HH1S  2217      //高高音#dou
#define HH2 2349
#define HH2S  2489
#define HH3 2637
#define HH4 2794
#define HH4S  2960
#define HH5 3136
#define HH5S  3322
#define HH6 3520
#define HH6S  3729
#define HH7 3951

#define P1  640   //停顿时间
#define P2  320
#define P4  160
#define P8  80
#define P3  213

#define NOTE_NUM  278  //音符个数

/**********************************************************
Function：       music

Description：    在小黄车“行驶中”循环播放音乐（超级玛丽背景音乐）

Input：      define中有定义各个音的频率以及停顿的时间的长短
             int frq[NOTE_NUM] 数组中存储了各个声音的频率
             int tm[NOTE_NUM] 数组中存储了各个声音的时间长短以及停顿时间的长短

Output：     一个一个的声音频率，组成一首完整的曲子

Return：     空

Others：     无
**********************************************************/
void music(void)
{
    int i;
    int frq[NOTE_NUM]=
    {
    H3, H3, H3, 0, H1, H3, H5, 0, M5, 0,
    H1, 0, M5, 0, M3, 0, M6, M7, 0, M6S, M6,
    M5, H3, H5, H6, H4, H5, 0, H3, H1, H2, M7, 0,

    H1, 0, M5, 0, M3, 0, M6, M7, 0, M6S, M6,
    M5, H3, H5, H6, H4, H5, 0, H3, H1, H2, M7, 0,
    0, H5, H4S, H4, H3, H2S, 0, M5S, M6, H1, 0, M6, H1, H2,

    0, H5, H4S, H4, H2S, H3, 0, HH1, HH1, HH1, 0,
    0, H5, H4S, H4, H2S, H3, 0, M5S, M6, H1, 0, M6, H1, H2,
    0, H2S, 0, H2, 0, H1, 0, 0,

    0, H5, H4S, H4, H2S, H3, 0, M5S, M6, H1, 0, M6, H1, H2,
    0, H5, H4S, H4, H2S, H3, 0, HH1, HH1, HH1, 0,
    0, H5, H4S, H4, H2S, H3, 0, M5S, M6, H1, 0, M6, H1, H2,

    0, H2S, 0, H2, 0, H1, 0, 0,
    H1, H1, H1, 0, H1, H2, H3, H1, M6, M5, 0,
    H1, H1, H1, 0, H1, H2, H3, 0, 0,

    H1, H1, H1, 0, H1, H2, H3, H1, M6, M5, 0,
    H3, H3, H3, 0, H1, H3, H5, 0, M5, 0,
    H1, 0, M5, 0, M3, 0, M6, M7, 0, M6S, M6, 0,

    M5, H3, H5, H6, H4, H5, 0, H3, H1, H2, M7, 0,
    H1, 0, M5, 0, M3, 0, M6, M7, 0, M6S, M6,
    M5, H3, H5, H6, H4, H5, 0, H3, H1, H2, M7, 0,

    H3, H1, M5, 0, M5S, M6, H4, H4, M6, 0,
    M7, H6, H6, H6, H5, H4, H3, H1, M6, M5, 0,
    H3, H1, M5, 0, M5S, M6, H4, H4, M6, 0,

    M7, H4, H4, H4, H3, H2, H1, 0, 0
    };

    int tm[NOTE_NUM]=
    {
    P4, P2, P4, P4, P4, P2, P2, P2, P2, P2,
    P2, P4, P4, P2, P2, P4, P2, P4, P4, P4, P2,
    P3, P3, P3, P2, P4, P4, P4, P2, P4, P4, P2, P4,

    P2, P4, P4, P2, P2, P4, P2, P4, P4, P4, P2,
    P3, P3, P3, P2, P4, P4, P4, P2, P4, P4, P2, P4,
    P2, P4, P4, P4, P2, P4, P4, P4, P4, P4, P4, P4, P4, P4,

    P2, P4, P4, P4, P2, P4, P4, P2, P4, P2, P2,
    P2, P4, P4, P4, P2, P4, P4, P4, P4, P4, P4, P4, P4, P4,
    P2, P2, P4, P2, P4, P2, P2, P1,

    P2, P4, P4, P4, P2, P4, P4, P4, P4, P4, P4, P4, P4, P4,
    P2, P4, P4, P4, P2, P4, P4, P2, P4, P2, P2,
    P2, P4, P4, P4, P2, P4, P4, P4, P4, P4, P4, P4, P4, P4,

    P2, P2, P4, P2, P4, P2, P2, P1,
    P4, P2, P4, P4, P4, P2, P4, P2, P4, P2, P2,
    P4, P2, P4, P4, P4, P4, P4, P1, P1,

    P4, P2, P4, P4, P4, P2, P4, P2, P4, P2, P2,
    P4, P2, P4, P4, P4, P2, P2, P2, P2, P2,
    P2, P4, P4, P2, P2, P4, P2, P4, P4, P4, P4, P4,

    P3, P3, P3, P2, P4, P4, P4, P2, P4, P4, P2, P4,
    P2, P4, P4, P2, P2, P4, P2, P4, P4, P4, P2,
    P3, P3, P3, P2, P4, P4, P4, P2, P4, P4, P2, P4,

    P4, P2, P4, P2, P2, P4, P2, P4, P2, P2,
    P3, P3, P3, P3, P3, P3, P4, P2, P4, P2, P2,
    P4, P2, P4, P2, P2, P4, P2, P4, P2, P2,

    P4, P2, P4, P3, P3, P3, P2, P2, P1
    };

    for(i=0;i<=(NOTE_NUM-1);i+=1)
    {
        sound(frq[i]);   //播放
        delay(tm[i]);     //停顿
    }
    nosound();     //播放结束，停止播放
}

