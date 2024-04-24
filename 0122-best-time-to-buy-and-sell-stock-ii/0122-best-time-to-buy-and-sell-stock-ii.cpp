class Solution {
public:
int dp[30000][3];
    int helper(int i,int c,vector<int>& prices)
    {
        if(i==prices.size())
        return 0;
        if(dp[i][c]!=-1)return dp[i][c];
        if(c==0)
        {
            return dp[i][c]=max(-prices[i]+helper(i+1,1,prices),helper(i+1,0,prices));
        }
        else
        { 
            return dp[i][c]=max(prices[i]+helper(i+1,0,prices),helper(i+1,1,prices));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,prices);
    }
};