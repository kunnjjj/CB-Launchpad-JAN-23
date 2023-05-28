#include<iostream>
using namespace std;

int main()
{
    pair<string,int> student;

    student.first="prabhnoor";
    student.second=19;

    pair<string,string> couple;

    couple.first="prabhnoor";
    couple.second="sonamBajwa";

    cout<<couple.first<<endl;
    cout<<couple.second<<endl;

    couple.second="sara";

    couple=make_pair("vivek","kuchNai");

    couple={"simranjeet","simran"};

    // deque<pair<int,int>> dq;

    // deque<dataType> dq;
    // deque<pair<int,int>> dq;
    
    return 0;
}