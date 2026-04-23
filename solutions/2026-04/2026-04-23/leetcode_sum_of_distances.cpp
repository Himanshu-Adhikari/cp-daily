class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        #define ll long long
        vector<ll>res;
        map<int,vector<ll>>m,mp,sp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        for(auto [a,b]:m){
            ll sm=0;
            for(auto c:b){
                sm+=c;
                mp[a].push_back(sm);
            }
            int s=b.size();
            sm=0;
            for(int i=s-1;i>=0;i--){
                sm+=b[i];
                sp[a].push_back(sm);
            }
            reverse(begin(sp[a]),end(sp[a]));
        }
        for(int i=0;i<n;i++){
            int s=m[nums[i]].size();
            if(s==1)res.push_back(0);
            else{
                int id=lower_bound(m[nums[i]].begin(),end(m[nums[i]]),i)-begin(m[nums[i]]);
               long long left = (long long)id * i - (id ? mp[nums[i]][id - 1] : 0);
                long long right = (sp[nums[i]][id] - i) - (long long)(s - id - 1) * i;
                res.push_back(left + right);
            }
        }
        return res;
    }
};