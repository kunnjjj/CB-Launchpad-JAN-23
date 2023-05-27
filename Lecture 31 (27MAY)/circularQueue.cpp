#include<bits/stdc++.h>
using namespace std;


class Queue
{
    int *Q;
    int curSize;
    int N;
    int front;
    int back;
    public:
    Queue(int initSize)
    {
        Q=new int[initSize];
        N=initSize;
        back=-1; // N-1
        curSize=0;
        front=0;
    }

    void push(int x)
    {
        if(curSize==N)
        {
            cout<<"Overflow"<<endl;
            return ;
        }

        back=(back+1)%N;
        Q[back]=x;
        curSize++;
    }

    void pop()
    {
        if(curSize==0)
        {
            cout<<"underflow"<<endl;
            return ;
        }
        // Q[front]=junk;
        front=(front+1)%N;
        curSize--;
    }

    int Front()
    {
        if(curSize==0)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return Q[front];
    }


};

int main()
{
    Queue q(8);
    q.push(3);
    q.push(10);
    q.push(12);
    cout<<q.Front()<<endl;
    q.pop();
    cout<<q.Front()<<endl;
    return 0;
}





