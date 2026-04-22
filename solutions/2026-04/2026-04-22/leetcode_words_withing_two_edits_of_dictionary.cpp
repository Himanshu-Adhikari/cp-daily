class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>res;
        for(auto c:queries){
            int m=c.size();
            int f=1;
            for(auto d:dictionary){
                int n=d.size();
                if(m!=n)continue;
                vector<int>a(26,-1);
                f=1;
                int cnt=0;
                for(int i=0;i<n and f;i++){
                    if(c[i]!=d[i]){
                        if(a[d[i]-'a']==-1 or a[d[i]-'a']==(c[i]-'a')){
                            a[d[i]-'a']=c[i]-'a';
                            cnt++;
                        }else{
                            f=0;break;
                        }
                    }
                }
                if(cnt>2){
                    f=0;
                }
                if(f and cnt<3)break;
            }
                if(f)res.push_back(c);
        }
        return res;
    }
};