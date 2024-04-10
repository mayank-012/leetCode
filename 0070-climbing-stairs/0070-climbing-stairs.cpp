class Solution {
public:
    
    int helper(int n,vector<int> &dp)
    {
        if (n == 1) 
        {
            return 1;
        }
        if (n == 0) 
        {
            return 1;
        }
        if(dp[n]==0){
        dp[n]=helper(n-1,dp)+helper(n-2,dp);
        return dp[n];
        }
        else{
            return dp[n];
        }
    }

    int climbStairs(int n) {
   
    vector<int> dp(n + 1, 0);
    dp[0]=1;
    dp[1]=1;
    
    
    return helper(n,dp);

    
    }
};