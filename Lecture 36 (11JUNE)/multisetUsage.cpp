// sliding window max leetcode
class Solution {
public:
    void find_and_erase(int x,multiset<int> &ms)
    {
        auto it=ms.find(x);
        if(it!=ms.end())
        {
            ms.erase(it);
        }
    }
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        int n=A.size();

        multiset<int> ms;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ms.insert(A[i]);

            if(i>=k)
            {
                find_and_erase(A[i-k],ms);
            }
            if(i>=k-1)
            {
                ans.push_back(*ms.rbegin());
            }
        }
        return ans;
    }
};