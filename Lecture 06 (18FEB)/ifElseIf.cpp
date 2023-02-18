#include<iostream>
using namespace std;



int main()
{

    int numberOfGirlfriends=5;
    bool btech=true;

    if(numberOfGirlfriends>0 && btech==false)
    {
        cout<<"DU ka launda"<<endl;
    }
    else if(numberOfGirlfriends==0 && btech==true)
    {
        cout<<"NSIT"<<endl;
    }
    else if(numberOfGirlfriends >=4 && btech==true)
    {
        cout<<"Vedant"<<endl;
    }
    else if(numberOfGirlfriends>0 && btech==true)
    {
        cout<<"Kunj Bhaiya"<<endl;
    }
    else
    {
        cout<<"abhi padhai karlo, kuch nahi rakha in sab mein"<<endl;
    }

    return 0;
}