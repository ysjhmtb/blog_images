> 52. [N-Queens II](https://leetcode.com/problems/n-queens-ii/description/)
>
> The *n*-queens puzzle is the problem of placing *n* queens on an *n*×*n* chessboard such that no two queens attack each other.
>
> <img src="https://leetcode.com/static/images/problemset/8-queens.png">
>
> Given an integer *n*, return the number of distinct solutions to the *n*-queens puzzle.
>
> **Example:**
>
> ```
> Input: 4
> Output: 2
> Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
> [
>  [".Q..",  // Solution 1
>   "...Q",
>   "Q...",
>   "..Q."],
> 
>  ["..Q.",  // Solution 2
>   "Q...",
>   "...Q",
>   ".Q.."]
> ]
> ```

<br>

[Accepted Java Solution](https://leetcode.com/problems/n-queens-ii/discuss/20058/Accepted-Java-Solution) 의 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        System.out.println(ref.totalNQueens(4));

    }
}

class Solution {

    /**
     * don't need to actually place the queen,
     * instead, for each row, try to place without violation on
     * col/ diagonal1/ diagnol2.
     * trick: to detect whether 2 positions sit on the same diagnol:
     * if delta(col, row) equals, same diagnol1;
     * if sum(col, row) equals, same diagnal2.
     */
    private final Set<Integer> occupiedCols = new HashSet<Integer>();
    private final Set<Integer> occupiedDiag1s = new HashSet<Integer>();
    private final Set<Integer> occupiedDiag2s = new HashSet<Integer>();

    public int totalNQueens(int n) {
        return totalNQueensHelper(0, 0, n);
    }

    /*

    퀸의 특성상 대각석으로도 움직일 수 있는데, diag1과 diag2로 겹치는지를 확인할 수 있다.
    퀸을 (1,3)에 놓으면 diag1 = 1 - 3 = -2이고, diag2 = 1 + 3 = 4가 된다.
    (2,4)의 diag1 = 2 - 4 = -2, diag2 = 2 + 4 = 6.
    (0,2)의 diag1 = 0 - 2 = -2, diag2 = 0 + 2 = 2.
    (2,2)의 diag1 = 2 - 2 = 0, diag2 = 2 + 2 = 4.
    (0,4)의 diag1 = 0 - 4 = -4, diag2 = 0 + 4 = 4.

    대각선이 체스판의 어느 지역을 통과하는지 알 수 있다.

     */

    private int totalNQueensHelper(int row, int count, int n) {

        //한개의 열씩 검사
        for (int col = 0; col < n; col++) {

            if (occupiedCols.contains(col))
                continue;

            int diag1 = row - col;

            if (occupiedDiag1s.contains(diag1))
                continue;

            int diag2 = row + col;

            if (occupiedDiag2s.contains(diag2))
                continue;

            // we can now place a queen here
            if (row == n - 1)
                count++;

            else {
                occupiedCols.add(col);
                occupiedDiag1s.add(diag1);
                occupiedDiag2s.add(diag2);

                //아직 마지막 행에 도달하지 못 했다. 현재 열에서 다음 행을 검사.
                count = totalNQueensHelper(row + 1, count, n);

                // recover
                occupiedCols.remove(col);
                occupiedDiag1s.remove(diag1);
                occupiedDiag2s.remove(diag2);
            }
        }

        return count;
    }


}
```

