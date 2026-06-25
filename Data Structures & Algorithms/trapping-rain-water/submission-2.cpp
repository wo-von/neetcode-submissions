class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.size() == 0) return res;
        vector<int> lmax(height.size(), 0);
        vector<int> rmax(height.size(), 0);
        lmax[0] = height[0];
        rmax[height.size()-1] = height.back();
        
        for (int i = 1; i < height.size(); i++){
            lmax[i] = max(lmax[i-1], height[i]);
        }
        for (int i = height.size()-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            res += min(rmax[i], lmax[i]) - height[i];
        }
        return res;
    }
};
