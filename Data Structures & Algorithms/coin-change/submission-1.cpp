class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 0);   // valid indices 0..amount
        return coinDFS(coins, amount, memo);
    }

    int coinDFS(vector<int>& coins, int amount, vector<int>& memo){
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo[amount])                  // 0 = not computed yet
            return memo[amount];

        int best = INT_MAX;
        for (int i = 0; i < (int)coins.size(); i++){
            int sub = coinDFS(coins, amount - coins[i], memo);
            if (sub >= 0 && sub + 1 < best) // sub == -1 → this coin dead-ends, skip it
                best = sub + 1;
        }

        memo[amount] = (best == INT_MAX) ? -1 : best;  // cache -1 for impossible too
        return memo[amount];
    }
};