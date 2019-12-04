
/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

4 5 6 7 0 1 2, target = 0

4 5 6 7 0 1 2
0 1 2
0
 */

public class N33 {

    public int search(int[] nums, int target) {
        return -1;
    }


    /*
    public int search(int[] nums, int target) {
        int start = 0, end = nums.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target <= nums[end] && target > nums[mid]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }

     */
}
