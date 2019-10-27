
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


        LRUCache cache = new LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));// returns 1
        cache.put(3, 3);    // evicts key 2
        System.out.println(cache.get(2));// returns -1 (not found)
        cache.put(4, 4);    // evicts key 1
        System.out.println(cache.get(1));// returns -1 (not found)
        System.out.println(cache.get(3));// returns 3
        System.out.println(cache.get(4));// returns 4

    }
}
