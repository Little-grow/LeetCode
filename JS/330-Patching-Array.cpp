class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long missing = 1;
        int index = 0;

        while (missing <= n) {
            if (index < nums.size() && nums[index] <= missing) {
                missing += nums[index++];
            } else {
                missing += missing;
                patches++;
            }
        }

        return patches;
    }
};