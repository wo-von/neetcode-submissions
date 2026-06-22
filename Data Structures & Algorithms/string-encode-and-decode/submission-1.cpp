class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        if (strs.empty()) return result;
        for (const string& str:strs){
            result.append(to_string(str.size()));
            result.push_back('#');
            result.append(str);
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        if (s.empty()) return result;
        int i = 0;
        while (i < s.size()){
            string ssize;
            while(s[i] != '#'){
                ssize.push_back(s[i]);
                i++;
            }
            i++;
            int size = stoi(ssize);
            result.push_back(s.substr(i, size));
            i+=size;
        }
        return result;
    }
};
