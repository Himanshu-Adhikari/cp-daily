class Solution:
    def maxPeople(self, arr):
        n=len(arr)
        def rec(arr):
            st=[]
            fw=[n]*n
            for i in range(n):
                while(st and arr[st[-1]]<=arr[i]):
                    fw[st[-1]]=i
                    st.pop()
                st.append(i)
            return fw
        f,s=rec(arr),rec(arr[::-1])
        s=[n-x for x in s][::-1]
        return max(i-j for i,j in zip(f,s))
        