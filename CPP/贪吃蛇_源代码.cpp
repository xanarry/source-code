/*
 *程序用的pthread.h实现的双线程。主线程用于显示不断行走的蛇，
 *另外一个线程则时时监控键盘的输入动态，检查上下左右键，一旦
 *有新的输入就在主线程中的蛇表现出新的方向，编译的时候请包涵
 *pthread头文件和动态链接库，否则无法通过编译，windows运行需
 *要用pthreadgc2.dll文件，所以请下载pthreadgc2.dll文件,并且放
 *到C:\windows\system32文件夹中
 */
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <conio.h>
#include <string>

//定义四个方向
#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

using namespace std;

//贪吃蛇结构是一个双向链表
struct Node
{
	Node *pre;
	int x;
	int y;
	Node *next;
};

//定义蛇
class Snack
{
private:
	Node *head;//链表头
	Node *tail;//链表尾(实际上蛇的头部是链表尾部)
	int direction;//将要走的方向
	int running_direction;//正在走的方向
	bool alive;//判段是否死亡

public:
	Snack(){};
	bool initialize();//初始化
	void start();//开始游戏
	void generate_food();//创建一个食物
	void dead(int);//死亡后跳转都本函数
	bool is_itself(int, int);//判断是否咬到自己
	void setDirection(int input)//设置下一步走向
	{
		direction = input;
	}

	int getRunning_direction()//获取正在走的方向
	{
        return running_direction;
	}

	bool getAlive()//判断是死亡
	{
	    return alive;
	}
};


//全局变量
void draw_map();//绘制面板

const int X_LEN = 22;//横宽
const int Y_LEN = 75;//列宽

void show(char a[][Y_LEN]);

char map[X_LEN][Y_LEN];//记录整个运行面板

int LEVAL = 0;//默认等级

Snack snack;//创建蛇对象

//此函数传递给线程创建，始终在后台运行
void * change_direction(void *args)//通过键盘改变运行方向
{
    int input;
    while (1)
    {
        input = (int)getch();
        switch(input)
        {
            case 72:
                if (snack.getRunning_direction() != SOUTH)//禁止向背后走
                    snack.setDirection(NORTH);//改变下一步的方向
                break;

            case 77:
                if (snack.getRunning_direction() != WEST)
                    snack.setDirection(EAST);
                break;

            case 80:
                if (snack.getRunning_direction() != NORTH)
                    snack.setDirection(SOUTH);
                break;

            case 75:
                if (snack.getRunning_direction() != EAST)
                    snack.setDirection(WEST);
                break;
        }
    }
}

int logo()
{
    cout << "\n\t\t------------------------------------------------\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t* \t       贪吃蛇v2.0(渣渣版)              *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t*      本版本修复v1.0屏幕严重闪烁的问题        *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t* \t作    者：xanarry                      *\n";
    cout << "\t\t* \t完成时间：2014/7/31                    *\n";
    cout << "\t\t* \t联系方式：xanarry@163.com              *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t*     开始请按 1                               *\n";
    cout << "\t\t*     退出请直接点右上角的'叉'。haha!          *\n";
    cout << "\t\t------------------------------------------------\n";
    cout << "\n";
    cout << "\t\t\t在此输入: ";
    int choose;
    int leval;
    cin >> choose;
    if (choose == 1);
    {
        printf("\t\t\t请输入等级(1-10): ");
        cin >> leval;
        LEVAL = (10 - leval) * 50;//设置等级->行走速度
        return 1;
    }
    exit(0);
}

int main()
{
    if (logo())//如果前面已经准备好
    {
        draw_map();//绘制地图
        snack.initialize();//初始化蛇

        //创建第二线程获取键盘的输入，主线程用于显示屏上不断运动的蛇
        pthread_t id;//设置进程id
        int ret = pthread_create(&id, NULL, change_direction, NULL);//创建另外一个线程获取键盘输入
        if (ret = 0)
        {
            cout << "error code is 147" << endl;
            exit(-1);//线程创建失败
        }

        snack.start();//开始游戏
    }
	return 0;
}


void draw_map()
{
	for (int i = 0; i < X_LEN; i++)
	{
		for (int j = 0; j < Y_LEN; j++)
		{
		    if (i == 0 || j == 0 || j == Y_LEN - 1 || i == X_LEN - 1)//边界
                map[i][j] = '#';
			else
                map[i][j] = ' ';//内部
		}
	}
}

void show(char a[][Y_LEN])
{
    system("cls");//重新绘制屏幕
    string screen = "";
    for (int i = 0; i < X_LEN; i++)//将整个字符数组转换为string对象，防止过度屏幕闪烁
    {
        screen += (string(a[i], 0, Y_LEN) + "\n");
    }
    cout << screen;
}

bool Snack::initialize()
{
	head = new Node;
	tail = new Node;

	if (head == NULL || tail == NULL)
	{
		cout << "birth snack failed" << endl;
		exit(-1);
	}

    //创建双向链表
	head->next = tail;
	head->pre = NULL;
	tail->pre = head;
	tail->next = NULL;

	int i = 1;
	Node *temp = head;

	while (i < 4)//默认开始三个节点
	{
		Node *_new = new Node;
        //默认开始出现的位置
		_new->x = X_LEN/2;
		_new->y = i;
		_new->next = NULL;

		while(temp->next != tail)
			temp = temp->next;

        temp->next->pre = _new;
        _new->next = temp->next;
		temp->next = _new;
		_new->pre = temp;

		i++;
	}

	temp = head->next;
	while (temp != tail)
    {
        map[temp->x][temp->y] = 'o';//将蛇用*表示出来
        temp = temp->next;
    }

    //设置默认参数
    alive = true;//贪吃蛇是活的
    generate_food();//绘制食品
    running_direction = EAST;//默认正在行走方向向东
	direction = EAST;//默认行走方向向东
}


