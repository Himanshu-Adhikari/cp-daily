class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        a=[]
        for i in nums:
            s=str(i)
            while(s and s[-1]=='0'):s=s[:-1]
            s=s[::-1]
            a.append(int(s))
        li={}
        ix,n=0,len(nums)
        res=n+1
        for i,j in zip(nums,a):
            if(li.get(i,-1)!=-1):res=min(res,abs(li[i]-ix))
            li[j]=ix
            ix+=1
        return -1 if res==n+1 else res