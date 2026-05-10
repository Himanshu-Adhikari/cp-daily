class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>a(n,0);
        a[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])<=target and a[i]){
                    a[j]=max(a[j],a[i]+1);
                }
            }
        }
        return a[n-1]?a[n-1]-1:-1;
    }
};