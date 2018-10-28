

```java


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


/*
[1 2 3 4 5 6 7 8 9] [2 6]

1 C
2 H
3 C
4 C
5 C
6 H
7 C
8 C
9 C

r = 3

 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public static void main(String[] args) {

        int[] houses = new int[]{1, 2, 3, 4};
        int[] heaters = new int[]{1, 4};
        Solution ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));

        houses = new int[]{1, 2, 3};
        heaters = new int[]{2};
        ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));

        houses = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
        heaters = new int[]{2, 6};
        ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));

        houses = new int[]{1, 5};
        heaters = new int[]{2};
        ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));


        /*

        다음과 같은 입력에서 오류가 발생하는데 입력이 모순 아닌가?

        houses = new int[]{1, 5};
        heaters = new int[]{10};
        ref = new Solution();
        System.out.println(ref.findRadius(houses, heaters));
         */




    }

    public int findRadius(int[] houses, int[] heaters) {

        // Map에 키와 값으로 히터의 위치와 차가운 공간을 기록하자.
        HashMap<Integer, String> houseMap = new HashMap<>();


        Arrays.sort(houses);
        Arrays.sort(heaters);

        for (int i = 1; i <= houses[houses.length-1]; i++) {
            houseMap.put(i, "C");
        }

        for (int i = 0; i < heaters.length; i++) {
            houseMap.put(heaters[i], "H");
        }

        System.out.println(houseMap);

        //r을 조금씩 늘려가면서 모든 공간을 커버할 수 있는지 조사하자.

        int result = findHelper(0, houseMap);


        return result;


    }

    public HashMap<Integer, String> mapDeepCopy(HashMap<Integer, String> inmap) {

        HashMap<Integer, String> outmap = new HashMap<>();

        for (int i = 1; i <= inmap.size(); i++) {
            outmap.put(i, inmap.get(i));
        }

        return outmap;

    }

    public boolean checkerAllH(HashMap<Integer, String> houseMap) {
        boolean flag = true;

        for (int i = 1; i <= houseMap.size(); i++) {
            if (houseMap.get(i).equals("C")) {
                flag = false;
            }
        }

        return flag;
    }

    public int findHelper(int r, HashMap<Integer, String> houseMap) {


        HashMap<Integer, String> testmap = mapDeepCopy(houseMap);

        for (int i = 1; i <= testmap.size(); i++) {
            if (houseMap.get(i).equals("H")) {

                int j = i - r;
                if (j < 1) {
                    j = 1;
                }

                while (j >= 1 && j <= testmap.size() && j >= (i - r) && j <= (i + r)) {
                    testmap.put(j, "H");
                    j++;
                }

            }
        }


        if (checkerAllH(testmap))
            return r;
        else
            return findHelper(r + 1, houseMap);


    }


}
```

