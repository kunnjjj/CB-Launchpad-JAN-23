#include<iostream>
using namespace std;

int A[100][100];
int prefix[100][100];

int bruteForce(int n,int m)
{
    int sum=0;
    for(int L1=0;L1<n;L1++) // L1: row number for top left corner of rectangle in consideration
    {
        for(int L2=L1;L2<n;L2++) //L2: row number for bottom right corner of rectangle .....
        {
            for(int R1=0;R1<m;R1++) //R1: top left col number
            {
                for(int R2=R1;R2<m;R2++) //R2: bottom right col number
                {
                    for(int i=L1;i<=L2;i++)
                    {
                        for(int j=R1;j<=R2;j++)
                        {
                            sum+=A[i][j];
                        }
                    }
                }
            }
        }
    }   
    return sum;
}

int usingPrefixSums(int n,int m)
{
    int sum=0;
    for(int L1=0;L1<n;L1++) // L1: row number for top left corner of rectangle in consideration
    {
        for(int L2=L1;L2<n;L2++) //L2: row number for bottom right corner of rectangle .....
        {
            for(int R1=0;R1<m;R1++) //R1: top left col number
            {
                for(int R2=R1;R2<m;R2++) //R2: bottom right col number
                {
                    sum+=prefix[L2][R2]- (R1-1>=0?prefix[L2][R1-1]:0) - (L1-1>=0?prefix[L1-1][R2]:0) + (L1-1>=0 && R1-1>=0?prefix[L1-1][R1-1]:0);
                    // for(int i=L1;i<=L2;i++)
                    // {
                    //     for(int j=R1;j<=R2;j++)
                    //     {
                    //         sum+=A[i][j];
                    //     }
                    // }
                }
            }
        }
    }   
    return sum;
}

int contributionTechnique(int n,int m)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int left_corners=(i+1) * (j+1);
            int right_corners=(n-i) * (m-j);
            ans+=A[i][j] * left_corners * right_corners;
        }
    }
    return ans;
}

int main()
{
    int n,m;  cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>A[i][j];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            prefix[i][j]=(j-1>=0?prefix[i][j-1]:0) + A[i][j];
        }
    }

    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            prefix[i][j]+=(i-1>=0?prefix[i-1][j]:0); 
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++) cout<<A[i][j]<<" ";
    //     cout<<endl;
    // }

    cout<<"------------------------------------"<<endl;
    cout<<"prefix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cout<<prefix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<endl;

    cout<<bruteForce(n,m)<<endl;
    cout<<usingPrefixSums(n,m)<<endl;
    cout<<contributionTechnique(n,m)<<endl;

    return 0;
}