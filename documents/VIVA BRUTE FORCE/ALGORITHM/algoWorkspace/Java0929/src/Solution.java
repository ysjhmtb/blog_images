/*
NHNENT 2018 점령지 확장

보기 입력 1
5↵
A ␣0 ␣0 ␣0 ␣0↵
0 ␣0 ␣6 ␣0 ␣D↵
0 ␣0 ␣B ␣0 ␣0↵
0 ␣C ␣8 ␣0 ␣0↵
0 ␣0 ␣0 ␣0 ␣0↵

출력 1
3↵
A ␣A ␣A ␣D ␣D↵
A ␣A ␣D ␣D ␣D↵
0 ␣0 ␣B ␣B ␣D↵
C ␣C ␣C ␣B ␣D↵
C ␣C ␣C ␣0 ␣D↵

보기 입력 2
5↵
A ␣0 ␣0 ␣0 ␣0↵
0 ␣0 ␣0 ␣0 ␣0↵
0 ␣0 ␣0 ␣0 ␣0↵
0 ␣0 ␣0 ␣0 ␣0↵
0 ␣0 ␣0 ␣0 ␣B↵

출력 2
3↵
A ␣A ␣A ␣A ␣0↵
A ␣A ␣A ␣0 ␣B↵
A ␣A ␣0 ␣B ␣B↵
A ␣0 ␣B ␣B ␣B↵
0 ␣B ␣B ␣B ␣B↵

보기 입력 3
5↵
A ␣0 ␣0 ␣0 ␣10↵
0 ␣0 ␣0 ␣10 ␣0↵
0 ␣0 ␣10 ␣0 ␣0↵
0 ␣10 ␣0 ␣0 ␣0↵
10 ␣0 ␣0 ␣0 ␣0↵

출력 3
4↵
A ␣A ␣A ␣A ␣A↵
A ␣A ␣A ␣A ␣0↵
A ␣A ␣A ␣0 ␣0↵
A ␣A ␣0 ␣0 ␣0↵
A ␣0 ␣0 ␣0 ␣0↵
 */


/*

1)
5
A 0 0 0 0
0 0 6 0 D
0 0 B 0 0
0 C 8 0 0

2)
A A 0 0 D
A 0 6 D D
0 0 B B D
C C 8 0 0
0 C 0 0 0

3)
A A A D D
A A D D D
0 0 B B D
C C 8 B D
C C C 0 0

4)
3
A A A D D
A A D D D
0 0 B B D
C C C B D
C C C 0 D

 */


import java.util.*;

class Result {

    List<List<String>> result;
    int count;

    public Result(List<List<String>> arr, int count) {
        result = arr;
        this.count = count;
    }
}


class Solution {
    public static void main(String[] args) {
        List<List<String>> arr = new ArrayList<>();

        int N = 5;
        String[] a1 = new String[]{"A", "0", "0", "0", "0"};
        String[] a2 = new String[]{"0", "0", "6", "0", "D"};
        String[] a3 = new String[]{"0", "0", "B", "0", "0"};
        String[] a4 = new String[]{"0", "C", "8", "0", "0"};
        String[] a5 = new String[]{"0", "0", "0", "0", "0"};


        arr.add(Arrays.asList(a1));
        arr.add(Arrays.asList(a2));
        arr.add(Arrays.asList(a3));
        arr.add(Arrays.asList(a4));
        arr.add(Arrays.asList(a5));


        Solution ref = new Solution();

        System.out.println(ref.canExit(arr));

        List<List<Integer>> dirs = ref.getDirection(0, 0, arr);
        System.out.println(ref.getConqueror(0, 0, arr, dirs));

        dirs = ref.getDirection(0, 1, arr);
        System.out.println(ref.getConqueror(0, 1, arr, dirs));


        Result result = ref.getResult(arr);
        System.out.println(result.count);
        System.out.println(result.result);

    }


    public List<List<String>> getDeepCopy(List<List<String>> arr) {

        List<List<String>> deepcopy = new ArrayList<>();

        for (int i = 0; i < arr.size(); i++) {
            List<String> temp = new ArrayList<>();
            for (int j = 0; j < arr.get(0).size(); j++) {
                String tmpStr = arr.get(i).get(j);
                temp.add(tmpStr);
            }
            deepcopy.add(temp);

        }
        return deepcopy;

    }


    /*
    현재 인덱스에 글자가 아닌 숫자가 존재하고, 지배적인 국가가 존재한다면
    깊은 복사를 통해 생성된 저장소에서 변경이 이루어져야 하며, 이후 인덱스에서의
    조사는 새로 생성된 저장소가 아닌 원본을 기준으로 조사가 이루어져야 한다.

     */

    public Result getResult(List<List<String>> arr) {

        int count = 0;
        List<List<String>> newStorage = new ArrayList<>();
        newStorage = this.getDeepCopy(arr);


        while (!this.canExit(arr)) {

            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr.get(0).size(); j++) {

                    String cur = arr.get(i).get(j);

                    // 이미 숫자가 아니라 국가가 존재한다면 continue
                    if ('A' <= cur.charAt(0) && cur.charAt(0) <= 'Z')
                        continue;

                    List<List<Integer>> dirs = this.getDirection(i, j, arr);
                    String conqueror = this.getConqueror(i, j, arr, dirs);

                    // conqueror가 "NO"가 아니라면 새로운 저장소에서 수정을 한다.
                    if (!conqueror.equals("NO")) {
                        List<String> jTemp = newStorage.get(i);
                        jTemp.set(j, conqueror);
                    }
                }
            }

