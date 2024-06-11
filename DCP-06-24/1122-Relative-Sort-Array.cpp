class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        vector<int> ans;

        for (int i = 0; i < arr1.size(); i++) {
            m[arr1[i]]++;
        }

        int y = 0;
        while (y < arr2.size()) {
            if (m[arr2[y]]) {
                ans.push_back(arr2[y]);
                m[arr2[y]]--;
            } 
            else
                y++;
        }

        for (auto it : m){
            while(it.second != 0){
                ans.push_back(it.first);
                it.second--; 
            }

        }
        return ans;
    }
};