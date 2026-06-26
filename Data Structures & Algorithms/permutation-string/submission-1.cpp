class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        array<int, 26> need{};
        for (auto& c: s1)
            need[c - 'a']++;
        for (int i = 0; i + s1.size() <= s2.size(); i++){
            array<int, 26> window{};
            for (int j = i; j < i + s1.size(); j++)
                window[s2[j] - 'a']++;
            if (window == need)
                return true;
        }
        return false;
    }
};
