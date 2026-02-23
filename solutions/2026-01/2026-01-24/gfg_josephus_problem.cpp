class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        vector<int> cir(n,1);
        int i=0,z=0,c=0;
        while(z<n-1){
           if(cir[i]==1){
               c++;
               if(c==k){
               cir[i]=0;
               c=0;
               z++;
               }
           }
           i=(i+1)%n;
        }
        for(int i=0;i<n;i++){
            if(cir[i]==1){
                return i+1;
            }
        }
        return -1;
    }
};