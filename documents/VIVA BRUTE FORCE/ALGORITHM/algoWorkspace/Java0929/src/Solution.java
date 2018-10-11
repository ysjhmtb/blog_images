
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




    /*
    현재 위치에서 어느 방향을 탐색하고 어느 방향을 탐색하지 말지를 결정해야 한다.
   	결정된 결과를 반환한다. 이 메소드가 실행 전에 현재 위치에 글자가 존재한다면
   	실행할 필요가 없다,
    */


}