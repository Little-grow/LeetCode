class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         static int N = [] () {
            ios::sync_with_stdio(false); 
            cin.tie(0); 
            return 0;
        } ();

        int n = nums.size();
       
        int target = 0; 
        for(int i = 0; i < n; i++)   
            target += nums[i];
        target-=x;

        int ans = INT_MAX;
        if(target < 0 )
            return -1;
        if(target == 0)
            return n;
        
        int l = 0;
        int currSum = 0;
       
        for(int r = 0 ; r < n ;){
            currSum +=nums[r++];
            while(l < n && currSum > target){
                currSum -= nums[l++];
            }
            if(currSum == target)
                ans = min(ans, n - (r-l));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};