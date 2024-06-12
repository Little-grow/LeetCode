class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        int i = 0;
        for (auto it : m) {
            while (it.second > 0) {
                nums[i++] = it.first;
                it.second--;
            }
        }
    }
};