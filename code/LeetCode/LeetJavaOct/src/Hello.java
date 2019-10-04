import kakao2020.Kakao2020N1;

public class Hello {
    public static void main(String[] args) {
        String str1 = "aabbaccc";
        String str2 = "ababcdcdababcdcd";
        String str3 = "abcabcdede";
        String str4 = "abcabcabcabcdededededede";
        String str5 = "xababcdcdababcdcd";

        Kakao2020N1 ref = new Kakao2020N1();
        ref.solution(str1);
        System.out.println(ref.solution(str1));
        System.out.println(ref.solution(str2));
        System.out.println(ref.solution(str3));
        System.out.println(ref.solution(str4));
        System.out.println(ref.solution(str5));
    }
}
