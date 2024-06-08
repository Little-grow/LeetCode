class Solution {
public:
    int findWinningPlayer(vector<int>& sk, int k) {
        int sz = sk.size();
        if (k >= sz-1)
            return max_element(sk.begin(), sk.end()) - sk.begin();
        
        deque<int>q;
        for (int i = 0;i < sz;i++) {
            q.push_back(i);
        }

        int player1 ,player2,win,los;
        int last_winner = q.front();
        int cnt = 0;
        while (cnt < k) {
            player1 = q[0];
            player2 = q[1];

            if (sk[player1] < sk[player2]) {
                q.pop_front();
                q.push_back(player1);
                win = player2;
                los = player1;
            }
            else {
                q.pop_front();
                q.pop_front();
                q.push_back(player2);
                q.push_front(player1);
                win = player1;
                los = player2;
            }

            if (win == last_winner) {
                cnt++;
            }
            else {
                last_winner = win;
                cnt = 1;
            }
        }
        return last_winner;
    }
};