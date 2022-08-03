//link:https://leetcode.com/problems/3sum/discuss/1462423/C%2B%2B-or-Both-Two-Pointers-and-HashMap-Approach-Explained

Case:1  MAP TYPE SOLUTION:
Time Complexity:O(N^2*log(N))

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>V;
        sort(nums.begin(),nums.end());
        if(nums.size()<3||nums[0]>0)return V;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]=i;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0)break;
            int j=i+1;
            for(;j<nums.size()-1;j++){
            int sum=-1*(nums[i]+nums[j]);
                auto it=mp.find(sum);
                if(it!=mp.end()&&it->second>j){
                    V.push_back({nums[i],nums[j],it->first});
                }
                j=mp.find(nums[j])->second;
            }
            i=mp.find(nums[i])->second;
        }
        return V;
    }
};


Case:2  2 POINTER APPROACH:

Time Complexity:O(N^N)
class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
            int sum = 0;
            while(low < high){                          //Search between two pointers, just similiar to binary search.
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                    high--;
                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                    low++;
                } else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(low < high && nums[low] == last_low_occurence){   // Update the low and high with last occurences of low and high.
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};
