class Solution {
public:
    int trap(const vector<int>& height) {
    int n = (int)height.size();
    if (n == 0) return 0;

    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            // left side is the limiting side now
            if (height[left] >= leftMax) {
                leftMax = height[left];      // update left max
            } else {
                total += leftMax - height[left]; // water trapped at left
            }
            left++; // move inward from left
        } else {
            // right side is the limiting side now
            if (height[right] >= rightMax) {
                rightMax = height[right];    // update right max
            } else {
                total += rightMax - height[right]; // water trapped at right
            }
            right--; // move inward from right
        }
    }

    return total;
}
};