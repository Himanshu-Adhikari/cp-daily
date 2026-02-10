class Solution:
    def kokoEat(self, arr, k):
        l=1
        h=10**15
        n=len(arr)
        while(l<=h):
            c=0
            m=l+(h-l)//2
            for i in arr:
                if(m>i):c+=1
                else:c+=((i+m-1)//m)
            if(c<=k):h=m-1
            else:l=m+1
        return l
        