class Solution {
  public:
    int findPosition(int n) {
        if(n==1)return 1;
        if((1<<int(log2(n)))!=n)return -1;
        return log2(n)+1;
    }
};