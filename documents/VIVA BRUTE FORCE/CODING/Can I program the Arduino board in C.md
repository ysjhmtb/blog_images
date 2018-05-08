<br>

> Can I program the Arduino board in C?

아두이노 보드를 C언어를 사용해서 프로그래밍 할 수 있을까요?

<br>

> In fact, you already are; the Arduino language is merely a set of C/C++ functions that can be called from your code. Your sketch undergoes minor changes (e.g. automatic generation of function prototypes) and then is passed directly to a C/C++ compiler (avr-g++). All standard C and C++ constructs [supported by avr-g++](http://www.nongnu.org/avr-libc/user-manual/FAQ.html#faq_cplusplus) should work in Arduino. For more details, see the page on the [Arduino build process](https://www.arduino.cc/en/Hacking/BuildProcess). 

사실 당신은 이미 그렇게 하고 있습니다. 아두이노 랭귀지는 그저 당신의 코드에서 호출될 수 있는 C/C++ 함수의 집합입니다. 당신의 sketch [^1]는 약간의 변화를 겪고 (예를 들어서 함수 원형의 자동 완성) C/C++ 컴파일러(avr-g++)로 바로 전달됩니다.  avr-g++에서 지원되는 모든 표준 C와 C++ 명령어들은 아두이노에서 동작합니다. 더 세부적인 내용을 위해서는 첨부된 페이지를 참조하세요.

<br>

https://www.arduino.cc/en/Main/FAQ#toc13



<br>

언젠가 아두이노를 다루고 싶어서 메모.



[^1]: 아두이노에서 사용되는 언어

