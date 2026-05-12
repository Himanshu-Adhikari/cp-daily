class Solution {
  public:
    #define ll long long 
    ll lc(ll a,ll b){
        return (1LL * a / __gcd(1ll*a, 1ll*b)) * b;
    }
    vector<ll>aux;
    void build(int si,vector<int>&arr,int l,int r){
        if(l==r){
            aux[si]=arr[l];
            return;
        }
        int md=l+(r-l)/2;
        build(2*si+1,arr,l,md);
        build(2*si+2,arr,md+1,r);
        aux[si]=lc(aux[2*si+1],aux[2*si+2]);
    }
    ll rec(int si,int sl,int sr,int l,int r){
        if(sl>r or sr<l)return 1ll;
        if(sl>=l && sr<=r)return aux[si];
        int md=sl+(sr-sl)/2;
        return lc(rec(2*si+1,sl,md,l,r),rec(2*si+2,md+1,sr,l,r));
    }
    void upd(int si,int sl,int sr,int id,int val,vector<int>&arr){
        if(sl==id and sl==sr){
            arr[id]=val;
            aux[si]=val;
            return;
        }
        int md=sl+(sr-sl)/2;
        if(id<=md){
            upd(2*si+1,sl,md,id,val,arr);
        }
        else{
            upd(2*si+2,md+1,sr,id,val,arr);
        }
        aux[si]=lc(aux[2*si+1],aux[2*si+2]);
    }
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n=arr.size();
        aux=vector<ll>(4*n+1,1);
        build(0,arr,0,n-1);
        vector<ll>res;
        for(auto c:queries){
            if(c[0]==1){
                upd(0,0,n-1,c[1],c[2],arr);
            }
            else{
                res.push_back(rec(0,0,n-1,c[1],c[2]));
            }
        }
        return res;
    }
};