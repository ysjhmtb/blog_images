
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

        NetworkDelayTime ref = new NetworkDelayTime();
        int[][] times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        int N = 4;
        int K = 2;

        System.out.println(ref.networkDelayTime(times, N, K));;

    }
}
