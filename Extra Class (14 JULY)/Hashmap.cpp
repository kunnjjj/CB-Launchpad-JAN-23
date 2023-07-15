#include <iostream>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~Node()
    {

        if (this->next != NULL)
        {
            delete (this->next);
        }

        cout << "deleting " << key << endl;
    }
};

class Hashmap
{
    Node **hashtable;
    int prime;
    int M;
    float loadFactor;
    int curSize;
    int hashFunction(string key)
    {
        int index = 0;
        int power = 1;
        for (int i = 0; i < (int)key.size(); i++)
        {
            int asciiValue = (int)key[i];
            index = (index + asciiValue * power) % M;
            power = (power * prime) % M;
        }
        return index;
    }

    void insertAtTail(Node *&head, string &key, int &val)
    {
        if (head == NULL)
        {
            head = new Node(key, val);
            return;
        }
        insertAtTail(head->next, key, val);
    }
    void printLL(Node *head)
    {
        if (head == NULL)
        {
            cout << endl;
            return;
        }
        cout << "{ " << head->key << " , " << head->value << " } ->";
        printLL(head->next);
    }

    void rehash()
    {
        cout << "REHASHING" << endl;
        int oldM = M;
        M *= 2;
        Node **newHashtable = new Node *[M];
        for (int i = 0; i < M; i++)
        {
            newHashtable[i] = NULL;
        }

        for (int i = 0; i < oldM; i++)
        {
            Node *head = hashtable[i];
            while (head != NULL)
            {
                string key = head->key;
                int val = head->value;
                int newIndex = hashFunction(key);
                insertAtTail(newHashtable[newIndex], key, val);
                head = head->next;
            }
        }

        // DELETE EACH LL
        for (int i = 0; i < oldM; i++)
        {
            if (hashtable[i] != NULL)
                delete (hashtable[i]);
        }
        cout<<"check"<<endl;

        // DELETE HASHTABLE
        delete[] hashtable;

        // ASSIGN NEW HASHTABLE TO ORIGINAL HASHTABLE
        hashtable = newHashtable;
    }

public:
    Hashmap(int initialSize)
    {
        M = initialSize;
        hashtable = new Node *[M];
        for (int i = 0; i < M; i++)
            hashtable[i] = NULL;
        loadFactor = 0.5; /* 0.75 */
        curSize = 0;
    }

    void insert(string key, int value)
    {
        cout<<"inserting "<<key<<endl;
        if (((1 + curSize) * 1.0) / M > loadFactor)
        {
            rehash();
        }

        int index = hashFunction(key);
        insertAtTail(hashtable[index], key, value);
        curSize++;
    }

    // find,update,delete func
    int find(string key)
    {
        /*TODO*/
        return -1;
        // returns -1 of key is not present,
        // returns value associated with key

        // find index with hash(key)
        // iterate over hashtable[index]
    }

    void printMap()
    {
        for (int i = 0; i < M; i++)
        {
            cout << i << ": ";
            printLL(hashtable[i]);
        }
        cout << endl;
    }
};

int main()
{
    int initSize; cin>>initSize;
    Hashmap hashmap(initSize);

    hashmap.insert("burger", 70);
    hashmap.printMap();

    hashmap.insert("pizza", 120);
    hashmap.printMap();

    hashmap.insert("brownie", 50);
    hashmap.printMap();

    hashmap.insert("bread", 50);
    hashmap.printMap();

    hashmap.insert("oats", 80);
    hashmap.printMap();

    hashmap.insert("protein", 520);
    hashmap.printMap();
    
    hashmap.insert("pastry", 150);
    hashmap.printMap();

    return 0;
}