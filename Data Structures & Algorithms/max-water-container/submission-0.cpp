class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int mmax = 0;
        while (i < j){
            int rain = (j-i)*min(heights[j], heights[i]);
            mmax = max(mmax, rain);
            if (heights[j]<heights[i]) j--;
            else if (heights[j]>heights[i]) i++;
            else j--;
        }
        return mmax;
    }
};
