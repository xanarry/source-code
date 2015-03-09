/*
车队：motorCade
	信息：编号， 车的数量， 运行线路
	功能：添加车队信息， 车队调度（把一条线路的n辆车调到另一条线路）， 车队信息
线路：busLine
	信息：编号，价格， 运行车队
	功能：一条线路可以有好几个车队在跑

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
	int runningBus[100];//记录每条线路所有的公交车队
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
const int xianlu = 1;//给save和load传递参数，选择加载或保存公交线路还是车队信息

int main(int argc, char const *argv[])
{
	load(chedui);
	load(xianlu);

	menu();
	return 0;
}
////////////无用的代码（开始）/////////
void menu()
{
	printf("\t\t1：管理车队\n");
	printf("\t\t2：管理线路\n");
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
	printf("\t\t1：添加车队\n");
	printf("\t\t2：调度车队\n");
	printf("\t\t3：显示车队\n");
	printf("\t\t4：删除车队\n");
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
	printf("\t\t1：添加线路\n");
	printf("\t\t2：调整线路\n");
	printf("\t\t3：显示线路\n");
	printf("\t\t4：删除线路\n");
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
////////无用的代码（结束）///////////////

void add_motorcade()
{
	struct MOTORCADE tmp;
	printf("输入车队编号:");
	scanf("%d", &tmp.num);

	printf("输入车队数量:");
	scanf("%d", &tmp.busCount);

	int i = 0;
	int flag = 0;
	printf("输入运行线路:");
	while (1)
	{
		scanf("%d", &tmp.runLine);
		for (i = 0; i < bus_line_count; i++)//判断要运行的公交线路是否开设
		{
			if (tmp.runLine == bus_line[i].num)//假如开设了
			{
				int len = 0; 
				while (bus_line[i].runningBus[len])
				{
					len++;//获取先在正在运行的公交车队数量
				}
			//	printf("%d\n", len);
				bus_line[i].runningBus[len + 1] = 0;//用0标记循环的终点，不然无法获取长度
				bus_line[i].runningBus[len] = tmp.num;//再加一个车队到该线路
				flag = 1;
				break;
			}
		}
		if (flag == 1)//输入成功后退出循环
			break;
		else
			printf("输入有误");//错误提示
	}

	motor_cade[motor_cade_count] = tmp;
	motor_cade_count++;

	save(chedui);
	save(xianlu);
	menu();
}	

void scheduling_motorcade()
{
	printf("从哪一条线路开始调度：");
	int from;
	scanf("%d", &from);

	int get_line_from_index = -1;//
	int get_bus_index = -1;//
	int get_line_to_index = -1;//让默认为负数，同时做标记和获取下标的作用

	int i = 0;
	for (i = 0; i < bus_line_count; i++)//判断输入的线路是否合法
	{
		if (from == bus_line[i].num)
		{
			get_line_from_index = i;
			break;
		}
	}
	if (i == bus_line_count)
	{
		puts("没有找到您输入的线路");
		menu();
	}

	int len = 0;
	if (get_line_from_index != -1)//如果合法，继续执行
	{
		while (bus_line[get_line_from_index].runningBus[len] != 0)
		{
			len++;
		}
		printf("调用多少车队(本线路可以调用%d个)：", len);
		int count;
		scanf("%d", &count);
		if (count > 0 && count <= len)
		{
			printf("请输入目标线路：");
			int to;
			scanf("%d", &to);

			for (i = 0; i < bus_line_count; i++)//判断目标线路
			{
				if (to == bus_line[i].num)
				{
					get_line_to_index = i;
					break;
				}
			}

			if (i == bus_line_count)
			{
				puts("没有找到您输入的目标线路");
				menu();
			}

			//开始调度
			if (get_line_to_index != -1)//如果以上输入都正确，
			{
				int len_to = 0;
				while (bus_line[get_line_to_index].runningBus[len_to] != 0)
				{
					len_to++;//获取先在正在运行的公交车队数量
				}

				for (i = 0; i < count; i++)
				{
							//目标线路        //运行公交数组尾部      //原线路                   //运行公交起点
					bus_line[get_line_to_index].runningBus[len_to + i] = bus_line[get_line_from_index].runningBus[len - 1 - i];
					//重新写入公交车队的运行线路信息
					
					int j;
					for (j = 0; j < motor_cade_count; j++)//在公交车队中遍历所有编号，查找被移动的公交车队
					{
						if (motor_cade[j].runLine == bus_line[get_line_from_index].num)//公交车队的运行线路是被修改的线路
						{
							motor_cade[j].runLine = bus_line[get_line_to_index].num;//将旧的线路改为新的线路
						}
					}
				}
				//公交数量减去count
				bus_line[get_line_from_index].runningBus[len - count] = 0;//删除原线路的count公交
				bus_line[get_line_to_index].runningBus[len_to + count] = 0;//目标线路数量增加count

				puts("调度成功");
				save(chedui);
				save(xianlu);
				menu();
			}
		}
		else
		{
			puts("您输入的数量不在范围内");
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
			printf("\t%d\t%d\t\t%s\n", motor_cade[i].num, motor_cade[i].busCount, "未运行");
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
	for (i = 0; i < motor_cade_count; i++)//遍历车队
	{
		if (motor_cade[i].num == tmp)//如果找到要删除的车队编号
		{
			for (flag = i; flag < motor_cade_count; flag++)//删除车队关联的线路信息
			{
				int bl;
				int rb;
				int len = 0;
				for (bl = 0; bl < bus_line_count; bl++)//遍历公交线路，查找该车队
				{
					while (bus_line[bl].runningBus[len] != 0)
					{
						len++;//获取当前线路的车队数量
					}

					for (rb = 0; bus_line[bl].runningBus[rb] != 0; rb++)//遍历当前车队的所有车队
					{
						if (tmp == bus_line[bl].runningBus[rb])//如果删除的是这一线路的这一公交，该线路的公交运行数量减1
						{
							int t;
							for (t = rb; t < len; t++)//前移元素覆盖删除的元素
							{
								bus_line[bl].runningBus[t] = bus_line[bl].runningBus[t + 1];
							}
							bus_line[bl].runningBus[len - 1] = 0;//数组终止标记前移一位
						}
					}
				}
				motor_cade[flag] = motor_cade[flag + 1];//删除车队
			}
			motor_cade_count--;
		}
	}
	save(chedui);
	save(xianlu);
	puts("删除成功");
	menu();
}

void add_runline()
{
	struct BUSLINE tmp;
	printf("这是在创建第几路公交:");
	scanf("%d", &tmp.num);

	printf("他的价格是:");
	scanf("%d", &tmp.price);

	tmp.runningBus[0] = 0;
	bus_line[bus_line_count] = tmp;
	bus_line_count++;
	save(xianlu);
	menu();
}

void scheduling_runline()
{
	puts("目前仅提供线路调价");
	printf("请输入要调价的线路：");
	int line;
	scanf("%d", &line);
	int i;
	for (i = 0; i < bus_line_count; i++)
	{
		if (bus_line[i].num == line)//查找线路是否合法
		{
			printf("\t线路编号\t原价\n");
			printf("\t%d\t\t%d\n", bus_line[i].num, bus_line[i].price);
			puts("--------------------------------------------------");
			printf("以上是查找的要调价的线路，请输入新的价格：");
			int new_price;
			scanf("%d", &new_price);
			bus_line[i].price = new_price;
			save(xianlu);
			puts("调价成功");
			menu();
		}
	}
	if (i == bus_line_count)
	{
		puts("没有找到您输入的线路编号");
		menu();
	}
}

void list_runline()
{
	int i;
	int len = 0;
	for (i = 0; i < bus_line_count; i++)
	{
		printf("\t编号\t单价\t运行中的公交车队\n");
		puts("----------------------------------------------");
		printf("\t%d\t%d\t\t%s\n", bus_line[i].num, bus_line[i].price, "细节");
		for (len = 0; bus_line[i].runningBus[len] != 0; len++)
		{
			printf("\t\t\t公交车队: %d\n", bus_line[i].runningBus[len]);
		}
		printf("\t\t\t一共有 %d 公交车队\n", len);
		puts("----------------------------------------------\n");
	}
	menu();
}

void del_runline()
{
	printf("输入要删除的线路:");
	int tmp;
	scanf("%d", &tmp);
	int i, flag;
	for (i = 0; i < bus_line_count; i++)
	{
		if (bus_line[i].num == tmp)
		{
			int t;
			//处理在这条线路上运行的公交车队
			for (t = 0; t < motor_cade_count; t++)
			{
				if (motor_cade[t].runLine == tmp)
					motor_cade[t].runLine = -1;
			}

			//删除该线路
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