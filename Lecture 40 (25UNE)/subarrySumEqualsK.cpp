// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& A, int target) {
        unordered_map<int,int> cntOfPrefSum;
        int ans=0;
        cntOfPrefSum[0]=1;
        int prefSum=0;
        for(int i=0;i<(int)A.size();i++)
        {   
            prefSum+=A[i];
            unordered_map<int,int>::iterator rameshIterator=cntOfPrefSum.find(prefSum-target);
            if(rameshIterator!=cntOfPrefSum.end())
            {
                ans+=(rameshIterator->second);
            }
            cntOfPrefSum[prefSum]++;
        }
        return ans;
    }
};