<br>

> 347. Top K Frequent Elements
>
> Given a non-empty array of integers, return the **k** most frequent elements.
>
> For example,
> Given `[1,1,1,2,2,3]` and k = 2, return `[1,2]`.
>
> **Note:** 
>
> - You may assume *k* is always valid, 1 ≤ *k* ≤ number of unique elements.
> - Your algorithm's time complexity **must be** better than O(*n* log *n*), where *n* is the array's size.

<br>

<hr>

[Java O(n) Solution - Bucket Sort](https://leetcode.com/problems/top-k-frequent-elements/discuss/81602/Java-O(n)-Solution-Bucket-Sort) 의 알고리즘을 참조하여 학습.

<br>

```java

public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        int[] nums = new int[]{1, 1, 1, 2, 2, 3};
        int k = 2;

        System.out.println(ref.topKFrequent(nums, k));


    }
}

/*
입력 :
nums = 1 1 1 2 2 3
k = 2



topKFrequent(nums, k) :

1)
List<Integer>[] bucket = new List[6 + 1]
Map<Integer, Integer> frequencyMap

2)
requencyMap :
i = 0) 1 => 3
i = 1) 2 => 2
i = 2) 3 => 1

3)
bucket :
1 => 3
2 => 2
3 => 1 (i = 0) 1 => 3 이 사용됨.)

4)
res = 1 2

 */


class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {

        List<Integer>[] bucket = new List[nums.length + 1];
        Map<Integer, Integer> frequencyMap = new HashMap<Integer, Integer>();

        for (int n : nums) {
            frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
        }

        for (int key : frequencyMap.keySet()) {
            int frequency = frequencyMap.get(key);
            if (bucket[frequency] == null) {
                bucket[frequency] = new ArrayList<>();
            }
            bucket[frequency].add(key);
        }

        List<Integer> res = new ArrayList<>();

        for (int pos = bucket.length - 1; pos >= 0 && res.size() < k; pos--) {
            if (bucket[pos] != null) {
                res.addAll(bucket[pos]);
            }
        }
        return res;
    }
}

/*
default V getOrDefault(Object key, V defaultValue)

Returns the value to which the specified key is mapped,
or defaultValue if this map contains no mapping for the key.


Set<K> keySet()

Returns a Set view of the keys contained in this map.
The set is backed by the map, so changes to the map are reflected
in the set, and vice-versa. If the map is modified
while an iteration over the set is in progress
(except through the iterator's own remove operation),
the results of the iteration are undefined.
The set supports element removal, which removes the corresponding mapping from the map,
via the Iterator.remove, Set.remove, removeAll, retainAll, and clear operations.
It does not support the add or addAll operations.



boolean addAll(int index, Collection<? extends E> c)

Inserts all of the elements in the specified collection into this list
at the specified position (optional operation). Shifts the element currently
at that position (if any) and any subsequent elements to the right (increases their indices).
The new elements will appear in this list in the order that they are returned
by the specified collection's iterator. The behavior of this operation is undefined
if the specified collection is modified while the operation is in progress.
(Note that this will occur if the specified collection is this list, and it's nonempty.)

Parameters:
index - index at which to insert the first element from the specified collection
c - collection containing elements to be added to this list
 */
```

<br>



