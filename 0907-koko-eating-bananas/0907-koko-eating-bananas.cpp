class Solution {
public:
long long int findHour(vector<int>& p, int mid)
{
    long long int hour = 0;
    for(int i = 0; i< p.size();i++)
    {
        hour += ceil((double)p[i]/(double)mid);
    }
    return hour;
}
    int minEatingSpeed(vector<int>& p, int h) {
        int s = 1;
        int e = *max_element(p.begin(),p.end());
        int ans = 0;
        while(s<=e)
        {
            int mid = s+(e-s)/2;

            long long int hour = findHour(p,mid);

            if(hour<=h)
            {
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }

        }
        return ans;
        
    }
};