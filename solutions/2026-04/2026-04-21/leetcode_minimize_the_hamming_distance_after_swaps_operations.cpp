class Solution {
public:
    int par(int i,vector<int>&p){
        if(p[i]==i)return i;
        return p[i]=par(p[i],p);
    }
    void un(int i,int j,vector<int>&p,vector<int>&r){
        int pi=par(i,p),pj=par(j,p);
        if(r[pi]>=r[pj]){
            p[pj]=pi;
            r[pi]+=1;
        }
        else{
            p[pi]=pj;
            r[pj]+=1;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int res=0;
        map<int,multiset<int>>m;
        int n=source.size();
        vector<int>pr(n),rnk(n,0);
        iota(begin(pr),end(pr),0);
        for(auto c:allowedSwaps){
            int p1=par(c[0],pr),p2=par(c[1],pr);
            if(p1!=p2){
                un(c[0],c[1],pr,rnk);
            }
        }
        for(int i=0;i<n;i++){
            m[par(i,pr)].insert(source[i]);
        }
        for(int i=0;i<n;i++){
            int prp=par(i,pr);
            if(m[prp].count(target[i])){
                m[prp].erase(m[prp].find(target[i]));
            }
            else{
                res++;
            }
        }
        return res;

    }
};