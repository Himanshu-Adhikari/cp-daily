class Solution:
    def findLargest(self, arr):
        def compare(a, b):
            if str(a) + str(b) > str(b) + str(a):
                return -1
            elif str(a) + str(b) < str(b) + str(a):
                return 1
            else:
                return 0
        
        arr.sort(key=cmp_to_key(compare))
        res=""
        for i in arr:
            res+=str(i)
        if(res[0]=='0'):return "0"
        return res
        