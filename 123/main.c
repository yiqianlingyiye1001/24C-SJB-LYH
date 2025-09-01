#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main_menu();                          //���˵�
void sub_menu();                          //����ѡ��˵�
void AtoB(char,char,int );                //n���˻������˶�ս
int one_round(char roleA,char roleB);     //һ���˻������˶�ս
char make_choice(char );                    //��������J,S,B
void show_choice(char,char);                //��ʾ�˻����ѡ��
int pk(char,char);                         //˭��ʤ
char regular(char,char);                   //����ʤ���ߵ�ѡ��
void show_score(int,int,int );              //����÷�
void show_winner(int,int,int);             //���ʤ����
int main()
{
    int mode,number;
    main_menu();
    srand(time(NULL));                //��ʼ���������
    scanf("%d",&mode);
    while(mode)
    {
        sub_menu();
        scanf("%d",&number);
        switch(mode)
        {
        case 1:
            AtoB('P','M',number);
            break;
        case 2:
            AtoB('A','B',number);
            break;
        }
        main_menu();
            scanf("%d",&mode);
    }
    return 0;
}
void main_menu()
{
    //��ʾ���˵�
    printf("*******************\n");
    printf("*    1----�˻�    *\n");
    printf("*    2----���    *\n");
    printf("*    0----�˳�    *\n");
    printf("*******************\n");
}
void sub_menu()
{
    //��ʾ�Ӳ˵�
    printf("*******************\n");
    printf("*��ѡ�����       *\n");
    printf("*    3----����    *\n");
    printf("*    5----���    *\n");
    printf("*******************\n");
}
int one_round(char roleA,char roleB)
{
    //����roleA��roleB��սһ�ֵĽ��
    int winner;
    char choiceA,choiceB;
    choiceA=make_choice(roleA);
    choiceB=make_choice(roleB);
    show_choice(roleA,choiceA);
    show_choice(roleB,choiceB);
    winner=pk(choiceA,choiceB);
    return winner;
}
void AtoB(char roleA,char roleB,int n)
{
    //roleA��roleB��սn��
    int i;
    int winner,scoreA,scoreB,mode;
    scoreA=scoreB=0;
    printf("��ѡ��J����SʯͷB��\n");
    for(i=1; i<=n; i++)
    {
        printf("��%d�֣�\n",i);
        winner=one_round(roleA,roleB);
        if(winner==1||winner==0)
            scoreA++;
        if(winner==2||winner==0)
            scoreB++;
    }
    mode=(roleA=='P')?1:2;
    show_score(mode,scoreA,scoreB);
    show_winner(mode,scoreA,scoreB);
}
char make_choice(char role)
{
    //����roleѡ��Ľ�� ��������ʯͷ������
    char choice;
    if(role=='M')
        switch(rand()%3+1)
        {
        case 1:
            choice='J';
            break;
        case 2:
            choice='S';
            break;
        case 3:
            choice='B';
        }
    else
        do
        {
            if(role='p')
                printf("��������ѡ��");
            else
                printf("���ɫ%c����ѡ��");
                choice=getchar();
            if(choice=='\n')
                choice=getchar();
            if(choice!='J'&&choice!='S'&&choice!='B')
                printf("������J��S��B��ѡ��\n");
        }
        while(choice!='J'&&choice!='S'&&choice!='B');
    return choice;
}
void show_choice(char ch,char choice)
{
    //�����ɫch���˻������ѡ�񣨼�����ʯͷ������
    switch(ch)
    {
    case'P':
        printf("����ѡ���ǣ�");
        break;
    case'M':
        printf("����ѡ���ǣ�");
        break;
    default:
        printf("��ɫ%c��ѡ���ǣ�",ch);
    }
    switch(choice)
    {
    case 'J':
        printf("����\n");
        break;
    case 'S':
        printf("ʯͷ\n");
        break;
    case 'B':
        printf("��\n");
    }
}
int pk(char ch1,char ch2)
{
    //����˭��ʤ��ƽ�֣�ch1��ch2��ʾ����ʯͷ��
    char winner;
    winner=regular(ch1,ch2);
    if(ch1==winner)
        return 1;
    else if(ch2==winner)
        return 2;
    else
        return 0;
}
char regular(char ch1,char ch2)
{
    //����ʤ���ߵ��ַ���ʾ��ch1��ch2��ʾ������ʯͷ����
    if(ch1=='J'&&ch2=='S'||ch1=='S'&&ch2=='J')
        return 'S';
    else if(ch1=='J'&&ch2=='B'||ch1=='B'&&ch2=='J')
        return 'J';
    else if(ch1=='S'&&ch2=='B'||ch1=='B'&&ch2=='S')
        return 'B';
    else
        return '0';
}
void show_score(int mode,int score1,int score2)
{
    //�����ɫmode�˻������˶�ս�ĵ÷�
    if(mode==1)                  //�˻���ս
        printf("���ĵ÷֣�");
    else
        printf("��ɫA�ĵ÷֣�");  //renren���˶�ս
    printf("%d\n",score1);
    if(mode==1)
        printf("���Եĵ÷֣�");
    else
        printf("��ɫB�ĵ÷֣�");
    printf("%d\n",score2);
}
void show_winner(int mode,int score1,int score2)
{
    //�����ɫ��mode��ʾ�˻������˶�ս������Ӯ���
    if(mode=1)
    {
        if(score1>score2)
            printf("��ϲ��Ӯ�ˣ�\n");
        else if(score1<score2)
            printf("������˵����ϣ�\n");
        else
            printf("ƽ��\n");
    }
    if(mode=2)
    {
        if(score1>score2)
            printf("���Aʤ����\n");
        else if(score1<score2)
            printf("���Bʤ����\n");
        else
            printf("ƽ��\n");
    }
}























