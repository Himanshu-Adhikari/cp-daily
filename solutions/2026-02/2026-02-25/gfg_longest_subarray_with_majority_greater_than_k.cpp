int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int,int>m;
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]<=k)sum-=1;
            else sum+=1;
            
            if(sum>0)ans=i+1;
            else{
                int num = -((abs(sum)+1));
                if(m.count(num))ans = max(ans,i-m[num]);
            }
            
            if(m.count(sum)==0)m[sum]=i;
            
        }
        
        return ans;
    }