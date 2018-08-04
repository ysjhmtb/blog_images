
-- employees DB를 사용하겠다.
use employees;

select * from titles;
select * from employees.titles;

select first_name, last_name, gender from employees;


-- 데이터베이스 조회 
show databases;
use employees;


-- 테이블 조회 및 정보 확인 
show tables;
show table status;
describe employees;

select first_name, gender from employees;

 

-- sqlDB 
drop database if exists sqlDB;
create database sqlDB;
use sqlDB;

CREATE TABLE userTBL -- 회원 테이블
( userID  	CHAR(8) NOT NULL PRIMARY KEY, -- 사용자 아이디(PK)
  userName  	VARCHAR(10) NOT NULL, -- 이름
  birthYear 	INT NOT NULL,  -- 출생년도
  addr	  	CHAR(2) NOT NULL, -- 지역(경기,서울,경남 식으로 2글자만입력)
  mobile1	CHAR(3), -- 휴대폰의 국번(010, 011, 016, 017, 018, 019 등)
  mobile2	CHAR(8), -- 휴대폰의 나머지 전화번호(하이픈제외)
  height    	SMALLINT,  -- 키
  mDate    	DATE  -- 회원 가입일
);


CREATE TABLE buyTBL -- 회원 구매 테이블
(  idNum 	INT AUTO_INCREMENT NOT NULL PRIMARY KEY, -- 순번(PK)
   userID  	CHAR(8) NOT NULL, -- 아이디(FK)
   prodName 	CHAR(6) NOT NULL, --  물품명
   groupName 	CHAR(4)  , -- 분류
   price     	INT NOT NULL, -- 단가
   amount    	SMALLINT  NOT NULL, -- 수량
   FOREIGN KEY (userID) REFERENCES userTBL(userID)
);


INSERT INTO userTBL VALUES('LSG', '이승기', 1987, '서울', '011', '11111111', 182, '2008-8-8');
INSERT INTO userTBL VALUES('KBS', '김범수', 1979, '경남', '011', '22222222', 173, '2012-4-4');
INSERT INTO userTBL VALUES('KKH', '김경호', 1971, '전남', '019', '33333333', 177, '2007-7-7');
INSERT INTO userTBL VALUES('JYP', '조용필', 1950, '경기', '011', '44444444', 166, '2009-4-4');
INSERT INTO userTBL VALUES('SSK', '성시경', 1979, '서울', NULL  , NULL      , 186, '2013-12-12');
INSERT INTO userTBL VALUES('LJB', '임재범', 1963, '서울', '016', '66666666', 182, '2009-9-9');
INSERT INTO userTBL VALUES('YJS', '윤종신', 1969, '경남', NULL  , NULL      , 170, '2005-5-5');
INSERT INTO userTBL VALUES('EJW', '은지원', 1972, '경북', '011', '88888888', 174, '2014-3-3');
INSERT INTO userTBL VALUES('JKW', '조관우', 1965, '경기', '018', '99999999', 172, '2010-10-10');
INSERT INTO userTBL VALUES('BBK', '바비킴', 1973, '서울', '010', '00000000', 176, '2013-5-5');

INSERT INTO buyTBL VALUES(NULL, 'KBS', '운동화', NULL   , 30,   2);
INSERT INTO buyTBL VALUES(NULL, 'KBS', '노트북', '전자', 1000, 1);
INSERT INTO buyTBL VALUES(NULL, 'JYP', '모니터', '전자', 200,  1);
INSERT INTO buyTBL VALUES(NULL, 'BBK', '모니터', '전자', 200,  5);
INSERT INTO buyTBL VALUES(NULL, 'KBS', '청바지', '의류', 50,   3);
INSERT INTO buyTBL VALUES(NULL, 'BBK', '메모리', '전자', 80,  10);
INSERT INTO buyTBL VALUES(NULL, 'SSK', '책'    , '서적', 15,   5);
INSERT INTO buyTBL VALUES(NULL, 'EJW', '책'    , '서적', 15,   2);
INSERT INTO buyTBL VALUES(NULL, 'EJW', '청바지', '의류', 50,   1);
INSERT INTO buyTBL VALUES(NULL, 'BBK', '운동화', NULL   , 30,   2);
INSERT INTO buyTBL VALUES(NULL, 'EJW', '책'    , '서적', 15,   1);
INSERT INTO buyTBL VALUES(NULL, 'BBK', '운동화', NULL   , 30,   2);

COMMIT;
SELECT * FROM userTBL;
SELECT * FROM buyTBL;










