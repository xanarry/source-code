#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct STUDENT
{
	string name;
	int score;
	int operator < (const STUDENT a) const
	{
		return score < a.score;
	}

	STUDENT(string n, int s)
	{
		name = n;
		score = s;
	}
};

struct BOOK
{
	int pages;
	int price;
	BOOK(int pa, int pr)
	{
		pages = pa;
		price = pr;
	}
};


struct cmp//使最小元素优先
{
	bool operator() (const int a, const int b) const
	{
		return a < b;//改为大于符号就是最大元素优先
	}
};

struct cmpbook
{
	bool operator() (const BOOK a, const BOOK b)
	{
		return a.price < b.price;
	}
};


int main(int argc, char const *argv[])
{
	cout << "basic queue" << endl;
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << "---------------------" << endl;

	cout << "priority_queue with default comparitor" << endl;
	priority_queue<int> pq;
	pq.push(1);
	pq.push(22);
	pq.push(38);
	pq.push(4);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	cout << "---------------------" << endl;

	cout << "priority_queue with self defined comparitor" << endl;
	priority_queue<int, vector<int>, cmp> mpq;
	mpq.push(1);
	mpq.push(22);
	mpq.push(38);
	mpq.push(4);
	cout << mpq.top() << endl;
	mpq.pop();
	cout << mpq.top() << endl;
	cout << "---------------------" << endl;

	cout << "priority_queue with self defined data type need to reload <" << endl;
	priority_queue<STUDENT> spq;
	spq.push(STUDENT("xanarry", 100));
	spq.push(STUDENT("micheal", 90));
	spq.push(STUDENT("obma", 60));
	spq.push(STUDENT("bob", 80));
	spq.push(STUDENT("sarah", 70));
	spq.push(STUDENT("marry", 50));
	cout << spq.top().name << " " << spq.top().score << endl;
	spq.pop();
	cout << spq.top().name << " " << spq.top().score << endl;
	cout << "---------------------" << endl;

	cout << "priority_queue with self defined data type and comparitor" << endl;
	priority_queue<BOOK, vector<BOOK>, cmpbook> bpq;
	bpq.push(BOOK(507, 68));
	bpq.push(BOOK(780, 89));
	bpq.push(BOOK(576, 57));
	bpq.push(BOOK(879, 64));
	bpq.push(BOOK(763, 97));
	cout << bpq.top().pages << " " << bpq.top().price << endl;
	bpq.pop();
	cout << bpq.top().pages << " " << bpq.top().price << endl;
	return 0;
}
