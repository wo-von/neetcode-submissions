class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < 
            accumulate(cost.begin(), cost.end(), 0)) {
                return -1;
            }
        int total = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++){
            total += (gas[i] - cost[i]);
            if (total < 0) {
                index = i + 1;
                total = 0;
            }
        }
        return index;
    }
};
