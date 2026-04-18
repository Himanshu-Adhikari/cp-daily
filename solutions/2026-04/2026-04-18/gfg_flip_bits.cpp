class Solution {
  public:
    int maxOnes(vector<int>& a) {
         int zero = 0;
         int n=a.size();
        int one = 0;
        int maxiContiZero =  0;
        
        for(int i=0; i<n; i++){
            if(a[i]==0)
                zero++;
            else{
                one++;
                zero--;
            }
            maxiContiZero = max(maxiContiZero,zero);
            if(zero<0)
                zero=0;
        }
        return maxiContiZero+one;
    }
};