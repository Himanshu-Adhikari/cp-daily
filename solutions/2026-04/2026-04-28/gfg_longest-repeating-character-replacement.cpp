class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int res=0;
        int n=s.size(),cur=0;
        vector<int>a(26,0);
        cur=0;
        for(int i=0,j=0;i<n;i++){
            a[s[i]-'A']++;
            cur=max(cur,a[s[i]-'A']);
            while(i-j+1-cur>k){
                a[s[j]-'A']--;
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};