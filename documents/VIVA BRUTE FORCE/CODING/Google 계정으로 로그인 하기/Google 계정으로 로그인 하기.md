## Google 계정으로 로그인 하기







### 클라이언트 ID를 발급받자

구글의 API를 사용하기 위해서는 먼저 등록을 통해 키를 생성해야 한다.   

https://console.developers.google.com/ 에서 다음의 과정을 통해 키를 생성할 수 있다.



<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/Google%20%EA%B3%84%EC%A0%95%EC%9C%BC%EB%A1%9C%20%EB%A1%9C%EA%B7%B8%EC%9D%B8%20%ED%95%98%EA%B8%B0/1.png?raw=true">



<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/Google%20%EA%B3%84%EC%A0%95%EC%9C%BC%EB%A1%9C%20%EB%A1%9C%EA%B7%B8%EC%9D%B8%20%ED%95%98%EA%B8%B0/3.png?raw=true">

<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/Google%20%EA%B3%84%EC%A0%95%EC%9C%BC%EB%A1%9C%20%EB%A1%9C%EA%B7%B8%EC%9D%B8%20%ED%95%98%EA%B8%B0/2.png?raw=true">









### 로그인 페이지로 이동할 링크를 생성하자

```jsp

<!-- index.jsp  -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	Hello World <br>
	
	<a href="googlelogin.do">google login</a>

</body>
</html>
```

```java
package com.kh.googleLogin.member.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class MemberController {

	
	@RequestMapping("googlelogin.do")
	public String googleLogin() {
		return "member/googleLogin";
	}
	
}

```







### 인증 후 사용자 정보를 확인하기

```jsp
<!-- googleLogin.jsp  -->

<html lang="en">
  <head>
    <meta name="google-signin-scope" content="profile email">
    <meta name="google-signin-client_id" content="906384191970-n96eii1dt986cgrh7krom313i4us4kab.apps.googleusercontent.com">
    <script src="https://apis.google.com/js/platform.js" async defer></script>
  </head>
  <body>
    <div class="g-signin2" data-onsuccess="onSignIn" data-theme="dark"></div>
    <script>
      function onSignIn(googleUser) {
        // Useful data for your client-side scripts:
        var profile = googleUser.getBasicProfile();
        console.log("ID: " + profile.getId()); // Don't send this directly to your server!
        console.log('Full Name: ' + profile.getName());
        console.log('Given Name: ' + profile.getGivenName());
        console.log('Family Name: ' + profile.getFamilyName());
        console.log("Image URL: " + profile.getImageUrl());
        console.log("Email: " + profile.getEmail());

        // The ID token you need to pass to your backend:
        var id_token = googleUser.getAuthResponse().id_token;
        console.log("ID Token: " + id_token);
      };
    </script>
  </body>
</html>
```





 처음에 등록해서 발급받은 클라이언트 ID를 `<meta name="google-signin-client_id" content="">` 에서 content 부분에 입력을 하면 된다.



<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/Google%20%EA%B3%84%EC%A0%95%EC%9C%BC%EB%A1%9C%20%EB%A1%9C%EA%B7%B8%EC%9D%B8%20%ED%95%98%EA%B8%B0/4.png?raw=true">



성공적으로 사용자의 정보를 확인하였다. 







