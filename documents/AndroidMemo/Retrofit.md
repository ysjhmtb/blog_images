# Retrofit

<br>

1) REST 

[REST API 학습](https://devhz.tistory.com/63) 참조.

<br>

> 유튜브에서 "배트맨"이란 단어를 사용해서 검색하면 이와 관련된 목록들을 확인할 수 있는데, REST API 역시 비슷하게 동작한다.
>
> **API** 를 통해 프로그램들은 의사소통을 한다. 그리고 **REST** 는 개발자가 API를 만들 때 준수해야 할 규칙들이다. 이런 규칙들을 통해 특정 URL에 접근해서 데이터들을 가져올 수 있다. 여기서 URL이 **request** 라고 불리고, 데이터가 **response** 라고 불린다.

<br>

REST API 통신에 사용되는 데이터 형식은 JSON이며, 쿼리를 통해 요청을 하고 결과를 전달받는다.

<br>

<br>

2) Retrofit을 통한 JSON 데이터 읽기

<br>

[안드로이드 Retrofit으로 API 통신하기](https://lx5475.github.io/2017/03/30/android-retrofit/) 참조.

<br>

Retrofit은 API 통신을 위한 안드로이드 라이브러리

<br>

- 읽어들여야 할 JSON 데이터의 형태.

```json
// https://api.github.com/repos/square/retrofit/contributors

[
  {
    "login": "JakeWharton",
    "id": 66577,
    "node_id": "MDQ6VXNlcjY2NTc3",
    "avatar_url": "https://avatars0.githubusercontent.com/u/66577?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/JakeWharton",
    "html_url": "https://github.com/JakeWharton",
    "followers_url": "https://api.github.com/users/JakeWharton/followers",
    "following_url": "https://api.github.com/users/JakeWharton/following{/other_user}",
    "gists_url": "https://api.github.com/users/JakeWharton/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/JakeWharton/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/JakeWharton/subscriptions",
    "organizations_url": "https://api.github.com/users/JakeWharton/orgs",
    "repos_url": "https://api.github.com/users/JakeWharton/repos",
    "events_url": "https://api.github.com/users/JakeWharton/events{/privacy}",
    "received_events_url": "https://api.github.com/users/JakeWharton/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 966
  },
  {
    "login": "swankjesse",
    "id": 133019,
    "node_id": "MDQ6VXNlcjEzMzAxOQ==",
    "avatar_url": "https://avatars3.githubusercontent.com/u/133019?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/swankjesse",
    "html_url": "https://github.com/swankjesse",
    "followers_url": "https://api.github.com/users/swankjesse/followers",
    "following_url": "https://api.github.com/users/swankjesse/following{/other_user}",
    "gists_url": "https://api.github.com/users/swankjesse/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/swankjesse/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/swankjesse/subscriptions",
    "organizations_url": "https://api.github.com/users/swankjesse/orgs",
    "repos_url": "https://api.github.com/users/swankjesse/repos",
    "events_url": "https://api.github.com/users/swankjesse/events{/privacy}",
    "received_events_url": "https://api.github.com/users/swankjesse/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 260
  },
  {
    "login": "pforhan",
    "id": 331925,
    "node_id": "MDQ6VXNlcjMzMTkyNQ==",
    "avatar_url": "https://avatars3.githubusercontent.com/u/331925?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/pforhan",
    "html_url": "https://github.com/pforhan",
    "followers_url": "https://api.github.com/users/pforhan/followers",
    "following_url": "https://api.github.com/users/pforhan/following{/other_user}",
    "gists_url": "https://api.github.com/users/pforhan/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/pforhan/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/pforhan/subscriptions",
    "organizations_url": "https://api.github.com/users/pforhan/orgs",
    "repos_url": "https://api.github.com/users/pforhan/repos",
    "events_url": "https://api.github.com/users/pforhan/events{/privacy}",
    "received_events_url": "https://api.github.com/users/pforhan/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 48
  },
  {
    "login": "eburke",
    "id": 63761,
    "node_id": "MDQ6VXNlcjYzNzYx",
    "avatar_url": "https://avatars0.githubusercontent.com/u/63761?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/eburke",
    "html_url": "https://github.com/eburke",
    "followers_url": "https://api.github.com/users/eburke/followers",
    "following_url": "https://api.github.com/users/eburke/following{/other_user}",
    "gists_url": "https://api.github.com/users/eburke/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/eburke/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/eburke/subscriptions",
    "organizations_url": "https://api.github.com/users/eburke/orgs",
    "repos_url": "https://api.github.com/users/eburke/repos",
    "events_url": "https://api.github.com/users/eburke/events{/privacy}",
    "received_events_url": "https://api.github.com/users/eburke/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 36
  },
  {
    "login": "NightlyNexus",
    "id": 4032667,
    "node_id": "MDQ6VXNlcjQwMzI2Njc=",
    "avatar_url": "https://avatars2.githubusercontent.com/u/4032667?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/NightlyNexus",
    "html_url": "https://github.com/NightlyNexus",
    "followers_url": "https://api.github.com/users/NightlyNexus/followers",
    "following_url": "https://api.github.com/users/NightlyNexus/following{/other_user}",
    "gists_url": "https://api.github.com/users/NightlyNexus/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/NightlyNexus/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/NightlyNexus/subscriptions",
    "organizations_url": "https://api.github.com/users/NightlyNexus/orgs",
    "repos_url": "https://api.github.com/users/NightlyNexus/repos",
    "events_url": "https://api.github.com/users/NightlyNexus/events{/privacy}",
    "received_events_url": "https://api.github.com/users/NightlyNexus/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 28
  },
  {
    "login": "dnkoutso",
    "id": 310370,
    "node_id": "MDQ6VXNlcjMxMDM3MA==",
    "avatar_url": "https://avatars2.githubusercontent.com/u/310370?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/dnkoutso",
    "html_url": "https://github.com/dnkoutso",
    "followers_url": "https://api.github.com/users/dnkoutso/followers",
    "following_url": "https://api.github.com/users/dnkoutso/following{/other_user}",
    "gists_url": "https://api.github.com/users/dnkoutso/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/dnkoutso/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/dnkoutso/subscriptions",
    "organizations_url": "https://api.github.com/users/dnkoutso/orgs",
    "repos_url": "https://api.github.com/users/dnkoutso/repos",
    "events_url": "https://api.github.com/users/dnkoutso/events{/privacy}",
    "received_events_url": "https://api.github.com/users/dnkoutso/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 26
  },
  {
    "login": "edenman",
    "id": 1063557,
    "node_id": "MDQ6VXNlcjEwNjM1NTc=",
    "avatar_url": "https://avatars2.githubusercontent.com/u/1063557?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/edenman",
    "html_url": "https://github.com/edenman",
    "followers_url": "https://api.github.com/users/edenman/followers",
    "following_url": "https://api.github.com/users/edenman/following{/other_user}",
    "gists_url": "https://api.github.com/users/edenman/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/edenman/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/edenman/subscriptions",
    "organizations_url": "https://api.github.com/users/edenman/orgs",
    "repos_url": "https://api.github.com/users/edenman/repos",
    "events_url": "https://api.github.com/users/edenman/events{/privacy}",
    "received_events_url": "https://api.github.com/users/edenman/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 24
  },
  {
    "login": "loganj",
    "id": 18877,
    "node_id": "MDQ6VXNlcjE4ODc3",
    "avatar_url": "https://avatars3.githubusercontent.com/u/18877?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/loganj",
    "html_url": "https://github.com/loganj",
    "followers_url": "https://api.github.com/users/loganj/followers",
    "following_url": "https://api.github.com/users/loganj/following{/other_user}",
    "gists_url": "https://api.github.com/users/loganj/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/loganj/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/loganj/subscriptions",
    "organizations_url": "https://api.github.com/users/loganj/orgs",
    "repos_url": "https://api.github.com/users/loganj/repos",
    "events_url": "https://api.github.com/users/loganj/events{/privacy}",
    "received_events_url": "https://api.github.com/users/loganj/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 17
  },
  {
    "login": "Noel-96",
    "id": 20171941,
    "node_id": "MDQ6VXNlcjIwMTcxOTQx",
    "avatar_url": "https://avatars3.githubusercontent.com/u/20171941?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/Noel-96",
    "html_url": "https://github.com/Noel-96",
    "followers_url": "https://api.github.com/users/Noel-96/followers",
    "following_url": "https://api.github.com/users/Noel-96/following{/other_user}",
    "gists_url": "https://api.github.com/users/Noel-96/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/Noel-96/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/Noel-96/subscriptions",
    "organizations_url": "https://api.github.com/users/Noel-96/orgs",
    "repos_url": "https://api.github.com/users/Noel-96/repos",
    "events_url": "https://api.github.com/users/Noel-96/events{/privacy}",
    "received_events_url": "https://api.github.com/users/Noel-96/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 16
  },
  {
    "login": "rcdickerson",
    "id": 63143,
    "node_id": "MDQ6VXNlcjYzMTQz",
    "avatar_url": "https://avatars1.githubusercontent.com/u/63143?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/rcdickerson",
    "html_url": "https://github.com/rcdickerson",
    "followers_url": "https://api.github.com/users/rcdickerson/followers",
    "following_url": "https://api.github.com/users/rcdickerson/following{/other_user}",
    "gists_url": "https://api.github.com/users/rcdickerson/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/rcdickerson/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/rcdickerson/subscriptions",
    "organizations_url": "https://api.github.com/users/rcdickerson/orgs",
    "repos_url": "https://api.github.com/users/rcdickerson/repos",
    "events_url": "https://api.github.com/users/rcdickerson/events{/privacy}",
    "received_events_url": "https://api.github.com/users/rcdickerson/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 14
  },
  {
    "login": "rjrjr",
    "id": 1884445,
    "node_id": "MDQ6VXNlcjE4ODQ0NDU=",
    "avatar_url": "https://avatars0.githubusercontent.com/u/1884445?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/rjrjr",
    "html_url": "https://github.com/rjrjr",
    "followers_url": "https://api.github.com/users/rjrjr/followers",
    "following_url": "https://api.github.com/users/rjrjr/following{/other_user}",
    "gists_url": "https://api.github.com/users/rjrjr/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/rjrjr/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/rjrjr/subscriptions",
    "organizations_url": "https://api.github.com/users/rjrjr/orgs",
    "repos_url": "https://api.github.com/users/rjrjr/repos",
    "events_url": "https://api.github.com/users/rjrjr/events{/privacy}",
    "received_events_url": "https://api.github.com/users/rjrjr/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 13
  },
  {
    "login": "kryali",
    "id": 174889,
    "node_id": "MDQ6VXNlcjE3NDg4OQ==",
    "avatar_url": "https://avatars1.githubusercontent.com/u/174889?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/kryali",
    "html_url": "https://github.com/kryali",
    "followers_url": "https://api.github.com/users/kryali/followers",
    "following_url": "https://api.github.com/users/kryali/following{/other_user}",
    "gists_url": "https://api.github.com/users/kryali/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/kryali/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/kryali/subscriptions",
    "organizations_url": "https://api.github.com/users/kryali/orgs",
    "repos_url": "https://api.github.com/users/kryali/repos",
    "events_url": "https://api.github.com/users/kryali/events{/privacy}",
    "received_events_url": "https://api.github.com/users/kryali/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 9
  },
  {
    "login": "adriancole",
    "id": 64215,
    "node_id": "MDQ6VXNlcjY0MjE1",
    "avatar_url": "https://avatars2.githubusercontent.com/u/64215?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/adriancole",
    "html_url": "https://github.com/adriancole",
    "followers_url": "https://api.github.com/users/adriancole/followers",
    "following_url": "https://api.github.com/users/adriancole/following{/other_user}",
    "gists_url": "https://api.github.com/users/adriancole/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/adriancole/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/adriancole/subscriptions",
    "organizations_url": "https://api.github.com/users/adriancole/orgs",
    "repos_url": "https://api.github.com/users/adriancole/repos",
    "events_url": "https://api.github.com/users/adriancole/events{/privacy}",
    "received_events_url": "https://api.github.com/users/adriancole/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 9
  },
  {
    "login": "holmes",
    "id": 59162,
    "node_id": "MDQ6VXNlcjU5MTYy",
    "avatar_url": "https://avatars3.githubusercontent.com/u/59162?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/holmes",
    "html_url": "https://github.com/holmes",
    "followers_url": "https://api.github.com/users/holmes/followers",
    "following_url": "https://api.github.com/users/holmes/following{/other_user}",
    "gists_url": "https://api.github.com/users/holmes/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/holmes/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/holmes/subscriptions",
    "organizations_url": "https://api.github.com/users/holmes/orgs",
    "repos_url": "https://api.github.com/users/holmes/repos",
    "events_url": "https://api.github.com/users/holmes/events{/privacy}",
    "received_events_url": "https://api.github.com/users/holmes/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 7
  },
  {
    "login": "JayNewstrom",
    "id": 713288,
    "node_id": "MDQ6VXNlcjcxMzI4OA==",
    "avatar_url": "https://avatars3.githubusercontent.com/u/713288?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/JayNewstrom",
    "html_url": "https://github.com/JayNewstrom",
    "followers_url": "https://api.github.com/users/JayNewstrom/followers",
    "following_url": "https://api.github.com/users/JayNewstrom/following{/other_user}",
    "gists_url": "https://api.github.com/users/JayNewstrom/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/JayNewstrom/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/JayNewstrom/subscriptions",
    "organizations_url": "https://api.github.com/users/JayNewstrom/orgs",
    "repos_url": "https://api.github.com/users/JayNewstrom/repos",
    "events_url": "https://api.github.com/users/JayNewstrom/events{/privacy}",
    "received_events_url": "https://api.github.com/users/JayNewstrom/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 7
  },
  {
    "login": "swanson",
    "id": 56947,
    "node_id": "MDQ6VXNlcjU2OTQ3",
    "avatar_url": "https://avatars3.githubusercontent.com/u/56947?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/swanson",
    "html_url": "https://github.com/swanson",
    "followers_url": "https://api.github.com/users/swanson/followers",
    "following_url": "https://api.github.com/users/swanson/following{/other_user}",
    "gists_url": "https://api.github.com/users/swanson/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/swanson/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/swanson/subscriptions",
    "organizations_url": "https://api.github.com/users/swanson/orgs",
    "repos_url": "https://api.github.com/users/swanson/repos",
    "events_url": "https://api.github.com/users/swanson/events{/privacy}",
    "received_events_url": "https://api.github.com/users/swanson/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 7
  },
  {
    "login": "crazybob",
    "id": 170788,
    "node_id": "MDQ6VXNlcjE3MDc4OA==",
    "avatar_url": "https://avatars2.githubusercontent.com/u/170788?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/crazybob",
    "html_url": "https://github.com/crazybob",
    "followers_url": "https://api.github.com/users/crazybob/followers",
    "following_url": "https://api.github.com/users/crazybob/following{/other_user}",
    "gists_url": "https://api.github.com/users/crazybob/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/crazybob/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/crazybob/subscriptions",
    "organizations_url": "https://api.github.com/users/crazybob/orgs",
    "repos_url": "https://api.github.com/users/crazybob/repos",
    "events_url": "https://api.github.com/users/crazybob/events{/privacy}",
    "received_events_url": "https://api.github.com/users/crazybob/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 6
  },
  {
    "login": "Jawnnypoo",
    "id": 1459320,
    "node_id": "MDQ6VXNlcjE0NTkzMjA=",
    "avatar_url": "https://avatars3.githubusercontent.com/u/1459320?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/Jawnnypoo",
    "html_url": "https://github.com/Jawnnypoo",
    "followers_url": "https://api.github.com/users/Jawnnypoo/followers",
    "following_url": "https://api.github.com/users/Jawnnypoo/following{/other_user}",
    "gists_url": "https://api.github.com/users/Jawnnypoo/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/Jawnnypoo/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/Jawnnypoo/subscriptions",
    "organizations_url": "https://api.github.com/users/Jawnnypoo/orgs",
    "repos_url": "https://api.github.com/users/Jawnnypoo/repos",
    "events_url": "https://api.github.com/users/Jawnnypoo/events{/privacy}",
    "received_events_url": "https://api.github.com/users/Jawnnypoo/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 6
  },
  {
    "login": "danrice-square",
    "id": 1952897,
    "node_id": "MDQ6VXNlcjE5NTI4OTc=",
    "avatar_url": "https://avatars0.githubusercontent.com/u/1952897?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/danrice-square",
    "html_url": "https://github.com/danrice-square",
    "followers_url": "https://api.github.com/users/danrice-square/followers",
    "following_url": "https://api.github.com/users/danrice-square/following{/other_user}",
    "gists_url": "https://api.github.com/users/danrice-square/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/danrice-square/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/danrice-square/subscriptions",
    "organizations_url": "https://api.github.com/users/danrice-square/orgs",
    "repos_url": "https://api.github.com/users/danrice-square/repos",
    "events_url": "https://api.github.com/users/danrice-square/events{/privacy}",
    "received_events_url": "https://api.github.com/users/danrice-square/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 5
  },
  {
    "login": "vanniktech",
    "id": 5759366,
    "node_id": "MDQ6VXNlcjU3NTkzNjY=",
    "avatar_url": "https://avatars0.githubusercontent.com/u/5759366?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/vanniktech",
    "html_url": "https://github.com/vanniktech",
    "followers_url": "https://api.github.com/users/vanniktech/followers",
    "following_url": "https://api.github.com/users/vanniktech/following{/other_user}",
    "gists_url": "https://api.github.com/users/vanniktech/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/vanniktech/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/vanniktech/subscriptions",
    "organizations_url": "https://api.github.com/users/vanniktech/orgs",
    "repos_url": "https://api.github.com/users/vanniktech/repos",
    "events_url": "https://api.github.com/users/vanniktech/events{/privacy}",
    "received_events_url": "https://api.github.com/users/vanniktech/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 5
  },
  {
    "login": "Turbo87",
    "id": 141300,
    "node_id": "MDQ6VXNlcjE0MTMwMA==",
    "avatar_url": "https://avatars2.githubusercontent.com/u/141300?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/Turbo87",
    "html_url": "https://github.com/Turbo87",
    "followers_url": "https://api.github.com/users/Turbo87/followers",
    "following_url": "https://api.github.com/users/Turbo87/following{/other_user}",
    "gists_url": "https://api.github.com/users/Turbo87/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/Turbo87/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/Turbo87/subscriptions",
    "organizations_url": "https://api.github.com/users/Turbo87/orgs",
    "repos_url": "https://api.github.com/users/Turbo87/repos",
    "events_url": "https://api.github.com/users/Turbo87/events{/privacy}",
    "received_events_url": "https://api.github.com/users/Turbo87/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 5
  },
  {
    "login": "naturalwarren",
    "id": 1113225,
    "node_id": "MDQ6VXNlcjExMTMyMjU=",
    "avatar_url": "https://avatars3.githubusercontent.com/u/1113225?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/naturalwarren",
    "html_url": "https://github.com/naturalwarren",
    "followers_url": "https://api.github.com/users/naturalwarren/followers",
    "following_url": "https://api.github.com/users/naturalwarren/following{/other_user}",
    "gists_url": "https://api.github.com/users/naturalwarren/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/naturalwarren/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/naturalwarren/subscriptions",
    "organizations_url": "https://api.github.com/users/naturalwarren/orgs",
    "repos_url": "https://api.github.com/users/naturalwarren/repos",
    "events_url": "https://api.github.com/users/naturalwarren/events{/privacy}",
    "received_events_url": "https://api.github.com/users/naturalwarren/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 5
  },
  {
    "login": "guptasourabh04",
    "id": 27951986,
    "node_id": "MDQ6VXNlcjI3OTUxOTg2",
    "avatar_url": "https://avatars1.githubusercontent.com/u/27951986?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/guptasourabh04",
    "html_url": "https://github.com/guptasourabh04",
    "followers_url": "https://api.github.com/users/guptasourabh04/followers",
    "following_url": "https://api.github.com/users/guptasourabh04/following{/other_user}",
    "gists_url": "https://api.github.com/users/guptasourabh04/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/guptasourabh04/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/guptasourabh04/subscriptions",
    "organizations_url": "https://api.github.com/users/guptasourabh04/orgs",
    "repos_url": "https://api.github.com/users/guptasourabh04/repos",
    "events_url": "https://api.github.com/users/guptasourabh04/events{/privacy}",
    "received_events_url": "https://api.github.com/users/guptasourabh04/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 4
  },
  {
    "login": "artem-zinnatullin",
    "id": 967132,
    "node_id": "MDQ6VXNlcjk2NzEzMg==",
    "avatar_url": "https://avatars0.githubusercontent.com/u/967132?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/artem-zinnatullin",
    "html_url": "https://github.com/artem-zinnatullin",
    "followers_url": "https://api.github.com/users/artem-zinnatullin/followers",
    "following_url": "https://api.github.com/users/artem-zinnatullin/following{/other_user}",
    "gists_url": "https://api.github.com/users/artem-zinnatullin/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/artem-zinnatullin/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/artem-zinnatullin/subscriptions",
    "organizations_url": "https://api.github.com/users/artem-zinnatullin/orgs",
    "repos_url": "https://api.github.com/users/artem-zinnatullin/repos",
    "events_url": "https://api.github.com/users/artem-zinnatullin/events{/privacy}",
    "received_events_url": "https://api.github.com/users/artem-zinnatullin/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "chriscizek",
    "id": 17190266,
    "node_id": "MDQ6VXNlcjE3MTkwMjY2",
    "avatar_url": "https://avatars1.githubusercontent.com/u/17190266?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/chriscizek",
    "html_url": "https://github.com/chriscizek",
    "followers_url": "https://api.github.com/users/chriscizek/followers",
    "following_url": "https://api.github.com/users/chriscizek/following{/other_user}",
    "gists_url": "https://api.github.com/users/chriscizek/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/chriscizek/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/chriscizek/subscriptions",
    "organizations_url": "https://api.github.com/users/chriscizek/orgs",
    "repos_url": "https://api.github.com/users/chriscizek/repos",
    "events_url": "https://api.github.com/users/chriscizek/events{/privacy}",
    "received_events_url": "https://api.github.com/users/chriscizek/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "codebutler",
    "id": 3827,
    "node_id": "MDQ6VXNlcjM4Mjc=",
    "avatar_url": "https://avatars2.githubusercontent.com/u/3827?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/codebutler",
    "html_url": "https://github.com/codebutler",
    "followers_url": "https://api.github.com/users/codebutler/followers",
    "following_url": "https://api.github.com/users/codebutler/following{/other_user}",
    "gists_url": "https://api.github.com/users/codebutler/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/codebutler/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/codebutler/subscriptions",
    "organizations_url": "https://api.github.com/users/codebutler/orgs",
    "repos_url": "https://api.github.com/users/codebutler/repos",
    "events_url": "https://api.github.com/users/codebutler/events{/privacy}",
    "received_events_url": "https://api.github.com/users/codebutler/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "icastell",
    "id": 1678605,
    "node_id": "MDQ6VXNlcjE2Nzg2MDU=",
    "avatar_url": "https://avatars2.githubusercontent.com/u/1678605?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/icastell",
    "html_url": "https://github.com/icastell",
    "followers_url": "https://api.github.com/users/icastell/followers",
    "following_url": "https://api.github.com/users/icastell/following{/other_user}",
    "gists_url": "https://api.github.com/users/icastell/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/icastell/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/icastell/subscriptions",
    "organizations_url": "https://api.github.com/users/icastell/orgs",
    "repos_url": "https://api.github.com/users/icastell/repos",
    "events_url": "https://api.github.com/users/icastell/events{/privacy}",
    "received_events_url": "https://api.github.com/users/icastell/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "jjNford",
    "id": 965425,
    "node_id": "MDQ6VXNlcjk2NTQyNQ==",
    "avatar_url": "https://avatars3.githubusercontent.com/u/965425?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/jjNford",
    "html_url": "https://github.com/jjNford",
    "followers_url": "https://api.github.com/users/jjNford/followers",
    "following_url": "https://api.github.com/users/jjNford/following{/other_user}",
    "gists_url": "https://api.github.com/users/jjNford/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/jjNford/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/jjNford/subscriptions",
    "organizations_url": "https://api.github.com/users/jjNford/orgs",
    "repos_url": "https://api.github.com/users/jjNford/repos",
    "events_url": "https://api.github.com/users/jjNford/events{/privacy}",
    "received_events_url": "https://api.github.com/users/jjNford/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "ojh102",
    "id": 14901903,
    "node_id": "MDQ6VXNlcjE0OTAxOTAz",
    "avatar_url": "https://avatars2.githubusercontent.com/u/14901903?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/ojh102",
    "html_url": "https://github.com/ojh102",
    "followers_url": "https://api.github.com/users/ojh102/followers",
    "following_url": "https://api.github.com/users/ojh102/following{/other_user}",
    "gists_url": "https://api.github.com/users/ojh102/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/ojh102/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/ojh102/subscriptions",
    "organizations_url": "https://api.github.com/users/ojh102/orgs",
    "repos_url": "https://api.github.com/users/ojh102/repos",
    "events_url": "https://api.github.com/users/ojh102/events{/privacy}",
    "received_events_url": "https://api.github.com/users/ojh102/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  },
  {
    "login": "f2prateek",
    "id": 843979,
    "node_id": "MDQ6VXNlcjg0Mzk3OQ==",
    "avatar_url": "https://avatars2.githubusercontent.com/u/843979?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/f2prateek",
    "html_url": "https://github.com/f2prateek",
    "followers_url": "https://api.github.com/users/f2prateek/followers",
    "following_url": "https://api.github.com/users/f2prateek/following{/other_user}",
    "gists_url": "https://api.github.com/users/f2prateek/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/f2prateek/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/f2prateek/subscriptions",
    "organizations_url": "https://api.github.com/users/f2prateek/orgs",
    "repos_url": "https://api.github.com/users/f2prateek/repos",
    "events_url": "https://api.github.com/users/f2prateek/events{/privacy}",
    "received_events_url": "https://api.github.com/users/f2prateek/received_events",
    "type": "User",
    "site_admin": false,
    "contributions": 3
  }
]
```

<br>

- 의존성 주입

```
// build.gradle(Module: app)

dependencies {
    implementation fileTree(dir: 'libs', include: ['*.jar'])
    implementation 'com.android.support:appcompat-v7:28.0.0'
    implementation 'com.android.support.constraint:constraint-layout:1.1.3'
    testImplementation 'junit:junit:4.12'
    androidTestImplementation 'com.android.support.test:runner:1.0.2'
    androidTestImplementation 'com.android.support.test.espresso:espresso-core:3.0.2'
    implementation 'com.squareup.retrofit2:retrofit:2.2.0'
    implementation 'com.squareup.retrofit2:converter-gson:2.2.0'
}
```

<br>

- xml

```xml
// activity_retrofit.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical" android:layout_width="match_parent"
    android:layout_height="match_parent">
    <TextView
        android:text="TextView"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:id="@+id/textView" />
</LinearLayout>

```

<br>

- RetroActivity.java

```java
package company.co.retrofit;

import android.app.Activity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


// https://lx5475.github.io/2017/03/30/android-retrofit/

public class RetorofitActivity extends AppCompatActivity {

    private Retrofit retrofit;
    private TextView textView;

    private final String BASE_URL = "https://api.github.com";

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        Log.e("E : ", "onCreate in RetrofitActivity");

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_retrofit);
        init();



        GitHub gitHub = retrofit.create(GitHub.class);
        Call<List<Contributor>> call = gitHub.contributors("square","retrofit");

        call.enqueue(new Callback<List<Contributor>>() {
            @Override
            public void onResponse(Call<List<Contributor>> call, Response<List<Contributor>> response) {
                List<Contributor> contributors = response.body();

                for(Contributor contributor : contributors){
                    Log.e("E : ", contributor.login);
                    textView.append("    " + contributor.login);
                }
            }

            @Override
            public void onFailure(Call<List<Contributor>> call, Throwable t) {
                Toast.makeText(RetorofitActivity.this, "failed for getting information", Toast.LENGTH_LONG).show();

            }
        });

    }

    public void init(){

        textView = (TextView)findViewById(R.id.textView);
        retrofit = new Retrofit.Builder().baseUrl(BASE_URL).addConverterFactory(GsonConverterFactory.create()).build();


    }
}

```

<br>

- Contributor.java

```java
package company.co.retrofit;

public class Contributor {

    public final String login;

    public Contributor(String login){
        this.login = login;
    }
}

```

<br>

- GitHub.java

```java
package company.co.retrofit;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;

public interface GitHub {

    @GET("/repos/{owner}/{repo}/contributors")
    Call<List<Contributor>> contributors(@Path("owner") String owner, @Path("repo") String repo);

}

```

<br>

- RetrofitActivity.java

```java
package company.co.retrofit;

import android.app.Activity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


// https://lx5475.github.io/2017/03/30/android-retrofit/

public class RetorofitActivity extends AppCompatActivity {

    private Retrofit retrofit;
    private TextView textView;

    private final String BASE_URL = "https://api.github.com";

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        Log.e("E : ", "onCreate in RetrofitActivity");

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_retrofit);
        init();



        GitHub gitHub = retrofit.create(GitHub.class);
        Call<List<Contributor>> call = gitHub.contributors("square","retrofit");

        call.enqueue(new Callback<List<Contributor>>() {
            @Override
            public void onResponse(Call<List<Contributor>> call, Response<List<Contributor>> response) {
                List<Contributor> contributors = response.body();

                for(Contributor contributor : contributors){
                    Log.e("E : ", contributor.login);
                    textView.append("    " + contributor.login);
                }
            }

            @Override
            public void onFailure(Call<List<Contributor>> call, Throwable t) {
                Toast.makeText(RetorofitActivity.this, "failed for getting information", Toast.LENGTH_LONG).show();

            }
        });

    }

    public void init(){

        textView = (TextView)findViewById(R.id.textView);
        retrofit = new Retrofit.Builder().baseUrl(BASE_URL).addConverterFactory(GsonConverterFactory.create()).build();


    }
}

```

<br>



