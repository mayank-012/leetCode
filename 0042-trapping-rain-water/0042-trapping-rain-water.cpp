class Solution {
public:
    int trap(vector<int>& arr) {
    
    int n = arr.size();
    if (n <= 2) 
    {
        return 0; 
    }

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = arr[0];
    for (int i = 1; i < n; ++i) 
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) 
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int trappedWater = 0;
    for (int i = 1; i < n - 1; ++i) 
    {
        trappedWater += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return trappedWater;
    }
};