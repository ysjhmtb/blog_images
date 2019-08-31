# 백기선의 스프링 데이터 JPA

## 관계형 데이터베이스와 자바

```bash
# https://medium.com/@yutafujii_59175/a-complete-one-by-one-guide-to-install-docker-on-your-mac-os-using-homebrew-e818eb4cfc3
$ brew install docker docker-machine
$ brew cask install virtualbox
-> need password
-> possibly need to address System Preference setting
$ docker-machine create --driver virtualbox default
$ docker-machine env default
$ eval "$(docker-machine env default)"
$ docker run hello-world
$ docker-machine stop default

# brew가 아닌 Docker 설치
# https://myjamong.tistory.com/105
# https://kji6252.github.io/2017/04/03/windows-docker-install/

# 5432포트를 도커의 5432와 연결. -e는 환경변수. -d는 데몬으로 실행. 마지막 postgres는 이미지의 이름.
$ docker run -p 5432:5432 -e POSTGRES_PASSWORD=pass -e POSTGRES_USER=yun -e POSTGRES_DB=springdata --name postgres_boot -d postgres

$ docker exec -i -t postgres_boot bash
$ su - postgres
# 접속할 데이터베이스의 이름.
$ psql --username yun --dbname springdata

# 데이터베이스 조회
$ \list

# 테이블 조회
$ \dt

# 쿼리
$ SELECT * FROM account;


```

