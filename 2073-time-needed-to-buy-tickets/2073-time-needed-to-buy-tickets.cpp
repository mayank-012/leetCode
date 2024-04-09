class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        // queue <int> q;
        // for(int i =0; i< t.size();i++){
        //     q.push(t[i]);
        // }
        int i =0;
        int ans=0;
        while(t[k]!=0)
        {
            if(i==t.size())
            {
                i=0;
            }
           if(t[i]==0){
                i++;
           }
           else{
            t[i]--;
            i++;
            ans++;
           }
        }
    return ans;
    }
};