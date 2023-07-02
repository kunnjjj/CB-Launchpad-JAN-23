// https://leetcode.com/problems/k-closest-points-to-origin/solutions/

class Solution {
public:
    int squareOfDist(vector<int> &point)
    {
        int x=point[0],y=point[1];
        return (x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++)
        {
            int squaredDist=squareOfDist(points[i]);
            if((int)pq.size() + 1 <=k)
            {
                pq.push({squaredDist,i});
            }
            else if(squaredDist < pq.top().first)
            {
                pq.pop();
                pq.push({squaredDist,i});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            int index=pq.top().second;
            ans.push_back(points[index]);
            pq.pop();
        }
        return ans;
    }
};