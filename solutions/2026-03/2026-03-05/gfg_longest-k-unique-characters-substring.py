class Solution:
    def longestKSubstr(self, s, k):
       a=set(s)
       if(len(a)<k):return -1
       d={}
       n=len(s)
       j=0
       res=0
       for i in range(n):
          d[s[i]]=d.get(s[i],0)+1
          while(len(d)>k):
              d[s[j]]-=1
              if(d[s[j]]==0):
                  del d[s[j]]
              j+=1
          if(len(d)==k):
              res=max(res,i-j+1)
       return res