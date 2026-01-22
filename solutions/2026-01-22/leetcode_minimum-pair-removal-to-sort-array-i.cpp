class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size(),res=0;
        while(!is_sorted(begin(nums),end(nums))){   
            vector<int>t;
            int s=0;
            n=nums.size();
            if(n==1)break;
            for(int i=0;i<n-1;i++){
                if((nums[i]+nums[i+1] )<(nums[s]+nums[s+1]))s=i;
            }
            for(int i=0;i<n;){
                if(i==s){
                    t.push_back(nums[i]+nums[i+1]);i++;
                }
                else t.push_back(nums[i]);
                i++;
            }
            nums=t;
            res+=1;
        }
        return res;
    }
};