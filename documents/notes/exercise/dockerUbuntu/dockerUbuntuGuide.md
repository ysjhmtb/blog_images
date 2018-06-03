

<br>

[초보를 위한 도커 안내서 - 설치하고 컨테이너 실행하기](https://subicura.com/2017/01/19/docker-guide-for-beginners-2.html)

<br>

```bash
docker version
```

<br>

```bash
Client:
 Version:      18.03.1-ce
 API version:  1.37
 Go version:   go1.9.5
 Git commit:   9ee9f40
 Built:        Thu Apr 26 07:13:02 2018
 OS/Arch:      darwin/amd64
 Experimental: false
 Orchestrator: swarm

Server:
 Engine:
  Version:      18.03.1-ce
  API version:  1.37 (minimum version 1.12)
  Go version:   go1.9.5
  Git commit:   9ee9f40
  Built:        Thu Apr 26 07:22:38 2018
  OS/Arch:      linux/amd64
  Experimental: true

```

<br>

<hr>

<h2>Ubuntu 16.04 container</h2>

```bash
docker run ubuntu:16.04
```

저장된 이미지가 없다면 pull 한 후에 컨테이너를 create 하고 start .

<br>

```bash
docker run --rm -it ubuntu:16.04 /bin/bash
```

bash를 실행해서 컨테이너 내부에 들어가고, **-it** 옵션으로 키보드 입력 가능. 프로세스가 종료되면 컨테이너가 삭제되도록 **--rm** 옵션 추가.

<br>

```bash
cat /etc/issue
ls
exit
```



<br>

<hr>

```bash
docker run [OPTIONS] IMAGE[:TAG|@DIGEST] [COMMAND] [ARG...]
```

<br>

<!--|옵션|설명| -->

| 옵션  | 설명                                                   |
| ----- | ------------------------------------------------------ |
| -d    | detached mode. 백그라운드 모드.                        |
| -p    | 호스트와 컨테이너 포트를 연결. (포워딩)                |
| -v    | 호스트와 컨테이너의 디렉터리를 연결.(마운트)           |
| -e    | 컨테이너 내에서 사용할 환경변수 설정.                  |
| -name | 컨테이너 이름 설정.                                    |
| -rm   | 프로세스 종료시 컨테이너 자동 제거.                    |
| -it   | -i와 -t를 동시에 사용한 것으로 터미널 입력을 위한 옵션 |
| -link | 컨테이너 연결[컨테이너명:별칭]                         |

<br>

<hr>

```bash
docker run --name "dockerUbuntu" ubuntu:16.04 
docker run --name "dockerUbuntu" -it ubuntu:16.04 /bin/bash
docker restart "dockerUbuntu"
```



<br>

<hr>



<br>

<hr>

[왕초보를 위한 vim 사용방법](http://zeddios.tistory.com/122)



<br>











