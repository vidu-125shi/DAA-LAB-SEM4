#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0, j = height.size()-1;
        int maxWater = 0;
        while(j>i)    
        {
            maxWater = max(min(height[i], height[j]) * (j-i), maxWater);
            (height[i] <height[j])?i++:j--;
        }
        return maxWater;
    }
};
