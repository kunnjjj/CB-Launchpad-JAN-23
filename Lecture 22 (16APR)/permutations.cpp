#include<iostream>
using namespace std;


void generatePermutations(string input,string output)
{
    if(input=="")
    {
        cout<<output<<endl;
        return ;
    }

    for(int j=0;j<(int)input.size();j++)
    {
        generatePermutations(input.substr(0,j) + input.substr(j+1),output+input[j]);
    }
}


int main()
{

    generatePermutations("abcd","");

    return 0;
}