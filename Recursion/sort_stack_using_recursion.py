class Solution:
    def insert(self,st,ele):
        if(len(st)==0 or st[-1]<=ele):
            st.append(ele)
            return
        top = st.pop()
        self.insert(st,ele)
        st.append(top)

    def sortStack(self, stack):
        if(len(stack)==0 or len(stack)==1):
            return stack
        top = stack.pop()
        self.sortStack(stack)
        self.insert(stack,top)
        return stack