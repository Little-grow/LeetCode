class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

            int lremove = 3;
        int rremove = 0;

        while (rremove <= 3) {

            int maxNum = nums[n - 1 - rremove];
            int minNum = nums[lremove];

            ans = min(maxNum - minNum, ans);
            lremove--;
            rremove++;
        }
        return ans;
    }
};