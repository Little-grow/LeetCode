class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        int max_val = 0;
        int n = nums.size();
        for (int val : nums) {
            max_val = max(max_val, val);
        }

        vector<int> freq(n + max_val + 1, 0);

        for(int val : nums){
            freq[val]++;
        }

        for(int i = 0; i < freq.size(); i++){
            if(freq[i] <= 1)
                continue;
            
            int duplicates = freq[i] - 1;
            freq[i+1] += duplicates;
            freq[i] = 1;
            moves += duplicates;
        }
        return moves;
    }
};