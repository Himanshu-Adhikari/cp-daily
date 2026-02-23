class Solution():
    def checkRedundancy(self, s):
        st,aux=[],"+-/*"
        i,n=0,len(s)
        while(i<n):
            if(s[i]=='(' or s[i] in aux):
                st.append(s[i])
            elif(s[i]==')'):
                if(st[-1]=='('):
                    return True
                while(st and st[-1]!='('):
                    st.pop()
                st.pop()
            i+=1
        return False