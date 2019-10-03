/*
https://leetcode.com/problems/the-maze-ii/
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)
Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
지금 지점이 1이거나 범위를 벗어나면 장벽인 것이다. 카운트 증가를 중단한다.
필요한 경우 무한대를 업데이트 하고, 벽을 마주한 지점에서 다시 시작점을 만들어 재귀를 사용한다.
? ?  ?   1  0
5 4  3   2  ?
6 7  8   ?  ?
? ?  9   ?  ?
? ? 10  11 12
Accepted
time complexity O(M * N * max(M, N))
- 제한사항이 없는, 즉 상하좌우에 막혀있지 않는 곳이라면 한칸씩 갈 수 있는 미로 문제를 생각해 보자.
- 지나간 길을 모두 stack에 넣으면서 앞이 막히는 경우 새로운 방법이 있을 때까지 pop해서 후퇴하는 방법.
- 현재 위치가 i, j이고 여태까지 지나온 길이 stack에 있을 때, 상하좌우를 검사해서 갈 수 있은 곳이면 stack에 push.
- 다음 item을 stack에서 꺼내서 계속 진행.
- 이 경우 최악의 경우는 모든 칸을 다 방문해야 하는 경우이고, 한 칸당 4번의 칸을 다시 방문해야 하기 때문에 O(M * N * 4) = O(M * N)
- 원래의 문제로 돌아오면, 여기서는 한 방향당 최대 M 또는 N까지 갈 수 있음. 그런 점에서 O(M * N * Max(M, N)) 보다 O(M * N * (M + N))이
  더 적합할 것으로 생각됨.
 */

import java.util.Arrays;

public class TheMazeII {

    public int shortestDistance(int[][] maze, int[] start, int[] destination) {

        int[][] distance = new int[maze.length][maze[0].length];
        for (int[] one : distance)
            Arrays.fill(one, Integer.MAX_VALUE);

        distance[start[0]][start[1]] = 0;
        this.dfs(maze, start, distance);

        return distance[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : distance[destination[0]][destination[1]];

    }

    public void dfs(int[][] maze, int[] start, int[][] distance) {
        int[][] dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for (int[] dir : dirs) {
            int count = 0;
            int x = start[0] + dir[0];
            int y = start[1] + dir[1];
            while (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0) {
                x += dir[0];
                y += dir[1];
                count++;
            }
            if (distance[start[0]][start[1]] + count < distance[x - dir[0]][y - dir[1]]) {
                distance[x - dir[0]][y - dir[1]] = distance[start[0]][start[1]] + count;
                this.dfs(maze, new int[]{x - dir[0], y - dir[1]}, distance);
            }
        }
    }

}
