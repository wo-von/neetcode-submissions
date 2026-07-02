class Solution {
public:
    int findMin(vector<int> &nums) {
        vector<vector<int>> subs;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            vector<int> sub1, sub2;
            int mid = l + (r - l) / 2;
            for (int i = l; i <= mid; i++)        
                sub1.push_back(nums[i]);          
            for (int i = mid + 1; i <= r; i++)    
                sub2.push_back(nums[i]);          
            if (sub1.front() <= sub1.back()) {     
                subs.push_back(sub1);
                l = mid + 1;                      
            }
            if (sub2.front() <= sub2.back()) {    
                subs.push_back(sub2);
                r = mid;                          
            }
        }
        int minn = nums[0];                       
        for (auto &sub : subs)                    
            minn = min(minn, sub[0]);
        return minn;
    }
};