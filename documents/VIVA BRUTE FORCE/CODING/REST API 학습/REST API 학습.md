<h1>REST API 학습</h1>

<br>

REST API란 단어를 들어본 적이 있었고, 수업 시간에 이에 대한 사용이 있어서 이에 대해 찾아보게 되었다. 그리고 [Understanding And Using REST APIs](https://www.smashingmagazine.com/2018/01/understanding-using-rest-api/) 란 글을 발견하였다.

<br>

> If you want to be able to read API documentations and use them effectively, you’ll first need to understand everything about REST APIs. Let’s get started.

이란 QUICK SUMMARY와 함께 시작되는데, 확실히 알아두어야 할 내용으로 판단된다.

<br>

<h2>REST API란?</h2>

<br>

유튜브에서 "배트맨"이란 단어를 사용해서 검색하면 이와 관련된 목록들을 확인할 수 있는데, REST API 역시 비슷하게 동작한다.<br>

**API** 를 통해 프로그램들은 의사소통을 한다. 그리고 **REST** 는 개발자가 API를 만들 때 준수해야 할 규칙들이다. 이런 규칙들을 통해 특정 URL에 접근해서 데이터들을 가져올 수 있다. 여기서 URL이 **request** 라고 불리고,  데이터가 **response** 라고 불린다.

<br>

<h2>Request에 대해 더 자세히 알아보자</h2>

<br>

request는 

1. The endpoint
2. The method
3. The headers
4. The data (or body)

로 이루어져 있다. 

<br>

**The endpoint** (or route) 는 요청을 보내게 되는 url이고, 다음의 구조를 갖는다. 

```
root-endpoint/?
```

**root-endpoint** 는 API의 시작 지점이고, **path** 는 요청하는 resource가 무엇인지를 나타낸다. 

<br>

쉽게 생각해서 일상적으로 사용하는 웹 사이트를 생각해 볼 수 있는데, `https://www.smashingmagazine.com/tag/javascript/` 에서 `https://www.smashingmagazine.com/` 가 root-endpoint이고 `/tag/javascript` 가 path이다.

<br>

path로 무엇을 할 수 있을까? 다음의 경우를 생각해 보자. 예를 들어, Github API로 특정 사용자의 저장소 리스트를 알고 싶다면 어떻게 해야 할까? 이를 위해서는 다음과 같은 path를 사용해야 한다.

```
/users/:username/repos
```

Path 에 있는 `:` 은 한 개의 변수를 나타낸다. `zellwk` 라는 사용자의 저장소 리스트를 알고 싶다면 다음과 같을 것이다.

```
https://api.github.com/users/zellwk/repos
```

<br>

Endpoint의 마지막 부분은 **query parameters** 이다. 엄밀히 말해서 쿼리 패러미터는 REST의 일부는 아니지만, 많은 API에서 이들을 보게 될 것이다. 쿼리 패러미터는 키-밸류 조합을 통해 리퀘스트를 수정할 수 있게 해주는데, 다음과 같이 언제나 `?` 로 시작하며, `&` 로 분리된다.

```
?query1=value1&query2=value2
```

<br>

만약에 사용자 zellwk 가 최근에 올린 저장소의 리스트를 얻고 싶다면 다음과 같이 작성한다.

```
https://api.github.com/users/zellwk/repos?sort=pushed
```

<br>

<h2>curl을 사용하여 endpoints 테스트 해보기</h2>

