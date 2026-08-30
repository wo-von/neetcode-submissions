class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) count[t - 'A']++;

        priority_queue<int> pq;                 // max-heap of remaining counts
        for (int c : count) if (c) pq.push(c);

        queue<pair<int,int>> cooling;           // {readyTime, remainingCount}, FIFO

        int time = 0;
        while (!pq.empty() || !cooling.empty()) {
            time++;                             // we are now executing slot `time`

            while (!cooling.empty() && cooling.front().first <= time) {
                pq.push(cooling.front().second);
                cooling.pop();
            }

            if (!pq.empty()) {
                int c = pq.top() - 1; pq.pop();
                if (c > 0) cooling.push({time + n + 1, c});
            }
            // else: nothing available -> idle tick, time already advanced
        }
        return time;
    }
};