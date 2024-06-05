class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> last = count(words[0]);

        for (int i = 1; i < words.size(); i++) {
            last = intersect(last, count(words[i]));
        }

        for (int i = 0; i < 26; i++) {
            while (last[i] > 0) {
                res.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        return res;
    }


    vector<int> count(const string& str){
        vector<int> freq(26,0);
        for(char c: str){
            freq[c-'a']++;
        }
        return freq;
    }

    vector<int> intersect(const vector<int>& a,const vector<int>& b){
        vector<int> t(26,0);
        for(int i = 0; i < 26; i++){
            t[i] = min(a[i], b[i]);
        }
        return t;
    }

};