class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];

        while(left < right){
            if (leftMax <= rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }
        return ans;
    }
};