class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n), right(n);   // nearest strictly-smaller index on each side
        stack<int> st;

        // Pass 1: previous smaller to the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();     // reset

        // Pass 2: next smaller to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++)
            area = max(area, heights[i] * (right[i] - left[i] - 1));
        return area;

    }
};
