class Solution {
public:

    string encode(vector<string>& strs) {
        string result ="";
        if (strs.empty()) return result;
        for (const string& str: strs){
            int size = str.size();
            result.append(to_string(size)+',');
        }
        result.push_back('#');
        for (const string& str: strs) {
            result.append(str);
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        if (s.empty()) return decoded;
        vector<int> sizes;
        int i=0;
        while (s[i] != '#'){
            string size;
            while(s[i] != ','){
                size += s[i];
                i++;
            }
            sizes.push_back(stoi(size));
            i++;
        }
        i++;
        for (int sz: sizes){
            decoded.push_back(s.substr(i, sz));
            i+=sz;
        }
        return decoded;
        
    }
};
