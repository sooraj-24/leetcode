class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[low]){
                if(target <= nums[mid] && target >= nums[low]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};