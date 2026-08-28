class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto order_func = [](pair<int, vector<int>>& a,
            pair<int, vector<int>>& b) {return a.first < b.first;};
        priority_queue<pair<int, vector<int>>, vector<pair<int, 
            vector<int>>>, decltype(order_func)> st;
        for (auto& p: points){
            int distance = p[0] * p[0] + p[1] * p[1];
            st.push({distance, p});
            if (st.size() > k){
                st.pop();
            }
        }
        vector<vector<int>>res;
        while(!st.empty()){
            res.push_back(st.top().second);
            st.pop();
        }
        return res;
    }
};
