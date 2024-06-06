class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size() % k != 0)
            return false;

        map<int,int> m;
        for(int i = 0; i < hand.size(); i++){
            m[hand[i]]++;
        }

        while(m.size() > 0)
        {
            int cur = m.begin()->first;
            for(int i = 0; i < k; i++){
                if(m[cur+i] == 0)
                    return false;
                m[cur+i]--;
                if(m[cur+i] == 0)
                m.erase(cur+i);
            }
        }
        return true;
    }
};