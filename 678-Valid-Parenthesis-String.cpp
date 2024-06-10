class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParentheses;
        stack<int> stars;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                leftParentheses.push(i);
            } else if (s[i] == ')') {
                if (!leftParentheses.empty()) {
                    leftParentheses.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '*') {
                stars.push(i);
            }
        }

        // Now, we need to balance any remaining left parentheses with stars
        while (!leftParentheses.empty() && !stars.empty()) {
            // A left parenthesis must appear before a star to be balanced
            if (leftParentheses.top() < stars.top()) {
                leftParentheses.pop();
                stars.pop();
            } else {
                return false;
            }
        }

        return leftParentheses.empty();
    }
};
