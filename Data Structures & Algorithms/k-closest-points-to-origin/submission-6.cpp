class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto order_func = [](pair<int, vector<int>>a,
            pair<int, vector<int>>b) {return a.first > b.first;};
        priority_queue<pair<int, vector<int>>, vector<pair<int, 
            vector<int>>>, decltype(order_func)> st;
        for (auto& p: points){
            int distance = pow(p[0], 2) + pow(p[1], 2);
            st.push({distance, p});
        }
        vector<vector<int>>res;
        for (int i = 0; i < k; i++){
            res.push_back(st.top().second);
            st.pop();
        }
        return res;
    }
};
