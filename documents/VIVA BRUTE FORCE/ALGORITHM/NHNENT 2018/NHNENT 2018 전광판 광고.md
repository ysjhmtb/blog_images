

```java

/*


NHNENT 2018 전광판 광고



입력 )

5 -2

강미나 김도연 김세정 김소혜 김청하

유연정 임나영 전소미 정채연 주결경

최유정 강시라 기희현 김나영 김소희

박소연 윤채경 이해인 전소연 정은우

한혜리 강예빈 권은빈 김다니 김서경



출력 )

김세정 김소혜 김청하 주결경 김소희

김도연 윤채경 강시라 임나영 정은우

강미나 이해인 기희현 전소미 김서경

유연정 전소연 김나영 정채연 김다니

최유정 박소연 한혜리 강예빈 권은빈




1) 사이즈가 5라면 회전시켜야 할 사각형이 5 / 2 = 2개,
   사이즈가 6이라면 회전시켜야 할 사각형이 6 / 2 = 3개.

2) 만약 사이즈가 6이라면 사각형 세개의 시작점은 00, 11, 22가 된다.
   나선형으로 조사한다.

3) 하나의 박스의 시작 인덱스를 방향에 따라 조정한다.




 */


import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution {

    private int arraySize;
    private int direction;
    private String[][] inputArr;
    private List<List<String>> boxStorage;
    String[][] result;


    public Solution(int size, int direction, String[][] inputArr) {
        this.arraySize = size;
        this.direction = direction;
        this.inputArr = inputArr;
        this.boxStorage = new LinkedList<>();
        this.result = new String[size][size];

    }


    public List<String> boxToList(int startI, int startJ) {

        int i = startI;
        int j = startJ;
        int searchLimit = this.arraySize - 2 * startI;
        int lenCount = 0;
        List<String> boxList = new LinkedList<>();

        for (; lenCount < searchLimit; j++) {
            boxList.add(this.inputArr[i][j]);
            lenCount++;
        }

        i++;
        j--;
        lenCount = 0;

        for (; lenCount < searchLimit - 1; i++) {
            boxList.add(this.inputArr[i][j]);
            lenCount++;
        }

        i--;
        j--;
        lenCount = 0;


        for (; lenCount < searchLimit - 1; j--) {
            boxList.add(this.inputArr[i][j]);
            lenCount++;
        }

        i--;
        j++;
        lenCount = 0;

        for (; lenCount < searchLimit - 2; i--) {
            boxList.add(this.inputArr[i][j]);
            lenCount++;
        }

        return boxList;

    }

    public List<String> modifiedList(List<String> boxList, int direction) {

        List<String> results = new LinkedList<>();
        int i = (direction < 0) ? -direction : boxList.size() - direction;

        for (; i < boxList.size(); i++) {
            results.add(boxList.get(i));
        }

        i = 0;
        int rightLimit = (direction < 0) ? Math.abs(direction) : boxList.size() - direction;

        for (; i < rightLimit; i++) {
            results.add(boxList.get(i));
        }

        return results;

    }

    public void listToBox(List<String> boxList, int startI, int startJ) {

        int i = startI;
        int j = startJ;
        int listIndex = 0;
        int searchLimit = this.arraySize - 2 * startI;
        int lenCount = 0;

        for (; lenCount < searchLimit; j++) {

            this.result[i][j] = boxList.get(listIndex++);
            lenCount++;
        }

        i++;
        j--;
        lenCount = 0;

        for (; lenCount < searchLimit - 1; i++) {
            this.result[i][j] = boxList.get(listIndex++);
            lenCount++;
        }

        i--;
        j--;
        lenCount = 0;


        for (; lenCount < searchLimit - 1; j--) {
            this.result[i][j] = boxList.get(listIndex++);
            lenCount++;
        }

        i--;
        j++;
        lenCount = 0;

        for (; lenCount < searchLimit - 2; i--) {
            this.result[i][j] = boxList.get(listIndex++);
            lenCount++;
        }


    }

    public void lastFilling(int i, int j) {
        this.result[i][j] = this.inputArr[i][j];
    }


    public String[][] totalSolution() {
        for (int i = 0; i < (this.arraySize / 2); i++) {
            List<String> temp = this.boxToList(i, i);
            this.boxStorage.add(temp);
        }

        for (int i = 0; i < this.boxStorage.size(); i++) {

            int tempDir = (i % 2 == 0) ? direction : -direction;
            List<String> temp = this.modifiedList(this.boxStorage.get(i), tempDir);
            this.boxStorage.set(i, temp);

        }

        for (int i = 0; i < (this.arraySize / 2); i++) {
            this.listToBox(this.boxStorage.get(i), i, i);

        }

        if ((this.arraySize % 2) != 0) {
            int i = (this.arraySize / 2);
            this.lastFilling(i, i);
        }


        return this.result;
    }


    public static void main(String[] args) {


        String[][] inputArr = {
                {"강미나", "김도연", "김세정", "김소혜", "김청하" },
                {"유연정", "임나영", "전소미", "정채연", "주결경" },
                {"최유정", "강시라", "기희현", "김나영", "김소희" },
                {"박소연", "윤채경", "이해인", "전소연", "정은우" },
                {"한혜리", "강예빈", "권은빈", "김다니", "김서경" }

        };

        int size = 5;
        int direction = -2;

        Solution ref = new Solution(size, direction, inputArr);
        String[][] result = ref.totalSolution();
        for (int i = 0; i < result.length; i++) {

            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }

            System.out.println();
        }


    }


}

```

