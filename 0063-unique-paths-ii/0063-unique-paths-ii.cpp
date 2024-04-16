class Solution {
public:
    int helper(int i, int j,vector<vector<int>>& oG,vector<vector<int>> &dp,int m, int n)
    {
            if(i >= m || j >= n)
            {
                return 0;
            }
            if(oG[i][j]==1)return 0;

            if(i == m-1 && j ==n-1)
            {
                return 1;
            }
            if(dp[i][j]!=-1)return dp[i][j];
            int p1 = helper(i+1,j,oG,dp,m,n);
            int p2 = helper(i,j+1,oG,dp,m,n);

            return dp[i][j]=p1+p2;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        int m = oG.size();
        int n = oG[0].size();
        vector<vector<int>> dp(100,vector<int> (100,-1));
        return helper(0,0,oG,dp,m,n);
    }
};