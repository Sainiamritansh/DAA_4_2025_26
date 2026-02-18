class Solution {
  public:
  
    bool canPaint(vector<int> &boards, int k, long long maxTime) {
        long long currentSum = 0;
        int painters = 1;

        for(int i = 0; i < boards.size(); i++) {
            
            if(currentSum + boards[i] <= maxTime) {
                currentSum += boards[i];
            } 
            else {
                painters++;
                currentSum = boards[i];
                
                if(painters > k) return false;
            }
        }
        return true;
    }

    long long minTime(vector<int> &boards, int k) {
        
        long long low = *max_element(boards.begin(), boards.end());
        long long high = accumulate(boards.begin(), boards.end(), 0LL);
        long long ans = high;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(canPaint(boards, k, mid)) {
                ans = mid;          // possible answer
                high = mid - 1;     // try smaller
            } 
            else {
                low = mid + 1;      // increase limit
            }
        }

        return ans;
    }
};
