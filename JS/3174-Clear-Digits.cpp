class Solution {
public:
   string clearDigits(string s) {
        for (int i = 0; s.length() > 0 && i < s.length(); i++) {
            if (is_digit(s[i]) && i == 0) {
                s = s.erase(i, 1);
                i = -1; 
            } else if (is_digit(s[i])) {
                s = s.erase(i - 1, 2);
                i = -1; 
            }
        }
        return s;
    }
    
    bool is_digit(char c) {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
    
   
};