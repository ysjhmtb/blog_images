

public class LeetJava {
    public static void main(String[] args) {

        int[][] maze = new int[5][5];
        maze[0] = new int[]{0, 0, 1, 0, 0};
        maze[1] = new int[]{0, 0, 0, 0, 0};
        maze[2] = new int[]{0, 0, 0, 1, 0};
        maze[3] = new int[]{1, 1, 0, 1, 1};
        maze[4] = new int[]{0, 0, 0, 0, 0};
        int[] start = new int[]{0, 4};
        int[] destination = new int[]{3, 2};

        TheMazeII ref = new TheMazeII();
        System.out.println(ref.shortestDistance(maze,start,destination));

    }
}

