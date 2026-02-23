class Solution {
  public:
    string firstNonRepeating(string &s) {
        vector<int>v(26,0);
        vector<int>m(26,-1);
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            v[s[i]-'a']+=1;
            m[s[i]-'a']=i;
            int c=-1;
            for(int j=0;j<26;j++){
                if(v[j]==1 and (c==-1 or m[c]>m[j]))c=j;
            }
            res+=(c==-1?'#':('a'+c));
        }
        return res;
    }
};
