// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size(),m=text2.size();
        vector<vector<int>> LCS(n+1,vector<int> (m+1));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    LCS[i][j]=1+LCS[i+1][j+1];
                }
                else
                {
                    LCS[i][j]=max(LCS[i+1][j],LCS[i][j+1]);
                }
            }
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<LCS[i][j]<<" ";
            }
            cout<<endl;
        }

        int i=0,j=0;
        string ans="";
        while(i<n && j<m)
        {
            if(text1[i]==text2[j])
            {
                ans+=text1[i];
                i++;
                j++;
            }
            else if(LCS[i+1][j]>=LCS[i][j+1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        cout<<ans<<endl;

        return LCS[0][0];
    }
};