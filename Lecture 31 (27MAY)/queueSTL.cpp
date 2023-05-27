#include<iostream>
#include<queue>



int main()
{
    // stack<int> q;
    std::queue<int> q;
    q.push(10);
    q.pop();
    q.push(11);
    std::cout<<q.front()<<std::endl;

    return 0;
}