// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        
        unordered_map<int,int> isPresent;
        // key= A[i]
        // value= where A[i] is present i.e index(i)

        for(int i=0;i<(int)A.size();i++)
        {
            int remainingSum=target-A[i];
            auto it=isPresent.find(remainingSum);

            if(it!=isPresent.end())
            {
                vector<int> ans(2);
                ans[0]=it->second;
                ans[1]=i;
                return ans;
            }
            isPresent[A[i]]=i;
        }

        return {};
    }
};