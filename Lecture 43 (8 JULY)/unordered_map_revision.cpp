#include<iostream> 
#include<unordered_map>
#include<vector>
using namespace std; 

int main()
{
    // unordered_map<keyDatatype,valueType> mapName;
    unordered_map<int,int> mp;

    mp[3]=10;
    mp[3]+=4;

    cout<<mp[3]<<endl;


    mp[-12]=27;

    // key=int, value=vector<int> mp1
    unordered_map<int,vector<int>> mp1;

    mp1[3].push_back(10);
    mp1[3].push_back(12);

    mp1[-4].push_back(11);
    mp1[-4].push_back(16);

    mp1[2].push_back(120);

    for(int i=0;i<3;i++)
    {
        int x; cin>>x;
        mp1[2].push_back(x);
    }




    return 0;
}