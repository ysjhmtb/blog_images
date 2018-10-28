

/*

https://leetcode.com/problems/heaters/

Heaters

Winter is coming! Your first job during the contest is to design a standard heater
with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line,
find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately,
and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.



Example 1:

Input: [1,2,3],[2]

Output: 1

Explanation: The only heater was placed in the position 2,
and if we use the radius 1 standard, then all the houses can be warmed.



Example 2:

Input: [1,2,3,4],[1,4]

Output: 1

Explanation: The two heater was placed in the position 1 and 4.
We need to use radius 1 standard, then all the houses can be warmed.
 */


import java.util.Arrays;

class Solution {
    public static void main(String[] args) {

        int[] houses = new int[]{1, 2, 3, 4};
        int[] heaters = new int[]{1, 4};

        Solution ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));


    }

    public int findRadius(int[] houses, int[] heaters) {
        int res = 0;
        Arrays.sort(heaters);
        int[] closetHeaterForEachHouse = new int[houses.length];
        for (int i = 0; i < houses.length; i++) {
            int position = findClosetHeater(heaters, houses[i]);
            closetHeaterForEachHouse[i] = position;
        }
        for (int i = 0; i < houses.length; i++) {
            res = Math.max(res, Math.abs(houses[i] - closetHeaterForEachHouse[i]));
        }
        return res;
    }

    private int findClosetHeater(int[] heaters, int target) {
        int start = 0;
        int end = heaters.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (heaters[mid] == target) {
                return heaters[mid];
            } else if (heaters[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (start == heaters.length) return heaters[start - 1];
        if (start > 0 && Math.abs(heaters[start - 1] - target) <= Math.abs(heaters[start] - target))
            return heaters[start - 1];
        return heaters[start];
    }


}