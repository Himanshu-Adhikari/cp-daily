class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        mn,res=float('inf'),letters[0]
        for i in letters:
            cst=(ord(i)-ord(target))
            if(i>target and mn>cst):
                res,mn=i,cst
        return res