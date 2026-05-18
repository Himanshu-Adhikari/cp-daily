class Solution {
  public:
    int maxSum(int n) {
        if(n<12)return n;
        return max(13*(n/12),maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
    }
};