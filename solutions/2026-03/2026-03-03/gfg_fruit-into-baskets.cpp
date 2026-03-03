class Solution {
  public:
    int totalElements(vector<int> &arr) {
        map<int,int>m;
        int n=arr.size();
        int res=1;
        for(int i=0,j=0;i<n;i++){
            m[arr[i]]++;
            while(int(m.size())>2){
                m[arr[j]]--;
                if(m[arr[j]]==0)m.erase(arr[j]);
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};