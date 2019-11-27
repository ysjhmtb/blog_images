/*
https://leetcode.com/problems/merge-intervals/

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].


Accepted
time complexity : N log(N)
 */



import java.util.*;


public class MergeIntervals {

    private class Container {
        int start;
        int end;

        public Container(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    private class ContainerComparator implements Comparator<Container> {
        @Override
        public int compare(Container a, Container b) {
            return a.start < b.start ? -1 : a.start == b.start ? 0 : 1;
        }
    }


    public int[][] merge(int[][] intervals) {
        List<Container> intervalList = new LinkedList<>();
        for (int[] inter : intervals) {
            intervalList.add(new Container(inter[0], inter[1]));
        }
        Collections.sort(intervalList, new ContainerComparator());
        List<Container> merged = new LinkedList<>();
        for (Container interval : intervalList) {
            if (merged.isEmpty() || merged.get(merged.size() - 1).end < interval.start) {
                merged.add(interval);
            } else {
                merged.get(merged.size() - 1).end = Math.max(merged.get(merged.size() - 1).end, interval.end);
            }
        }

        int[][] result = new int[merged.size()][2];
        for (int i = 0; i < merged.size(); i++) {
            int[] tmp = new int[2];
            tmp[0] = merged.get(i).start;
            tmp[1] = merged.get(i).end;
            result[i] = tmp;
        }
        return result;
    }
}
