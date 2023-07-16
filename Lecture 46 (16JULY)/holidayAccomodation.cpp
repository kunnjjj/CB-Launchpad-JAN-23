#include<iostream> 
#include<map>
#include<vector>
// #include<map>
using namespace std; 

// map<int,vector<int>> graph;
vector<vector<pair<int,int>>> graph((int)1e5+1);
// map<int,bool> visited;
// map<int,vector<pair<int,int>>> graph;

vector<bool> visited((int)1e5+1);
// map<pair<int,int>,int> weight;
int N;
int dfs(int root,long long& ans)
{
    // cout<<"root: "<<root<<endl;
    int mySize=1;
    visited[root]=true;
    for(pair<int,int> edge:graph[root])
    {
        int wt=edge.second;
        int child=edge.first;

        if(visited[child]) continue;

        int sizeOfChild=dfs(child,ans);
        int remainingSize=N-sizeOfChild;

        ans+=2LL * min(sizeOfChild,remainingSize) * wt;

        mySize+=sizeOfChild;
    }
    return mySize;

}

void solve()
{
    graph.clear();
    for(int i=1;i<=N;i++)
    {
        // graph[i].clear();
        visited[i]=0;
    }
    // graph.clear();
    // visited.clear();
    // weight.clear();

    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int a,b; cin>>a>>b;
        int wt; cin>>wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});

        // weight[p]=wt;
    }

    int root=1;

    long long ans=0;
    dfs(root,ans);
    cout<<ans<<endl;
}

int main()
{
    int t; cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}