class Solution {
public:
  int longestPalindrome(string s) {

      int chars[52]{};
      int x = s.size();
        for (int i =0 ; i < x; i++)
        {
            char c = s[i];
            if (s[i] <= 'z' && s[i] >='a')
            {
                chars[c-'a']++;
            }
            else
            {
                chars[c-'A'+26]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 52; i++)
        {
            cnt += chars[i]/2;
        }
        cnt *= 2 ;
    return min(x , cnt + 1);
    }
};