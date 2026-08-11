class Solution {
public:

    void leloYaNhi(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> toPush){
        // base case
        if(i >= nums.size()){ 
            ans.push_back(toPush);
            return;}

        // lelo
        toPush.push_back(nums[i]);
        
        leloYaNhi(nums, i+1, ans, toPush);

        // matt lo
        toPush.pop_back();
        leloYaNhi(nums, i+1, ans, toPush);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;
        vector<int> toPush;
        leloYaNhi(nums, i, ans, toPush);
        return ans;
    }
};