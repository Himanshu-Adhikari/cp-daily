class Fancy {
public:
    int md=1e9+7;
    int n=0,N=200005;
    vector<long long>t,lzAdd,lzMul;

    Fancy() {
        t.assign(4*N,0);
        lzAdd.assign(4*N,0);
        lzMul.assign(4*N,1);
    }

    void push(int v,int l,int r){
        if(lzMul[v]==1 && lzAdd[v]==0) return;
        t[v]=(t[v]*lzMul[v]%md + (r-l+1)*lzAdd[v]%md)%md;
        if(l!=r){
            for(int u:{v*2,v*2+1}){
                lzMul[u]=lzMul[u]*lzMul[v]%md;
                lzAdd[u]=(lzAdd[u]*lzMul[v]%md + lzAdd[v])%md;
            }
        }
        lzMul[v]=1;
        lzAdd[v]=0;
    }

    void upd(int v,int l,int r,int ql,int qr,long long mul,long long add){
        push(v,l,r);
        if(r<ql||l>qr) return;
        if(ql<=l && r<=qr){
            lzMul[v]=mul;
            lzAdd[v]=add;
            push(v,l,r);
            return;
        }
        int m=(l+r)/2;
        upd(v*2,l,m,ql,qr,mul,add);
        upd(v*2+1,m+1,r,ql,qr,mul,add);
        t[v]=(t[v*2]+t[v*2+1])%md;
    }

    long long get(int v,int l,int r,int pos){
        push(v,l,r);
        if(l==r) return t[v];
        int m=(l+r)/2;
        if(pos<=m) return get(v*2,l,m,pos);
        return get(v*2+1,m+1,r,pos);
    }

    void append(int val){
        upd(1,0,N-1,n,n,1,val);
        n++;
    }

    void addAll(int inc){
        if(n) upd(1,0,N-1,0,n-1,1,inc);
    }

    void multAll(int m){
        if(n) upd(1,0,N-1,0,n-1,m,0);
    }

    int getIndex(int idx){
        if(idx>=n) return -1;
        return get(1,0,N-1,idx);
    }
};