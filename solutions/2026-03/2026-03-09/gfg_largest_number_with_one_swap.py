class Solution:
    def largestSwap(self, s):
        t=[i for i in s]
        t.sort(reverse=True)
        p=[i for i in s]
        i,n=0,len(s)
        while(i<n):
            if(s[i]==t[i]):
                i+=1
            else:
                break
        if(i==n):return s
        j=n-1
        while(j>=0 and s[j]!=t[i]):
            j-=1
        p[j],p[i]=p[i],p[j]
        res=""
        for i in p:
            res+=i
        return res