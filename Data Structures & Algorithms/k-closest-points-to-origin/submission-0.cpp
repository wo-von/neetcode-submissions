class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distancef = [](const vector<int>& p) {
            return sqrt((double)(p[0]*p[0] + p[1]*p[1]));
        };
        vector<double>distance;
        distance.reserve(points.size());
        for (auto p: points){
            distance.push_back(distancef(p));
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> dheap;
        for (int i = 0; i < (int)points.size(); i++){
            dheap.push({distance[i], i});
            if (dheap.size() > k)
                dheap.pop();
        }
        vector<vector<int>>res;
        res.reserve(k);
        for(int i = 0; i < k; i++){
            res.push_back(points[dheap.top().second]); dheap.pop();
        }
        return res;
    }
};
