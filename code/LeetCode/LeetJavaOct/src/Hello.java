
import DataStructures.PQComparable;
import kakao2020.Kakao2020N2;

public class Hello {
    public static void main(String[] args) {
        // [[1,3],[2,6],[8,10],[15,18]]
        int[][] intervals = new int[4][2];
        intervals[0] = new int[]{1, 3};
        intervals[1] = new int[]{2, 6};
        intervals[2] = new int[]{8, 10};
        intervals[3] = new int[]{15, 18};

        MergeIntervals ref = new MergeIntervals();
        int[][] sol = ref.merge(intervals);
        System.out.println(sol);
    }
}
