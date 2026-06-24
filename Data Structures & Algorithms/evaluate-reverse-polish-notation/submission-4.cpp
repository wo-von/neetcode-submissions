class Solution {
string ops = "+-*/";
public:
    int dfs(vector<string>& tokens){
        string token = tokens.back(); tokens.pop_back();
        if (ops.find(token)==string::npos){ // if it is not an op
            return stoi(token);
        }
        int right = dfs(tokens);
        int left = dfs(tokens);
        switch(token[0]){
            case '+':
                return left+right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                return left / right;
             
        }
        return 0;
    }
    
    
    
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};
