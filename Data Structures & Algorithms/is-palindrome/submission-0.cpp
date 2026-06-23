class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i <= j){
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if (((unsigned char)tolower(s[i])) == ((unsigned char)tolower(s[j]))){
                i++, j--;
                continue;
            } else return false;
        }
        return true;
    }
};
