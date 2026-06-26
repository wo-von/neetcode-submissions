class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> counter;
        int mmax = 0;
        int result = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            counter[s[r]]++;
            mmax = max(mmax, counter[s[r]]);
            while ((r - l + 1 -mmax) > k) {
                counter[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1); 
        }
        return result;
    }
};
