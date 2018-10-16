
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







import java.util.*;

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

        List<List<Integer>> dirs = ref.getDirection(3, 0, arr);
        String conqueror = ref.getConqueror(3, 0, arr, dirs);
        System.out.println(conqueror);
    }




    /*
    게임을 종료해야 하는지를 검사.
    각 위치가 국가로 위치해 있거나,
    반환 글자가 "NO"이면 종료해도 된다.
    종료 가능하면 true 반환하자.

    */


    /*
    어느 방향을 탐색할지 결정되면, 점령을 할 국가가 있는지,
    있다면 어느 국가인지 반환한다.
    국가가 존재한다면 해당 알파벳을 없다면 "NO"를 반환한다.
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
        String maxState = "";
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

        if ('A' <= curChar.charAt(0) && curChar.charAt(0) <= 'Z') {
            return new ArrayList<>();
        }

        // 상하좌우
        int[][] dirs = new int[][]{
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

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


}