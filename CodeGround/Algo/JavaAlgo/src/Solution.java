/*
https://academy.elice.io/courses/486/lectures/3420/materials/1

elice 주간 알고리즘 - 행렬의 제곱

크기가 N*N인 행렬이 있을 때, 행렬의 K제곱을 구하는 프로그램을 만들어 보세요.


입력

첫 번째 줄에 행렬의 크기 N과 제곱을 할 수 K가 입력됩니다.
( 2 ≤ N ≤ 5)
( 1 ≤ K ≤ 100,000,000,000)

두 번째 줄부터 행렬이 입력됩니다.

행렬의 각 원소는 0 이상 1000 이하의 자연수입니다.


[입력 예시]

3 3
1 2 3
4 5 6
7 8 9


출력

행렬을 K제곱한 결과값을 나타냅니다.

단, 수가 너무 커질 수 있으므로 결과값을 1000으로 나눈 나머지 값을 출력합니다.


[출력 예시]

468 576 684
62 305 548
656 34 412

 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Solution {

    public static void main(String[] args) {

        KMP ref = new KMP("ABCDABCDABEE", "ABCDABE");
        System.out.println(ref.search());
    }

}

class KMP {

    private String string;
    private String pattern;

    /**
     * 길이가 N 인 문자열 S(string) 에서 길이가 M 인 문자열 P(pattern) 를 탐색한다.<br/>
     * 시간복잡도는 O(N+M) 이다.<br/>
     *
     * @param string  원본 문자열
     * @param pattern 찾을 문자열
     */
    public KMP(String string, String pattern) {
        this.string = string;
        this.pattern = pattern;
    }

    public void setString(String string) {
        this.string = string;
    }

    public void setPattern(String pattern) {
        this.pattern = pattern;
    }

    /**
     * @return 문자열이 일치하는 index 의 배열
     */
    public List<Integer> search() {
        List<Integer> searchIndex = new ArrayList<>();

        char[] s = string.toCharArray();
        char[] p = pattern.toCharArray();
        int[] pi = getPI();
        int n = string.length();
        int m = pattern.length();
        int j = 0;


        for (int i = 0; i < n; i++) {
            while (j > 0 && s[i] != p[j]) {// j > 0 : 한 글자 라도 일치한 것이 있는지
                j = pi[j - 1];
            }
            if (s[i] == p[j]) {
                if (j == m - 1) {
                    searchIndex.add(i - m + 1);
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }

        return searchIndex;
    }

    /**
     * 탐색 실패 시 i번째까지 일치 할 경우 몇글자를 건너뛰어야 하는지 알려주는 pi 배열을 구한다.<br/>
     * pi 배열을 구할 때도 search 방식을 적용하여 O(M) 의 시간복잡도를 갖는다.<br/>
     *
     * @return pi 배열
     */
    public int[] getPI() {
        int m = pattern.length();
        int j = 0;
        char[] p = pattern.toCharArray();
        int[] pi = new int[m];

        for (int i = 1; i < m; i++) {
            while (j > 0 && p[i] != p[j]) {
                j = pi[j - 1];  // ?
            }
            if (p[i] == p[j]) {
                pi[i] = ++j;
            }

        }

        return pi;
    }

    public void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ", ");
        }
        System.out.println();
    }


}

