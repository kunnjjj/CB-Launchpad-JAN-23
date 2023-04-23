#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> A;
    A.push_back(4);
    A.push_back(10);
    A.push_back(3);
    for(int i=0;i<(int)A.size();i++) cout<<A[i]<<" "; 
    cout<<endl;

    A.push_back(13);

    for(int i=0;i<(int)A.size();i++) cout<<A[i]<<" "; 
    cout<<endl;

    vector<int> B(5,0);
    for(int i=0;i<(int)B.size();i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    B.push_back(11);

    for(int i=0;i<(int)B.size();i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;

    vector<vector<int>> C;
    C.push_back(A);
    C.push_back(B);

    cout<<"2D vector C: "<<endl;
    for(int i=0;i<(int)C.size();i++)
    {
        for(int j=0;j<(int)C[i].size();j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    A.pop_back();

    cout<<"2D vector C: "<<endl;
    for(int i=0;i<(int)C.size();i++)
    {
        for(int j=0;j<(int)C[i].size();j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<(int)A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    C.push_back(A);
    
    cout<<"2D vector C: "<<endl;
    for(int i=0;i<(int)C.size();i++)
    {
        for(int j=0;j<(int)C[i].size();j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }




    // vector<float> B;

    // while(true)
    // {
    //     int x; cin>>x;
    //     if(x==-1) break;

    //     A.push_back(x);

    //     for(int i=0;i<(int)A.size();i++)
    //     {
    //         cout<<A[i]<<" ";
    //     }
    //     cout<<endl;

    //     cout<<"size of A: "<<A.size()<<endl;
    //     cout<<"capacity of A: "<<A.capacity()<<endl;
    // }


    vector<vector<int>> F(3,vector<int> (5,7));
    
    cout<<"\nF: \n";
    for(int i=0;i<(int)F.size();i++)
    {
        for(int j=0;j<(int)F[i].size();j++)
        {
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<A.back()<<endl;
    cout<<A[(int)A.size() -1]<<endl;

    cout<<A.front()<<endl;

    A.clear();
    cout<<"printing A"<<endl;
    for(int i=0;i<(int)A.size();i++)
    {
        cout<<A[i];
    }

    

    return 0;
}