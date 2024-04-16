class Solution {
public:

     int helper(int i, int j,vector<vector<int>>& oG,vector<vector<int>> &dp,int m, int n)
    {
            if(i >= m || j >= n)
            {
                return 1e7;
            }

            if(i == m-1)
            {
                return oG[i][j];
            }
            if(dp[i][j]!=-1)return dp[i][j];
            int p1 = oG[i][j] + helper(i+1,j,oG,dp,m,n);
            
            int p2 = oG[i][j]+helper(i+1,j+1,oG,dp,m,n);

            return dp[i][j]=min(p1,p2);

    }
    int minimumTotal(vector<vector<int>>& oG) {
        int m = oG.size();
        int n = oG[m-1].size();
        vector<vector<int>> dp(200,vector<int> (200,-1));
        return helper(0,0,oG,dp,m,n);
    }
};