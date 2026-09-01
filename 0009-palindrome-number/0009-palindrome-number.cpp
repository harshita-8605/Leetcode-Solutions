class Solution {
public:
    bool isPalindrome(int x) {
        // approach : we will reverse the second half and check if first half of the number is = reversed second half or not

        // edge case : negative numbers or numbers ending with 0 cannot be palindormes
        if(x < 0 || (x%10 == 0 && x!=0)) return false;

        // finding revered second half
        int rh = 0;
        while(x>rh){
            rh = rh*10 + x%10;
            x /=10;
        }

        // return true if x = rh ; in case of odd digits we ignore the middle digit
        return (x == rh) || (x== rh/10);
    }
};