class Solution {
public:
    int helper(int i, int s,vector<int>& coins, int amount,vector<vector<int>> &dp)
    {   
        if(s==amount)return 0;
        if(s>amount)return 100000;
        if(i==coins.size())return 100000;
        if(coins[i]>amount)return 100000;

        
        if(dp[i][s]!=-1)return dp[i][s];
        int l = 1+helper(i,s+coins[i],coins,amount,dp);
        int r = helper(i+1,s,coins,amount,dp);

        return dp[i][s]=min(l,r);

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int>(amount,-1));
        if(helper(0,0,coins,amount,dp)>10000)return -1;
        return helper(0,0,coins,amount,dp);
    }
};