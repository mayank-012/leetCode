class Solution {
public:
    
    int maximumPrimeDifference(vector<int>& nums) {
        set<int>s;
    s.insert(2);    
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(11);
    s.insert(13);
    s.insert(17);
    s.insert(19);
    s.insert(23);
    s.insert(29);
    s.insert(31);
    s.insert(37);
    s.insert(41);
    s.insert(43);
    s.insert(47);
    s.insert(53);
    s.insert(59);
    s.insert(61);
    s.insert(67);
    s.insert(71);
    s.insert(73);
    s.insert(79);
    s.insert(83);
    s.insert(89);
    s.insert(97);

        
        int l=0;
        int j=0;
        int cnt =0;
        for(int i=0;i< nums.size();i++)
        {
            if(s.find(nums[i])!=s.end() && cnt==0)
            {
                l=i;
                j=i;
                cnt++;
            }
            else if(s.find(nums[i])!=s.end() && cnt!=0)
            {
                j=i;
                cnt++;
            }
        }
        return j-l;
    }
};