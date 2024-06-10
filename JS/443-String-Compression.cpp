class Solution {
public:
    int compress(vector<char>& arr) {
        int i = 0, res = 0;
        while(i < arr.size()){
            int groupLength = 1;
            while(i + groupLength < arr.size() && arr[i+groupLength] == arr[i]){
                ++groupLength;
            }
            arr[res++]= arr[i];
            if(groupLength > 1){
                for(char c : to_string(groupLength))
                    arr[res++] = c;
            }   
            i += groupLength;
        }
        return res;
    }
};