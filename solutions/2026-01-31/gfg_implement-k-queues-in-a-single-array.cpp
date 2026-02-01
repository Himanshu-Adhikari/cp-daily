class kQueues {
  public:
    int sz;
    int k,curr;
    map<int,queue<int>>m;
    kQueues(int n, int k) {
        sz=n;
        this->k=k;
        curr=0;
    }
    void enqueue(int x, int i) {
        if(curr<sz){m[i].push(x);curr+=1;}
    }

    int dequeue(int i) {
        if(m[i].empty())return -1;
        int res=m[i].front();m[i].pop();
        curr-=1;
        return res;
    }

    bool isEmpty(int i) {
        return m[i].empty();
    }

    bool isFull() {
        return curr==sz;
    }
};
