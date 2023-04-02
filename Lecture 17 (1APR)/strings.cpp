#include<iostream>
#include<algorithm>

using namespace std;

void ReverseString(string &s)
{
    int n=s.size();
    int i=0,j=n-1;
    while(i<j) 
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}

int main()
{
    string s="kuch bhi likhdo";
    getline(cin,s);

    cout<<s<<endl;
    
    int n=s.size(); //s.length()

    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }

    ReverseString(s);
    cout<<endl;

    cout<<s<<endl;
    ReverseString(s);

    // s="prabhnoor, " + s;
  
    // cout<<s<<endl;

    // s=s+",prabhnoor"; //M1
    // cout<<s<<endl;
    // a=a+b; a+=b;

    // s+=",prabhnoor"; //M2
    // cout<<s<<endl;


    // m3
    s.append(",prabhnoor ji");
    cout<<s<<endl;    

    string s2="kunjaroraXYZ";
    cout<<s2.substr(4,5)<<endl;

    s2+='Q';
    s2+="Q";
    s2.push_back('Q');

    cout<<s2<<endl;

    cout<<endl;

    for(int i=0;i<(int)s2.size();i++) cout<<s2[i];
    cout<<endl;
    char x='A';
    cout<<(int)x<<endl;

    cout<<"sizeof(x): "<<sizeof(x);

    string s3="ABC";
    string s4="ABCD";
    cout<<endl;

    if(s3==s4)
    {
        cout<<"equal"<<endl;
    }
    else
    {
        cout<<"unequal"<<endl;
    }

    if(s3 < s4) // on basic of ascii values
    {
        cout<<"s3 is smaller"<<endl;
    }
    else
    {
        cout<<"s4 is smaller(or equal)"<<endl;
    }

    s="pqrabc";


    size_t found=s.find("abcd");

    if(found==string::npos)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found at idx: "<<found<<endl;
    }

    sort(s.begin(),s.end());
    // sort(s.begin(),s.begin()+3);
    cout<<s<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;

  

    return 0;
}