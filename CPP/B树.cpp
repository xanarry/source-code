#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

//B树阶数
const int LEVEL = 3;
//结点中元素上限
const int UPPER = 2 * LEVEL - 1;
//结点中元素下限
const int LOWER = LEVEL - 1;

//B数存储结构
struct Node
{
    bool isLeaf;//是否为叶子的标记
    int n;//当前结点中的元素个数
    int *keys;//保存元素列表的数组指针
    Node **childPointers;//保存孩子指针的指针数组
};

Node *newNode(int n = 0, bool isLeaf = true)
{
    //初始化新的B树结点, 参数为元素个数和是否为叶结点的标志, 默认元素个数为0并且是叶结点
    Node *newOne = new Node();
    newOne->n = n;
    newOne->isLeaf = isLeaf;
    newOne->keys = new int[UPPER];//申请足够的数组空间存放元素
    newOne->childPointers = new Node*[2 * LEVEL];//申请足够的空间存放孩子指针
    //将新结点的所有孩子指针置为NULL
    for (int i = 0; i < 2 * LEVEL; i++)
        newOne->childPointers[i] = NULL;
    return newOne;
}

bool search(Node *root, int key)
{
    /*在B树中搜索目标元素,如果元素存在则返回true, 否则返回false*/
    cout << "search: " << key << endl;
    if (root == NULL)//对于空树的处理
        return false;

    int index = 0;//初始下标为0
    //搜索目标元素在结点中的位置, 并记录下标
    for (; index < root->n; index++)
        if (key <= root->keys[index])
            break;

    cout << "get index: " << index << endl;

    if (root->keys[index] == key)//如果正好搜索到目标元素, 返回true
        return true;
    else //否则递归搜索该下标对应的孩子结点
        return search(root->childPointers[index], key);
}

Node *splitChild(Node *parent, int x)//x = 1
{
    /*分裂孩子正如名字一样, 分裂的点是当前结点某个孩子结点, 参数为父节点和将要分裂结点对应的下标
    方法: 先获取要分裂目标结点标记为左结点, 然后申请新的结点, 保存分裂结点的另外一部分, 再移动左边元素
        和对应的指针到右新结点, 再将中间结点上升至父节点, 重新设置各个结点的元素个数, 分裂完成*/

    //获取要分裂的目标结点
    Node *childL = parent->childPointers[x];
    //申请新的空间保存分裂的另一部分
    Node *childR = newNode();
    //满结点分裂成两部分后, 各部分的元素个数一定是LEVEL-1个
    childR->n = LEVEL - 1;
    childL->n = LEVEL - 1;
    //新申请的结点是否为叶结点与分裂的结点一致
    childR->isLeaf = childL->isLeaf;

    //从分裂结点后复制一半的元素到新申请的结点
    for (int i = 0; i < LEVEL - 1; i++)
        childR->keys[i] = childL->keys[i + LEVEL];

    //如果不是叶结点, 复制后一半的孩子指针到新的结点
    if (!childL->isLeaf)
        for (int i = 0; i < LEVEL; i++)
            childR->childPointers[i] = childL->childPointers[i + LEVEL];

    //移动父节点中的元素和指针, 流出空将分裂结点的中间结点上升至父节点分裂结点下标对应的位置
    for (int i = parent->n - 1; i >= x; i--)
    {
        parent->keys[i + 1] = parent->keys[i];
        parent->childPointers[i + 2] = parent->childPointers[i + 1];
    }

    //将分裂结点的中间元素上升到父节点
    parent->keys[x] = childL->keys[LEVEL - 1];
    //指针将分裂出来的新结点连接到树中
    parent->childPointers[x + 1] = childR;
    //父节点的元素个数增加1
    parent->n++;
}

Node *insertToNotFull(Node *&root, int key)
{
    /*插入元素到非满结点
    方法: 如果插入的非满结点是叶结点, 那么直接插入, 跟新数量即可, 如果插入的结点是内结点, 
    那么先找到要插入的位置即下标, 然后检查该下标对应子结点的元素数量, 如果已经到达上限,
    那么分裂, 再递归将新元素插入的分裂后的结点中*/
    int index = root->n;
    if (root->isLeaf)
    {
        //正要插入的结点是叶结点, 那么直接插入, 更新数量
        //移动元素找到位置
        for (; index > 0 && root->keys[index - 1] > key; index--)
            root->keys[index] = root->keys[index - 1];
        //插入新元素
        root->keys[index] = key;
        //更新数量
        root->n++;
    }
    else
    {
        //将元素插入到内结点
        //找到应该所在的下标位置
        while (index > 0 && root->keys[index - 1] > key)
            index--;

        //如果该下标对应的孩子结点元素数量已经达到上限
        if (root->childPointers[index]->n == UPPER)
        {
            //分裂该结点
            splitChild(root, index);
            //判断并设置应该插入的位置
            if (key > root->keys[index])
                index++;
        }
        //递归调用插入到分裂的结点中
        insertToNotFull(root->childPointers[index], key);
    }
}

