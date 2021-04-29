#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define M 300
struct food
{
    int x;
    int y;
    int request;
}food;

struct snake
{
    int x[M];
    int y[M];
    int festival;
    int life;
    int go;
}snake;

int SC=0,key;
void Paint(void);
void Score(void);
void gameplay(void);
void gameover(void);
int main()
{
    Paint();
    Score();
    gameplay();
    gameover();
    return 0;
}
void Paint()
{
    int i,j;
    initgraph(600,700);
    setbkcolor(BLUE);
    bar(100,20,580,680);
}
void Score(void)
{
    setfillcolor(GREEN);
    setcolor(EGERGB(0x0, 0xFF, 0x0));
    setfont(12,0,"宋体");
    bar(0,30,100,100);
    outtextxy(0,40,"西瓜次郎提醒您");
    outtextxy(0,60,"您的分数是:");
    xyprintf(0,80,"%d",SC);
}
void gameplay(void)
{
    int a=0,j,i;
    srand((unsigned)time(NULL));
    food.request=1;
    snake.x[0]=140;
    snake.y[0]=60;
    snake.x[1]=120;
    snake.y[1]=60;
    snake.festival=2;
    snake.go=1;
    snake.life=0;
    while(1){
        while(!kbhit())
        {
            if(food.request==1)
            {
                food.x=rand()%460+120;
                food.y=40+(rand()%640);
                while(food.x%20!=0)
                    food.x++;
                while(food.y%20!=0)
                    food.y++;
                for(i=0;i<snake.festival-1;i++)
                {
                    if(snake.x[i]==food.x&&snake.y[i]==food.y)snake.x[i]+=20;
                }
                food.request=0;
            }
            if(food.request==0)
            {
                setfillcolor(YELLOW);
                bar(food.x,food.y,food.x-20,food.y-20);
            }
            if(a>=1)
            {
                snake.x[299]=snake.x[snake.festival-1];
                snake.y[299]=snake.y[snake.festival-1];
                for(j=snake.festival-1;j>0;j--)
                {
                    setfillcolor(WHITE);
                    snake.x[j]=snake.x[j-1];
                    snake.y[j]=snake.y[j-1];
                    if(snake.go==1)snake.x[j-1]+=20;
                    if(snake.go==3)snake.x[j-1]-=20;
                    if(snake.go==2)snake.y[j-1]+=20;
                    if(snake.go==4)snake.y[j-1]-=20;
                }
            }
            else
            {
                snake.x[299]=120;snake.y[299]=60;
            }

            for(i=3;i<=snake.festival-1;i++)
            {
                if(snake.x[0]==snake.x[i]&&snake.y[0]==snake.y[i])
                {
                    snake.life=1;
                    return;
                }
            }

            setfillcolor(BLACK);
            bar(snake.x[299],snake.y[299],snake.x[299]-20,snake.y[299]-20);
            for(i=0;i<snake.festival;i++)
            {
                setfillcolor(WHITE);
                bar(snake.x[i],snake.y[i],snake.x[i]-20,snake.y[i]-20);
            }
            Sleep(50);
            if(snake.x[0]>580||snake.y[0]>680||snake.x[0]-20<100||snake.y[0]-20<20)
            {
                snake.life=1;
                break;
            }

            if(snake.x[0]==food.x&&snake.y[0]==food.y)
            {
                setfillcolor(WHITE);
                bar(food.x,food.y,food.x-20,food.y-20);
                snake.festival+=1;
                snake.x[snake.festival-1]=snake.x[299];
                snake.y[snake.festival-1]=snake.y[299];
                setfillcolor(WHITE);
                bar(snake.x[snake.festival-1],snake.y[snake.festival-1],snake.x[snake.festival-1]-20,snake.y[snake.festival-1]-20);
                SC+=10;
                Score();
                food.request=1;
            }
            a+=1;
        }

        if(snake.life==1)break;
        key=getch();
        if(key==119&&snake.go!=2)
            snake.go=4;
        else if(key==115&&snake.go!=4)
            snake.go=2;
        else if(key==97&&snake.go!=1)
            snake.go=3;
        else if(key==100&&snake.go!=3)
            snake.go=1;

    }
}
void gameover()
{
    setfillcolor(GREEN);
    bar(220,250,420,450);
    outtextxy(260,350,"YOU DIED!你的分数为:");
    xyprintf(315,380,"%d",SC);
    Sleep(2000);
    getch();
}
