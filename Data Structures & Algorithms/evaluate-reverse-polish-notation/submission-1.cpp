class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;

        for (string &c: tokens) {
            if (c == "+") {
                int a = res.top(); res.pop();
                int b = res.top(); res.pop();
                int r = b + a;
                res.push(r);
            }
            else if (c == "-") {
                int a = res.top(); res.pop();
                int b = res.top(); res.pop();
                int r = b - a;
                res.push(r);
            }
            else if (c == "*") {
                int a = res.top(); res.pop();
                int b = res.top(); res.pop();
                int r = b * a;
                res.push(r);
            }
            else if (c == "/") {
                int a = res.top(); res.pop();
                int b = res.top(); res.pop();
                int r = b / a;
                res.push(r);
            }
            else
                res.push(stoi(c));
        }

        return res.top();
    }

};
