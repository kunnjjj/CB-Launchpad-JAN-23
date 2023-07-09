#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Graph
{
    // unordered_map<int, vector<pair<int,int>>> graph;
    vector<vector<int>> edgeList;
    int N;

public:
    Graph(int N)
    {
        this->N = N;
    }

    void addEdge(int x, int y, int edWt)
    {
        vector<int> edge = {x, y, edWt};
        edgeList.push_back(edge);
        // graph[x].push_back({y,edWt}); //{node,edWt}
        // graph[y].push_back({x,edWt});
    }

    void bellmanFord(int src)
    {
        int INF = 1e9;
        vector<int> dist(N + 1, INF);
        // cout<<"src: "<<src<<endl;

        dist[src] = 0;
        int V = N;
        for (int i = 1; i <= V - 1; i++)
        {
            for (vector<int> &edge : edgeList)
            {
                int a = edge[0], b = edge[1], wt = edge[2];
                if (dist[a] + wt < dist[b])
                    dist[b] = dist[a] + wt;
                if (dist[b] + wt < dist[a])
                    dist[a] = dist[b] + wt;
            }
        }

        for (vector<int> &edge : edgeList)
        {
            int a = edge[0], b = edge[1], wt = edge[2];
            if (dist[a] + wt < dist[b])
            {
                cout << "Neg wt cycle exists" << endl;
                return;
            }
            if (dist[b] + wt < dist[a])
            {
                cout << "Neg wt cycle exists" << endl;
                return;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            if (i == src)
                continue;

            if (dist[i] == INF)
                cout << "-1"
                     << " ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
};

void test_case()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);

    for (int i = 0; i < M; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        G.addEdge(x, y, wt);
    }

    int src;
    cin >> src;
    G.bellmanFord(src);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test_case();
    return 0;
}