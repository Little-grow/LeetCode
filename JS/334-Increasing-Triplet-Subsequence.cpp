class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
        if (nums.size() < 3)
            return false;
        int first = INT_MAX, second = INT_MAX;
        for (int n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }
        return false;
    }
};