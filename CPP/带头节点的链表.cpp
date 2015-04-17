#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *init();
void insert_front(NODE *head, int n);
void insert_back(NODE *head, int n);
void insert_into(NODE *head, int index, int n);
bool isempty(NODE *head);
void delete_node(NODE *head, int index);
NODE *find_node(NODE *head, int dest);
void travers(NODE *head);
NODE *merge_list(NODE *a, NODE *b);

int main(int argc, char const *argv[])
{
    cout << "create head..." << endl;
    NODE *head = init();

    cout << "insert 0-9 into tail:" << endl;
    for (int i = 0; i < 2; i++)
       insert_back(head, i);
    travers(head);
   
    cout << "delete node of index 0:" << endl;
    delete_node(head, 0);

    /*
    cout << "find 90 in the list: " << endl;
    NODE *re = find_node(head, 90);
    if (re)
        cout << re->data << endl;
    else
        cout << "NULL" << endl;

    NODE *h1 = init();
    for (int i = 0; i < 10; i += 2)
        insert_back(h1, i);
    cout << "h1: ";
    travers(h1);
    NODE *h2 = init();
    for (int i = 1; i < 10; i += 2)
        insert_back(h2, i);
    cout << "h2: ";
    travers(h2);

    cout << "merge h1 h2: " << endl;
    NODE *m = merge_list(h1, h2);
    travers(m);*/

    return 0;
}

NODE *init()
{
    NODE *head = new NODE();
    head->next = NULL;
    return head;
}

void insert_front(NODE *head, int n)
{
    NODE *new_node = new NODE();
    new_node->data = n;
    new_node->next = head->next;
    head->next = new_node;
}

void insert_back(NODE *head, int n)
{
    NODE *h = head;
    while (h->next)
        h = h->next;
    NODE *new_node = new NODE();
    new_node->data = n;
    new_node->next = NULL;
    new_node->next = h->next;
    h->next = new_node;
}

void insert_into(NODE *head, int index, int n)
{
    int mark = 0;
    NODE *h = head;
    while (h && mark < index)
    {
        h = h->next;
        mark++;
    }
    NODE *new_node = new NODE();
    new_node->data = n;
    new_node->next = NULL;
    new_node->next = h->next;
    h->next = new_node;
}

void delete_node(NODE *head, int index)
{
    if (isempty(head))
    {
        cout << "empty list" << endl;
        return;
    }

    int mark = 0;
    NODE *h = head;
    while (h && mark < index)
    {
        h = h->next;
        mark++;
    }
    if (h == NULL || index < 0)
    {
        cout << "index " << index << " out of range" << endl;
        return;
    }
    NODE *del_node = h->next;
    h->next = h->next->next;
    delete(del_node);
}

NODE *find_node(NODE *head, int dest)
{
    NODE *h = head;
    while (h && h->data != dest)
        h = h->next;
    return h;
}

NODE *merge_list(NODE *a, NODE *b)
{
    NODE *new_h = new NODE();
    new_h->next = NULL;
    a = a->next;
    b = b->next;
    while (a && b)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        if (a->data < b->data)
        {
            insert_back(new_h, a->data);
            a = a->next;
        }
        else 
        {
            insert_back(new_h, b->data);
            b = b->next;
        }
    }
    while (a)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        insert_back(new_h, a->data);
        a = a->next;
    }
    while (b)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        insert_back(new_h, b->data);
        b = b->next;
    }
    return new_h;
}

void travers(NODE *head)
{
    if (isempty(head))
    {
        cout << "empty list" << endl; 
        return;
    }
    NODE *h = head->next;
    while (h)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

bool isempty(NODE *head)
{
    return head->next ? false : true;
}