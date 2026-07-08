class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto s: stones)
            pq.push(s);
        while(pq.size() >= 2){
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            if (t1 == t2)
                continue;
            pq.push(t1 - t2);
        }
        if (pq.size() == 1)
            return pq.top();
        else {
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            return t1 - t2;
        }

    }
};
