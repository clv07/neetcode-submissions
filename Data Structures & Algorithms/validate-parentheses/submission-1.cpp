class Solution {
public:
    bool isValid(string s) {

            if (s.size() < 2) return false;

           stack<char> bracket;

           for (char &c: s) {
                if (c == '(' || c == '{' || c == '[')
                    bracket.push(c);
                else if (c == ')' || c == ']' || c == '}') {
                    if (bracket.empty()) return false;
                    char top = bracket.top();
                    if (
                        (c == ')' && top != '(') ||
                        (c == ']' && top != '[') ||
                        (c == '}' && top != '{') 
                    ) {
                        return false;
                    }
                    else
                        bracket.pop();      
                }
           }

           return bracket.empty();
    }
};
