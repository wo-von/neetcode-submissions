class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk; //index, height
        int area = 0;
        int n = heights.size();
        int start = 0;
        for (int i = 0; i < n; i++){
            start = i;
            while (!stk.empty() && stk.top().second > heights[i]){
                int height = stk.top().second;
                int index = stk.top().first;
                stk.pop();
                area = max(area, (i - index) * height);
                start = index;
            }
            stk.push({start, heights[i]});
        }
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            area = max(area, (n - top.first) * top.second);
        }
        return area;
    }
};
