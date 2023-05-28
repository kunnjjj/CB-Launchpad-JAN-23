#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(3);
    dq.push_front(10);

    cout<<dq.front()<<endl;

    dq.push_front(14);
    dq.push_front(19);
    cout<<dq.back()<<endl;
    

    return 0;
}