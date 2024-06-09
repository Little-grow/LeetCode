class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;
        int i = 0;

        while (j < s.size()) {
            if (i < g.size() && s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};