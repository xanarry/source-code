#include <iostream>
using namespace std;

struct NODE
{
    int a;
    int pol;
    NODE *next;
};

NODE *init();
void travers(NODE *head);
void insert(NODE *head, int a, int pol);
NODE *add(NODE *h1, NODE *h2);
NODE *multi(NODE *h1, NODE *h2);

int main(int argc, char const *argv[])
{
    NODE *exa = init();
    NODE *exb = init();

    insert(exa, 2, 2);
    insert(exa, 3, 1);
    cout << "b = "; travers(exa);

    insert(exb, 4, 3);
    insert(exb, 3, 2);
    insert(exb, 1, 1);
    insert(exb, 1, 9);
    cout << "a = "; travers(exb);

    NODE *add_result = add(exa, exb);
    cout << "a + b = ";travers(add_result);

    NODE *multi_result = multi(exa, exb);
    cout << "a * b = "; travers(multi_result);
    return 0;
}

NODE *add(NODE *h1, NODE *h2)
{
    NODE *result = new NODE();
    result->next = NULL;
    h1 = h1->next;
    h2 = h2->next;
    while (h1 && h2)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        if (h1->pol > h2->pol)
        {
            insert(result, h1->a, h1->pol);
            h1 = h1->next;
        }
        else if (h1->pol < h2->pol)
        {
            insert(result, h2->a, h2->pol);
            h2 = h2->next;
        }
        else
        {
            insert(result, h1->a + h2->a, h1->pol);
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    while (h1)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        insert(result, h1->a, h1->pol);
        h1 = h1->next;
    }
    while (h2)
    {
        NODE *new_node = new NODE();
        new_node->next = NULL;
        insert(result, h2->a, h2->pol);
        h2 = h2->next;
    }
    return result;
}

NODE *multi(NODE *h1, NODE *h2)
{
    NODE *result = init();
    h1 = h1->next;
    h2 = h2->next;
    while (h1)
    {
        NODE *th2 = h2;
        while (th2)
        {   
            insert(result, h1->a * th2->a, h1->pol + th2->pol);
            th2 = th2->next;
        }
        h1 = h1->next;
    }
    return result;
}

NODE *init()
{
    NODE *head = new NODE();
    head->next = NULL;
    return head;
}

void insert(NODE *head, int a, int pol)
{
    NODE *h = head;
    NODE *new_node = new NODE();
    new_node->a = a;
    new_node->pol = pol;
    new_node->next = NULL;

    if (h->next == NULL)
        h->next = new_node;
    else
    {
        while (h->next && h->next->pol > pol)
            h = h->next;
        new_node->next = h->next;
        h->next = new_node;
    }
}

void travers(NODE *head)
{
    NODE *h = head->next;
    int i = 0;
    while (h)
    {
        if (h->a >= 0) 
            cout << (i == 0 ? "" : "+");
        cout << h->a << "x^" << h->pol;
        h = h->next;
        i++;
    }
    cout << endl;
}