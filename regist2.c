#include "regist2.h"

void Register()  //ע��ĺ���
{

    /*״̬�����������ж��û����������Ƿ�ɹ���ȡ*/
    int k[2];

    /*���ڴ洢�û����û���������*/
    char reg[2][20];

    /*���ڴ洢ע��ʱ��һ������ʱ������ֵ*/
    char check_password[1][20];

    char mima;

    int temp2=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);

    /*��ѭ�����ڽ����û���ע�ᣬ�����ȷ�����˳���ť֮���Ƴ�ѭ��*/
    while(1)
    {


        /*������λ�������û����ķ����ڣ�����������û����Ĳ���*/
        if(Mouse_above(327,151,794,249))
        {
           Newxy3();
        }

        /*�����������,������û���������*/
        if(Mouse_press(327,151,794,249))
        {
            k[0]=InputInformation(327,794,151,249,0,reg);
        }

        /*������λ����������ķ�����,�������������Ĳ���*/
        if(Mouse_above(327,290,794,388))
        {
           Newxy3();
        }

        /*�����������,��������������*/
        if(Mouse_press(327,290,794,388))
        {
            k[1]=InputInformation(327,794,290,388,1,reg);
        }

        if(Mouse_above(327,429,794,527))//ȷ�������
        {
            Newxy3();
        }
        if(Mouse_press(327,429,794,527))
        {
            mima=InputInformation(327,794,429,527,1,check_password);  //��������
            // OutASC(data->name,48,65500,0,0,1000,600);
            // OutASC(data->password,48,65500,0,300,1000,600);
            // OutASC(check_password,48,65500,0,600,1000,800);
            if(strcmp(mima,k[1]))
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi2.bmp");
            }
        }

        /*�����ť*/
        if(Mouse_above(431,581,524,631))
        {
            a7();
        }
        if(Mouse_press(431,581,524,631))
        {
            //Newxy2();
            Putbmp64k(327,151,"bmp\\kong.bmp");
            Putbmp64k(327,290,"bmp\\kong.bmp");
            Putbmp64k(327,429,"bmp\\kong.bmp");
        }

        /*��������ȷ����ť������Ϣ����ɹ�ʱ����д���ļ������ɹ�ʱ���˻ص���Ϣ�������*/
        if(Mouse_above(702,582,793,632))
        {
            a5();
        }
        if(Mouse_press(702,582,793,632))
        {
            if(strlen(reg[1])==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                break;
            }
            // if(search(info,data)==1)//�����û����Ƿ��Ѿ�����
            // {
            //     Putbmp64k(327,151,"bmp\\kong.bmp");
            //     Putbmp64k(327,290,"bmp\\kong.bmp");
            //     Putbmp64k(327,429,"bmp\\kong.bmp");
            //     Putbmp64k(300,300,"bmp\\tishi7.bmp");
            //     break;
            // }
            if(strlen(reg[2])==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                break;
            }

            /*����û��������붼�ѳɹ���ȡ������д���ļ�*/
            else
            {
                if(k[0]==1&&k[1]==1)
                {

                    /*����ɹ�д���ļ�*/
                    if(Putfile(reg))
                    {
                        Putbmp64k(300,300,"bmp\\tishi3.bmp");
                        delay(1000);
                        Initmouse(0,1024,0,768);
                        Putbmp64k(0,0,"bmp\\zhu.bmp");
                        return 0;
                    }
                }
            }




            readbmp(0,0,"pic\\begin.bmp");
            readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
            InterFace(info,mouse);  /*�˻ص���ʼ����*/

            break;
        }

        /*���������˳���ť����ֱ���˻ص���һ����*/
        if(Mouse_above(189,584,272,631))         //�˳�
        {
            a6();
        }
        if(Mouse_press(189,584,272,631))         //�������
        {
            Initmouse(0,1024,0,768);//�����
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            return 0;
        }

        /*������λ������λ�ã�����ʾ���*/
       if(!Mouse_above(327,151,794,249)&&!Mouse_above(327,290,794,388)&&!Mouse_above(327,429,794,527)&&!
            Mouse_above(431,581,524,631)&&!Mouse_above(702,582,793,632)&&!Mouse_above(189,584,272,631))
        {
            Newxy();

            Linex(702,582,793,582,temp3);
            Liney(702,582,702,632,temp3);
            Linex(702,632,793,632,temp3);
            Liney(793,582,793,632,temp3);

            Linex(189,584,272,584,temp3);
            Liney(189,584,189,631,temp3);
            Linex(189,631,272,631,temp3);
            Liney(272,584,272,631,temp3);

            Linex(431,581,524,581,temp3);
            Liney(431,581,431,631,temp3);
            Linex(431,631,524,631,temp3);
            Liney(524,581,524,631,temp3);

        }

    }
}
/**********************************************************
Function��       InputInformation

Description��    �û���Ϣ���뺯������ȡ�û�������û��������룬���洢��reg��

Input��          int x1      �û���Ϣ���뷽��ĺ�������Сֵ
                int x2      �û���Ϣ���뷽��ĺ��������ֵ
                int y1      �û���Ϣ���뷽�����������Сֵ
                int y2      �û���Ϣ���뷽������������ֵ
                int pan     0��ʾ�����û������룬1��ʾ������������

                char reg[][20]
                            �û���¼��Ϣ���û���������reg[0]��
                            ���뱣����reg[1]��
                MOUSE *mouse ������

Output��     ��ȡ�û�������û���������

Return��     ״̬������0��ʾ��ȡ��Ϣʧ�ܣ�1��ʾ��ȡ��Ϣ�ɹ�

Others��     None
**********************************************************/
int InputInformation(int x1,int x2,int y1,int y2,int pan,char reg[][20])
{

    /*���ڻ�ȡ������ַ�*/
    char ac;

    /*����ȡ���ַ���ֵ��zac[0],�������*/
    char zac[2]={'\0'};

    /*���ڼ�¼�����ַ��ĸ���*/
    int n1=0;

    /*���ڼ�¼����ַ���λ��*/
    int n2=x1+1;

    /*������̻���*/
    while(bioskey(1))
    {
        getch();
    }

    /*��ѭ�����ڻ�ȡ�û��������Ϣ��������س���ʱ�˳�ѭ��*/
    while((ac=getch())!=13)
    {
        /*�����ǰ�����û�������ֱ������ַ�*/
        if(pan==0)
        {
            /*�����ǰλ��λ�ڷ���Χ�ڣ�������������*/
            if((n2>x1)&&(n2<(x2-21)))
            {
                /*���������ĸ������ʱ�������ȡ���*/
                if(((ac>='0')&&(ac<='9'))||((ac>='a')&&(ac<='z')))
                {
                    /*���и�ֵ����*/
                    zac[0]=ac;
                    reg[pan][n1++]=ac;

                    /*�������*/

                    OutASC(zac,size,0,x,y,1024,768);

                    /*������һ�ַ������λ��*/
                    n2+=15;
                }

                // /*������롰Backspace����,�����һ��*/
                // else if(ac==8&&n1>=1)
                // {
                //     n1--;
                //     n2-=15;

                //     /*�������θ����������ַ�*/
                //     bar_(n2+8,y1+1,n2+23,y1+18,-1);
                // }
            }
        }
        /*�����ǰ�������룬�����ԲȦ*/
        else if(pan==1)
        {
            /*�����ǰλ��λ�ڷ���Χ�ڣ�������������*/
            if((n2>x1)&&(n2<(x2-21)))
            {
                /*���������ĸ������ʱ�������ȡ���*/
                if(((ac>='0')&&(ac<='9'))||((ac>='a')&&(ac<='z')))
                {
                    /*���и�ֵ����*/
                    zac[0]=ac;
                    reg[pan][n1++]=ac;

                    OutASC(zac,size,0,x,y,1024,768);

                    /*������һ�ַ������λ��*/
                    n2+=15;
                }

                // /*������롰Backspace����,�����һ��*/
                // else if(ac==8&&n1>=1)
                // {
                //     n1--;
                //     n2-=15;

                //     /*�������θ����������ַ�*/
                //     bar_(n2+8,y1+1,n2+23,y1+18,-1);
                // }
            }
        }
    }

    reg[pan][n1]='\0';

    /*����ַ���������4-7λ���򷵻�0������ʧ��*/
    if(!(n1>=4&&n1<=7))
    {
        return 0;
    }

    return 1;
}
/**********************************************************
Function��       Putfile

Description��    ��InputInformation�л�ȡ���û���������д���ļ�

Input��          char reg[][20]
                            �û���¼��Ϣ���û���������reg[0]��
                            ���뱣����reg[1]��
                INFO *info  ������Ϣ
                MOUSE *mouse    ������

Output��     ���û���Ϣд���ļ�

Return��     ״̬������0��ʾ���û����Ѵ���д��ʧ�ܣ�1��ʾд��ɹ�

Others��     None
**********************************************************/
int Putfile(char reg[][20])
{
    /*�ļ�ָ��*/
    FILE *fp;

    /*���ڴ洢�û���Ϣ*/
    char userinfor[40];

    /*���ڻ���ļ�·��*/
    char path[12]={'\0'},newpath[25];
    char str[]=".txt";

    /*���ڼ�¼�ַ�λ��*/
    int n1;

    /*���ڼ���*/
    int i;

    /*��ȡ��ǰ�ļ�·��,����newpath*/
    strcpy(path,reg[0]);
    strcat(path,str);
    strcpy(newpath,"text\\");
    strcat(newpath,path);

    n1=0;

    /*��ѭ�����ڻ�ȡ�û���������ȡ���ʱ�˳�*/
    for(i=0;reg[0][i]!='\0';n1++,i++)
    {
       userinfor[n1]=reg[0][i];
    }
    userinfor[n1++]='=';

    /*��ѭ�����ڻ�ȡ����,����ȡ���ʱ�˳�*/
    for(i=0;reg[1][i]!='\0';n1++,i++)
    {
        userinfor[n1]=reg[1][i];
    }
    userinfor[n1++]='=';
    userinfor[n1]='\0';

    /*�����ǰ�ļ��Ѵ��ڣ���д��ʧ�ܣ�����0ֵ*/
    if((fp=fopen(newpath,"rb"))!=NULL)
    {
        Putbmp64k(300,300,"bmp\\tishi9.bmp");
        delay(1000);
        fclose(fp);
        return 0;
    }

    /*�����ǰ�ļ������ڣ��򽫵�ǰ�û���Ϣд���ļ�*/
    else if((fp=fopen(newpath,"wt+"))==NULL)
    {
        getch();
    }

    n1=0;

    while(userinfor[n1]!='\0')
    {
        fputc(userinfor[n1],fp);
        n1++;
    }

    fclose(fp);

    return 1;

}

