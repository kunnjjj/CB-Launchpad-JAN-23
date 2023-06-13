#include<iostream> 
#include<set>
using namespace std; 

int main()
{

    set<int> s;// insertion, deletion,find -> O(logN)

    s.insert(4);
    s.insert(10);
    s.insert(3);

    for(int x:s)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    for(set<int>:: iterator it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    s.insert(10);
    s.insert(5);
    for(int x:s)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"----------MULTISET OPERATIONS(MOSTLY COMMON WITH SET)-----------"<<endl;

    multiset<int> ms;

    ms.insert(10);
    ms.insert(1);
    ms.insert(5);
    ms.insert(10);
    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    ms.erase(5);
    cout<<"after erasing 5"<<endl;
    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    // ms.find(key); // returns an iterator
    // multiset<int>:: iterator it=ms.find(10);
    auto it=ms.find(1);

    // if element is present
    if(it!=ms.end())
    {   
        cout<<"found element"<<endl;
        cout<<(*it)<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }

    ms.erase(it);




    // ms.insert(key)
    // ms.find(key)
    // ms.erase(key) or ms.erase(iterator)
    ms.insert(10);
    ms.insert(15);
    ms.insert(15);
    ms.insert(15);
    ms.insert(15);
    ms.insert(12);
    ms.insert(12);
    ms.insert(12);
    ms.insert(12);
    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    it=ms.find(12);
    if(it!=ms.end())
    {
        ms.erase(it);
    }

    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<(*ms.begin())<<endl;

    cout<<(*ms.rbegin())<<endl;



    return 0;
}