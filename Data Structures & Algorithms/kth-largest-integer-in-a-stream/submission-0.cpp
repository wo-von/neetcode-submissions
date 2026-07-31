class KthLargest {
private:
    priority_queue<int, vector<int>, std::greater<int>>heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int num: nums){
            heap.push(num);
            if (heap.size() > k){
                heap.pop();
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > this->k)
            heap.pop();
        return heap.top();
    }
};
