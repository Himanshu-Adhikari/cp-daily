class Solution:
    
    def rec(self, md, tasks):
        for actual, minimum in tasks:
            if md >= minimum:
                md -= actual
            else:
                return False
        return True

    def minimumEffort(self, tasks):
        
        tasks.sort(
            key=lambda x: (-(x[1] - x[0]), -x[0])
        )

        l = 0
        r = sum(task[1] for task in tasks)

        while l <= r:

            md = l + (r - l) // 2

            if self.rec(md, tasks):
                r = md - 1
            else:
                l = md + 1

        return l