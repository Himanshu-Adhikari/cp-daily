class Solution {
public:
    int reverseBits(int n) {
        #define ll long long
        bitset<32>a(n);
        int i=0,j=31;
        while(i<=j){
            int t=a[i];
            a[i++]=a[j];
            a[j--]=t;
        }
        ll res=0;
        for(int i=0;i<32;i++){
            if(a[i])res+=(1ll<<i);
        }
        return res;
    }
};