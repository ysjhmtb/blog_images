/*
 *  elice 주간 알고리즘 - 행렬의 제곱
 *
 *  크기가 N * N인 행렬이 있을 때, 행렬의 K제곱을 구하는 프로그램을 만들어 보세요!
 *
 *  입력 예시
 *  3 3 행렬의 크기 N과 K
 *
 *  1 2 3
 *  4 5 6
 *  7 8 9
 *
 *
 *  출력 예시
 *  468 576 684
 *  62  305 548
 *  656 34  412
 *
 */


import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {

    }

    public static int getArrCal(int i, int j, int[][] arr1, int[][] arr2) {

        int result = 0;

        for (int k = 0; k < arr1.length; k++) {
            result += (arr1[i][k] * arr2[k][j]);
        }

        return result;
    }

}
