
class Solution{
    public:
    bool isMaxHeap(vector<int>&arr)
    {   
        int n=arr.size();
        int l,r;
        for(int i=0;i<n;i++){
             if(2*i+1 < n){
                 l=arr[2*i+1];
                 if(arr[i]<l)return 0;
             }
             if(2*i+2<n){
                 r=arr[2*i+2];
                 if(r>arr[i])return 0;
             }
        }
        return 1;
    }
};
