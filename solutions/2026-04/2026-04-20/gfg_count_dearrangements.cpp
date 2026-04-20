class Solution {
  public:
    int derangeCount(int n) {
        if(n <= 2)
            return n - 1;
        return (n - 1) * (derangeCount(n - 1) + derangeCount(n - 2));
    }
};
 

