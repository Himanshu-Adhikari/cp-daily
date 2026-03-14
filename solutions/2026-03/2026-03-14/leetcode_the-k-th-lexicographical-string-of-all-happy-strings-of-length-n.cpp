class Solution {
public:
    vector<string>a;
    void rec(string l,int n){
        if(l.size()==n){
            a.push_back(l);
            return;
        }
        for( char c='a';c<='c';c++){
            if(l.size() && l.back()==c)continue;
            rec(l+c,n);
        }
    }
    string getHappyString(int n, int k) {
        rec("",n);
        if(a.size()<k)return "";
        sort(begin(a),end(a));
        return a[k-1];
    }
};