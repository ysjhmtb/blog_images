# Clang and beginning

<br>

CLion과 같은 IDE가 아니라 Vim이나 VSCode 같은 에디터로 C/C++ 코드를 작성하고, Clang으로 터미널에서 컴파일을 시도하다 보니 IDE가 자동으로 해주던 것을 숙지해야 할 필요가 있다.

<br>

1) [How do I compile C++ with Clang?](https://stackoverflow.com/questions/9148488/how-do-i-compile-c-with-clang) <br>

`clang++ -Wall -std=c++11 test.cpp -o test` 를 터미널에 입력하면, `test` 라는 실행파일을 만들게 되고 `./test` 를 통해 실행시킬 수 있다. 만일 `clang++ test.cpp` 를 터미널에 입력하면, `a.out` 이라는 실행파일이 만들어 지고 `./a.out` 을 사용하면 실행시킬 수 있다. <br>

<br>

2) [make와 Makefile](https://bowbowbow.tistory.com/12) <br>

<br>

```C++
// diary.h

#include <stdio.h>
void memo();
void calendar();

```

<br>

```C++
// memo.c

#include "diary.h"
void memo(){
    printf("I'm function Memo! \n");
}
```

<br>

```C++
// calendar.c

#include "diary.h"
void calendar(){
    printf("I'm function Calendar() \n");
}
```

<br>

```C++
// main.c

#include "diary.h"

int main(void){
    memo();
    calendar();
    return 0;
}
```

<br>

3) Makefile의 구성

<br>

```
목적파일(Target) : 명령어가 수행되어 나온 결과를 저장할 파일
의존성(Dependency) : 목적파일을 만들기 위해 필요한 재료
명령어(Command) : 실행되어야 할 명령어들
매크로(Macro) : 코드를 단순화시키기 위한 방법
```

<br>

```makefile
# Makefile

# 타겟절 : 의존성
# 	(tab) 명령어
diary_exe : memo.o calendar.o main.o
	gcc -o diary_exe memo.o calendar.o main.o

memo.o : memo.c
	gcc -c -o memo.o memo.c

calendar.o : calendar.c
	gcc -c -o calendar.o calendar.c

main.o : main.c
	gcc -c -o main.o main.c

# 더미타겟
clean :
	rm *.o diary_exe

```

<br>

```bash
$ make clean
$ make
$ ./diary_exe
```

<br>

4) Makefile 개선하기

<br>

```makefile
# Makefile

CC = gcc	# gcc 컴파일러를 이용.
CFLAGS = -W -Wall	# 사소한 오류까지 출력
TARGET = diary_exe	# 최종 타겟 파일은 diary_exe
OBJECTS = memo.o main.o calendar.o # OBJECT로 정의할 파일들은 memo.o main.o calendar.o

all : $(TARGET)	# all은 현재는 사용되지 않았지만 타겟 파일이 여러 개 일때 사용된다.

$(TARGET): $(OBJECTS)	# 타겟 파일을 만들기 위해 OBJECT 들을 사용한다. OBJECT 파일이 없다면 OBJECT 파일과 이름이 동일한 C파일을 찾아 OBJECT 파일을 생성한다.
	$(CC) $(CFLAGS) -o $@ $^	# $@ : 현재 타겟의 이름, $^ : 현재 타겟의 종속 항목 리스트 

clean :
	rm *.o diary_exe
```

<br>

<br>