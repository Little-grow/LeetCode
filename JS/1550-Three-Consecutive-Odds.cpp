class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                res += 1;
                if (res == 3)
                    return true;
            } else
                res = 0;
        }
        return false;
    }
};