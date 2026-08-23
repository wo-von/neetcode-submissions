class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxx = 0;
        int i = 0;
        while(i <= maxx && i < nums.size()){
            maxx = max(maxx, i + nums[i]);
            i++;
        }
        if (maxx >= nums.size() - 1){
            return true;
        } else {
            return false;
        }
    }
};
