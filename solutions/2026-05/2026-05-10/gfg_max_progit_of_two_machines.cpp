class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int res=0;
        int n=a.size();
        vector<int>aux(n);
        iota(begin(aux),end(aux),0);
        sort(begin(aux),end(aux),[&](int i,int j){
            return abs(a[i]-b[i])>abs(b[j]-a[j]);
        });
        for(int j=0;j<n;j++){
            int i=aux[j];
            if(a[i]>b[i]){
                if(x){res+=a[i];x--;}
                else{res+=b[i];y--;}
            }
            else{
                if(y){res+=b[i];y--;}
                else{res+=a[i];x--;}
            }
        }
        return res;
    }
};