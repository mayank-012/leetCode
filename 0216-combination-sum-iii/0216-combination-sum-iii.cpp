class Solution {
public:
void helper(int indx,int target, vector<vector<int>> & ans,vector<int> & temp,vector<int>& candidates,int k)
    {
        if(target==0 && k==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=indx;i<candidates.size();i++)
        {
            if(i>indx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            k--;
            helper(i+1,target-candidates[i],ans,temp,candidates,k);
            temp.pop_back();
            k++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
         vector<int> temp;
         helper(0,n,ans,temp,candidates,k);
         return ans;
    }
};