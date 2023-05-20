#include<iostream>
using namespace std;

bool shrutikaKriti(string s)
{
    int n=s.size();
    int i=0;
    // assuming string contains '(' and ')'
    for(int j=0;j<n;j++)
    {
        if(s[j]=='#')
        {
            continue;
        }
        if(s[j]==')') return false;
        while(i<n && s[i]!=')') i++;
        if(i==n) return false;
        s[i]='#';
    }
    return true;
}

bool isBal(string &s)
{
    int cnt=0;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='(') cnt++;
        else cnt--;
        if(cnt<0) return false;
    }
    return cnt==0;
}

int main()
{
    string s; cin>>s;
    cout<<boolalpha<<shrutikaKriti(s)<<endl;

    return 0;
}