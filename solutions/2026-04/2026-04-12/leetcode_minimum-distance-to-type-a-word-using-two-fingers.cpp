#define pi pair<int,int>
map<char,pi>m;
class Solution {
public:
    tuple<char,char,int> key(char a,char b,int i){
        return make_tuple(a,b,i);
    }
    Solution(){
        if(int(m.size())==0){
            char c='A';
            for(int i=0,f=0;f==0;i++){
                for(int j=0;j<6 and !f;j++){
                    m[c]={i,j};
                    if(c=='Z')f=1;
                    c++;
                }
            }
        }
    }
    map<tuple<char,char,int>,int>dp;
    int rec(char a,char b,int i,string s,int n){
        if(n==i)return 0;
        auto aux=key(a,b,i);
        if(dp.count(aux))return dp[aux];
        int cst=INT_MAX;
        if(a=='!')cst=min(cst,rec(s[i],b,i+1,s,n));
        else cst=min(cst,abs(m[s[i]].first-m[a].first)+abs(m[s[i]].second-m[a].second)+rec(s[i],b,i+1,s,n));
        if(b=='!')cst=min(cst,rec(a,s[i],i+1,s,n));
        else cst=min(cst,abs(m[s[i]].first-m[b].first)+abs(m[s[i]].second-m[b].second)+rec(a,s[i],i+1,s,n));
        return dp[aux]=cst;
    }
    int minimumDistance(string word) {
        int res=0;
        int n=word.size();
        return rec('!','!',0,word,n);
    }

};