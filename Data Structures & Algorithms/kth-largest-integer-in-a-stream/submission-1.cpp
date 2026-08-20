class KthLargest {
private:
    int k_;
    auto static constexpr cmp = [](int a, int b){return a>b;};
    priority_queue<int, vector<int>, decltype(cmp)> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto num: nums){
            pq.push(num);
            if (pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_) {pq.pop();}
        return pq.top();
    }
};
