#include<iostream> 
#include<vector>
using namespace std; 

class DSU
{
    public:
    vector<int> parent;
    vector<int> sizeOfComp;
    int n;
    int CC;
    DSU(int n)
    {
        this->n=n;
        parent=vector<int> (n+1);
        sizeOfComp=vector<int> (n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            sizeOfComp[i]=1;
        }
        CC=n;
    }


    int find_parent(int x)
    {
        /* returns topMost parent of x */
        if(parent[x]==x) return x;
        
        parent[x]=find_parent(parent[x]);
        return parent[x];
    }

    void merge(int a,int b)
    {
        int par_a=find_parent(a);
        int par_b=find_parent(b);

        if(par_a==par_b) return ; // already in same CC
        
        CC--;
        // CONVENTION par_a is that par whose size is small
        if(sizeOfComp[par_a] > sizeOfComp[par_b])
        {
            swap(par_a,par_b);
        }

        parent[par_a]=par_b;
        sizeOfComp[par_b]+=sizeOfComp[par_a];


        // if(sizeOfComp[par_a] <= sizeOfComp[par_b])
        // {
        //     parent[par_a]=par_b;
        //     sizeOfComp[par_b]+=sizeOfComp[par_a];
        // }
        // else
        // {
        //     parent[par_b]=par_a;
        //     sizeOfComp[par_a]+=sizeOfComp[par_b];
        // }
        
    }

    int getSize(int x)
    {
        int par_x=find_parent(x);
        return sizeOfComp[par_x];
    }

    int numberOfCC()
    {
        return CC;
    }
};


int main()
{
    int n,q; cin>>n>>q;
    DSU dsu(n);
    while(q--)
    {
        char type; cin>>type;
        if(type=='M')
        {
            int a,b; cin>>a>>b;
            dsu.merge(a,b);
        }
        else
        {
            int a; cin>>a;
            cout<<dsu.getSize(a)<<endl;
            // cout<<dsu.sizeOfComp[a]<<endl; THIS WILL GIVE WRONG ANS (WHY?)
        }
    }
    return 0;
}