class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        if (arr.size() % k != 0)
            return false;
       
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] +=1;
        }

        int cur;
        while (m.size() > 0) {
             cur = m.begin()->first;
            for (int i = 0; i < k; i++) {
                if (m[cur + i] == 0)
                    return false;
                --m[cur + i];
                cout <<m[cur + i] <<'\n';
                if (m[cur + i] == 0)
                    m.erase(cur + i);
            }
        }

        return true;
    }
};