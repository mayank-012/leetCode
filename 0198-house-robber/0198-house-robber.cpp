class Solution {
public:

    int helper(int i,vector<int>& nums, vector<int> & dp)
    {
        if(i==nums.size()-1)return nums[i];

        if(i>nums.size()-1)return 0;

        if(dp[i]!=-1)return dp[i];

        int pick = helper(i+2,nums,dp)+nums[i];

        int notPick = helper(i+1,nums,dp);
        return dp[i]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};