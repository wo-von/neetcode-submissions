class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return changer(amount, 0, coins, memo);
    }

    int changer(int amount, int start, vector<int>& coins,
                vector<vector<int>>& memo) {
        if (amount == 0) return 1;                  // one complete combination
        if (amount < 0) return 0;                   // overshot
        if (start == (int)coins.size()) return 0;   // out of coins, amount left
        if (memo[start][amount] != -1) return memo[start][amount];

        int ways = 0;
        ways += changer(amount - coins[start], start, coins, memo);  // take, reuse allowed
        ways += changer(amount, start + 1, coins, memo);             // skip forever

        memo[start][amount] = ways;
        return ways;
    }
};