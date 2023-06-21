// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& loot) {
        int n=loot.size();
        // vector<vector<int>> AMT(n+1,vector<int> (2));

        int dpOld0=0,dpOld1=0;
        for(int i=n-1;i>=0;i--)
        {
            // AMT[i][0], what is max loot I can get if I do not rob the ith house
            // AMT[i][0]=max(AMT[i+1][0],AMT[i+1][1]);
            int dpNow0=max(dpOld0,dpOld1);


            // AMT[i][1], what is max loot I can get if I do rob the ith house
            // AMT[i][1]=loot[i] + AMT[i+1][0];
            int dpNow1=loot[i] + dpOld0;
            dpOld0=dpNow0;
            dpOld1=dpNow1;
        }

        return max(dpOld0,dpOld1);
    }
};

class Solution {
public:
    int rob(vector<int>& loot) {
        int n=loot.size();
        vector<vector<int>> AMT(n+1,vector<int> (2));

        for(int i=n-1;i>=0;i--)
        {
            // AMT[i][0], what is max loot I can get if I do not rob the ith house
            AMT[i][0]=max(AMT[i+1][0],AMT[i+1][1]);


            // AMT[i][1], what is max loot I can get if I do rob the ith house
            AMT[i][1]=loot[i] + AMT[i+1][0];
        }

        return max(AMT[0][0],AMT[0][1]);
    }
};