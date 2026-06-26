class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mmax = 0;
        int lowest_so_far = prices[0];
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < lowest_so_far) {
                lowest_so_far = prices[i];
                continue;
            }
            mmax = max(mmax, prices[i] - lowest_so_far);
        }
        return mmax;
    }
};
