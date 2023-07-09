#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph
{
    unordered_map<int, vector<int>> graph;
    int N;
    public:

    Graph(int N)
    {
        this->N=N;
    }

    void addEdge(int x,int y)
    {
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    void bfs(int src)
    {
        queue<int> q;
        vector<bool> visited(N+1);
        q.push(src);
        visited[src]=true;


        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();

            cout<<frontNode<<" ";
            for(int nbr:graph[frontNode])
            {
                if(visited[nbr]==false)
                {
                    visited[nbr]=true;
                    q.push(nbr);
                }
            } 
        }
    }

    void bfsWithDist(int src)
    {
        queue<int> q;
        // vector<bool> visited(N+1);
        int INF=1e9;
        vector<int> dist(N+1,INF);
        q.push(src);
        // visited[src]=true;
        dist[src]=0;
        // OBSERVATION: if dist[node]==INF, it means it has not been visited yet
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();

            cout<<"node: "<<frontNode<<", dist: "<<dist[frontNode]<<endl;
            for(int nbr:graph[frontNode])
            {
                // if(visited[nbr]==false)
                if(dist[nbr]==INF)
                {
                    // visited[nbr]=true;
                    q.push(nbr);
                    dist[nbr]=1+dist[frontNode];
                }
            } 
        }
    }

};

int main()
{
    int N,M; cin>>N>>M;
    Graph G(N);  
    // nodeLabels from [1.....N] 

    for(int i=0;i<M;i++)
    {
        int xi,yi; cin>>xi>>yi;
        G.addEdge(xi,yi);
    }   

    int src=1;
    G.bfsWithDist(src);

    return 0;
}