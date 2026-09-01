class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int majEle1 = NULL;
        int count1 = 0;

        int majEle2 = NULL;
        int count2 = 0;

        for(int i=0;i<nums.size();i++){

            if(nums[i] == majEle1){
                count1++;
            }
            else if(nums[i] == majEle2){
                count2++;
            }
            else if(count2 == 0){
                majEle2 = nums[i];
                count2 = 1;
            }
            else if(count1 == 0){
                majEle1 = nums[i];
                count1 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // verification
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == majEle1){
                cnt1++;
            }
            else if(nums[i] == majEle2){
                cnt2++;
            }
        }
        if(cnt1 > floor(n/3)){
            ans.push_back(majEle1);
        }
        if(cnt2 > floor(n/3)){
            ans.push_back(majEle2);
        }
        return ans;
    }
};