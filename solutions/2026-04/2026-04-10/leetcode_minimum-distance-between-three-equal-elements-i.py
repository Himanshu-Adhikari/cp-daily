class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        aux=defaultdict(list)
        res=-1
        for i,val in enumerate(nums):
            # if(val not in aux):aux[val]=[]
            aux[val].append(i)
            if(len(aux[val])>2):
                calc=2*(aux[val][-1] - aux[val][-3])
                if(res==-1):
                    res=calc
                else:res=min(res,calc)
        return res