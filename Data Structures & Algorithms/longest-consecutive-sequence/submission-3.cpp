class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_table(nums.begin(), nums.end());
        vector<int> beginnings = {};
        for (auto item: hash_table){
            if(!hash_table.contains(item - 1)){
                beginnings.push_back(item);
            }
        }
        int max_length = 0;
        for (int i = 0; i <beginnings.size(); i++){
            int length = 0;
            while (hash_table.contains(beginnings[i]++)){
                length++;
            }
            if (length > max_length) max_length = length;
        }
        return max_length;
    }
};
