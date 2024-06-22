class Solution {
public:
int helper(vector<int>& nums, int goal)
    {
        if (goal<0)
        {
            return 0;
        }
        int s = 0;
        int e = 0;
        int sum =0;
        int cnt =0;

        for(e =0; e<nums.size();e++)
        {
            if(nums[e]%2!=0)
            {
                sum +=1;
            }
            
            while(sum>goal && s < nums.size())
            {
                if(nums[s]%2!=0)
                {
                    sum -=1;
                }
                s++;
            }
            cnt+= e - s+1;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
         return helper(nums,k)-helper(nums,k-1);
    }
};