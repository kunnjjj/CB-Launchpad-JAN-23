#include <iostream>
#include <vector>
#include <unordered_map>
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

    void addEdge(int x, int y, bool isDirected = false)
    {
        graph[x].push_back(y);
        if (isDirected == false)
        {
            graph[y].push_back(x);
        }
    }
    // void preorder(node* root)
    // {
    //     cout<<root->data<<" ";
    //     preorder(root->left);
    //     preorder(root->right);
    // }

    void dfs(int node,vector<bool> &visited) 
    {
        cout<<node<<" ";
        visited[node]=true;

        for(int nbr:graph[node])
        {
            if(visited[nbr]==false)
            {
                dfs(nbr,visited);
            }
        }
    }

    int numberOfCC()
    {
        vector<bool> visited(N+1);
        int components=0;
        for(int i=1;i<=N;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited);
                cout<<endl;
                components++;
            }
        }
        return components;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    // assuming nodeLabel are from [1...N] 

    Graph G(N);

    for (int i = 0; i < M; i++)
    {
        int Xi, Yi;
        cin >> Xi >> Yi;
        G.addEdge(Xi, Yi);
    }


    cout<<G.numberOfCC()<<endl;


    return 0;
}