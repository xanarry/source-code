#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
}Node;

Node *newNode(int key)
{
    Node *newOne = (Node*) malloc(sizeof(Node));
    newOne->key = key;
    newOne->left = NULL;
    newOne->right = NULL;
    return newOne;
}

Node *recurInsert(Node *root, int key)
{
    if (!root)
        return root = newNode(key);
    else if (key >= root->key)
        root->right = recurInsert(root->right, key);
    else
        root->left = recurInsert(root->left, key);
}

void loopInsert(Node *(&root), int key)
{
    if (!root)
        root = newNode(key);
    else
    {
        Node *parent = root;
        Node *curPos = root;
        while (curPos)
        {
            parent = curPos;
            if (key >= curPos->key)
                curPos = curPos->right;
            else
                curPos = curPos->left;
        }
        Node *newOne = newNode(key);
        if (key >= parent->key)
            parent->right = newOne;
        else
            parent->left = newOne;
    }
}


void d(Node *root)
{
    if (root)
    {
        printf("%d ", root->key);
        d(root->left);
        d(root->right);
    }
}
int len = 1000;
int *a;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    double beginTime = 0, genarrayTime, recurTime, loopTime;

    for (int i = 0; i < 20; i++)
    {
        printf("data recods count: %d\n", len);
        a = (int *) malloc(len * sizeof(int));
        Node *root = NULL;
        for (int i = 0; i < len; i++)
            a[i] = rand() % 1000;
        genarrayTime = (double) clock() / CLOCKS_PER_SEC;
        printf("gen random array time consume: %6f\n", genarrayTime - beginTime);

        for (int i = 0; i < len; i++) root = recurInsert(root, a[i]);
        recurTime = (double) clock() / CLOCKS_PER_SEC;
        printf("recursive insert time consume: %6f\n", recurTime - beginTime);

        root = NULL;
        for (int i = 0; i < len; i++) loopInsert(root, a[i]);
        loopTime = (double) clock() / CLOCKS_PER_SEC;
        printf("loop  insertion  time consume: %6f\n\n", loopTime - recurTime);
        beginTime = loopTime;
        len *= 2;
    }
    
    return 0;
}

/*
data recods count: 1000
gen random array time consume: 0.005000
recursive insert time consume: 0.012000
loop  insertion  time consume: 0.007000

data recods count: 2000
gen random array time consume: 0.011000
recursive insert time consume: 0.018000
loop  insertion  time consume: 0.007000

data recods count: 4000
gen random array time consume: 0.010000
recursive insert time consume: 0.019000
loop  insertion  time consume: 0.008000

data recods count: 8000
gen random array time consume: 0.012000
recursive insert time consume: 0.025000
loop  insertion  time consume: 0.012000

data recods count: 16000
gen random array time consume: 0.012000
recursive insert time consume: 0.034000
loop  insertion  time consume: 0.019000

data recods count: 32000
gen random array time consume: 0.014000
recursive insert time consume: 0.072000
loop  insertion  time consume: 0.044000

data recods count: 64000
gen random array time consume: 0.020000
recursive insert time consume: 0.186000
loop  insertion  time consume: 0.144000

data recods count: 128000
gen random array time consume: 0.022000
recursive insert time consume: 0.762000
loop  insertion  time consume: 0.641000

data recods count: 256000
gen random array time consume: 0.029000
recursive insert time consume: 3.851000
loop  insertion  time consume: 3.392000

data recods count: 512000
gen random array time consume: 0.039000
recursive insert time consume: 17.894000
loop  insertion  time consume: 15.905000

data recods count: 1024000
gen random array time consume: 0.071000
recursive insert time consume: 78.298000
loop  insertion  time consume: 70.204000

data recods count: 2048000
gen random array time consume: 0.121000
recursive insert time consume: 331.672000
loop  insertion  time consume: 293.362000

data recods count: 4096000
gen random array time consume: 0.236000
recursive insert time consume: 1384.850000
loop  insertion  time consume: 1222.894000

从对比结果可以看出, 使用循环的速度显然比递归插入的速度快很多, 因为在
每次递归时都要保存额外的信息到栈, 等递归完成再从栈恢复, 这些操作需要
执行额外的指令, 所以更慢, 由于使用普通二叉树并不是一个比较平衡的二叉
树, 所以总的操作时间显然比平衡树的时间要多很多
*/