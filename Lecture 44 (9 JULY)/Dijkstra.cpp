// https://hack.codingblocks.com/app/contests/3616/292/problem
#include<iostream> 
#include<unordered_map>
#include<vector>
#include<set>
using namespace std; 

class Graph
{
    unordered_map<int, vector<pair<int,int>>> graph;
    int N;
    public:

    Graph(int N)
    {
        this->N=N;
    }

    void addEdge(int x,int y,int edWt)
    {
        graph[x].push_back({y,edWt}); //{node,edWt}
        graph[y].push_back({x,edWt});
    }

    void dijkstra(int src)
    {
        int INF=1e9;
        vector<int> dist(N+1,INF);

        set<pair<int,int>> s;
        // {distFromSrc,nodeLabel}

        dist[src]=0;
        s.insert({dist[src],src});

        while(!s.empty())
        {
            pair<int,int> bestNode=*s.begin();
            s.erase(s.begin());
            int from=bestNode.second;
            for(pair<int,int> nbr:graph[from])
            {
                int edWt=nbr.second , to=nbr.first;
                // try to relax
                if(dist[from] + edWt < dist[to])
                {
                    auto it=s.find({dist[to],to}); // if old entry is present then remove it
                    if(it!=s.end())
                    {
                        s.erase(it);
                    }

                    dist[to]=dist[from] + edWt; // insert new entry
                    s.insert({dist[to],to});
                }
            }
        }

        for(int i=1;i<=N;i++)
        {
            if(i==src) continue;

            if(dist[i]==INF) cout<<"-1"<<" ";
            else cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
};


void test_case()
{
    int N,M; cin>>N>>M;
    Graph G(N);


    for(int i=0;i<M;i++)
    {
        int x,y,wt; cin>>x>>y>>wt;
        G.addEdge(x,y,wt);
    }

    int src; cin>>src;
    G.dijkstra(src);

}

int main()
{
    int t; cin>>t;
    while(t--) test_case();
    return 0;
}