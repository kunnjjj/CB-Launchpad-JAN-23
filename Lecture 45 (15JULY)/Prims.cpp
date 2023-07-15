// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	unordered_map<int,vector<pair<int,int>>> graph;
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
                    graph[i].push_back({otherEnd,wt});
                    graph[otherEnd].push_back({i,wt});
                    // vector<int> edge={i,otherEnd,wt};
                    // edges.push_back(edge);
                }
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<bool> visited(V,false);
        int anyNode=0; // V-1
        
        
        visited[anyNode]=true;
        for(pair<int,int> edge: graph[anyNode])
        {
            pq.push({edge.second,edge.first});
        }
        
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int> bestEdge=pq.top();
            pq.pop();
            int node=bestEdge.second,wt=bestEdge.first;
            
            if(visited[node]==true) continue;
            
            // cout<<"wt: "<<wt<<" ,node: "<<node<<endl;
            visited[node]=true;
            ans+=wt;
            for(pair<int,int> nbrEdge:graph[node])
            {
                if(visited[nbrEdge.first]==false)
                {
                    pq.push({nbrEdge.second,nbrEdge.first});
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends