class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
         int ct = 0;
        int n = arr.size();
        int ptr = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                arr[ptr] = arr[i];
                ptr++;
            }
            else{
                ct++;
            }
        }
        for(int i=n-1;ct>0;ct--){
            arr[i--] = 0; 
        }
    }
};
