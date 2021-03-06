#include <iostream>
#include <list>

using namespace std;

class HashTable
{
    int capacity;
    list<int>* table;

public:
    HashTable(int c);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int checkPrime(int n);
    int getPrime(int n);
    int hashFunction(int key);
    void displayHash();
};

HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data)
{ 
    int index = hashFunction(key);
    table[index].push_back(data);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    for (int i = 0; i < 10; i++) {
        if (i == index) {
            table[index].pop_front();
        }
    }
}

int HashTable::hashFunction(int key)
{
    return (key % capacity);
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i << "]";
        for (auto x : table[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
    cout << endl;
}

int HashTable::checkPrime(int n)
{
    int i;
    if (n == 1 || n == 0) {
        return 0;
    }
    for (i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int HashTable::getPrime(int n)
{
    if (n % 2 == 0) {
        n++;
    }
    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

int main()
{
    int key[] = { 231, 321, 212, 321, 433, 262 };
    int data[] = { 123, 432, 523, 43, 423, 111 };
    int size = sizeof(key) / sizeof(key[0]);
    HashTable table(size);
    for (int i = 0; i < size; i++) {
        table.insertItem(key[i], data[i]);
    }
    table.displayHash();
    table.deleteItem(231);
    table.displayHash();
    table.deleteItem(321);
    table.displayHash();
}