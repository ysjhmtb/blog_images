# VSCode에서 LLDB 사용하기

<br>

CLion에서 사용했던 것처럼 VSCode에서 C++ 디버거를 사용하려고 했는데 문제 발생. 여러 내용들을 읽어보면서 IDE와 다른 절차가 필요함을 확인.

<br>

VSCode에서 다음의 예시를 디버거로 확인하고자 함.

```C++
#include <iostream>

int main()
{

    int a = 1;

    for(int i = 0; i < 5; i++)
        a = i;

    return 0;
}
```

<br>

1) [Debugging a simple program with LLDB](https://gist.github.com/CynicalApe/3ed55bcb594df17da6e5f5a79fadf222) 

```bash
$ clang++ -g hello.cpp -o hello # -g 옵션 필요. hello 생성.
```

<br>

<br>

2) VSCode에서 <br>

`.vscode/launch.json` 에서 다음과 같이 기술. <br>

```json
// launch.json

{
    // IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
    // 기존 특성에 대한 설명을 보려면 가리킵니다.
    // 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            //"program": "enter program name, for example ${workspaceFolder}/a.out",
            "program": "${workspaceFolder}/hello",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "lldb"
        }
    ]
}
```

<br>

3) VSCode에서 breakpoint를 설정해서 디버깅이 가능해짐. 공식문서에 나온 내용에 부합하는 방법은 아니고, 여러 문서를 참조해서 잠정적인 방안을 선택함.

<br>









