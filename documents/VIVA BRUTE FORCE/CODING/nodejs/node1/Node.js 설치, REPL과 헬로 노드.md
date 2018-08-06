## Node.js 설치, REPL과 헬로 노드



```shell
node와 npm 삭제
$ cd /usr/local; sudo rm -r bin/node bin/npm include/node /lib/node_modules


brew로 node 삭제
$ brew uninstall node


npm을 제외하고 node만 설치
$ brew install node --without-npm


.bash_profile 내용 추가
$ vi ~/.bash_profile

#Node.js
export PATH="/usr/local/Cellar/node/10.8.0/bin:$PATH"


node 파일의 경로를 system에 등록하기.
$ . .bash_profile


npm 설치
$ curl -L https://www.npmjs.com/install.sh | sh


하지만 yarn을 사용하자
$ brew install yarn



버전을 확인해서 설치 여부를 확인하자
$ node --version
$ npm --version
$ yarn --version


```



-----

REPL = Read, Evaluate, Print, Loop



-----

```javascript
//helloNode.js

var a = 1;
var b = 2;
console.log(a + b);
console.log('hello world');


```



파일이 저장된 폴더로 이동해서 실행.

```shell
$ node helloNode.js
```



