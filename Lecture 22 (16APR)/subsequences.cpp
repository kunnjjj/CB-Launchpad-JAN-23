#include<iostream>
using namespace std;


void printSubsequences(string input,string output)
{   

    // if((int)input.size()==0)
    // if(input.empty())
    if(input=="")
    {
        cout<<output<<endl;
        return ;
    }

    // exclude input[0] char
    printSubsequences(input.substr(1),output);

    // include input[0] char
    printSubsequences(input.substr(1),output + input[0]);
}

int main()
{

    string s; cin>>s;
    printSubsequences(s,"");


    return 0;
}