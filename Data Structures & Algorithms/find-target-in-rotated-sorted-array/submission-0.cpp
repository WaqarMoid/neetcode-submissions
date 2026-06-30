class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right) 
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) 
            {
                // Check if target lies in left half
                if (target >= nums[left] && target < nums[mid]) 
                    right = mid - 1;
                else 
                    left = mid + 1;
            } 
            else  // right half is sorted
            {
                if (target > nums[mid] && target <= nums[right]) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1; // not found
    }
};
