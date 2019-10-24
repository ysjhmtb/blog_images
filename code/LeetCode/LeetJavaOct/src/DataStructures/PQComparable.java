package DataStructures;

import java.util.PriorityQueue;

public class PQComparable {
    PriorityQueue<Student> priorityQueue = new PriorityQueue<>();

    public PriorityQueue<Student> getPriorityQueue() {
        priorityQueue.offer(new Student("김철수", 20));
        priorityQueue.offer(new Student("김영희", 100));
        priorityQueue.offer(new Student("한택희", 66));
        priorityQueue.offer(new Student("이나영", 7));
        priorityQueue.offer(new Student("이혁", 43));
        priorityQueue.offer(new Student("안영희", 100));
        return priorityQueue;
    }

    public void printElements() {
        PriorityQueue<Student> ref = this.getPriorityQueue();

        // 나이 내림차순
        while (!ref.isEmpty()) {
            System.out.println(ref.poll());
        }

        // 나이 오름차순
        PriorityQueue<Student> ref2 = new PriorityQueue<>(2,
                (Student p1, Student p2) -> p1.age >= p2.age ? 1 : -1);
        ref2.offer(new Student("이나영", 7));
        ref2.offer(new Student("안영희", 100));

        while (!ref2.isEmpty()) {
            System.out.println(ref2.poll());
        }

    }
}

class Student implements Comparable<Student> {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Student target) {
        return this.age <= target.age ? 1 : -1;
    }

    @Override
    public String toString() {
        return "이름 : " + name + ", 나이 : " + age;
    }
}
