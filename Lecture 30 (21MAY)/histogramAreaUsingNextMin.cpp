// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Pair
{
    public:
    int value;
    int idx;
    Pair(int value,int idx)
    {
        this->value=value;
        this->idx=idx;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        
        int n=H.size();
        vector<int> right(n);
        stack<Pair> s;


        for(int i=0;i<n;i++)
        {
            Pair cur(H[i],i);
            while(!s.empty() && s.top().value > cur.value)
            {
                int idxJiskeLiyeAnsMila=s.top().idx;
                right[idxJiskeLiyeAnsMila]=cur.idx;
                s.pop();
            }
            s.push(cur);
        }

        while(!s.empty())
        {
            int idxJissaiHatana=s.top().idx;
            right[idxJissaiHatana]=n;
            s.pop();
        }


        vector<int> left(n);
        for(int i=n-1;i>=0;i--)
        {
            Pair cur(H[i],i);
            while(!s.empty() && s.top().value > cur.value)
            {
                int idxJiskaAnsMila=s.top().idx;
                left[idxJiskaAnsMila]=cur.idx;
                s.pop();
            }
            s.push(cur);
        }

        while(!s.empty())
        {
            int idxJissaiHatana=s.top().idx;
            left[idxJissaiHatana]=-1;
            s.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int height=H[i];
            int width=right[i]-left[i]-1;
            ans=max(ans,height*width);
        }
        return ans;
    }
};