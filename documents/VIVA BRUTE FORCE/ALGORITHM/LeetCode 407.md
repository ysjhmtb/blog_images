> 407. Trapping Rain Water II
>
> Given an `m x n` matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
>
> **Note:**
> Both *m* and *n* are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
>
> **Example:**
>
> ```j
> Given the following 3x6 height map:
> [
>   [1,4,3,1,3,2],
>   [3,2,1,3,2,4],
>   [2,3,3,2,3,1]
> ]
> 
> Return 4.
> ```
>
> <img src="https://leetcode.com/static/images/problemset/rainwater_empty.png">
>
> The above image represents the elevation map `[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]` before the rain.
>
> <img src="https://leetcode.com/static/images/problemset/rainwater_fill.png">
>
> After the rain, water is trapped between the blocks. The total volume of water trapped is 4.

<br>

<hr>

[Java solution using PriorityQueue](https://leetcode.com/problems/trapping-rain-water-ii/discuss/89461/Java-solution-using-PriorityQueue) 의 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        int[][] heightMap = new int[][]{
                {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}
        };

        int[][] heightMap2 = new int[][]{
                {2, 1, 1, 2}, {1, 0, 0, 1}, {2, 1, 1, 1}
        };

        System.out.println(ref.trapRainWater(heightMap));
        System.out.println(ref.trapRainWater(heightMap2));
        /*
            row : 1 col : 1 heights[row][col] : 0 cell.height : 1
            row : 1 col : 2 heights[row][col] : 0 cell.height : 1
            2
        */


    }
}


class Solution {

    public class Cell {
        int row;
        int col;
        int height;

        public Cell(int row, int col, int height) {
            this.row = row;
            this.col = col;
            this.height = height;
        }
    }

    public int trapRainWater(int[][] heights) {
        if (heights == null || heights.length == 0 || heights[0].length == 0)
            return 0;

        PriorityQueue<Cell> queue = new PriorityQueue<>(1, new Comparator<Cell>() {
            public int compare(Cell a, Cell b) {
                return a.height - b.height;
            }
        });

        int m = heights.length;
        int n = heights[0].length;
        boolean[][] visited = new boolean[m][n];

        // Initially, add all the Cells which are on borders to the queue.
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            queue.offer(new Cell(i, 0, heights[i][0]));
            queue.offer(new Cell(i, n - 1, heights[i][n - 1]));
        }

        for (int i = 0; i < n; i++) {
            visited[0][i] = true;
            visited[m - 1][i] = true;
            queue.offer(new Cell(0, i, heights[0][i]));
            queue.offer(new Cell(m - 1, i, heights[m - 1][i]));
        }

        // from the borders, pick the shortest cell visited and check its neighbors:
        // if the neighbor is shorter, collect the water it can trap and update its height
        // as its height plus the water trapped
        // add all its neighbors to the queue.

        // poll() : 큐에서 우선순위가 가장 높은 요소를 빼냅니다. 즉 반환 후에 큐에서 삭제됩니다.
        // peek() : poll과 달리 큐에서 삭제하지 않고 가장 우선순위가 높은 요소를 얻습니다.


        //상 하 좌 우
        int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        while (!queue.isEmpty()) {
            Cell cell = queue.poll();

            for (int[] dir : dirs) {
                int row = cell.row + dir[0];
                int col = cell.col + dir[1];

                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = true;

                    //우선순위 큐에서 나온 셀과 인접한 셀의 높이를 비교. 그 차이가 0보다 크다면 담을 수 있는 양이다.
                    //처음에 한 지점에 담을 수 있는 물의 양은 네 방향 전체를 전체를 고려해야 하는 것이 아닌가 생각했다.
                    //그래서 필요한 것이 우선순위 큐와 방문했던 장소에 대한 저장이다.
                    res += Math.max(0, cell.height - heights[row][col]);

                    System.out.println("row : " + row + " col : " + col
                            + " heights[row][col] : " + heights[row][col] +
                            " cell.height : " + cell.height);

                    queue.offer(new Cell(row, col, Math.max(heights[row][col], cell.height)));
                }
            }
        }

        return res;
    }


}
```

<br>

