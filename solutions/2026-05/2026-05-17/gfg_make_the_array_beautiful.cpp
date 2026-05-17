class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int>p,n,res;
        int nm=arr.size();
        for(int i=0;i<nm;i++){
            if(arr[i]>=0){
                if(int(n.size())){
                    n.pop_back();
                }
                else{
                    p.push_back(i);
                }
            }
            else{
                
                if(int(p.size()) ){
                    p.pop_back();
                }
                else{
                    n.push_back(i);
                }
            }
        }
        vector<int>po;
        for(auto c:p)po.push_back(c);
        for(auto c:n)po.push_back(c);
        int i=0,j=0;
        int fn=p.size(),sn=n.size();
        while(i<fn && j<sn){
            if(p[i]<n[j])res.push_back(arr[p[i++]]);
            else res.push_back(arr[n[j++]]);
        }
        while(i<fn)res.push_back(arr[p[i++]]);
        while(j<sn)res.push_back(arr[n[j++]]);
        return res;
    }
};