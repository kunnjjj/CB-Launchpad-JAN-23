#include<iostream> 
#include<stack>
using namespace std; 

int main()
{
    stack<int> stackInt;
    stack<char> stackChar;

    stackInt.push(10);
    cout<<stackInt.top()<<endl;
    stackInt.pop();
    cout<<boolalpha<<stackInt.empty()<<endl;
    cout<<stackInt.size()<<endl;
    return 0;
}