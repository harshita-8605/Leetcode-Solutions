class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int count = 1;
        while(count<k){
            pq.pop();
            count++;
        }
        return pq.top();
    }
};