void Login()
{
    /*�ļ�ָ��*/
    FILE *fp;

    /*��ȡ�ļ�·��*/
    char *str=".txt";
    char path[15]={'\0'} ,newpath[30];

    /*���ڴ洢�û���������û���*/
    char account[15],password[15];

    // /*���û���Ϣ�������*/
    // readbmp(264,254,"pic\\login.bmp");

    /*�û��������룬��������û�������account,�������password*/
    Input(account,password);

    /*��ȡ�ļ�·��������newpath*/
    strcpy(path,account);
    strcat(path,str);
    strcpy(newpath,"text\\");
    strcat(newpath,path);

    /*����û��������ڣ����¼ʧ��*/
    if((fp=fopen(newpath,"rb"))==NULL)
    {
        fclose(fp);


        delay(2000);
    }

    /*����û������ڣ����ж������Ƿ���ȷ*/
    else
    {
        fclose(fp);
        Putbmp64k(300,300,"bmp\\tishi8.bmp");
        /*���������ȷ�����޸ĵ�ǰ��¼״̬*/
        if(!JudgePassword(password,newpath))   //�ж������Ƿ���ȷ
        {

            Putbmp64k(300,300,"bmp\\tishi1.bmp");
            delay(2000);
        }
    }

    /*��ȡ��ʼ�����ͼƬ*/
    Putbmp64k(0,0,"bmp\\yongche.bmp");



}
/**********************************************************
Function��       Input

Description��    �û���Ϣ���뺯��
                �����û����û���������

Input��          INFO *info  ������Ϣ
                char *account
                            �û���
                char *password
                            ����
                MOUSE *mouse
                            ������

Output��     ���û�������û�������account
                �������password

Return��     None

Others��     None
**********************************************************/
void Input(char *account,char *password)
{

    int temp2=0;

    /*��ʱ�洢�û���������*/
    char log[2][20]={'\0','\0'};

    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);


    while(1)
    {
        if(Mouse_above(452,529,540,581))
        {
            a2();
        }
        if(Mouse_press(452,529,540,581))
        {
            //Newxy2();
            Putbmp64k(305,190,"bmp\\kong.bmp");
            Putbmp64k(305,361,"bmp\\kong.bmp");
        }
        if(Mouse_above(570,671,732,712))        //���û�ע��
        {
            a1();
        }
        if(Mouse_press(570,671,732,712))
        {

            Register();

            break;
        }

        if(Mouse_above(305,190,772,288)) //�����û���
        {
            Newxy3();
        }
        if(Mouse_press(305,190,772,288))
        {
            InputInformation(305,772,190,288,0,log);
            strcpy(account,log[0]);
        }
        if(Mouse_above(305,363,772,461)) //��������
        {
            Newxy3();
        }
        if(Mouse_press(305,363,772,461))
        {
            InputInformation(305,772,363,461,1,log);
            strcpy(password,log[1]);
        }
        if(Mouse_above(723,525,815,578))
        {
            a3();
        }
        if(Mouse_press(723,525,815,578))   //���ȷ��
        {
           Putbmp64k(0,0,"bmp\\yongche.bmp");
        }
        // else if(mouse->pos_x>526&&mouse->pos_x<611&&mouse->pos_y>448&&mouse->pos_y<478&&mouse->button==1)   //�����������
        // {
        //     free(buf);
        //     ForgetPassword(info,mouse);
        //     break;
        // }
        if(Mouse_above(126,532,328,578))         //������ҳ��
        {
            a4();
        }
        if(Mouse_press(126,532,328,578))         //�������
        {
            //Newxy2();
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            return 0;
        }
        if(!Mouse_above(305,190,772,288)&&!Mouse_above(305,363,772,461)&&!Mouse_above(570,671,732,712)
            &&!Mouse_above(452,529,540,581)&&!Mouse_above(723,525,815,578)&&!Mouse_above(126,532,328,578))
        {
            Newxy();
            Linex(570,671,732,671,temp2);
            Liney(570,671,570,712,temp2);
            Linex(570,712,732,712,temp2);
            Liney(732,671,732,712,temp2);

            Linex(452,529,540,529,temp2);
            Liney(452,529,452,581,temp2);
            Linex(452,581,540,581,temp2);
            Liney(540,529,540,581,temp2);

            Linex(723,525,815,525,temp2);
            Liney(723,525,723,578,temp2);
            Linex(723,578,815,578,temp2);
            Liney(815,525,815,578,temp2);

            Linex(126,532,328,532,temp2);
            Liney(126,532,126,578,temp2);
            Linex(126,578,328,578,temp2);
            Liney(328,532,328,578,temp2);

        }



    }
}
// /**********************************************************
// Function��       Input1

