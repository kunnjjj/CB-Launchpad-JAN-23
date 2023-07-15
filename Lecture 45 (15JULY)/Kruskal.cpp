// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h> 
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
        parent=vector<int> (n);
        sizeOfComp=vector<int> (n);
        for(int i=0;i<n;i++)
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

    bool merge(int a,int b)
    {
        int par_a=find_parent(a);
        int par_b=find_parent(b);

        if(par_a==par_b) return false; // already in same CC
        
        CC--;
        // CONVENTION par_a is that par whose size is small
        if(sizeOfComp[par_a] > sizeOfComp[par_b])
        {
            swap(par_a,par_b);
        }

        parent[par_a]=par_b;
        sizeOfComp[par_b]+=sizeOfComp[par_a];
        return true;

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

class Solution
{
	public:
	static bool comp(vector<int> &a,vector<int> &b)
	{
	    return a[2] < b[2];
	   // if(a[2] < b[2]) return true;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<(int)adj[i].size();j++)
            {
                int otherEnd=adj[i][j][0];
                int wt=adj[i][j][1];
                if(i < otherEnd)
                {
                    vector<int> edge={i,otherEnd,wt};
                    edges.push_back(edge);
                }
            }
        }
        
        sort(edges.begin(),edges.end(),comp);
        // for(int i=0;i<(int)edges.size();i++)
        // {
        //     cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
        // }
        // return 0;
        int ans=0;
        DSU dsu(V);
        for(int i=0;i<(int)edges.size();i++)
        {
            if(dsu.merge(edges[i][0],edges[i][1]))
            {
                ans+=edges[i][2];
            }
        }
        return ans;
    }
};

