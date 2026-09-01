class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // boyer - moore voting algorithm

        // assumption
        int potEle = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(count == 0){
                potEle = nums[i];
            }
            if(nums[i] == potEle){
                count++;
            }
            else{
                count--;
            }
        }
        return potEle;
    }
};