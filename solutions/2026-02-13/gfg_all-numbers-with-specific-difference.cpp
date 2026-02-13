class Solution {
   int check(int& d,int num){
        int sum = 0;
        int temp = num;
        while(temp>0){
            int d = temp%10;
            sum += d;
            temp /= 10;
        }
        return d <= (num-sum);
    }
  public:
    int getCount(int n, int d) {
        // code here
        if(n < 10) return 0;
        int low = 10;
        int high = n;
        int possible = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(d,mid)){
                possible = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(!possible) return 0;
        return n-possible+1;
    }
};