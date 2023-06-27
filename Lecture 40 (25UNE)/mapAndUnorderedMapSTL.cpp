#include<iostream>
#include<unordered_map> 
#include<vector>
using namespace std; 

int main()
{
    
    // unordered_map<keyDataType,valueDataType> name;
    unordered_map<int,int> mp;
    mp[5]=20;
    mp[7]=12;

    cout<<mp[7]<<endl;
    mp[3]=23;
    mp[5]=29;
    mp[10]=12;

    cout<<mp.size()<<endl;
    cout<<mp[90]<<endl; // if key is not inserted and value is of type int, then it is initialised with 0

    cout<<mp.size()<<endl;




















    unordered_map<int,string> mp2;
    cout<<"printing: "<<mp2[5]<<endl;;
    cout<<mp2.size()<<endl;
    // mp.find(key) // returns an iterator
    auto it2=mp.find(10);

    if(it2!=mp.end())
    {
        cout<<"found "<<endl;
        cout<<"key: "<<it2->first<<endl;
        cout<<"value: "<<it2->second<<endl;
    }

    if(mp.count(10))
    {
        cout<<mp[10]<<endl;
    }


    cout<<"iterating overmap"<<endl;
    for(pair<int,int> p:mp)
    {
        cout<<"key: "<<p.first<<endl;
        cout<<"value: "<<p.second<<endl;
    }

    cout<<"----------------------------"<<endl;
    unordered_map<int,int>:: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        // cout<<"key: "<<(*it).first<<endl;
        // cout<<"value: "<<(*it).second<<endl;
        cout<<"key: "<<it->first<<endl;
        cout<<"value: "<<it->second<<endl;
    }

    cout<<"---------------------------"<<endl;



    vector<int> A(3,-1);

    for(int x:A) cout<<x<<" ";
    cout<<endl;















    cout<<mp.size()<<endl;

    unordered_map<string,int> stringMap;

    stringMap["kunj"]=21;

    stringMap["aditya"]=20;



    unordered_map<string,float> stringFloatMap;
    stringFloatMap["simranjeet"]=12.45;

    cout<<stringFloatMap.size()<<endl;


    return 0;
}