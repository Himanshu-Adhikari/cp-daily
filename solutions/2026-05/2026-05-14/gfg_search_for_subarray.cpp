class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int m=b.size();
        vector<int>lp(m,0);
        int i=1,j=0;
        int n=a.size();
        while(i<m){
            if(b[i]==b[j]){
                lp[i++]=++j;
            }
            else{
                if(j)j=lp[j-1];
                else i++;
            }
        }
        i=0,j=0;
        vector<int>res;
        while(i<n){
            if(a[i]==b[j]){
                i++,j++;
                if(j==m){res.push_back(i-j);j=lp[j-1];}
            }
            else{
                if(j)j=lp[j-1];
                else i++;
            }
        }
        return res;
        
    }
};