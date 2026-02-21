class Solution:
    def hIndex(self, citations):
        l,h=0,max(citations)
        while(l<=h):
            m=(l+h)//2
            cnt=0
            for i in citations:
                if i>=m:
                    cnt+=1
            if(cnt>=m):l=m+1
            else:h=m-1
        return h
    
    