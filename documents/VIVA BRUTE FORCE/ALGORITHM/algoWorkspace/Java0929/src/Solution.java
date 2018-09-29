
/*
NHNENT 2018 카드 섞기


입력 )
10  = C
2   = P
2   = N
3   = N

출력 )
4
7
8
1
5

<- 4 7 8 1 5 6 3 2 9 10



1)
|---|                           |----|
1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 / 10

2)
|---|           |---|
3 / 4 / 5 / 6 / 7 / 8 / 1 / 2 / 9 / 10

3)
|-------|                   |--------|
5 / 6 / 3 / 4 / 7 / 8 / 1 / 2 / 9 / 10

4)
|---------------|
4 / 7 / 8 / 1 / 5 / 6 / 3 / 2 / 9 / 10






        String line = reader.readLine();


 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution {

    public static void main(String[] args) throws IOException {
//        int C = 10;
//        int P = 2;
//        int[] NArr = new int[]{2, 3};

        int C;
        int P;
        int[] NArr;

        List<Integer> NList = new ArrayList<>();

        Solution ref = new Solution();

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String line = reader.readLine();
        C = Integer.parseInt(line);

        line = reader.readLine();
        P = Integer.parseInt(line);

        for (int i = 0; i < P; i++) {
            line = reader.readLine();
            NList.add(Integer.parseInt(line));
        }

        NArr = NList.stream().mapToInt(i -> i).toArray();


        ref.totalSolution(C, P, NArr);
    }


    private List<List<Integer>> tailCardsStorage = new LinkedList<>();


    public void totalSolution(int C, int P, int[] NArr) {

        // 길이 C의 카드 리스트를 만들자.
        List<Integer> cards = this.makeCardsList(C);

        // N = 2, N = 3 인 경우, 이렇게 두번 카드를 섞어야 한다.
        for (int i = 0; i < P; i++) {
            int N = NArr[i];

            int start = N;
            int end = cards.size() - N;

            List<Integer> midCards = this.getMidCards(cards, start, end);
            List<Integer> tailCards = this.getTailCards(cards, start, end);

            this.tailCardsStorage.add(tailCards);

            while (midCards.size() > 2 * N) {
                cards = midCards;
                start = N;
                end = cards.size() - N;

                midCards = this.getMidCards(cards, start, end);
                tailCards = this.getTailCards(cards, start, end);
                this.tailCardsStorage.add(tailCards);
            }

            cards = this.concatenateMidTail(midCards);

        }

        for (int i = 0; i < 5; i++) {
            System.out.println(cards.get(i));
        }


    }


    public List<Integer> concatenateMidTail(List<Integer> midCards) {

        for (int i = tailCardsStorage.size() - 1; i >= 0; i--) {
            List<Integer> temp = this.tailCardsStorage.get(i);

            midCards.addAll(temp);
        }

        return midCards;
    }

    public void setTailCardsStorage(List<Integer> tailCards) {
        this.tailCardsStorage.add(tailCards);
    }

    public void setTailCardsStorageNull() {
        this.tailCardsStorage = null;
    }

    public List<Integer> makeCardsList(int C) {
        List<Integer> cards = new LinkedList<>();

        for (int i = 0; i < C; i++) {
            cards.add(i + 1);
        }

        return cards;

    }

    public List<Integer> getMidCards(List<Integer> cards, int start, int end) {

        List<Integer> midCards = cards.subList(start, end);
        return midCards;
    }

    public List<Integer> getTailCards(List<Integer> cards, int start, int end) {
        List<Integer> tailCards = new LinkedList<>();
        tailCards.addAll(cards.subList(0, start));
        tailCards.addAll(cards.subList(end, cards.size()));

        return tailCards;
    }


}
