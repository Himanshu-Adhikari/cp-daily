class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res=0
        s={2, 3, 5, 7, 11, 13, 17 , 19}
        for i in range(left,right+1):
            if(i.bit_count() in s):
                res+=1
        return res