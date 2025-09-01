#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main_menu();                          //主菜单
void sub_menu();                          //局数选择菜单
void AtoB(char,char,int );                //n局人机或人人对战
int one_round(char roleA,char roleB);     //一局人机或人人对战
char make_choice(char );                    //输入或产生J,S,B
void show_choice(char,char);                //显示人或机的选择
int pk(char,char);                         //谁获胜
char regular(char,char);                   //返回胜利者的选择
void show_score(int,int,int );              //输出得分
void show_winner(int,int,int);             //输出胜利者
int main()
{
    int mode,number;
    main_menu();
    srand(time(NULL));                //初始化随机种子
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
    //显示主菜单
    printf("*******************\n");
    printf("*    1----人机    *\n");
    printf("*    2----玩家    *\n");
    printf("*    0----退出    *\n");
    printf("*******************\n");
}
void sub_menu()
{
    //显示子菜单
    printf("*******************\n");
    printf("*请选择局数       *\n");
    printf("*    3----三局    *\n");
    printf("*    5----五局    *\n");
    printf("*******************\n");
}
int one_round(char roleA,char roleB)
{
    //计算roleA和roleB对战一局的结果
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
    //roleA和roleB对战n局
    int i;
    int winner,scoreA,scoreB,mode;
    scoreA=scoreB=0;
    printf("请选择：J剪刀S石头B布\n");
    for(i=1; i<=n; i++)
    {
        printf("第%d局：\n",i);
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
    //返回role选择的结果 （剪刀，石头，布）
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
                printf("请您做出选择：");
            else
                printf("请角色%c做出选择：");
                choice=getchar();
            if(choice=='\n')
                choice=getchar();
            if(choice!='J'&&choice!='S'&&choice!='B')
                printf("你必须从J、S、B中选择！\n");
        }
        while(choice!='J'&&choice!='S'&&choice!='B');
    return choice;
}
void show_choice(char ch,char choice)
{
    //输出角色ch（人或机）的选择（剪刀’石头‘不）
    switch(ch)
    {
    case'P':
        printf("您的选择是：");
        break;
    case'M':
        printf("电脑选择是：");
        break;
    default:
        printf("角色%c的选择是：",ch);
    }
    switch(choice)
    {
    case 'J':
        printf("剪刀\n");
        break;
    case 'S':
        printf("石头\n");
        break;
    case 'B':
        printf("布\n");
    }
}
int pk(char ch1,char ch2)
{
    //返回谁获胜或平局，ch1和ch2表示剪刀石头布
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
    //返回胜利者的字符表示，ch1和ch2表示剪刀，石头，布
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
    //输出角色mode人机或人人对战的得分
    if(mode==1)                  //人机对战
        printf("您的得分：");
    else
        printf("角色A的得分：");  //renren人人对战
    printf("%d\n",score1);
    if(mode==1)
        printf("电脑的得分：");
    else
        printf("角色B的得分：");
    printf("%d\n",score2);
}
void show_winner(int mode,int score1,int score2)
{
    //输出角色（mode表示人机或人人对战）的输赢结果
    if(mode=1)
    {
        if(score1>score2)
            printf("恭喜您赢了！\n");
        else if(score1<score2)
            printf("您输给了电脑呦！\n");
        else
            printf("平手\n");
    }
    if(mode=2)
    {
        if(score1>score2)
            printf("玩家A胜利！\n");
        else if(score1<score2)
            printf("玩家B胜利！\n");
        else
            printf("平手\n");
    }
}























