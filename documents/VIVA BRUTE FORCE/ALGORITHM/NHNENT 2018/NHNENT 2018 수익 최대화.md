```java

/*
NHNENT 2018 수익 최대화

주어진 가격 예측 데이터를 기반으로 ‘코인’을 사고 팔아서 얻을 수 있는 최대 이익


입력 1)
5
1 1 10 5 7

출력 1)
18 = (9 * 2 - 1) + (2 - 1)


입력 2)
5
5 4 3 2 1

출력 2)
0


입력 3)
5
5 10 5 10 5

출력 3)
9 = (5 * 2 - 1)






현재 인덱스에서 어느 지점에서 최대값으로 팔 수 있는지,
같은 최대값이면 어느 지점이 가장 뒤인지(수수료 감소 목적) 검사한다.

 */


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {


    Map<Integer, Integer> map = new HashMap<>();

    public void setLiPos(int[] arr) {
        int max = 0;
        int target = -1;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] < arr[j] && max <= arr[j]) {
                    max = arr[j];
                    target = j;
                }
            }

            if (target != -1) {
                this.map.put(i, target);
                max = 0;
                target = -1;
            }

        }
    }

    public int calResult(int[] arr) {
        int result = 0;
        List<List<Integer>> checkSto = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            checkSto.add(new ArrayList<>());
        }

        for (int i = 0; i < arr.length; i++) {


            if (this.map.containsKey(i)) {
                int j = this.map.get(i);
                List<Integer> temp = checkSto.get(j);
                temp.add(i);
                checkSto.set(j, temp);
            }

        }

        for (int i = 0; i < checkSto.size(); i++) {
            List<Integer> temp = checkSto.get(i);

            if (temp.size() != 0) {
                for (int j = 0; j < temp.size(); j++) {
                    result += (arr[i] - arr[temp.get(j)]);
                }

                result--;
            }


        }

        return result;
    }


    public static void main(String[] args) {

        Solution ref = new Solution();

        int size = 5;
        int[] arr = new int[]{5, 10, 5, 10, 5};

        ref.setLiPos(arr);
        System.out.println(ref.calResult(arr)); // 9


        ref = new Solution();
        size = 5;
        arr = new int[]{1, 1, 10, 5, 7};

        ref.setLiPos(arr);
        System.out.println(ref.calResult(arr)); // 18

        ref = new Solution();
        size = 5;
        arr = new int[]{5, 4, 3, 2, 1};

        ref.setLiPos(arr);
        System.out.println(ref.calResult(arr)); // 0


    }


}

```

