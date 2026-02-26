class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        map<char,char>m,a;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(!m.count(s1[i]) and !a.count(s2[i])){
                m[s1[i]]=s2[i];
                a[s2[i]]=s1[i];
            }
            else if(m.count(s1[i]) and a.count(s2[i]) and m[s1[i]]==s2[i] and a[s2[i]]==s1[i])continue;
            else return false;
        }
        return true;
    }
};