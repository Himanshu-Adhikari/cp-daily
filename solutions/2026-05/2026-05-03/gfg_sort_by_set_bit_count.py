class Solution:
    def sortBySetBitCount(self, arr):
        arr.sort(key=lambda x:(-
        x.bit_count()))
        return arr