void Snack::start()
{
	Node *temp;
	while (1)
	{
	    Node *_new = new Node;//新位置的节点
		switch(direction)
		{
			case EAST:

                running_direction = EAST;//设定新的方向

                //新节点的坐标是当前的下一个位置
				_new->x = tail->pre->x;//获取坐标
				if (tail->pre->y < Y_LEN - 2)//假如没有到边界
                {
                    _new->y = tail->pre->y + 1;//向前走
                    if (is_itself(_new->x, _new->y))//如果向前走之后遇到自己
                        snack.dead(0);//死亡
                }
                else
                   snack.dead(1);//到边界死亡


                //如果下一个节点是食物
                if (map[_new->x][_new->y] == '@')//如果找到食物
                    snack.generate_food();//创建新的食物
                else//没有找到食物就删掉最后一个节点。找到后不删，从而蛇变长
                {
                     //删除尾部的*
                    temp = head->next;//尾部
                    map[temp->x][temp->y] = ' ';//尾部坐标所在的字符置为空
                    head = head->next;//尾部标记指针head前移一个位置
                    delete temp->pre;//删除内存中的节点
                }
                map[_new->x][_new->y] = 'o';//插入新节点

                _new->pre = tail->pre;//头部
				tail->pre->next = _new;//插入新节点
				_new->next = tail;//插入新节点
				tail->pre = _new;//插入新节点

                show(map);//输出蛇

				Sleep(LEVAL);
				break;

            //以下的处理方式都和上面的一样，不再写注释
			case SOUTH:

                running_direction = SOUTH;

                _new->y = tail->pre->y;
                if (tail->pre->x < X_LEN - 2)
                {
                    _new->x = tail->pre->x + 1;
                    if (is_itself(_new->x, _new->y))
                        snack.dead(0);
                }
                else
                    snack.dead(1);

                if (map[_new->x][_new->y] == '@')
                    snack.generate_food();
				else
                {
                    temp = head->next;
                    map[temp->x][temp->y] = ' ';
                    head = head->next;
                    delete temp->pre;
                }

				map[_new->x][_new->y] = 'o';

                _new->pre = tail->pre;
				tail->pre->next = _new;
				_new->next = tail;
				tail->pre = _new;

				show(map);

				Sleep(LEVAL);
				break;

			case WEST:

                running_direction = WEST;

				_new->x = tail->pre->x;
				if (tail->pre->y > 1)
                {
                    _new->y = tail->pre->y - 1;
                    if (is_itself(_new->x, _new->y))
                        snack.dead(0);
                }
                else
                    snack.dead(1);


                if (map[_new->x][_new->y] == '@')
                    snack.generate_food();
				else
                {
                    temp = head->next;
                    map[temp->x][temp->y] = ' ';
                    head = head->next;
                    delete temp->pre;
                }

				map[_new->x][_new->y] = 'o';

                _new->pre = tail->pre;
				tail->pre->next = _new;
				_new->next = tail;
				tail->pre = _new;

				show(map);

				Sleep(LEVAL);
				break;

			case NORTH:

                running_direction = NORTH;

                _new->y = tail->pre->y;
                if (tail->pre->x > 1)
                {
                    _new->x = tail->pre->x - 1;
                    if (is_itself(_new->x, _new->y))
                        snack.dead(0);
                }
                else
                    snack.dead(1);


                if (map[_new->x][_new->y] == '@')
                    snack.generate_food();
				else
                {
                    temp = head->next;
                    map[temp->x][temp->y] = ' ';
                    head = head->next;
                    delete temp->pre;
                }

				map[_new->x][_new->y] = 'o';

                _new->pre = tail->pre;
				tail->pre->next = _new;
				_new->next = tail;
				tail->pre = _new;

				show(map);

				Sleep(LEVAL);
				break;
		}
	}
}


bool Snack::is_itself(int x, int y)//判断是否咬到自己
{
    Node *temp = head;
    while (temp != tail)//遍历自身所有节点
    {
        if (temp->x == x && temp ->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

void Snack::generate_food()
{

	srand(time(NULL));
	int x, y;
	while (1)//不断产生随机数
	{
	    //坐标范围限制
		x = rand() % (X_LEN - 2) + 1;
		y = rand() % (Y_LEN - 2) + 1;

		bool is_valid = true;
		Node *temp = head->next;
		while (temp != tail)//排除在蛇身上的坐标
		{
			if (x == temp->x && y == temp->y)
			{
				is_valid = false;
				break;
			}
			temp = temp->next;
		}
		if (is_valid)//直到产生了满足范围要求的坐标
			break;
	}

	map[x][y] = '@';//标记食物
}

void Snack::dead(int state)
{
    system("cls");
    alive = false;

    if (state == 1)
        cout << "\n\t\t撞墙身亡！！" << endl;
    else
        cout << "\n\t\t贪吃也不能咬自己！！" << endl;

    printf("\n   -------------------------------------------------------------------\n");
    printf("   *   #########     #########          #            #########       *\n");
    printf("   *   #        #    #                 # #           #        #      *\n");
    printf("   *   #         #   #                #   #          #         #     *\n");
    printf("   *   #         #   #########       #     #         #         #     *\n");
    printf("   *   #         #   #              # ##### #        #         #     *\n");
    printf("   *   #         #   #             #         #       #         #     *\n");
    printf("   *   #        #    #            #           #      #        #      *\n");
    printf("   *   #########     #########   #             #     #########       *\n");
    printf("   -------------------------------------------------------------------\n");

    int count = -3;
    Node *temp = head->next;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    cout << "\n\t\t本蛇这次吃了" << count << "个节点" << endl;
    system("pause");
}

