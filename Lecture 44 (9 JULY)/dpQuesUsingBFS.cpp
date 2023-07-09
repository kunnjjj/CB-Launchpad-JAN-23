// https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Graph
{
    unordered_map<int, vector<int>> graph;
    int N;
    public:

    Graph(int N)
    {
        this->N=N;
    }

    void addEdge(int x,int y) // adds directed edge from x->y
    {
        graph[x].push_back(y);
    }


    int bfsWithDist(int src,int dest)
    {
        queue<int> q;
        int INF=1e9;
        vector<int> dist(N+1,INF);
        q.push(src);
        dist[src]=0;
        vector<int> parent(N+1,-1);
        parent[src]=src;
        // OBSERVATION: if dist[node]==INF, it means it has not been visited yet
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            // cout<<"node: "<<frontNode<<", dist: "<<dist[frontNode]<<endl;
            for(int nbr:graph[frontNode])
            {
                // if(visited[nbr]==false)
                if(dist[nbr]==INF)
                {
                    // visited[nbr]=true;
                    q.push(nbr);
                    dist[nbr]=1+dist[frontNode];
                    parent[nbr]=frontNode;
                }
            } 
        }

        int me=dest;
        while(me!=1)
        {
            cout<<"me: "<<me<<endl;
            me=parent[me];
        }
        
        return dist[dest];
    }

};

class Solution{
    
	public:
	int minSteps(int N) 
	{
	    Graph G(N);
	    for(int i=2;i<=N;i++)
	    {
	       if(i%2==0)
	       {
	           G.addEdge(i/2,i);
	       }
	       if(i%3==0)
	       {
	           G.addEdge(i/3,i);
	       }
	       G.addEdge(i-1,i);
	    }
	        
	       
	   int src=1,dest=N;
	    return G.bfsWithDist(src,dest);

	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends