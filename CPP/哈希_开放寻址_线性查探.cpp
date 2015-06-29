#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Hash_table
{
    int current_size;
    int capacity;
    string *table;  
};

int next_prime(int n)
{
    //计算下一个素数
    if (n < 2)
        return 2;
    while (true)
    {
        bool flag = true;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return n;
        n++;
    }
}

Hash_table *init(int max_size)
{
    Hash_table *hash_table = new Hash_table();
    hash_table->capacity = next_prime(max_size);
    hash_table->current_size = 0;
    hash_table->table = new string[hash_table->capacity];
    for (int i = 0; i < hash_table->capacity; i++)
        hash_table->table[i] = "__null__";
    return hash_table;
}

int gen_hash_code(string key, int hash_table_size, int offset)
{
    int hash_code = 0;
    for (int i = 0; i < key.length(); i++)
        hash_code += (128 << i + 1) + key[i];
    //f(i) = i;
    //线程查探h(x) = h(x) + f(i);
    return (hash_code + offset) % hash_table_size;
}

bool insert(Hash_table *hash_table, string key)
{
    if (hash_table->current_size >= hash_table->capacity)
        return false;
    int offset = 0;
    int hash_code = gen_hash_code(key, hash_table->capacity, offset);
    while (hash_table->table[hash_code] != "__null__")
        hash_code = gen_hash_code(key, hash_table->capacity, ++offset);
    hash_table->table[hash_code] = key;
    hash_table->current_size++;
    return true;
}

bool search(Hash_table *hash_table, const string key)
{
    int offset = 0;
    int hash_code = gen_hash_code(key, hash_table->capacity, offset);
    while (hash_table->table[hash_code] != "__null__" && hash_table->table[hash_code] != key)
        hash_code = gen_hash_code(key, hash_table->capacity, ++offset);
    return hash_table->table[hash_code] == "__null__" ? false : true;
}

void disply_hash_table(Hash_table *hash_table)
{
    cout << "capacity: " << hash_table->capacity << endl;
    cout << "current_size: " << hash_table->current_size << endl;
    for (int i = 0; i < hash_table->capacity; i++)
        cout << i << " : " << (hash_table->table[i] == "__null__" ? "   " : hash_table->table[i]) << endl;
}

int main(int argc, char const *argv[])
{
    const int len = 10;
    const string a[] = {"string", "shoes", "computer", "boot", "contingency", "overflow", "world", "overlap", "scraper", "netowrk"};
    const int max_table_size = 10;
    Hash_table *hash_table = init(max_table_size);//初始化哈希表

    for (int i = 0; i < len; i++)//将以上单词插入哈希表
        insert(hash_table, a[i]);

    disply_hash_table(hash_table);//输出哈希表

    string dest = a[2];
    bool res = search(hash_table, dest);//查探哈希表
    cout << dest << (res ? " in" : " not in") << "this hash_table" << endl;
    return 0;
}