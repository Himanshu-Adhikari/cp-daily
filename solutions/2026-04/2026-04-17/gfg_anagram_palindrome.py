class Solution:
    def canFormPalindrome(self, s):
        a={}
        for i in s:
            a[i]=a.get(i,0)+1
        c=0
        for j in a.values():
            if(j%2):
                if(c):return False
                c=1
        return True