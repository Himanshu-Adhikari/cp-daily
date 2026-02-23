class Solution {
public:
    int longestBalanced(string s) {
        vector<int>a(3,0);
        #define ll long long
        int n=s.size(); ll res=0;
        for(int i=0;i<n;i++)a[s[i]-'a']++;
        int l=0,r=*min_element(begin(a),end(a));
        a=vector<int>(3,0);
       for(int i=0;i<n;i++){
           if(s[i]=='a')a[0]++,a[1]=0,a[2]=0;
           else if(s[i]=='b')a[0]=0,a[1]+=1,a[2]=0;
           else a[0]=0,a[1]=0,a[2]++;
           res=max(res,1ll*(*max_element(begin(a),end(a))));
       }
           for(char c='a';c<='c';c++){
               for( char d='a';d<='c';d++){
                   if(d==c)continue;
                    // map<pair<ll,ll>,ll>mp;
                   unordered_map<ll,pair<ll,ll>>mp;
                    // mp[{0,0}]=-1;
                   mp[0]={-1,0};
                   int j=0;
                   int f=0,o=0;
                   for(int i=0;i<n;i++){
                       if(s[i]==c)f++;
                       else if(s[i]==d)o++;
                       else {f=0,o=0,j++;mp[0]={i,j};continue;}
                       if(mp.count(f-o) && mp[f-o].second==j){
                           res=max(res,i-mp[f-o].first);
                       }
                       else mp[f-o]={i,j};
                       
                   }
               }
           }
        map<pair<int,int>,ll>m;
        a=vector<int>(3,0);
        m[{0,0}]=-1;
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            int f=a[0]-a[1],o=a[0]-a[2];
            // cout<<f<<" "<<o<<endl;
            if(m.count({f,o}))res=max(res,i-m[{f,o}]);
            else m[{f,o}]=i;
        }
        return res;
    }
};