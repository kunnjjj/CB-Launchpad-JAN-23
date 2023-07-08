// https://hack.codingblocks.com/app/contests/3616/1103/problem
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
        this->N = N;
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

    void dfs(int node, vector<bool> &visited,int &sizeOfComp)
    {
        // cout << node << " ";
        sizeOfComp++;
        visited[node] = true;

        for (int nbr : graph[node])
        {
            if (visited[nbr] == false)
            {
                dfs(nbr, visited,sizeOfComp);
            }
        }
    }

    long long religiousPeople(int A,int B)
    {
        vector<bool> visited(N + 1);
        long long ans=0;
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == false)
            {
                int sizeOfComp=0;
                dfs(i, visited,sizeOfComp);
                // either make all temples, or 1 temple and (size-1 roads)

                ans+=min(sizeOfComp*(long long)A,A + (sizeOfComp-1)*(long long)B);
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int A,B; cin>>A>>B;
        // assuming nodeLabel are from [1...N]

        Graph G(N);

        for (int i = 0; i < M; i++)
        {
            int Xi, Yi;
            cin >> Xi >> Yi;
            G.addEdge(Xi, Yi);
        }

        cout << G.religiousPeople(A,B) << endl;
    }

    return 0;
}