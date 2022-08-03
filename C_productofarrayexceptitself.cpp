METHOD1:SUFFIX AND PREFIX

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix,suffix(nums.size());
        prefix.push_back(1);
        for(int i=1;i<nums.size();i++){
            prefix.push_back(nums[i-1]*prefix[i-1]);
        }
        suffix[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=(nums[i+1]*suffix[i+1]);
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(prefix[i]*suffix[i]);
        }
        return res;
    }
};


METHOD 2:

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        Arrays.fill(ans, 1);
        int curr = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        curr = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        return ans;
    }
}
