class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int currlength = 0;
        int max_length = 0;
        int i=0, j=0;
        while(i < s.size() && j < s.size()){
            if (st.find(s[j]) != st.end() ){
                while(st.find(s[j]) != st.end()){
                    currlength--;
                    st.erase(s[i]);
                    i++;
                }
            }
            else{
                st.insert(s[j]);
                currlength++;
                j++;
            }
            max_length = max(max_length, currlength);
        }
        return max_length;
    }
};