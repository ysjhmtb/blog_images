
import DataStructures.PQComparable;
import kakao2020.Kakao2020N2;

public class Hello {


    public static void main(String[] args) {


//        Kakao2020N2 ref = new Kakao2020N2();
//        ref.solution(")(");
//        System.out.println("result: " + ref.solution("(()())()"));
//        System.out.println("result: " + ref.solution(")("));
//        System.out.println("result: " + ref.solution("()))((()"));
//        System.out.println("reulst: " + ref.solution(")()()("));
//        System.out.println("reulst: " + ref.solution(")()("));
//        ref.solution(")()(");

        NumberOfIslands ref = new NumberOfIslands();
        char[][] grid = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        System.out.println(ref.numIslands(grid));


    }
}