Node *insert(Node *&root, int key)
{
    //首先检查跟结点是否达到上限
    if (root->n == UPPER)
    {
        //分裂跟结点, 分裂根节点将会产生新的树根, 树的高度增加1
        Node *newRoot = newNode();//新的树根
        newRoot->isLeaf = 0;//非树叶
        newRoot->n = 0;//初始时为空
        newRoot->childPointers[0] = root;//设置第一个孩子为之前的树根
        splitChild(newRoot, 0);//分裂之前的树根
        root = newRoot;//重新标记树根
    }
    //树根没有满, 则调用非满结点插入函数
    insertToNotFull(root, key);
}

void traverse(Node *root)
{
    //中序遍历B树
    if (root == NULL)
        return;
    //descNode(root);
    for (int i = 0; i < root->n; i++)
    {
        if (root->childPointers[i])
            traverse(root->childPointers[i]);
        cout << root->keys[i] << " ";
    }
    traverse(root->childPointers[root->n]);
}

void levelOrderTraverse(Node *root)
{
    //层次遍历B树, 即广度优先搜索, 使用队列实现, 
    if (root == NULL)
        return;

    //使用结构体捆绑, 每个结点所在的层数
    queue<pair<Node *, int> > nodeQueue;
    nodeQueue.push(make_pair(root, 1));
    int curLevel = 1;
    while (!nodeQueue.empty())
    {
        pair<Node *, int> current = nodeQueue.front();
        nodeQueue.pop();
        if (current.second > curLevel)
        {
            curLevel = current.second;
            cout << endl;
        }
        cout << "(";
        for (int i = 0; i < current.first->n; i++)
        {
            cout << current.first->keys[i] << ",";
            if (!current.first->isLeaf)
                nodeQueue.push(make_pair(current.first->childPointers[i], current.second + 1));
        }
        cout << "\b) ";
        if (!current.first->isLeaf)
            nodeQueue.push(make_pair(current.first->childPointers[current.first->n], current.second + 1));
    }
}

int getPredecessor(Node *root)
{
    //递归获取前驱元素
    if (root->isLeaf)
        return root->keys[root->n - 1];
    else
        return getPredecessor(root->childPointers[root->n]);
}

int getSuccessor(Node *root)
{
    //递归获取后继元素
    if (root->isLeaf)
        return root->keys[0];
    else
        return getSuccessor(root->childPointers[0]);
}

Node *merge(Node *&parent, int index)
{
    //合并两个结点,参数同样为一个父节点和合并点的下标, 将合并该下标所在元素的左右孩子和目标元素到左结点
    //获取目标点的左边孩子
    Node *leftSibling = parent->childPointers[index];

    //获取目标点的右边孩子
    Node *rightSibling = parent->childPointers[index + 1];

    //下移父节点目标点的元素到左边孩子结点的元素列表末尾
    leftSibling->keys[leftSibling->n] = parent->keys[index];

    //临时跟新左边元素数量加1
    leftSibling->n += 1;

    //移动右边孩子结点的元素和孩子指针到左边结点
    for (int i = 0; i < rightSibling->n; i++)
    {
        leftSibling->keys[i + leftSibling->n] = rightSibling->keys[i];
        leftSibling->childPointers[i + leftSibling->n] = rightSibling->childPointers[i];
    }
    //再次更新左边结点元素的数量
    leftSibling->n += rightSibling->n;
    //孩子指针比元素多一个, 再单独复制最后一个右边结点的孩子指针
    leftSibling->childPointers[leftSibling->n] = rightSibling->childPointers[rightSibling->n];

    //父节点中的目标结点下降到子节点中后, 留出了空位, 移动父节点中的元素和指针填补空位
    for (int i = index; i < parent->n; i++)
    {
        parent->keys[i] = parent->keys[i + 1];
        parent->childPointers[i + 1] = parent->childPointers[i + 2];
    }
    //父节点的元素个数减1
    parent->n -= 1;
    //返回合并后的结点
    return leftSibling;
}

