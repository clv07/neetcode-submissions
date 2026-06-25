class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stk) {
        if (openN == closedN && openN == n) {
            res.push_back(stk);
            return;
        }

        if (openN < n) {
            stk += '(';
            backtrack(openN + 1, closedN, n, res, stk);
            stk.pop_back();
        }
        if (closedN < openN) {
            stk += ')';
            backtrack(openN, closedN + 1, n, res, stk);
            stk.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stk;
        backtrack(0, 0, n, res, stk);
        return res;
    }
};
