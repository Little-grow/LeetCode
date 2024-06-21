class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initial = 0;
        int maxExtra = 0;
        int currWindow = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                initial += customers[i];
            else if (i < minutes)
                currWindow += customers[i];
        }

        maxExtra = currWindow;
        for(int i = minutes; i < customers.size(); i++){
            currWindow += customers[i]* grumpy[i];
            currWindow -= customers[i-minutes] * grumpy[i-minutes];
            maxExtra = max(maxExtra, currWindow);
        }

        return initial + maxExtra;
    }
};