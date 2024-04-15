class Solution {
public:

        
    bool helper(int i,int s, int sum, vector<int>& nums,vector<vector<int>> &dp)
    {
            if(i==nums.size())
            {
                if(sum%2==0 && s==sum/2)return 1;
                return 0;
            }
            if(dp[i][s]!=-1)return dp[i][s];

            return dp[i][s]=helper(i+1,s+nums[i],sum,nums,dp) || helper(i+1,s,sum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (20000,-1));
        int sum=0;
        for(int i =0; i< nums.size();i++)
        {
            sum+=nums[i];
        }

        return helper(0,0,sum,nums,dp);
    }
};