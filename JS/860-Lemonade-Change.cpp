class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int b : bills) {
            if (b == 5)
                five++;
            else {
                if (b == 10 && five == 0)
                    return false;
                else if (b == 10 && five != 0) {
                    five--;
                    ten++;
                }
                else {
                    if(ten >= 1 && five >= 1)
                      {  ten--; five --;
                      }
                    else if (five >= 3)
                        five-= 3;
                    else 
                        return false;
                }
            }
        }
        return true;
    }
};