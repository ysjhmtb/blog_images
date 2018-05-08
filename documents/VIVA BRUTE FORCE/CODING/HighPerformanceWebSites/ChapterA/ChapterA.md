<br>

[High Performance Web Sites](https://www.amazon.com/High-Performance-Web-Sites-Essential/dp/0596529309/ref=sr_1_1?s=books&ie=UTF8&qid=1525713912&sr=1-1&keywords=high+performance+websites) 는 웹 애플리케이션의 성능을 향상시키는 방안에 대해 기술한 책이다. 출판된지 오랜 시간이 지났지만 여전히 유용한 내용을 담고 있다고 하여 읽기 시작하였다. 

<br><br><br>

<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/notes/HighPerformanceWebSites/ChapterA/HighPerformanceWebSites.png?raw=true">

<br>

<hr>

<br>

CHAPTER A

The Importance of Frontend Performance

<br>

1) 

> As such, I dutifully approached each performance project as an exercise in backend optimization, concentrating on compiler options, database indexes, memory management, etc. There’s a lot of attention and many books devoted to optimizing performance in these areas, so that’s where most people spend time looking for improvements. In reality, for most web pages, less than 10–20% of the end user response time is spent getting the HTML document from the web server to the browser.

<br>

시작부터 흥미로웠는데, 많은 사람들의 생각과 달리 백엔드 최적화, 데이터베이스 인덱싱 등의 요소로 향상시킬 수 있는 속도는 한계가 많다고 한다. 웹서버에서 브라우저로 HTML 문서를 가지고 오는데 소요되는 시간은 사용자 응답 시간의 10~20% 이하를 차지한다.

<br>

2)

그러면서 다음처럼 yahoo에 대한 응답 그래프를 사례로 들었다.

<br>

> <img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/notes/HighPerformanceWebSites/ChapterA/FigureA.png?raw=true">



<br>



3)



이번 챕터를 통해 확인할 수 있는 사실은 세 가지이다.

<br>

첫째, 웹 애플리케이션의 성능을 개선할 여지는 프런트엔드에 훨씬 많다. 백엔드 응답 시간을 절반으로 줄인다고 해도 사용자 반응 시간은 5 ~ 10% 정도 줄어들 뿐이다. 반면 프런트엔드에서 이를 절반으로 줄인다면 사용자 응답시간은 40 ~ 45% 정도 줄어들게 될 것이다.

<br>

둘째, 프런트엔드에서의 개선은 더 적은 시간과 더 적은 자원을 필요로 한다. 백엔드 부문에서 기술부채를 줄인다는 것은 아키텍처, 하드웨어, 데이터베이스 등을 재설계함을 의미하고, 이런 작업은 수주에서 수개월의 시간이 필요하다. 반면 이 책에서 소개될 프런트엔드에서의 개선책들은 수시간에서 며칠 정도만이 요구될 뿐이다. 

<br>

셋째, 프런트엔드 성능 튜닝은 그 효과가 이미 입증이 되었다. 야후의 여러 팀들은 권장되는 방법을 실행함으로서 25% 이상의 성능 개선을 달성했다. 

<br> 





