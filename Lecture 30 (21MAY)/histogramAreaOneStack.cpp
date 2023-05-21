// https://leetcode.com/problems/largest-rectangle-in-histogram/
// class Pair
// {
//     public:
//     int value;
//     int idx;
//     Pair(int value,int idx)
//     {
//         this->value=value;
//         this->idx=idx;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        
        int n=H.size();
        // stack<Pair> s;
        stack<int> s1; 
        int ans=0;
        for(int i=0;i<n;i++)
        {
            Pair cur(H[i],i);
            // while(!s.empty() && s.top().value > cur.value)
            while(!s1.empty() && H[s1.top()] > H[i])
            {
                // int heightOfPopped=s.top().value;
                int heightOfPopped=H[s1.top()];

                // int right=cur.idx;
                int right=i;
                s1.pop();
                // int left=(s.empty()?-1:s.top().idx);i
                int left=(s1.empty()?-1:s1.top());
                ans=max(ans,heightOfPopped * (right-left-1));
            }
            // s.push(cur);
            s1.push(i);
        }
  
        // while(!s.empty())
        while(!s1.empty())
        {
            // int Height=s.top().value;
            int Height=H[s1.top()];
            int right=n;
            s1.pop();
            // int left=(s.empty()?-1:s.top().idx);
            int left=(s1.empty()?-1:s1.top());
            int Width=right-left-1;
            ans=max(ans,Width*Height);
        }
        return ans;
    }
};