// Description��    �û���Ϣ���뺯��
//                 ������������ʱ�����û����û���������

// Input��          INFO *info  ������Ϣ
//                 char *account
//                             �û���
//                 char *password
//                             ����
//                 MOUSE *mouse
//                             ������

// Output��     ���û�������û�������account
//                 �������password

// Return��     None

// Others��     None
// **********************************************************/
// void Input1(char *account,char *password,INFO *info,MOUSE *mouse)
// {
//     /*�������*/
//     void *buf;

//     /*��ʱ�洢�û�����Ϣ*/
//     char reg[2][20]={'\0','\0'};

//     buf=malloc(32*32*2);

//     /*��ѭ����������������Ϣ������Ϣ�������ʱ�˳�*/
//     while(1)
//     {
//         /*��ȡ���λ��*/
//         mouse_position(mouse);

//         /*�������*/
//         drawmouse(mouse);

//         /*������λ�������û�����λ�ã�������û�������*/
//         if(mouse->pos_x>507&&mouse->pos_x<632&&mouse->pos_y>349&&mouse->pos_y<368)
//         {
//             mouse_recover(mouse);
//             MouseShape(buf);
//             if(mouse->button==1)
//             {
//                 InputInformation(507,632,349,368,0,reg,mouse);
//                 strcpy(account,reg[0]);
//             }
//             mouse_reset(mouse);

