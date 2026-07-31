class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26, 0);
        for (char t: tasks){
            count[t - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxf = count.back();
        int idle_time = (maxf - 1) * n;
        for (int i = 24; i >=0; i--) {
                idle_time -= min(maxf - 1, count[i]);
        }
        return max(0, idle_time) + tasks.size();
    }
};
