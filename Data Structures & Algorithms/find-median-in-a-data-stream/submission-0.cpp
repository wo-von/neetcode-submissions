class MedianFinder {
private:
    priority_queue<int> smallQ;
    priority_queue<int, vector<int>, std::greater<int>> largeQ;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smallQ.push(num);
        if (!largeQ.empty() && smallQ.top() > largeQ.top()){
            largeQ.push(smallQ.top());
            smallQ.pop();
        }
        if (smallQ.size() > largeQ.size() + 1){
            largeQ.push(smallQ.top()); smallQ.pop();
        }
        if (largeQ.size() > smallQ.size() + 1){
            smallQ.push(largeQ.top()); largeQ.pop();
        }
    }
    
    double findMedian() {
        if (largeQ.size() == smallQ.size()){
            return (largeQ.top() + smallQ.top()) / 2.0;
        } else if (largeQ.size() > smallQ.size()) {
            return largeQ.top();
        } else {
            return smallQ.top();
        }

    }
};
