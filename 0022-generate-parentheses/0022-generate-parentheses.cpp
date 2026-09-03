class Solution {
public:

    void addValid(int &n, vector<string>&ans, string toPush, int open, int close){
        // base case
        if(open == n && close == n){
            ans.push_back(toPush);
            return;
        }

        if(close < open && open != n){
            // can add both open parenthesis as well as closed one

            // add open
            toPush += "(";
            addValid(n, ans, toPush, open+1, close);

            // add close
            toPush.pop_back();
            toPush += ")";
            addValid(n, ans, toPush, open, close+1);
        }

        if(open == n && close < open){
            // add only close parenthesis
            toPush += ")";
            addValid(n, ans, toPush, open, close+1);
        }

        if(open == close && open != n){
            // add open parenthesis
            toPush += "(";
            addValid(n, ans, toPush, open+1, close);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string toPush = "(";
        int open = 1;
        int close = 0;
        addValid(n , ans, toPush, open, close);
        return ans;
    }
};