//         }

//         /*������λ�����������λ�ã���������������*/
//         else if(mouse->pos_x>507&&mouse->pos_x<632&&mouse->pos_y>392&&mouse->pos_y<413)
//         {
//             mouse_recover(mouse);
//             MouseShape(buf);
//             if(mouse->button==1)
//             {
//                 InputInformation(507,632,392,413,1,reg,mouse);
//                 strcpy(password,reg[1]);
//                 if(!(strlen(password)>=4&&strlen(password)<=15))
//                 {
//                     readbmp(264,254,"pic\\fail1.bmp");
//                     delay(2000);
//                     ForgetPassword(info,mouse);
//                     break;
//                 }
//             }
//             mouse_reset(mouse);

//         }

//         /*��������ȷ����ť�����˳�*/
//         else if(mouse->pos_x>639&&mouse->pos_x<724&&mouse->pos_y>448&&mouse->pos_y<478&&mouse->button==1)   //���ȷ��
//         {

//             free(buf);
//             break;
//         }

//         /*���������˳���ť�����˳�*/
//         else if(mouse->pos_x>723&&mouse->pos_x<754&&mouse->pos_y>254&&mouse->pos_y<273&&mouse->button==1)   //����˳���ť
//         {

//             free(buf);

//             readbmp(0,0,"pic\\begin.bmp");
//             readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
//             InterFace(info,mouse);
//             break;
//         }



