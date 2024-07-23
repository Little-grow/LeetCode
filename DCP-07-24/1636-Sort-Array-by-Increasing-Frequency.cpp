class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        sort(begin(nums), end(nums), [&](int a, int b) {
            if(freq[a] == freq[b])
                return a > b;
            
            return freq[a] < freq[b];
        });

        return nums;
    }
};