class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& std) {
        sort(s.begin(), s.end());
        sort(std.begin(), std.end());
        int moves = 0;
        for (int j = 0; j < s.size(); j++) {
            moves += abs(s[j] - std[j]);
        }
        return moves;
    }
};