```java
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

        Solution ref = new Solution();

        List<List<Integer>> arr = new ArrayList<>();
        arr.add(Arrays.asList(new Integer[]{1, 2, 3}));
        arr.add(Arrays.asList(new Integer[]{4, 5, 6}));
        arr.add(Arrays.asList(new Integer[]{7, 8, 9}));

        ref.showResult(3, 3, arr);

    }

    public void showResult(int N, int K, List<List<Integer>> arr) {

        int count = 0;

        List<List<Integer>> result = this.deepcopy(arr);


        while (count < K - 1) {
            List<List<Integer>> temp = this.deepcopy(result);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    result.get(i).set(j, this.matMul(i, j, N, temp, arr) % 1000);
                }
            }


            count++;
        }

        System.out.println(result);

    }

    public int matMul(int i, int j, int N, List<List<Integer>> arr1, List<List<Integer>> arr2) {

        int sum = 0;
        for (int k = 0; k < N; k++) {
            sum += (arr1.get(i).get(k) * arr2.get(k).get(j));
        }

        return sum;
    }

    public List<List<Integer>> deepcopy(List<List<Integer>> input) {

        List<List<Integer>> temp = new ArrayList<>();

        for (int i = 0; i < input.size(); i++) {
            temp.add(new ArrayList<>());
            for (int j = 0; j < input.get(0).size(); j++) {
                temp.get(i).add(input.get(i).get(j));
            }
        }

        return temp;

    }


}

```

