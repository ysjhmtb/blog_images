
USE sqlDB;

SELECT * FROM userTbl WHERE userName = '김경호';

SELECT userID, userName
	FROM userTbl
    WHERE birthYear >= 1970 AND height >= 182;
    

SELECT USERNAME, HEIGHT
	FROM USERTBL WHERE HEIGHT BETWEEN 180 AND 183;

SELECT USERNAME, ADDR
	FROM USERTBL
    WHERE ADDR='경남' OR ADDR='전남' OR addr='경북';
    
SELECT userName, addr
	from userTbl
    where addr in ('경남','전남','경북');
    
select userName, height
	from userTbl
    where userName like  '김%';

select userName, height
	from userTbl
    where userName like  '_종신';
    
select userName, height from userTbl 
	where height > (select height from userTbl where userName='김경호');
 

select username, height from usertbl
	where height in (select height from usertbl where addr='경남');

SELECT userName, mDate FROM userTBL ORDER BY mDate;

SELECT userName, mDate FROM userTBL ORDER BY mDate DESC;


-- 키로 먼저 정렬을 하고, 이름으로 정렬 
SELECT userName, height FROM userTBL ORDER BY height DESC, userName ASC;


-- 중복된 것을 제거하고 하나씩만 나온다.
SELECT DISTINCT addr FROM userTBL;
SELECT addr FROM userTBL ORDER BY addr;


use employees;
SELECT emp_no, hire_date FROM employees 
   ORDER BY hire_date ASC;


SELECT emp_no FROM 
   (SELECT emp_no, hire_date, rownum FROM employees  ORDER BY hire_date ASC) AS TTB
   WHERE ROWNUM <= 5;

set @rownum:=0;
select @rownum:=@rownum+1 rownum, emp_no, hire_date 
from employees;

create table employees2 
		(select @rownum:=@rownum+1 rownum, emp_no, hire_date 
		from employees);

-- mysql에서는 limit이 유용한듯 
select emp_no, hire_date from employees
order by hire_date asc
limit 5;




