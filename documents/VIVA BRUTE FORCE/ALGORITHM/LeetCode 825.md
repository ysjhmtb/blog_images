> [825. Friends Of Appropriate Ages](https://leetcode.com/problems/friends-of-appropriate-ages/description/)
>
> Some people will make friend requests. The list of their ages is given and `ages[i]` is the age of the ith person. 
>
> Person A will NOT friend request person B (B != A) if any of the following conditions are true:
>
> - `age[B] <= 0.5 * age[A] + 7`
> - `age[B] > age[A]`
> - `age[B] > 100 && age[A] < 100`
>
> Otherwise, A will friend request B.
>
> Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.
>
> How many total friend requests are made?
>
> **Example 1:**
>
> ```
> Input: [16,16]
> Output: 2
> Explanation: 2 people friend request each other.
> ```
>
> **Example 2:**
>
> ```
> Input: [16,17,18]
> Output: 2
> Explanation: Friend requests are made 17 -> 16, 18 -> 17.
> ```
>
> **Example 3:**
>
> ```
> Input: [20,30,100,110,120]
> Output: 
> Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
> ```
>
>  
>
> Notes:
>
> - `1 <= ages.length <= 20000`.
> - `1 <= ages[i] <= 120`.

<br>

[10ms concise Java  solution, O(n) time and O(1) space](https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127341/10ms-concise-Java-solution-O(n)-time-and-O(1)-space) 의 알고리즘.

```java

public class HelloWorld {

    public static void main(String[] args) {

        int[] arr1 = new int[]{16, 16};
        int[] arr2 = new int[]{16, 17, 18};
        int[] arr3 = new int[]{20, 30, 100, 110, 120};

        Solution ref = new Solution();

        System.out.println(ref.numFriendRequests(new int[]{14, 14, 15})); //0
        System.out.println(ref.numFriendRequests(new int[]{1, 3, 4, 7}));  //0


        System.out.println(ref.numFriendRequests(arr1));    //2
        System.out.println(ref.numFriendRequests(arr2));    //2
        System.out.println(ref.numFriendRequests(arr3));    //3


    }


}


class Solution {

    /*
    Three conditions could be merged to one:
    The Person with age A can request person with age B if

    B is in range ( 0.5 * A + 7, A ]

    A의 나이가 40세라면 B의 나이는 28세 ~ 40세여야 A가 친구를 신청할 수 있다.
     */

    public int numFriendRequests(int[] ages) {
        int res = 0;
        //나이의 범위가 1 <= ages[i] <= 120
        int[] numInAge = new int[121], sumInAge = new int[121];

        //입력받은 나이가 무엇이 몇개 있는지 기록
        for (int i : ages)
            numInAge[i]++;

        //현재 i에서 나이의 합 기록
        for (int i = 1; i <= 120; ++i)
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];

        //i가 1부터 시작하면 테스트 케이스를 통과하지 못 했음.
        //age[B] <= 0.5 * age[A] + 7
        //즉 A의 나이가 14라면 B가 15세 이상이어야 한다. B가 14세라면 신청하지 않는다.
        //따라서 15부터 검사하면 된다.
        for (int i = 15; i <= 120; ++i) {
            if (numInAge[i] == 0)
                continue;

            //입력이 {14, 14, 15}라면
            //i = 15에서
            //i / 2 + 7 = 14
            //sumInAge[i] = 3
            //sumInAge[i / 2 + 7] = 2
            //count = 3 - 2 = 1
            System.out.println(i / 2 + 7);
            System.out.println(sumInAge[i]);
            System.out.println(sumInAge[i / 2 + 7]);


            int count = sumInAge[i] - sumInAge[i / 2 + 7];
            res += count * numInAge[i] - numInAge[i];
            //people will not friend request themselves, so  - numInAge[i]


        }

        return res;
    }
}


```



[Easy and Straight Forward](https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127029/C++JavaPython-Easy-and-Straight-Forward) 의 알고리즘.

```java
import sun.tools.jstat.Literal;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}


public class HelloWorld {

    public static void main(String[] args) {

        int[] arr1 = new int[]{16, 16};
        int[] arr2 = new int[]{16, 17, 18};
        int[] arr3 = new int[]{20, 30, 100, 110, 120};

        Solution ref = new Solution();

        System.out.println(ref.numFriendRequests(new int[]{14, 14, 15})); //0
        System.out.println(ref.numFriendRequests(new int[]{1, 3, 4, 7}));  //0


        System.out.println(ref.numFriendRequests(arr1));    //2
        System.out.println(ref.numFriendRequests(arr2));    //2
        System.out.println(ref.numFriendRequests(arr3));    //3


    }


}


class Solution {

    public int numFriendRequests(int[] ages) {
        Map<Integer, Integer> count = new HashMap<>();

        //키-밸류 를 이용하여 입력받은 나이의 갯수를 기록
        for (int age : ages)
            count.put(age, count.getOrDefault(age, 0) + 1);

        int res = 0;


        //현재 조사하는 나이 a에서 신청할 수 있는 경우의 수를 기록
        for (Integer a : count.keySet())
            for (Integer b : count.keySet())

                if (request(a, b))
                    res += count.get(a) * (count.get(b) - (a == b ? 1 : 0));

        return res;
    }

    private boolean request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
}



```

 

알고리즘을 JavaScript로 옮겨 보았다.

```javascript
/**
 * @param {number[]} ages
 * @return {number}
 */

const request = function (a, b) {

    a *= 1;
    b *= 1;

    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

var numFriendRequests = function (ages) {

    let count = new Map();


    ages.forEach(function (age) {

        if (count.has(age)) {
            count.set(age, count.get(age) + 1);
        } else {
            count.set(age, 1);
        }

    });

    let res = 0;

    let countKeys = Array.from(count.keys());



    countKeys.forEach(function (a) {
        countKeys.forEach(function (b) {

            a *= 1;
            b *= 1;

            if (request(a, b)) {
                if (a == b) {
                    res += count.get(a) * (count.get(b) - 1);
                } else {
                    res += count.get(a) * count.get(b);
                }
            }

        })
    })

    return res;


};

console.log(numFriendRequests([14, 14, 15]));   // 0 
console.log(numFriendRequests([1, 3, 4, 7]));   // 0
console.log(numFriendRequests([16, 16]));       // 2
console.log(numFriendRequests([16, 17, 18]));   // 2
console.log(numFriendRequests([20, 30, 100, 110, 120]));    // 3

```

