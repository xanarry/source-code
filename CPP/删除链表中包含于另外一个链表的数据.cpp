#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node *head, int data)
{
    //头插法
    Node *newOne = new Node();
    newOne->data = data;
    newOne->next = head->next;
    head->next = newOne;
}

void output(Node *head)
{
    head = head->next;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool find(Node *head, int data)
{
    head = head->next;
    while (head)
    {
        if (head->data == data)
            return true;
        head = head->next;
    }
    return false;
}

//core code here
void delNode(Node *head1, Node *head2)
{
    Node *pre = head1;
    Node *cur = head1->next;
    while (cur)
    {
        if (!find(head2, cur->data))
        {
            pre = cur;
            cur = cur->next;
        }
        else
        {
            Node *tmp = cur;
            cur = cur->next;
            pre->next = cur;
            delete tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *head1 = new Node();
    Node *head2 = new Node();

    for (int i = 0; i < 10; i++)
        insert(head1, i);

    for (int i = 5; i < 15; i++)
        insert(head2, i);

    cout << "list1:" << endl;
    output(head1);

    cout << "list2" << endl;
    output(head2);

    cout << "after remove the element from list1 which is contained in list2" << endl;
    delNode(head1, head2);
    output(head1);
    return 0;
}