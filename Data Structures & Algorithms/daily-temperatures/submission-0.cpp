class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++){
            int temp = temperatures[i];
            
            while (!stk.empty() && temp > stk.top().first){
                auto curr = stk.top(); stk.pop();
                result[curr.second] = i - curr.second;
                
            }
            stk.push({temp, i});
        }
        return result;
    }    
};
