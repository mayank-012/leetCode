class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(),p.end());

        int s = 0;
        int e = p.size()-1;
        int cnt =0;
        while(s<=e)
        {
            if(p[s]+p[e]<=l){
                cnt++;
                s++;
                e--;
            }
            else
            {
                cnt++;
                e--;
            }
        }
        return cnt;

    }
};