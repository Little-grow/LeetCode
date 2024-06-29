class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int maxLen = 0;
        unordered_set<int> m;
       
        for(int right = 0; right < s.length(); right++){
            while(m.find(s[right]) != m.end()){
                m.erase(s[left]);
                left++;
            }

            m.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};