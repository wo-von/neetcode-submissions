class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        for (int i = 0; i < (int)heights.size(); i++){
            int height = heights[i];
            area = max(height, area);
            for (int j = i + 1; (int)j < heights.size(); j++){
                height = min(height, heights[j]);
                area = max(height * (j - i + 1), area);
            }
        }
        return area;
    }
};
