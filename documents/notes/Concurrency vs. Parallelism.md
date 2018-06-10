<h1>[Concurrency vs. Parallelism](https://howtodoinjava.com/core-java/multi-threading/concurrency-vs-parallelism/)</h1>

> Concurrency means multiple tasks which start, run, and complete **in overlapping time periods,** in no specific order. Parallelism is when multiple tasks OR several part of a unique task **literally run at the same time, e.g. on a multi-core processor.** Remember that Concurrency and parallelism are **NOT the same thing.**

<br>

> <h2>Differences between concurrency vs. parallelism</h2>
>
> Now let’s list down remarkable differences between concurrency and parallelism.
>
> Concurrency is when two tasks can start, run, and complete in overlapping time periods. Parallelism is when tasks literally run at the same time, eg. on a multi-core processor.
>
> Concurrency is the composition of independently executing processes, while parallelism is the simultaneous execution of (possibly related) computations.
>
> Concurrency is about **dealing with lots of things** at once. Parallelism is about **doing lots of things** at once.
>
> An application can be concurrent – but not parallel, which means that it processes more than one task at the same time, but no two tasks are executing at same time instant.
>
> An application can be parallel – but not concurrent, which means that it processes multiple sub-tasks of a task in multi-core CPU at same time.
>
> An application can be neither parallel – nor concurrent, which means that it processes all tasks one at a time, sequentially.
>
> An application can be both parallel – and concurrent, which means that it processes multiple tasks concurrently in multi-core CPU at same time .
>
> That’s all about Concurrency vs. Parallelism, a very important concept in java multi-threading concepts.

<br>

<br>

<br>

예전에 내가 작성했던 쓰레드. <br>

```java
public class Run {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TheRoom start = new TheRoom();
		
		Runnable task1 = ()->{
			
			start.setTitle("THE ROOM");
			start.setLocation(300, 130);
			start.setSize(1280, 800);
			start.setResizable(false);
			start.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			start.setIconImage(new ImageIcon("img/favicon.jpg").getImage());
			start.setVisible(true);
		};
		
		Runnable task2 = ()->{
			start.flowtime(start.timeBox, 600);
		};
		
		ExecutorService exr = Executors.newFixedThreadPool(2);
		exr.submit(task1);
		exr.submit(task2);
		exr.shutdown();
		
		

	}

}
```

<br>

<br>

<br>

<h1>[Java concurrency (multi-threading) - Tutorial](http://www.vogella.com/tutorials/JavaConcurrency/article.html)</h1>

<br>

> <h2>What is concurrency?</h2>
>
> Concurrency is the ability to run several programs or several parts of a program in parallel. If a time consuming task can be performed **asynchronously or in parallel**, this improve the throughput and the interactivity of the program.
>
> A modern computer has **several CPU’s** or **several cores within one CPU**. The ability to leverage these multi-cores can be the key for a successful high-volume application.

<br>

> <h2>Process vs. threads</h2>
>
> A **process** runs **independently** and isolated of **other processes**. It **cannot directly access** shared data in other processes. The resources of the process, e.g. memory and CPU time, are allocated to it **via the operating system**.
>
> A **thread** is a so called lightweight process. It has its own call stack, but **can access** shared data of other threads in the same process. Every thread **has its own memory cache.** If a thread reads shared data it stores this data in its own memory cache. A thread can re-read the shared data.
>
> A Java application runs **by default in one process.** Within a Java application you work **with several threads** to achieve parallel processing or asynchronous behavior.

<br>

> <h2> Limits of concurrency gains</h2>
>
> Within a Java application you work with several threads to achieve parallel processing or asynchronous behavior. Concurrency promises to perform certain task **faster** as these tasks can be divided into subtasks and these subtasks can be executed in parallel. **Of course the runtime is limited by parts of the task which can be performed in parallel.**
>
> The theoretical possible performance gain can be calculated by the following rule which is referred to as **Amdahl’s Law**.
>
> If **F** is the percentage of the program which can not run in parallel and **N** is the number of processes, then **the maximum performance gain** is 1 / (F+ ((1-F)/n)).
>

<br>

> <h2>Concurrency issues</h2>
>
> A **visibility problem** occurs if thread A reads shared data which is later changed by thread B and thread A is unaware of this change.
>
> An **access** problem can occur if several thread access and change the same shared data at the same time.
>
> Visibility and access problem can lead to
>
> - Liveness failure: The program does not react anymore due to problems in the concurrent access of data, e.g. deadlocks.
> - Safety failure: The program creates incorrect data.

<br>

> <h2>The Java memory model</h2>
>
> The *Java memory model* describes the communication between the memory of the threads and the main memory of the application.
>
> It defines the rules how changes in the memory done by threads **are propagated to other threads.**
>
> The *Java memory model* also defines the situations in which a thread **re-fresh its own memory** from the main memory.
>
> It also describes which operations are atomic and the ordering of the operations.

<br>

> <h2>Atomic operation</h2>
>
> An atomic operation is an operation which **is performed as a single unit of work** without the possibility of interference from other operations.
>
> The Java language specification guarantees that reading or writing a variable is an atomic operation(unless the variable is of type `long` or `double` ). Operations variables of type `long` or `double` are only atomic if they declared with the`volatile` keyword.
>
> Assume `i` is defined as `int`. The `i++` (increment) operation it **not an atomic operation** in Java. This also applies for the other numeric types, e.g. long. etc).
>
> The `i++` operation first reads the value which is currently stored in i (atomic operations) and then it adds one to it (atomic operation). But **between the read and the write** the value of i might have changed.
>
> Since Java 1.5 the java language provides atomic variables, e.g. AtomicInteger or AtomicLong which provide methods like `getAndDecrement()`, `getAndIncrement()` and `getAndSet()` which are atomic.

<br><br><br>



































