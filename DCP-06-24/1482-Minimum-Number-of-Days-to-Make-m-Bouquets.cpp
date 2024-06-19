class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
        if(k > (int) bloomDay.size() / m)
            return -1;
        int minimum = INT_MAX, maximum = INT_MIN;
		min_max(bloomDay, minimum, maximum);

		int low = minimum, high = maximum;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (possible(bloomDay, m, k, mid)) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}

	void min_max(vector<int>& bloomDay, int& minimum, int& maximum) {
		int n = bloomDay.size();
		for (int i = 0; i < n; i++) {
			minimum = min(minimum, bloomDay[i]);
			maximum = max(maximum, bloomDay[i]);
		}
	}

	bool possible(vector<int>& bloomDay, int m, int k, int day) {
		int cnt = 0;
		int noOfBouquets = 0;

		for (int i = 0; i < bloomDay.size(); i++) {
			if (bloomDay[i] > day) {
				noOfBouquets += (cnt / k);
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		noOfBouquets += (cnt / k);
		return noOfBouquets >= m;
	}
};