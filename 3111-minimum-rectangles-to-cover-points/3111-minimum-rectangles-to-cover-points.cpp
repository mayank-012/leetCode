class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int> x;
        for(int i =0; i< points.size();i++)
        {
            x.push_back(points[i][0]);
        }
        sort(x.begin(),x.end());
        
        int i =0;
        int cnt=1;
        for(int j =0; j<x.size();j++)
        {
            if(x[j]-x[i]<=w)
            {
                continue;
            }
            else{
                i=j;
                cnt++;
            }
        }
        return cnt;
    }
};