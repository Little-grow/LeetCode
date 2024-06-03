class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int i = 0;

        while (j < s.size() && i < t.size()) {
            if (s[j] != t[i]) {
                j++;
            } else {
                i++;
                j++;
            }
        }

        return (int)t.size() - i;
    }
};