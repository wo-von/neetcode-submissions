class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++){
            int counter = 0;
            int copy = i;
            while(copy > 0){
                counter += copy & 1;
                copy >>= 1;
            }
            res.push_back(counter);
        }
        return res;
    }
};