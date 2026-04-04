class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string>res;
        map<int,vector<string>>m;
        for(int i=0;i<n;i++){
            if(i==0){
                m[0].push_back("0");
                m[0].push_back("1");
                res.push_back("0");
                res.push_back("1");
            }
            else{
                for(auto&c:m[i-1]){
                    res.push_back("0"+c);
                    m[i].push_back("0"+c);
                }
                for(int j=m[i-1].size()-1;j>=0;j--){
                    m[i].push_back("1"+m[i-1][j]);
                    res.push_back("1"+m[i-1][j]);}
            }
        }
        return m[n-1];
    }
};