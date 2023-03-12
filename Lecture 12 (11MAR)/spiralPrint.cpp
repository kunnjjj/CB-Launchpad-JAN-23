#include<iostream>
using namespace std;
int main()
{
    int r,c; cin>>r>>c;
    int A[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) 
        {
            // cin>>A[i][j];
            A[i][j]=(i+1)*10 + (j+1);
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cout<<A[i][j]<<", ";
        cout<<endl;
    }

    cout<<"----------------------------------------------------"<<endl;

    int SR=0,ER=r-1,SC=0,EC=c-1;

    while(SR<=ER && SC<=EC)
    {
        for(int i=SR;i<=ER;i++)
        {
            cout<<A[i][SC]<<", ";
        }
        SC++;
        for(int i=SC;i<=EC;i++)
        {
            cout<<A[ER][i]<<", ";
        }
        ER--;
        if(SC<=EC)
        for(int i=ER;i>=SR;i--)
        {
            cout<<A[i][EC]<<", ";
        }
        EC--;
        if(SR<=ER)
        for(int i=EC;i>=SC;i--)
        {
            cout<<A[SR][i]<<", ";
        }
        SR++;
    }
    cout<<"END";

    return 0;
}