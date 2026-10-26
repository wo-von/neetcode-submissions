class Solution {
private:
    struct Frame {
        std::string prefix;
        int to_open;    // '(' still available
        int to_close;   // opened but not yet closed
    };

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        if (n < 0) return res;

        std::vector<Frame> stack;              // vector used as a stack
        stack.push_back({"", n, 0});

        while (!stack.empty()) {
            Frame cur = std::move(stack.back());   // take it out, don't copy
            stack.pop_back();

            if (cur.to_open == 0 && cur.to_close == 0) {
                res.push_back(std::move(cur.prefix));
                continue;
            }
            // push ')' first so '(' is popped first: same order as the recursion
            if (cur.to_close > 0)
                stack.push_back({cur.prefix + ')', cur.to_open, cur.to_close - 1});
            if (cur.to_open > 0)
                stack.push_back({cur.prefix + '(', cur.to_open - 1, cur.to_close + 1});
        }
        return res;
    }
};