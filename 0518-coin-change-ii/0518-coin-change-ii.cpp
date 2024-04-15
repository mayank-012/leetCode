class Solution {
public:

    int helper(int i,int sum, int amount, vector<int>& coins,vector<vector<int>> &dp)
    {
        if(i==coins.size())
        {
            if(sum==amount)return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take =0;
        if(sum+coins[i]<=amount) take = helper(i,sum+coins[i],amount,coins,dp);
        int nTake =  helper(i+1,sum,amount,coins,dp);
        return dp[i][sum]=take+nTake;
    }
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(50000,-1));
        return helper(0,0,amount,coins,dp);
    }
};