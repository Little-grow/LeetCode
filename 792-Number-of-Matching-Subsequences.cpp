class Solution {
public:
    bool findFuntions(string &s, string t) 
    {
        int i = 0, j = 0, n = s.size(), m = t.size();
        while(j<n and i < m)
            if(s[j++]==t[i]) i++;
        return (t.size() - i) == 0;
    }
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        map<string,int>mp;
        for(auto &str:words) mp[str]++;
        
        int ans = 0;
        for(auto ok:mp)
            if(findFuntions(s, ok.first)) ans += ok.second;
        return ans;
    }
};