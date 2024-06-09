class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;
        for (int i = 0; i < g.size(); i++) {
            
            while (j < s.size()) {
                if (s[j] >= g[i]) {
                    cnt++;
                    j++;
                    break;
                }
                else 
                    j++;
            }
        }
        return cnt;
    }
};