class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26, 0);
        for (auto t: tasks){
            count[t - 'A']++;
        }
        priority_queue<int>heap;
        for (auto c: count){
            if(c>0) heap.push(c);
        }
        int time = 0;
        queue<pair<int, int>>q; // to hold waiting processes {quantity, time}
        while(!q.empty() || !heap.empty()){
            time++;
            if (heap.empty()){
                // we jump if heap empty, nothing to do but wait
                time = q.front().second;
            } else {
                int cnt = heap.top() - 1; heap.pop();
                if (cnt > 0){
                    q.push({cnt, time + n});
                }
            }
            if (!q.empty() && q.front().second == time){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
