class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(auto &it : nums){
            sum += it;
           cnt += m[sum-goal];
           m[sum]++;
        }

        return cnt;
    }
};