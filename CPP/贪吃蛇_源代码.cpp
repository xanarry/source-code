/*
 *�����õ�pthread.hʵ�ֵ�˫�̡߳����߳�������ʾ�������ߵ��ߣ�
 *����һ���߳���ʱʱ��ؼ��̵����붯̬������������Ҽ���һ��
 *���µ�����������߳��е��߱��ֳ��µķ��򣬱����ʱ�������
 *pthreadͷ�ļ��Ͷ�̬���ӿ⣬�����޷�ͨ�����룬windows������
 *Ҫ��pthreadgc2.dll�ļ�������������pthreadgc2.dll�ļ�,���ҷ�
 *��C:\windows\system32�ļ�����
 */
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <conio.h>
#include <string>

//�����ĸ�����
#define EAST 1
#define SOUTH 2
#define WEST 3
#define NORTH 4

using namespace std;

//̰���߽ṹ��һ��˫������
struct Node
{
	Node *pre;
	int x;
	int y;
	Node *next;
};

//������
class Snack
{
private:
	Node *head;//����ͷ
	Node *tail;//����β(ʵ�����ߵ�ͷ��������β��)
	int direction;//��Ҫ�ߵķ���
	int running_direction;//�����ߵķ���
	bool alive;//�ж��Ƿ�����

public:
	Snack(){};
	bool initialize();//��ʼ��
	void start();//��ʼ��Ϸ
	void generate_food();//����һ��ʳ��
	void dead(int);//��������ת��������
	bool is_itself(int, int);//�ж��Ƿ�ҧ���Լ�
	void setDirection(int input)//������һ������
	{
		direction = input;
	}

	int getRunning_direction()//��ȡ�����ߵķ���
	{
        return running_direction;
	}

	bool getAlive()//�ж�������
	{
	    return alive;
	}
};


//ȫ�ֱ���
void draw_map();//�������

const int X_LEN = 22;//���
const int Y_LEN = 75;//�п�

void show(char a[][Y_LEN]);

char map[X_LEN][Y_LEN];//��¼�����������

int LEVAL = 0;//Ĭ�ϵȼ�

Snack snack;//�����߶���

//�˺������ݸ��̴߳�����ʼ���ں�̨����
void * change_direction(void *args)//ͨ�����̸ı����з���
{
    int input;
    while (1)
    {
        input = (int)getch();
        switch(input)
        {
            case 72:
                if (snack.getRunning_direction() != SOUTH)//��ֹ�򱳺���
                    snack.setDirection(NORTH);//�ı���һ���ķ���
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
    cout << "\t\t* \t       ̰����v2.0(������)              *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t*      ���汾�޸�v1.0��Ļ������˸������        *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t* \t��    �ߣ�xanarry                      *\n";
    cout << "\t\t* \t���ʱ�䣺2014/7/31                    *\n";
    cout << "\t\t* \t��ϵ��ʽ��xanarry@163.com              *\n";
    cout << "\t\t*                                              *\n";
    cout << "\t\t*     ��ʼ�밴 1                               *\n";
    cout << "\t\t*     �˳���ֱ�ӵ����Ͻǵ�'��'��haha!          *\n";
    cout << "\t\t------------------------------------------------\n";
    cout << "\n";
    cout << "\t\t\t�ڴ�����: ";
    int choose;
    int leval;
    cin >> choose;
    if (choose == 1);
    {
        printf("\t\t\t������ȼ�(1-10): ");
        cin >> leval;
        LEVAL = (10 - leval) * 50;//���õȼ�->�����ٶ�
        return 1;
    }
    exit(0);
}

int main()
{
    if (logo())//���ǰ���Ѿ�׼����
    {
        draw_map();//���Ƶ�ͼ
        snack.initialize();//��ʼ����

        //�����ڶ��̻߳�ȡ���̵����룬���߳�������ʾ���ϲ����˶�����
        pthread_t id;//���ý���id
        int ret = pthread_create(&id, NULL, change_direction, NULL);//��������һ���̻߳�ȡ��������
        if (ret = 0)
        {
            cout << "error code is 147" << endl;
            exit(-1);//�̴߳���ʧ��
        }

        snack.start();//��ʼ��Ϸ
    }
	return 0;
}


void draw_map()
{
	for (int i = 0; i < X_LEN; i++)
	{
		for (int j = 0; j < Y_LEN; j++)
		{
		    if (i == 0 || j == 0 || j == Y_LEN - 1 || i == X_LEN - 1)//�߽�
                map[i][j] = '#';
			else
                map[i][j] = ' ';//�ڲ�
		}
	}
}

void show(char a[][Y_LEN])
{
    system("cls");//���»�����Ļ
    string screen = "";
    for (int i = 0; i < X_LEN; i++)//�������ַ�����ת��Ϊstring���󣬷�ֹ������Ļ��˸
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

    //����˫������
	head->next = tail;
	head->pre = NULL;
	tail->pre = head;
	tail->next = NULL;

	int i = 1;
	Node *temp = head;

	while (i < 4)//Ĭ�Ͽ�ʼ�����ڵ�
	{
		Node *_new = new Node;
        //Ĭ�Ͽ�ʼ���ֵ�λ��
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
        map[temp->x][temp->y] = 'o';//������*��ʾ����
        temp = temp->next;
    }

    //����Ĭ�ϲ���
    alive = true;//̰�����ǻ��
    generate_food();//����ʳƷ
    running_direction = EAST;//Ĭ���������߷�����
	direction = EAST;//Ĭ�����߷�����
}


void Snack::start()
{
	Node *temp;
	while (1)
	{
	    Node *_new = new Node;//��λ�õĽڵ�
		switch(direction)
		{
			case EAST:

                running_direction = EAST;//�趨�µķ���

                //�½ڵ�������ǵ�ǰ����һ��λ��
				_new->x = tail->pre->x;//��ȡ����
				if (tail->pre->y < Y_LEN - 2)//����û�е��߽�
                {
                    _new->y = tail->pre->y + 1;//��ǰ��
                    if (is_itself(_new->x, _new->y))//�����ǰ��֮�������Լ�
                        snack.dead(0);//����
                }
                else
                   snack.dead(1);//���߽�����


                //�����һ���ڵ���ʳ��
                if (map[_new->x][_new->y] == '@')//����ҵ�ʳ��
                    snack.generate_food();//�����µ�ʳ��
                else//û���ҵ�ʳ���ɾ�����һ���ڵ㡣�ҵ���ɾ���Ӷ��߱䳤
                {
                     //ɾ��β����*
                    temp = head->next;//β��
                    map[temp->x][temp->y] = ' ';//β���������ڵ��ַ���Ϊ��
                    head = head->next;//β�����ָ��headǰ��һ��λ��
                    delete temp->pre;//ɾ���ڴ��еĽڵ�
                }
                map[_new->x][_new->y] = 'o';//�����½ڵ�

                _new->pre = tail->pre;//ͷ��
				tail->pre->next = _new;//�����½ڵ�
				_new->next = tail;//�����½ڵ�
				tail->pre = _new;//�����½ڵ�

                show(map);//�����

				Sleep(LEVAL);
				break;

            //���µĴ���ʽ���������һ��������дע��
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


bool Snack::is_itself(int x, int y)//�ж��Ƿ�ҧ���Լ�
{
    Node *temp = head;
    while (temp != tail)//�����������нڵ�
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
	while (1)//���ϲ��������
	{
	    //���귶Χ����
		x = rand() % (X_LEN - 2) + 1;
		y = rand() % (Y_LEN - 2) + 1;

		bool is_valid = true;
		Node *temp = head->next;
		while (temp != tail)//�ų��������ϵ�����
		{
			if (x == temp->x && y == temp->y)
			{
				is_valid = false;
				break;
			}
			temp = temp->next;
		}
		if (is_valid)//ֱ�����������㷶ΧҪ�������
			break;
	}

	map[x][y] = '@';//���ʳ��
}

void Snack::dead(int state)
{
    system("cls");
    alive = false;

    if (state == 1)
        cout << "\n\t\tײǽ��������" << endl;
    else
        cout << "\n\t\t̰��Ҳ����ҧ�Լ�����" << endl;

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
    cout << "\n\t\t������γ���" << count << "���ڵ�" << endl;
    system("pause");
}