//     }
// }
/**********************************************************
Function��       JudgePassword

Description��    �ж����뺯��
                �����û����������Ƿ���ȷ

Input��          char *password  �û�����
                char *path      �ļ�·��

Output��     None

Return��     ��������ȷ���򷵻�1
                ����������򷵻�0
**********************************************************/
int JudgePassword(char *password,char *path)
{
    /*�ļ�ָ��*/
    FILE *fp;

    /*���ڴ洢�û�������*/
    char userpassword[32];

    /*ѭ������*/
    int i;

    /*ָ��'='��һ�γ��ֵ�λ��*/
    char *p1;

    /*ָ��'=���ڶ��γ��ֵ�λ��*/
    char *p2;

    fp=fopen(path,"rt");
    fread(userpassword,64,1,fp);

    /*��ȡ�û���ԭ����*/
    p1=strchr(userpassword,'=');
    p1++;
    p2=strchr(p1,'=');
    for(i=0;p2-p1>0;p1++,i++)
    {
        userpassword[i]=*p1;
    }
    userpassword[i]='\0';

    fclose(fp);

    /*���������ȷ���򷵻�1*/
    if(strcmp(password,userpassword)==0)
    {
        return 1;
    }

    /*�����������򷵻�0*/
    else
    {
        return 0;
    }

}
// /**********************************************************
// Function��       ForgetPassword

// Description��    �������뺯��
//                 �����û���������ʱ���еĲ���

// Input��          INFO *info      ������Ϣ
//                 MOUSE *mouse    ������

// Output��     None

