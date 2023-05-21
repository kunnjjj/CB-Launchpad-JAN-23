#include<iostream> 
using namespace std; 



int main()
{

    pair<int,int> p1;
    pair<int,string> p2;

    p1.first=10;
    p1.second=12;

    p2.first=12;
    p2.second="abc";

    p2=make_pair(12,"pqr");
    p2={12,"abcde"};


    cout<<p1.first<<endl;
    cout<<p1.second<<endl;

    return 0;
}