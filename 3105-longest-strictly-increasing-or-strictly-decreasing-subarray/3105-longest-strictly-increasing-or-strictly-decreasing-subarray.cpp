class Solution {
public:
    int check(vector<int> a)
    {
        bool c=1;
        for(int i =1; i< a.size();i++)
        {
            if(a[i]>a[i-1])
            {
                continue;
            }
            else{
                c=0;
            }
        }
        if(c)
        return a.size();
        else
            return 0;
    }
    int check2(vector<int> a)
    {
        bool c=1;
        for(int i =1; i< a.size();i++)
        {
            if(a[i]<a[i-1])
            {
                continue;
            }
            else{
                c=0;
            }
        }
        if(c)
        return a.size();
        else
            return 0;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int l1=0;
        int l2 =0;
        
        for(int i =0; i< nums.size();i++)
        {
            for(int j =i; j<nums.size();j++)
            {
                            vector<int> temp;

                for(int k =i; k<=j;k++){
                    temp.push_back(nums[k]);
                }
                l1 =max(l1,check(temp));
            }
        }
        for(int i =0; i< nums.size();i++)
        {
            for(int j =i; j<nums.size();j++)
            {
                            vector<int> temp;

                for(int k =i; k<=j;k++){
                    temp.push_back(nums[k]);
                }
                l2 =max(l2,check2(temp));
            }
        }
        
       
        
        return max(l1,l2);
    }
};