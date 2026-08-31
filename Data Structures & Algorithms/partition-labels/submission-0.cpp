class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        vector<int> res;
        int i = 0;
        while (i < n) {
            int start = i;
            string open;
            while (i < n) {
                char c = s[i];
                if (--mp[c] == 0) {                 // this char is now finished
                    auto pos = open.find(c);
                    if (pos != string::npos) open.erase(pos, 1);
                } else if (open.find(c) == string::npos) {
                    open.push_back(c);              // newly opened
                }
                if (open.empty()) break;            // partition closes at i
                i++;
            }
            res.push_back(i - start + 1);
            i++;
        }
        return res;
    }
};