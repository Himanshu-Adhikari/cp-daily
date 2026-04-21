class Solution {
  public:
    int fun( int n , int m , int d){
         int i = n ,  j =0;
          int ans =1;
          while(i!= d && j!= d){
              int temp = min(i , m-j);
               j += temp;
               i -= temp;
               ans++;
               if( i ==d || j ==d) break;
                if(i==0){
                    i = n;
                    ans++;
                }
                 if( j==m){
                      j = 0;
                       ans++;
                 }
          }
           return ans;
    }
    int minSteps(int m, int n, int d) {
        int mn=gcd(m,n);
        if(d%mn or max(m,n)<d)return -1;
        
          return min( fun( n , m ,d) , fun( m , n, d));
    }
};