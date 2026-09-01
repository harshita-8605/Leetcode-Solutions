class Solution {
public:
    bool isPalindrome(string s) {
        // removing alphanumeric characters
        for(int i=0; i< s.size(); i++){
            if( !isalnum(s[i]) ){
                s.erase(i,1);
                i--;
            }
        }

        // uppercase to lowercase
        for(char &ch: s){
            if(isupper(ch)){
                ch = tolower(ch);
            }
        }

        // checking if palindrome or not by two pointer
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};