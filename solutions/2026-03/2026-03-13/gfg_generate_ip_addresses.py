class Solution:
    def generateIp(self, s):
        res = []
        n = len(s)

        def is_valid(part):
            # Check leading zero
            if len(part) > 1 and part[0] == '0':
                return False
            # Check range
            if int(part) > 255:
                return False
            return True

        # Try all possible splits
        for i in range(1, min(4, n)):
            for j in range(i+1, min(i+4, n)):
                for k in range(j+1, min(j+4, n)):
                    
                    p1 = s[:i]
                    p2 = s[i:j]
                    p3 = s[j:k]
                    p4 = s[k:]
                    
                    if (is_valid(p1) and is_valid(p2) and 
                        is_valid(p3) and is_valid(p4)):
                        res.append(p1 + "." + p2 + "." + p3 + "." + p4)

        return res