class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>res(n),ca(n),cb(n);
            int c=0;
        for(int i=0;i<n;i++){
            c=0;
            ca[A[i]-1]++,cb[B[i]-1]++;
            for(int j=0;j<n;j++)c+=(ca[j] && cb[j]);
            res[i]=c;
        }
        return res;
    }
};