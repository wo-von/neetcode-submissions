class Solution {
private:
    unordered_map<int, bool>memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        memo[s.length()] = true;
        return dfs(s, wordDict, 0);
    }
    bool dfs(const string& s, vector<string>& dict, int index){
        if (memo.find(index) != memo.end())
            return memo[index];
        for (const string word: dict){
            if ((index + word.size() <= s.size()) && 
                (s.substr(index, word.size()) == word )){
                    if(dfs(s, dict, index + word.size())){
                        memo[index] = true;
                        return true;
                    }
                }
        }
        memo[index] = false;
        return false;
    }
};
