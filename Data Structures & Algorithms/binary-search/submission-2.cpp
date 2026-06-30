class Solution {
public:
    int recursive_search(vector<int>& nums, int target, int l, int u){
        int m = l + (u - l)/2;
        if (l > u) return -1;
        else if (nums[m] == target) return m;
        else if (nums[m] < target){
            l = m + 1;
            return recursive_search(nums, target, l, u);
        } else if (target < nums[m]){
            u = m - 1;
            return recursive_search(nums, target, l, u);
        }
        
    }
    
    int search(vector<int>& nums, int target) {
        return recursive_search(nums, target, 0, nums.size() -1);    
    }
};
