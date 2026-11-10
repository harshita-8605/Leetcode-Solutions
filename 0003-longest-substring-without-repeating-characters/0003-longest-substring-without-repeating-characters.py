class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st = set()
        currlength = 0
        max_length = 0
        i,j = 0,0

        while i< len(s) and j< len(s):
            if s[j] in st:
                while s[j] in st:
                    st.remove(s[i])
                    currlength -= 1
                    i += 1
            
            else:
                st.add(s[j])
                currlength += 1
                j += 1
            
            max_length = max(max_length, currlength)
        
        return max_length