void deleteKey(Node *&root, int key)
{
    /*
    从B树删除目标元素
    方法:   递归处理保存在递归过程中每个结点的数大于下限, 首先在当前递归到的结点搜索目标元素, 如果存在, 
        并且目标点是叶结点, 直接删除

            如果删除的元素在当前结点中, 但是该结点不是叶结点, 那么使用该元素的前驱元素或者后继元素替换
        掉目标元素, 然后递归删除前驱或者后继元素, 如果前驱和后继元素所在的结点都只有正好下限个元素, 那么
        合并这两个结点和目标元素为一个新的满结点, 然后递归该结点删除目标元素

            如果删除的元素不在当前递归到的结点中, 那么查找到目标元素应该存在的孩子结点中, 判断孩子结点的
        元素个数是否大于下限, 如果是, 那么递归到该结点删除, 否则, 查看该孩子结点的左右兄弟结点元素是否大
        于下限, 如果是, 那向左边借或者向右边借, 如果左右都没法接, 那么合并目标元素和其左右的孩子结点, 然
        后递归带新合并的结点删除
    */
    int index = 0;
    //在当前结点查找目标结点
    for (; index < root->n; index++)
        if (key <= root->keys[index])
            break;
    
    //如果在当前结点查找到目标元素   
    if (index < root->n && root->keys[index] == key)
    {
        //检查结点是否为叶结点,叶结点直接删除
        if (root->isLeaf)
        {
            for (int i = index; i < root->n - 1; i++)//通过移动后面的元素覆盖掉删除的元素
                root->keys[i] = root->keys[i + 1];
            root->n -= 1;//元素个数减1
        }
        else//删除的元素在内结点中
        {
            //如果存在可删除的前驱,则用前驱替换并删除前驱
            if (root->childPointers[index]->n > LOWER) //get preceder
            {
                int predecessor = getPredecessor(root->childPointers[index]);
                root->keys[index] = predecessor;
                deleteKey(root->childPointers[index], predecessor);
            }
            //否则检查可删除的后继
            else if (root->childPointers[index + 1]->n > LOWER) //get successor
            {
                int successor = getSuccessor(root->childPointers[index + 1]);
                root->keys[index] = successor;
                deleteKey(root->childPointers[index + 1], successor);
            }
            //如果既没有可用前驱也没有可用的后继, 那么合并左右结点和目标元素, 并从合并的结点中删除目标结点
            else
            {  
                //合并将会使B树的层数降低
                index = index == root->n ? index -= 1 : index;
                Node *tRoot = merge(root, index);
                if (root->n == 0)
                {
                    delete root;
                    root = tRoot;
                }
                deleteKey(root, key);
            }
        }
    }
    else //目标元素没有在当前结点中, 搜索孩子结点
    {
        //获取存在目标元素的孩子结点
        Node *subtree = root->childPointers[index];

        //如果孩子结点元素个数大于下限, 那么递归删除
        if (subtree->n > LOWER)
            deleteKey(subtree, key);
        else //否则只有向左右边的孩子结点借, 或者合并新的结点
        {
            //获取左边的兄弟结点
            Node *leftSibling = index - 1 >= 0 ? root->childPointers[index - 1] : NULL;

            //获取右边的兄弟结点
            Node *rightSibling = index + 1 <= root->n ? root->childPointers[index + 1] : NULL;

            //如果左边孩子结点有足够的元素, 向左边借
            if (leftSibling and leftSibling->n > LOWER)
            {
                //左边借的元素在目标元素的结点中是最小的, 向后面移动目标元素结点的元素留出位置插入从父节点下降的元素
                for (int i = subtree->n; i > 0; i--)
                {
                    subtree->keys[i] = subtree->keys[i - 1];
                    subtree->childPointers[i + 1] = subtree->childPointers[i];
                }
                //从父节点下降一个元素
                subtree->keys[0] = root->keys[index - 1];

                //从左兄弟上升一个元素到父节点的目标位置中
                root->keys[index - 1] = leftSibling->keys[leftSibling->n - 1];

                //单独移动左兄弟最右边的指针到目标元素结点的最左边
                subtree->childPointers[0] = leftSibling->childPointers[leftSibling->n];

                //目标元素结点的个数加1
                subtree->n += 1;
                //左边兄弟的元素个数减1
                leftSibling->n -= 1;
                //递归删除
                deleteKey(subtree, key);
            }
            //否则向右边借
            else if (rightSibling and rightSibling->n > LOWER)///need to verify
            {
                //父节点的元素下降到目标元素结点尾部
                subtree->keys[subtree->n] = root->keys[index];

                //右边兄弟结点最前面的元素上升到父节点的目标位置中
                root->keys[index] = rightSibling->keys[0];

                //右兄弟最左边的孩子指针移动到左边孩子最右边的指针
                subtree->childPointers[subtree->n + 1] = rightSibling->childPointers[0];

                //向左移动右边兄弟结点右边的元素和指针填补刚移走的元素和指针的空位
                for (int i = 1; i < rightSibling->n; i++)
                {
                    rightSibling->keys[i - 1] = rightSibling->keys[i];
                    rightSibling->childPointers[i - 1] = rightSibling->childPointers[i];
                }
                //单独移动最后一个指针, 因为元素比指针少一个
                rightSibling->childPointers[rightSibling->n - 1] = rightSibling->childPointers[rightSibling->n];
                
                //更新数量
                rightSibling->n -= 1;
                subtree->n += 1;
                deleteKey(subtree, key);
            }
            else//如果左右两边都没法借, 那么合并左右孩子结点和目标元素
            {
                //合并将会使B树的层数降低
                index = index == root->n ? index -= 1 : index;
                Node *tRoot = merge(root, index);
                if (root->n == 0)
                {
                    delete root;
                    root = tRoot;
                }
                deleteKey(root, key);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Node *root = newNode();
    set<int> s;
    int eleCount = 10;
    cout << "gen array" << endl;
    while (s.size() != eleCount)
        s.insert(rand() % eleCount);
    
    cout << "insert" << endl;
    for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        insert(root, *iter); cout << "in " << *iter << ": "; traverse(root); cout << endl;
    }

    cout << "delete" << endl;
    for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        deleteKey(root, *iter); cout << "rm " << *iter << ": "; traverse(root); cout << endl;
    }
    return 0;
}
