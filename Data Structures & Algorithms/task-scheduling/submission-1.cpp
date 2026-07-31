class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26, 0); // which tasks and how many
        for (auto t: tasks)
            count[t - 'A']++;
        vector<pair<int, int>> arr; // task id and its quantity
        for (int i  = 0; i < 26; i++){
            if (count[i])
                arr.push_back({count[i], i});
        }
        int time = 0; // total time to return
        vector<int> processed; // to keep track of when sth has been processed
        while(!arr.empty()) {
            int maxi = -1; // which task has highest priority
            for (int i = 0; i < arr.size(); i++){
                bool ok = true;
                for (int j = max(0, time - n); j < time; j++){
                    if (j < processed.size() && processed[j] == arr[i].second){
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue; //task needs cool down find another one
                if (maxi == -1 || arr[maxi].first < arr[i].first){
                    maxi = i;// found a new task
                }
            }
            time++;
            int curr = -1;
            if (maxi != -1) { // found a task that can be run
                curr = arr[maxi].second;
                arr[maxi].first--;
                if (arr[maxi].first == 0){ // remove if nothing left
                    arr.erase(arr.begin() + maxi);
                }
            }
            processed.push_back(curr); // -1 if nothing processed
        }
        return time;
    }
};
