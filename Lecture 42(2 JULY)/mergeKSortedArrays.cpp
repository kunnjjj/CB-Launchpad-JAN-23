// https://hack.codingblocks.com/app/contests/1236/1087/problem
#include <iostream>
#include <queue>
using namespace std;

#define dataType pair<int,pair<int,int>>

int main()
{

    int k, m;
    cin >> k >> m;
    vector<vector<int>> A(k, vector<int>(m));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    }


    priority_queue<dataType,vector<dataType>,greater<dataType>> pq;

    for(int i=0;i<k;i++)
    {
        dataType toPush={A[i][0],{i,0}};
        pq.push(toPush);
    }

    vector<int> ans;
    while(!pq.empty())
    {
        dataType TOP_ELEMENT=pq.top();
        int val=TOP_ELEMENT.first;
        int row=TOP_ELEMENT.second.first;
        int col=TOP_ELEMENT.second.second;
        ans.push_back(val);
        pq.pop();
        if(col+1<(int)A[row].size())
        {
            dataType toPush={A[row][col+1],{row,col+1}};
            pq.push(toPush);
        }
    }

    for(int x:ans) cout<<x<<" ";

    return 0;
}