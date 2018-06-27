> 841. Keys and Rooms
>
> There are `N` rooms and you start in room `0`.  Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. 
>
> Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`.  A key `rooms[i][j] = v` opens the room with number `v`.
>
> Initially, all the rooms start locked (except for room `0`). 
>
> You can walk back and forth between rooms freely.
>
> Return `true` if and only if you can enter every room.
>
>
> **Example 1:**
>
> ```
> Input: [[1],[2],[3],[]]
> Output: true
> Explanation:  
> We start in room 0, and pick up key 1.
> We then go to room 1, and pick up key 2.
> We then go to room 2, and pick up key 3.
> We then go to room 3.  Since we were able to go to every room, we return true.
> ```
>
> **Example 2:**
>
> ```
> Input: [[1,3],[3,0,1],[2],[0]]
> Output: false
> Explanation: We can't enter the room with number 2.
> ```
>
> **Note:**
>
> 1. `1 <= rooms.length <= 1000`
> 2. `0 <= rooms[i].length <= 1000`
> 3. The number of keys in all rooms combined is at most `3000`.

<br>

[Straight Forward](https://leetcode.com/problems/keys-and-rooms/discuss/133855/Straight-Forward) 의 다음 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();


        Integer[] room1 = new Integer[]{1, 3};
        Integer[] room2 = new Integer[]{3, 0, 1};
        Integer[] room3 = new Integer[]{2};
        Integer[] room4 = new Integer[]{0};


        List<List<Integer>> rooms = new LinkedList<>();
        rooms.add(Arrays.asList(room1));
        rooms.add(Arrays.asList(room2));
        rooms.add(Arrays.asList(room3));
        rooms.add(Arrays.asList(room4));

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms.get(i).size(); j++) {
                System.out.println(rooms.get(i).get(j));
            }
        }


        System.out.println(ref.canVisitAllRooms(rooms));

    }
}

class Solution {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Stack<Integer> dfs = new Stack<>();
        dfs.add(0);
        HashSet<Integer> seen = new HashSet<Integer>();
        seen.add(0);

        while (!dfs.isEmpty()) {
            int i = dfs.pop();
            for (int j : rooms.get(i))
                if (!seen.contains(j)) {
                    //방문해야 할 방을 저장.
                    dfs.add(j);
                    //방문했던 방을 저장.
                    seen.add(j);
                    //방문했던 곳은 중복저장 되지 않으므로 방의 사이즈와 방문한 곳의 사이즈가
                    //같다면 모든 방을 방문할 수 있는 셈이다.
                    if (rooms.size() == seen.size())
                        return true;
                }
        }
        return rooms.size() == seen.size();
    }

}
```

<br>

