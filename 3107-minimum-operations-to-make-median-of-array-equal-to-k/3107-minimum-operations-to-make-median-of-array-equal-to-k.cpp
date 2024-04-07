class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long ans =0;
        if(nums[n/2]==k)
        {
            return 0;
        }
        
        else{
            if(nums[n/2]<k)
            {
                ans+=k-nums[n/2];
                for(int i =n/2 +1;i<nums.size();i++)
                {
                    if(nums[i]<k)
                    {
                        ans+=k-nums[i];
                    }
                    else{
                        break;
                    }
                }
            }
            if(nums[n/2]>k)
            {
                ans+=nums[n/2]-k;
                for(int i =n/2-1;i>=0;i--)
                {
                    if(nums[i]>k)
                    {
                        ans+=nums[i]-k;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};