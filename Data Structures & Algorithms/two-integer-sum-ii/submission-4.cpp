class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < (int)numbers.size(); i++){
            int diff = target - numbers[i];
            int l = i + 1;
            int m = numbers.size() - 1;
            while (l<=m){
                int mid = l + (m -l)/2;
                if (numbers[mid] == diff) return {i+1, mid+1};
                else if (numbers[mid]<diff){
                    l = mid+1;
                } else {
                    m = mid-1;
                }
            }
        }
        return {};
    }
};
