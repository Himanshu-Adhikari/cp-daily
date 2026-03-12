class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0, flip = 0;
        queue<int> q;
    
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() == i) {
                q.pop();
                flip ^= 1;
            }
            if ((arr[i] ^ flip) == 0) { // bit is 0 considering flips
                if (i + k > n) return -1;
                cnt++;
                flip ^= 1;
                q.push(i + k);
 
            }
        }
        return cnt;
    }
};