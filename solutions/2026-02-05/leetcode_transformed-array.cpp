class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0)res[i]=0;
            else{
                int id = ((nums[i] > 0)?nums[i]:n+nums[i]%n)% n;
                res[i] = nums[(i + id) % n];
            }
        }
        return res;      
    }
};