class Solution:
    def insert_at_bottom(self,st,ele):
        if (len(st)==0):
            st.append(ele)
        else:
            top = st.pop()
            self.insert_at_bottom(st,ele)
            st.append(top)
    def reverseStack(self, st):
        if (len(st)==0):
            return st# code here
        top = st.pop()
        self.reverseStack(st)
        self.insert_at_bottom(st,top)
        return st
