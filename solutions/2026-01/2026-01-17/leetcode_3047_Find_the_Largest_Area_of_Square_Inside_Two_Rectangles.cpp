class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        #define ll long long
        ll res=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wdth=min(topRight[i][0],topRight[j][0])-
                max(bottomLeft[i][0],bottomLeft[j][0]);
                int hgth=min(topRight[i][1],topRight[j][1])-
                max(bottomLeft[i][1],bottomLeft[j][1]);
                int sd=min(wdth,hgth);
                res=max(res,sd>0?1ll*sd*sd:0);
            }
        }
        return res;
    }
};