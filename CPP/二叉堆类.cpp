#include <iostream>
#include <cstdlib>
using namespace std;

class BinHeap
{
private:
    int *elem;
    int size; 
    int capacity;

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp; 
    }
public:
    BinHeap()
    {
        size = 0;
        capacity = 1000;
        elem = new int[capacity];
    }

    BinHeap(int cpct)
    {
        elem = new int[cpct];
        size = 0;
        capacity = cpct;
    }

    int top()
    {
        return elem[1];
    }

    int extra_top()
    {
        int top = elem[1];
        elem[1] = elem[size];
        size--;
        make_heap(1);
        return top;
    }

    void make_heap(int top)
    {
        while (top << 1 <= size)
        {
            int left = top << 1;
            int right = left + 1;
            int max_i = top;

            if (elem[max_i] < elem[left])
                max_i = left;
            if (right <= size && elem[max_i] < elem[right])//both l and r element
                max_i = right;

            if (max_i == top)
                break;
            swap(elem[top], elem[max_i]);
            top = max_i;
        }
    }
    
    void push(int n)
    {
        size++;
        if (capacity - size < 10)
        {
            capacity *= 2;
            elem = (int *) realloc(elem, capacity * sizeof(int));
        }
        elem[size] = n;

        int t = size >> 1;
        while (t)
        {
            make_heap(t);
            t = t >> 1;
        }
    }

    void show()
    {
        cout << "size:" << size << endl;
        for (int i = 1; i <= size; i++)
            cout << elem[i] << " ";
        cout << endl;
    }

    int get_size()
    {
        return size;
    }
};

int main(int argc, char const *argv[])
{
    BinHeap heap;
    int a[10] = {32,26,65,68,19,31,24,16,21,13};
    for (auto i : a)
        heap.push(i);

    while (heap.get_size())
        cout << heap.extra_top() << endl;
    return 0;
}