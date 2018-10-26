```java
/*
https://leetcode.com/problems/possible-bipartition/description/

Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group.
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.


Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false


Note:
1. 1 <= N <= 2000
2. 0 <= dislikes.length <= 10000
3. 1 <= dislikes[i][j] <= N
4. dislikes[i][0] < dislikes[i][1]
5. There does not exist i != j for which dislikes[i] == dislikes[j].

 */


/*

10
[[4,7],[4,8],[5,6],[1,6],[3,7],[2,5],[5,8],[1,2],[4,9],[6,10],[8,10],[3,6],
[2,10],[9,10],[3,9],[2,3],[1,9],[4,6],[5,7],[3,8],[1,8],[1,7],[2,4]]

 true
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public static void main(String[] args) {

        Solution ref = new Solution();
        int N = 4;
        int[][] dislikes = new int[][]{
                {1, 2}, {1, 3}, {2, 4}
        };

        System.out.println(1);
        System.out.println(ref.possibleBipartition(N, dislikes));   // true

        ref = new Solution();
        N = 3;
        dislikes = new int[][]{{1, 2}, {1, 3}, {2, 3}};

        System.out.println(2);
        System.out.println(ref.possibleBipartition(N, dislikes));   // false

        ref = new Solution();
        N = 5;
        dislikes = new int[][]{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};

        System.out.println(3);
        System.out.println(ref.possibleBipartition(N, dislikes));   // false

        ref = new Solution();
        N = 5;
        dislikes = new int[][]{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
        System.out.println(4);
        System.out.println(ref.possibleBipartition(N, dislikes));   // false


        ref = new Solution();
        N = 10;
        dislikes = new int[][]{
                {4, 7}, {4, 8}, {5, 6}, {1, 6}, {3, 7}, {2, 5}, {5, 8}, {1, 2}, {4, 9}, {6, 10}, {8, 10}, {3, 6},
                {2, 10}, {9, 10}, {3, 9}, {2, 3}, {1, 9}, {4, 6}, {5, 7}, {3, 8}, {1, 8}, {1, 7}, {2, 4}
        };

        System.out.println(5);
        System.out.println(ref.possibleBipartition(N, dislikes));   // true


        /*

        다음과 같은 테스트 케이스 결과를 받았다. 그런데 테스트 케이스 작성이 잘못된 것으로 보인다.
        내가 볼때 [1,2]로 인해 false로 반환되어야 한다.

        Input:
        10
        [[4,7],[4,8],[2,8],[8,9],[1,6],[5,8],[1,2],[6,7],[3,10],[8,10],[1,5],
        [7,10],[1,10],[3,5],[3,6],[1,4],[3,9],[2,3],[1,9],[7,9],[2,7],[6,8],[5,7],[3,4]]

        Output:
        false

        Expected:
        true


         */

        ref = new Solution();
        N = 10;
        dislikes = new int[][]{
                {4, 7}, {4, 8}, {2, 8}, {8, 9}, {1, 6}, {5, 8}, {1, 2}, {6, 7}, {3, 10},
                {8, 10}, {1, 5}, {7, 10}, {1, 10}, {3, 5}, {3, 6}, {1, 4}, {3, 9}, {2, 3}, {1, 9},
                {7, 9}, {2, 7}, {6, 8}, {5, 7}, {3, 4}
        };
        System.out.println(6);
        System.out.println(ref.possibleBipartition(N, dislikes));   // false


    }


    public boolean possibleBipartition(int N, int[][] dislikes) {

        Map<Integer, String> map = new HashMap<>();

        for (int[] sub : dislikes) {
            if (containBoth(map, sub)) {

                if (isEqualColor(map, sub)) {
                    return false;
                } else {
                    continue;
                }
            } else {

                String one = containOne(map, sub);
                if (one.equals("NO")) {
                    map.put(sub[0], "R");
                    map.put(sub[1], "B");
                } else {

                    if (map.containsKey(sub[0])) {
                        one = map.get(sub[0]);
                        if (one.equals("R")) {
                            map.put(sub[1], "B");
                        } else {
                            map.put(sub[1], "R");
                        }

                    } else if (map.containsKey(sub[1])) {
                        one = map.get(sub[1]);
                        if (one.equals("R")) {
                            map.put(sub[0], "B");
                        } else {
                            map.put(sub[0], "R");
                        }

                    }

                }
            }

        }
        return true;


    }


    public boolean containBoth(Map<Integer, String> map, int[] sub) {
        int count = 0;

        for (int i : sub) {
            if (map.containsKey(i))
                count++;
        }

        return count == sub.length;
    }

    public boolean isEqualColor(Map<Integer, String> map, int[] sub) {
        return map.get(sub[0]).equals(map.get(sub[1]));
    }

    public String containOne(Map<Integer, String> map, int[] sub) {
        for (int i : sub) {
            if (map.containsKey(i)) {
                return map.get(i);
            }
        }
        return "NO";
    }


}
```

