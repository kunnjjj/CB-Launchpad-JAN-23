#include<iostream>
using namespace std;

void generate_permutations(string &input,int pos)
{
    if(pos==(int)input.size())
    {
        cout<<input<<endl;
        return ;
    }

    for(int j=pos;j<(int)input.size();j++)
    {
        swap(input[pos],input[j]);
        generate_permutations(input,pos+1);
    }
}

int main()
{

    string s; cin>>s;
    generate_permutations(s,0);

    return 0;
}