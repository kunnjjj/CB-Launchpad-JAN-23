#include<iostream> 
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std; 

unordered_map<int,vector<int>> graph;
int main()
{
    int n; cin>>n;
    // labels [1...n]

    int m; cin>>m;

    
    vector<int> indegree(n+1);
    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        graph[x].push_back(y); // DIRECTED EDGE
        indegree[y]++;
    }



    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    if(q.empty()) 
    {
        cout<<"NO ORDER EXIST"<<endl;
        return 0;
    }

    while(!q.empty())
    {
        int frontNode=q.front();
        cout<<frontNode<<" ";
        q.pop();
        for(int nbr:graph[frontNode])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0) q.push(nbr);
        }
    }


    return 0;
}