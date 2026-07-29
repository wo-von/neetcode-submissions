class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min_index = 0;
        int l = 0;
        int r = nums.size() - 1;
        // find minimum
        while (l < r) {
            if (nums[l] < nums[r]) {   // window already sorted → min is at l
                break;
            }
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) { 
                l = m + 1;
            } else {
                r = m;
            }
        }
        min_index = l;                 

        if (target >= nums[min_index] && target <= nums.back()) {
            return binary_search(nums, min_index, nums.size() - 1, target);
        } else {
            return binary_search(nums, 0, min_index - 1, target);
        }
    }

    int binary_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {            
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;           
            }
        }
        return -1;
    }
};