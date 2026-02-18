class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            int n = piles.size();
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1) / mid;
            }

            if (hours <= h) {
                answer = mid;     
                high = mid - 1;   
            } 
            else {
                low = mid + 1;     
            }
        }

        return answer;
    }
};