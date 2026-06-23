class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> checker;

        // check the rows
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                if (board[i][j] == '.') continue;
                if (checker.count(board[i][j])) return false;
                checker.insert(board[i][j]);
            }
            checker.clear();
        }

        // check the columns
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                if (board[j][i] == '.') continue;
                if (checker.count(board[j][i])) return false;
                checker.insert(board[j][i]);
            }
            checker.clear();
        }

        vector<pair<int,int>> squares;
        // can simply be done by a loop with +3 jumps
        // for (int r = 0; r < 9; r += 3) for (int c = 0; c < 9; c += 3)
        // but keep here to remember that vector does not have contain()
        // and should be looped over with find for example.
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                pair<int,int> corner = {(i/3)*3, (j/3)*3};
                bool seen = false;
                for (auto& s : squares) if (s == corner) { seen = true; break; }
                if (seen) continue;
                squares.push_back(corner);
            }
        }

        for (auto& sq : squares){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (board[i+sq.first][j+sq.second] == '.') continue;
                    if (checker.count(board[i+sq.first][j+sq.second])) return false;
                    checker.insert(board[i+sq.first][j+sq.second]);
                }
            }
            checker.clear();
        }

        return true;
    }
};