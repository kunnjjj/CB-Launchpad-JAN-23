#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{







    string s="kunj";
    for(int i=0;s[i]!='\0';i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;

    for(char c:s)
    {
        cout<<c<<" ";
    }
    cout<<endl;

    string:: iterator stringIt;

    for(stringIt=s.begin();stringIt!=s.end();stringIt++)
    {
        cout<<(*stringIt)<<" ";
    }
    cout<<endl;

    for(auto it=s.rbegin();it!=s.rend();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;


    string s2="prabhnoor";

    for(char x:s2)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> v={10,12,11};

    for(int &i:v)
    {
        cout<<i<<" ";
        i=15;
    }
    cout<<endl;

    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    vector<vector<int>> A(3,vector<int> (2,-1));

    for(auto v:A)
    {
        for(auto x:v) cout<<x<<" ";
        cout<<endl;
    }

    for(auto i=0;i<10;i++)
    {
        cout<<i*4<<endl;
    }

    // iterators are anologous to pointers

    // arrays []->pointer
    // <> -> iterator

    sort(v.begin(),v.end());
    int B[3]={10,120,9};
    sort(B,B+3);
    vector<int>:: iterator it=v.begin();

    sort(it,it+3);
    string:: iterator it2=s.begin();


    return 0;
}