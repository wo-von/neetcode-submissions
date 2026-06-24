class Solution {
    stack<int> stk;
    string ops = "+-*/";
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0, operand1 = 0, operand2 = 0;
        for (auto token : tokens) {
            if (ops.find(token) != string::npos) {   // token is a single operator
                operand2 = stk.top(); stk.pop();
                operand1 = stk.top(); stk.pop();
                switch (token[0]) {
                    case '+': result = operand1 + operand2; break;
                    case '-': result = operand1 - operand2; break;
                    case '*': result = operand1 * operand2; break;
                    case '/': result = operand1 / operand2; break;
                }
                stk.push(result);
            } else {
                stk.push(stoi(token));               // token is a number
            }
        }
        return stk.top();
    }
};