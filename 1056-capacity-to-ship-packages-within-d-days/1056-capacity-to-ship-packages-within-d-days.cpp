class Solution {
public:
    int findDays(vector<int>& w, int mid)
    {
        int days = 1;
        int sum =0;
        for(int i =0; i<w.size();i++)
        {
            sum+=w[i];
            if(sum>mid)
            {
                days++;
                sum = w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int s = *max_element(w.begin(),w.end());
        int e = 0;
        int ans = 0;
        for(int i =0; i< w.size();i++)
        {
            e+=w[i];
        }

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            int days = findDays(w,mid);
            
            if(days<d)
            {
                e=mid-1;
                ans = mid;
            }
            else if(days>d)
            {
                s = mid+1;
            }
            else{
                e=mid-1;
                ans = mid;
            }
        }  
        return ans;  
    }
};