class Solution {
public:

    void addYaNhi(vector<int>& candidates, int& target, int i, vector<vector<int>>& ans, vector<int> toPush, int sum){
        // base cases
        if(sum == target){
            ans.push_back(toPush);
            return;
        }
        if(sum > target) return;
        if(i >= candidates.size()) return;

        // add karlo
        sum += candidates[i];
        toPush.push_back(candidates[i]);
        addYaNhi(candidates, target, i, ans, toPush, sum);

        toPush.pop_back();
        sum -= candidates[i];

        // matt karo add
        addYaNhi(candidates, target, i+1, ans, toPush, sum);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> toPush;
        addYaNhi(candidates, target, i, ans, toPush, 0);
        return ans;
    }
};