// Return��     None
// **********************************************************/
// void ForgetPassword(INFO *info,MOUSE *mouse)
// {
//     /*�ļ�ָ��*/
//     FILE *fp;

//     /*�ļ�·��*/
//     char *str=".txt";
//     char path[15]={'\0'} ,newpath[30];
//     char account[15],password[15];

//     readbmp(264,254,"pic\\forget.bmp");
//     mouse_reset(mouse);

//     /*�����û����û���������*/
//     Input1(account,password,info,mouse);

//     /*��ȡ�ļ�·��*/
//     strcpy(path,account);
//     strcat(path,str);
//     strcpy(newpath,"text\\");
//     strcat(newpath,path);

//     /*����û��������ڣ��򷵻�*/
//     if((fp=fopen(newpath,"rb"))==NULL)
//     {

//         readbmp(264,254,"pic\\non.bmp");
//         delay(2000);
//     }

//     /*����û������ڣ�������޸��������*/
//     else
//     {
//         ReviseFile(account,password,newpath);

//         readbmp(264,254,"pic\\revised.bmp");

//         delay(2000);
//     }

//     fclose(fp);

//     readbmp(0,0,"pic\\begin.bmp");
//     readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
//     InterFace(info,mouse);
// }
// /**********************************************************
// Function��       ReviseFile

// Description��    �޸����뺯��

// Input��          char *account       �û���
//                 char *password      ����
//                 char *newpath       �ļ�·��

// Output��     None

// Return��     None
// **********************************************************/
// void ReviseFile(char *account,char *password,char *newpath)//�ú��������޸�����
// {
//     /*ѭ������*/
//     int n=0;

//     /*�ļ�ָ��*/
//     FILE *fp;

//     /*��ʱ�����Ϣ*/
//     char *info;

//     /*���û���Ϣ����info*/
//     strcpy(info,account);
//     strcat(info,"=");
//     strcat(info,password);
//     strcat(info,"=");

//     fp=fopen(newpath,"wt+");

//     /*����Ϣд���ļ�*/
//     while(info[n]!='\0')
//     {
//         fputc(info[n],fp);
//         n++;
//     }
//     fclose(fp);
// }


int a1(void)   //��¼ --���û�ע��
{
    Newxy2();
    Linex(570,671,732,671,60000);
    Liney(570,671,570,712,60000);
    Linex(570,712,732,712,60000);
    Liney(732,671,732,712,60000);
    return 0;
}

int a2(void)   //��¼ --�����
{
    Newxy2();
    Linex(452,529,540,529,60000);
    Liney(452,529,452,581,60000);
    Linex(452,581,540,581,60000);
    Liney(540,529,540,581,60000);
    return 0;
}

int a3(void)  //��¼ --ȷ�ϼ�
{
    Newxy2();
    Linex(723,525,815,525,60000);
    Liney(723,525,723,578,60000);
    Linex(723,578,815,578,60000);
    Liney(815,525,815,578,60000);
    return 0;
}

int a4(void)  //��¼ --�����������
{
    Newxy2();
    Linex(126,532,328,532,60000);
    Liney(126,532,126,578,60000);
    Linex(126,578,328,578,60000);
    Liney(328,532,328,578,60000);
    return 0;
}

int a5(void)   //ע�� --ȷ��
{
    Newxy2();
    Linex(702,582,793,582,60000);
    Liney(702,582,702,632,60000);
    Linex(702,632,793,632,60000);
    Liney(793,582,793,632,60000);
    return 0;
}

int a6(void)  //ע�� --�˳�
{
    Newxy2();
    Linex(189,584,272,584,60000);
    Liney(189,584,189,631,60000);
    Linex(189,631,272,631,60000);
    Liney(272,584,272,631,60000);
    return 0;
}

int a7(void)  //ע�� --���
{
    Newxy2();
    Linex(431,581,524,581,60000);
    Liney(431,581,431,631,60000);
    Linex(431,631,524,631,60000);
    Liney(524,581,524,631,60000);
    return 0;
}