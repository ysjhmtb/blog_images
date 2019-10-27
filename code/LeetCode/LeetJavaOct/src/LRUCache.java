/*
https://leetcode.com/problems/lru-cache/

LRUCache cache = new LRUCache( 2  // capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1

cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)

cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)

cache.get(3);       // returns 3
cache.get(4);       // returns 4

accepted
time complexity O(1)
 */

import java.util.LinkedHashMap;
import java.util.Map;


public class LRUCache extends LinkedHashMap<Integer, Integer> {
    private int capacity;

    /*
    load factor가 크면  (즉, 한 bucket에 많은 element를 넣게 되면) 메모리 절약은 할 수 있으나,
    검색이 힘들어 집니다. 반대로 너무 작으면(bucket의 수가 너무 많으면,) 검색은 빠르겠지만,
    메모리 상의 낭비가 일어나게 됩니다. 그래서 가장 최적의 값은 일반적으로 0.75라고 합니다.
    http://egloos.zum.com/iilii/v/4457500

    public LinkedHashMap(int initialCapacity,
                     float loadFactor,
                     boolean accessOrder)
     https://docs.oracle.com/javase/8/docs/api/java/util/LinkedHashMap.html

     */
    public LRUCache(int capacity) {
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    /*
    eldest - The least recently inserted entry in the map,
    or if this is an access-ordered map, the least recently accessed entry.
    This is the entry that will be removed it this method returns true.
    https://docs.oracle.com/javase/8/docs/api/java/util/LinkedHashMap.html#removeEldestEntry-java.util.Map.Entry-
     */

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */