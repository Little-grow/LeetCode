class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int sum  = 0; 
        int cnt = 0;
        unordered_map <int, int> m;
        m[0]= 1;
        for(int it: nums){
            sum = (sum + it) % k;
            if( sum < 0)
                sum = sum + k;
            cnt += m[sum];
            m[sum]++;
        }
        return cnt;
    }
};