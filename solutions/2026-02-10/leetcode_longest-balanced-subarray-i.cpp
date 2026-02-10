class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int o=0,e=0;
            map<int,int>m;
            for(int j=i;j<n;j++){
                if(!m.count(nums[j])){
                if(nums[j]%2 )o++;
                else e++;
                }
                m[nums[j]]=1;
                if(o==e)res=max(res,j-i+1);
            }
        }
        return res;
    }
};