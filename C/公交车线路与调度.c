/*
���ӣ�motorCade
	��Ϣ����ţ� ���������� ������·
	���ܣ���ӳ�����Ϣ�� ���ӵ��ȣ���һ����·��n����������һ����·���� ������Ϣ
��·��busLine
	��Ϣ����ţ��۸� ���г���
	���ܣ�һ����·�����кü�����������

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MOTORCADE
{
	int num;
	int busCount;
	int runLine;
};

struct BUSLINE
{
	int num;
	int price;
	int runningBus[100];//��¼ÿ����·���еĹ�������
};

void menu();

void motorcade_manage();
void runline_manage();

void add_motorcade();
void scheduling_motorcade();
void list_motorcade();
void del_motorcade();

void add_runline();
void scheduling_runline();
void list_runline();
void del_runline();

int load(int);
void save();

struct MOTORCADE motor_cade[100];
int motor_cade_count = 0;

struct BUSLINE bus_line[100];
int bus_line_count = 0;

const int chedui = 0;//
const int xianlu = 1;//��save��load���ݲ�����ѡ����ػ򱣴湫����·���ǳ�����Ϣ

int main(int argc, char const *argv[])
{
	load(chedui);
	load(xianlu);

	menu();
	return 0;
}
////////////���õĴ��루��ʼ��/////////
void menu()
{
	printf("\t\t1��������\n");
	printf("\t\t2��������·\n");
	int choice;
	printf("\t\tyour choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			motorcade_manage();
			break;
		case 2:
			runline_manage();
			break;
		default:
			puts("input error");
			return;
	}
}

void motorcade_manage()
{	
	printf("\t\t1����ӳ���\n");
	printf("\t\t2�����ȳ���\n");
	printf("\t\t3����ʾ����\n");
	printf("\t\t4��ɾ������\n");
	printf("\t\tinput your choice:");
	int choice;
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			add_motorcade();
			break;
		case 2:
			scheduling_motorcade();
			break;
		case 3:
			list_motorcade();
			break;
		case 4:
			del_motorcade();
			break;
		default:
			puts("input error");
			menu();
	}
}

void runline_manage()
{
	printf("\t\t1�������·\n");
	printf("\t\t2��������·\n");
	printf("\t\t3����ʾ��·\n");
	printf("\t\t4��ɾ����·\n");
	printf("\t\tinput your choice:");
	int choice;
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			add_runline();
			break;
		case 2:
			scheduling_runline();
			break;
		case 3:
			list_runline();
			break;
		case 4:
			del_runline();
			break;
		default:
			puts("input error");
			menu();
	}
}
////////���õĴ��루������///////////////

void add_motorcade()
{
	struct MOTORCADE tmp;
	printf("���복�ӱ��:");
	scanf("%d", &tmp.num);

	printf("���복������:");
	scanf("%d", &tmp.busCount);

	int i = 0;
	int flag = 0;
	printf("����������·:");
	while (1)
	{
		scanf("%d", &tmp.runLine);
		for (i = 0; i < bus_line_count; i++)//�ж�Ҫ���еĹ�����·�Ƿ���
		{
			if (tmp.runLine == bus_line[i].num)//���翪����
			{
				int len = 0; 
				while (bus_line[i].runningBus[len])
				{
					len++;//��ȡ�����������еĹ�����������
				}
			//	printf("%d\n", len);
				bus_line[i].runningBus[len + 1] = 0;//��0���ѭ�����յ㣬��Ȼ�޷���ȡ����
				bus_line[i].runningBus[len] = tmp.num;//�ټ�һ�����ӵ�����·
				flag = 1;
				break;
			}
		}
		if (flag == 1)//����ɹ����˳�ѭ��
			break;
		else
			printf("��������");//������ʾ
	}

	motor_cade[motor_cade_count] = tmp;
	motor_cade_count++;

	save(chedui);
	save(xianlu);
	menu();
}	

void scheduling_motorcade()
{
	printf("����һ����·��ʼ���ȣ�");
	int from;
	scanf("%d", &from);

	int get_line_from_index = -1;//
	int get_bus_index = -1;//
	int get_line_to_index = -1;//��Ĭ��Ϊ������ͬʱ����Ǻͻ�ȡ�±������

	int i = 0;
	for (i = 0; i < bus_line_count; i++)//�ж��������·�Ƿ�Ϸ�
	{
		if (from == bus_line[i].num)
		{
			get_line_from_index = i;
			break;
		}
	}
	if (i == bus_line_count)
	{
		puts("û���ҵ����������·");
		menu();
	}

	int len = 0;
	if (get_line_from_index != -1)//����Ϸ�������ִ��
	{
		while (bus_line[get_line_from_index].runningBus[len] != 0)
		{
			len++;
		}
		printf("���ö��ٳ���(����·���Ե���%d��)��", len);
		int count;
		scanf("%d", &count);
		if (count > 0 && count <= len)
		{
			printf("������Ŀ����·��");
			int to;
			scanf("%d", &to);

			for (i = 0; i < bus_line_count; i++)//�ж�Ŀ����·
			{
				if (to == bus_line[i].num)
				{
					get_line_to_index = i;
					break;
				}
			}

			if (i == bus_line_count)
			{
				puts("û���ҵ��������Ŀ����·");
				menu();
			}

			//��ʼ����
			if (get_line_to_index != -1)//����������붼��ȷ��
			{
				int len_to = 0;
				while (bus_line[get_line_to_index].runningBus[len_to] != 0)
				{
					len_to++;//��ȡ�����������еĹ�����������
				}

				for (i = 0; i < count; i++)
				{
							//Ŀ����·        //���й�������β��      //ԭ��·                   //���й������
					bus_line[get_line_to_index].runningBus[len_to + i] = bus_line[get_line_from_index].runningBus[len - 1 - i];
					//����д�빫�����ӵ�������·��Ϣ
					
					int j;
					for (j = 0; j < motor_cade_count; j++)//�ڹ��������б������б�ţ����ұ��ƶ��Ĺ�������
					{
						if (motor_cade[j].runLine == bus_line[get_line_from_index].num)//�������ӵ�������·�Ǳ��޸ĵ���·
						{
							motor_cade[j].runLine = bus_line[get_line_to_index].num;//���ɵ���·��Ϊ�µ���·
						}
					}
				}
				//����������ȥcount
				bus_line[get_line_from_index].runningBus[len - count] = 0;//ɾ��ԭ��·��count����
				bus_line[get_line_to_index].runningBus[len_to + count] = 0;//Ŀ����·��������count

				puts("���ȳɹ�");
				save(chedui);
				save(xianlu);
				menu();
			}
		}
		else
		{
			puts("��������������ڷ�Χ��");
			menu();
		}
	}
}

void list_motorcade()
{
	printf("\tnum\tbusCount\trunLine\n");
	puts("----------------------------------------------");
	int i;
	for (i = 0; i < motor_cade_count; i++)
	{
		if (motor_cade[i].runLine != -1)
			printf("\t%d\t%d\t\t%d\n", motor_cade[i].num, motor_cade[i].busCount, motor_cade[i].runLine);
		else
			printf("\t%d\t%d\t\t%s\n", motor_cade[i].num, motor_cade[i].busCount, "δ����");
	}
	puts("----------------------------------------------");
	menu();
}

void del_motorcade()
{
	printf("input motorcade num:");
	int tmp;
	scanf("%d", &tmp);
	int i, flag;
	for (i = 0; i < motor_cade_count; i++)//��������
	{
		if (motor_cade[i].num == tmp)//����ҵ�Ҫɾ���ĳ��ӱ��
		{
			for (flag = i; flag < motor_cade_count; flag++)//ɾ�����ӹ�������·��Ϣ
			{
				int bl;
				int rb;
				int len = 0;
				for (bl = 0; bl < bus_line_count; bl++)//����������·�����Ҹó���
				{
					while (bus_line[bl].runningBus[len] != 0)
					{
						len++;//��ȡ��ǰ��·�ĳ�������
					}

					for (rb = 0; bus_line[bl].runningBus[rb] != 0; rb++)//������ǰ���ӵ����г���
					{
						if (tmp == bus_line[bl].runningBus[rb])//���ɾ��������һ��·����һ����������·�Ĺ�������������1
						{
							int t;
							for (t = rb; t < len; t++)//ǰ��Ԫ�ظ���ɾ����Ԫ��
							{
								bus_line[bl].runningBus[t] = bus_line[bl].runningBus[t + 1];
							}
							bus_line[bl].runningBus[len - 1] = 0;//������ֹ���ǰ��һλ
						}
					}
				}
				motor_cade[flag] = motor_cade[flag + 1];//ɾ������
			}
			motor_cade_count--;
		}
	}
	save(chedui);
	save(xianlu);
	puts("ɾ���ɹ�");
	menu();
}

void add_runline()
{
	struct BUSLINE tmp;
	printf("�����ڴ����ڼ�·����:");
	scanf("%d", &tmp.num);

	printf("���ļ۸���:");
	scanf("%d", &tmp.price);

	tmp.runningBus[0] = 0;
	bus_line[bus_line_count] = tmp;
	bus_line_count++;
	save(xianlu);
	menu();
}

void scheduling_runline()
{
	puts("Ŀǰ���ṩ��·����");
	printf("������Ҫ���۵���·��");
	int line;
	scanf("%d", &line);
	int i;
	for (i = 0; i < bus_line_count; i++)
	{
		if (bus_line[i].num == line)//������·�Ƿ�Ϸ�
		{
			printf("\t��·���\tԭ��\n");
			printf("\t%d\t\t%d\n", bus_line[i].num, bus_line[i].price);
			puts("--------------------------------------------------");
			printf("�����ǲ��ҵ�Ҫ���۵���·���������µļ۸�");
			int new_price;
			scanf("%d", &new_price);
			bus_line[i].price = new_price;
			save(xianlu);
			puts("���۳ɹ�");
			menu();
		}
	}
	if (i == bus_line_count)
	{
		puts("û���ҵ����������·���");
		menu();
	}
}

void list_runline()
{
	int i;
	int len = 0;
	for (i = 0; i < bus_line_count; i++)
	{
		printf("\t���\t����\t�����еĹ�������\n");
		puts("----------------------------------------------");
		printf("\t%d\t%d\t\t%s\n", bus_line[i].num, bus_line[i].price, "ϸ��");
		for (len = 0; bus_line[i].runningBus[len] != 0; len++)
		{
			printf("\t\t\t��������: %d\n", bus_line[i].runningBus[len]);
		}
		printf("\t\t\tһ���� %d ��������\n", len);
		puts("----------------------------------------------\n");
	}
	menu();
}

void del_runline()
{
	printf("����Ҫɾ������·:");
	int tmp;
	scanf("%d", &tmp);
	int i, flag;
	for (i = 0; i < bus_line_count; i++)
	{
		if (bus_line[i].num == tmp)
		{
			int t;
			//������������·�����еĹ�������
			for (t = 0; t < motor_cade_count; t++)
			{
				if (motor_cade[t].runLine == tmp)
					motor_cade[t].runLine = -1;
			}

			//ɾ������·
			for (flag = i; flag < bus_line_count; flag++)
			{
				bus_line[flag] = bus_line[flag + 1];
			}
			bus_line_count--;
		}
	}
	save(chedui);
	save(xianlu);
	menu();
}

void save(int flag)	
{
	FILE *fp;
	if (flag == 0)
	{
		fp = fopen("motorcade.dat", "wb");
		if (fp == NULL)
			return;

		int i = 0;
		while (i < motor_cade_count)
		{
			fwrite(&motor_cade[i], sizeof(struct MOTORCADE), 1, fp);
			i++;
		}
		fclose(fp);
	}
	else
	{
		fp = fopen("runLine.dat", "wb");
		if (fp == NULL)
		return;

		int j = 0;
		while (j < bus_line_count)
		{
			fwrite(&bus_line[j], sizeof(struct BUSLINE), 1, fp);
			j++;
		}
		fclose(fp);
	}	
}

int load(int flag)
{
	FILE *fp;
	if (flag == 0)
	{
		fp = fopen("motorcade.dat", "rb");
		if (fp == NULL)
			return;
		int i = 0;
		while (!feof(fp))
		{
			fread(&motor_cade[i], sizeof(struct MOTORCADE), 1, fp);
			i++;
		}
		motor_cade_count = i - 1;
		fclose(fp);
	}
	else
	{
		fp = fopen("runLine.dat", "rb");
		if (fp == NULL)
		return;

		int j = 0;
		while (!feof(fp))
		{
			fread(&bus_line[j], sizeof(struct BUSLINE), 1, fp);
			j++;
		}
		bus_line_count = j - 1;
		fclose(fp);
	}	
}