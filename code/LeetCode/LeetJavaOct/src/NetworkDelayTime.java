/*
https://leetcode.com/problems/network-delay-time/

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

graph) 2->(1,1) (3,1) 3->(4,1)
heap)   (0,2) (1,1) (1,3) (2,4)
dist)   (1,1) (2,0) (3,1) (4,2)

Accepted
time complexity N log(N)
 */

import java.util.*;

public class NetworkDelayTime {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] edge : times) {
            if (!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }

        PriorityQueue<int[]> heap = new PriorityQueue<>(
                (info1, info2) -> info1[0] - info2[0]
        );
        heap.offer(new int[]{0, K});
        Map<Integer, Integer> dist = new HashMap<>();

        while (!heap.isEmpty()) {
            int[] info = heap.poll();
            int node = info[1], distance = info[0];
            if (dist.containsKey(node))
                continue;
            dist.put(node, distance);
            if (graph.containsKey(node)) {
                for (int[] edge : graph.get(node)) {
                    if (!dist.containsKey(edge[0])) {
                        heap.offer(new int[]{distance + edge[1], edge[0]});
                    }
                }
            }
        }
        if (dist.size() != N)
            return -1;
        int answer = 0;
        for (int i : dist.keySet()) {
            answer = Math.max(answer, dist.get(i));
        }
        return answer;

    }
}

/*
public class NetworkDelayTime {

    public int networkDelayTime(int[][] times, int N, int K) {

        Map<Integer, List<int[]>> graph = new HashMap();
        for (int[] edge : times) {
            if (!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }

        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(
                (info1, info2) -> info1[0] - info2[0]);
        heap.offer(new int[]{0, K});

        Map<Integer, Integer> dist = new HashMap();

        while (!heap.isEmpty()) {
            System.out.println(heap.toArray().toString());
            int[] info = heap.poll();
            int d = info[0], node = info[1];
            if (dist.containsKey(node)) continue;
            dist.put(node, d);
            if (graph.containsKey(node))
                for (int[] edge : graph.get(node)) {
                    int nei = edge[0], d2 = edge[1];
                    if (!dist.containsKey(nei))
                        heap.offer(new int[]{d + d2, nei});
                }
        }

        if (dist.size() != N) return -1;
        int ans = 0;
        for (int cand : dist.values())
            ans = Math.max(ans, cand);
        return ans;
    }
}
*/