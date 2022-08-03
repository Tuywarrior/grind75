LINK:https://leetcode.com/problems/insert-interval/

Method 1:checking Individually
Time Complexity:O(N)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos=0;
        vector<vector<int>>V; 
        int j=0;
            while(j<intervals.size()&&intervals[j][1]<newInterval[0]){
                V.push_back(intervals[j++]);
            }
            while(j<intervals.size()&&intervals[j][0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0],intervals[j][0]);
                newInterval[1]=max(newInterval[1],intervals[j][1]);   
                j++;
            }
        V.push_back(newInterval);
        while(j<intervals.size()){
            V.push_back(intervals[j++]);
        }
        return V;
    }
};
