## C++ initialization





```c++
int a = 123;	// copy initialization
int b(123);		// direct initialization
int c{123};		// uniform initialization	

int k = 0, l(456), m{123};
```





b에 실수를 넣으면 워닝이 뜨고, c에 실수를 넣으면 에러가 뜬다. uniform initialization이 좀 더 엄격하다.