            count++;
            arr = this.getDeepCopy(newStorage);
        }

        Result result = new Result(arr, count);
        return result;


    }




    /*
    게임을 종료해야 하는지를 검사.
    각 위치가 국가로 위치해 있거나,
    반환 글자가 "NO"이면 종료해도 된다.
    종료 가능하면 true 반환하자.

    위와 같은 방법을 수정해야 한다.

    숫자가 있는 곳에서 지배자가 나올 수 없으면 종료해야 한다.
    true

    */

    public boolean canExit(List<List<String>> arr) {
        boolean flag = true;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.get(0).size(); j++) {

                String curPos = arr.get(i).get(j);

                if ('A' <= curPos.charAt(0) && curPos.charAt(0) <= 'Z')
                    continue;

                List<List<Integer>> dirs = this.getDirection(i, j, arr);
                String conqueror = this.getConqueror(i, j, arr, dirs);

                if (!(conqueror.equals("NO"))) {
                    flag = false;
                }

            }
        }

        return flag;
    }


    /*
    어느 방향을 탐색할지 결정되면, 점령을 할 국가가 있는지,
    있다면 어느 국가인지 반환한다.
    우위 국가가 없다면 "NO"를 반환한다.
    "NO"를 반환받으면 숫자를 "NO"로 수정하지는 말아야 한다.
    */

    public String getConqueror(int i, int j, List<List<String>> arr, List<List<Integer>> dirs) {

        List<String> states = new ArrayList<>();
        Map<String, Integer> count = new HashMap<>();

        for (int k = 0; k < dirs.size(); k++) {

            List<Integer> tempDir = dirs.get(k);
            if (tempDir.size() == 0)
                continue;

            String state = arr.get(tempDir.get(0)).get(tempDir.get(1));

            if (!('A' <= state.charAt(0) && state.charAt(0) <= 'Z'))
                continue;

            states.add(state);
            count.put(state, count.getOrDefault(state, 0) + 1);

        }

        // 가장 우위를 점하고 있는 국가의 수
        int maxCount = -1;
        String maxState = "NO";
        boolean duplFlag = false;

        for (int k = 0; k < states.size(); k++) {

            if (maxCount < count.get(states.get(k))) {
                maxCount = count.get(states.get(k));
                maxState = states.get(k);
            }
        }

        // 가장 우위에 있는 수와 동일한 국가의 존재 여부 조사
        for (int k = 0; k < states.size(); k++) {

            if (maxCount == count.get(states.get(k)) && !maxState.equals(states.get(k))) {
                duplFlag = true;
            }

        }

        if (duplFlag) {
            return "NO";
        } else {
            return maxState;
        }

    }


    /*
    현재 위치에서 어느 방향을 탐색하고 어느 방향을 탐색하지 말지를 결정해야 한다.
       결정된 결과를 반환한다. 이 메소드가 실행 전에 현재 위치에 글자가 존재한다면
       실행할 필요가 없다,
    */


    public List<List<Integer>> getDirection(int i, int j, List<List<String>> arr) {

        String curChar = arr.get(i).get(j);
        List<List<Integer>> result = new ArrayList<>();

        for (int k = 0; k < 4; k++) {
            result.add(new ArrayList<Integer>());
        }

        if ('A' <= curChar.charAt(0) && curChar.charAt(0) <= 'Z') {
            return new ArrayList<>();
        }

        // 상하좌우
        int[][] dirs = new int[][]{
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int cur = Integer.valueOf(curChar);
        // 1 + 2 + 4 + 8 = 15

        if (cur == 0) {

            for (int k = 0; k < dirs.length; k++) {
                int[] tempDir = dirs[k];
                int ti = i, tj = j;
                ti += tempDir[0];
                tj += tempDir[1];

                List<Integer> temp = new ArrayList<>();

                if (0 <= ti && ti < arr.size() && 0 <= tj && tj < arr.size()) {

                    temp.add(ti);
                    temp.add(tj);
                    result.add(temp);
                } else {

                    result.add(temp);
                }

            }

            return result;
        }


        if (cur >= 8) {
            cur -= 8;
            result.set(3, new ArrayList<Integer>());
        }

        if (cur >= 4) {
            cur -= 4;
            result.set(2, new ArrayList<>());
        }

        if (cur >= 2) {
            cur -= 2;
            result.set(1, new ArrayList<>());

        }

        if (cur >= 1) {
            cur -= 1;
            result.set(0, new ArrayList<>());
        }

        for (int k = 0; k < dirs.length; k++) {

            if (result.get(k) != null && result.get(k).size() == 0) {
                continue;
            }

            int[] tempDir = dirs[k];
            int ti = i, tj = j;
            ti += tempDir[0];
            tj += tempDir[1];

            List<Integer> temp = new ArrayList<>();

            if (0 <= ti && ti < arr.size() && 0 <= tj && tj < arr.size()) {

                temp.add(ti);
                temp.add(tj);
                result.add(temp);
            } else {

                result.add(temp);
            }

        }


        return result;
    }


}