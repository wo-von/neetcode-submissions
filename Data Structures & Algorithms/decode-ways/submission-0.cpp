class Solution {
unordered_map<int, int>table;
public:
    
    int numDecodings(string s) {
        table.clear();
        table[s.size()] = 1;
        return dfs(s, 0);
    }
    int dfs(string s, int index){
        if (table.count(index)){
            return table[index];
        }
        if (s[index] == '0') {
            return 0;
        }
        int res = dfs(s, index+1);
        if ((index + 1 < s.size()) &&
                (s[index] == '1' || (s[index] == '2' && s[index+1] < '7')))
            res += dfs(s, index + 2);
        table[index] = res;
        return res;
    }
};
