class Solution {
public:
    void rec(int index, vector<int>& nums,
             vector<int>& curr, vector<vector<int>>& ans) {

        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {

            // skip duplicates at same level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            rec(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        rec(0, nums, curr, ans);
        return ans;
    }
};
