class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(s<=e)
        {
            int mid = s +(e-s)/2;
            int sum  =0;
            for(int i = 0;i<nums.size();i++)
            {
                sum +=  ceil((double)nums[i]/(double)mid);
            }

            if(sum==t)
            {
                ans = mid;
                e = mid - 1;
            }
            else if(sum>t)
            {
                s = mid+1;
            }
            else{
                ans= mid;
                e = mid-1;
            }
        }
        return ans;

    }
};