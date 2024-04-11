class Solution {
public:
    int helper(int i,vector<int>& nums, vector<int> & dp)
    {
        if(i==nums.size()-1 )return nums[i];

        if(i>nums.size()-1)return 0;

        if(dp[i]!=-1)return dp[i];


        
        int pick = helper(i+2,nums,dp)+nums[i];

       
        int notPick = helper(i+1,nums,dp);
        return dp[i]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size(),-1);

        int temp =nums[0];
        nums[0]=0;
        int t1 = helper(0,nums,dp);

        vector<int> dp2(nums.size(),-1);

        nums[0]=temp;
        nums[nums.size()-1]=0;
        int t2 = helper(0,nums,dp2);

        return max(t1,t2);

    }
};