## 본격적인 리액트 코드 작성하기 & JSX



### Webpack

<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/React/%EB%B3%B8%EA%B2%A9%EC%A0%81%EC%9D%B8%20%EB%A6%AC%EC%95%A1%ED%8A%B8%20%EC%BD%94%EB%93%9C%20%EC%9E%91%EC%84%B1%ED%95%98%EA%B8%B0%20&%20JSX/Webpack.png?raw=true">

 자바스크립트 코드 내부에서 사용된 이미지나 여러 자바스크립트 파일들을 하나의 파일로 묶어주는 작업을 번들링이라고 하며, 이런 작업을 가능하게 도와주는 번들러 도구가 웹팩이다.



### Babel

<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/React/%EB%B3%B8%EA%B2%A9%EC%A0%81%EC%9D%B8%20%EB%A6%AC%EC%95%A1%ED%8A%B8%20%EC%BD%94%EB%93%9C%20%EC%9E%91%EC%84%B1%ED%95%98%EA%B8%B0%20&%20JSX/Babel.png?raw=true"> 

 차세대 자바스크립트 표준인 ES6는 현재의 웹 브라우저에서는 제대로 동작하지 못하는데, 이런 문제의 해결을 위한 변환도구가 바벨이다. 또한 리액트에서는 JSX라는 문법이 있는데, 이를 변환하는데도 바벨이 사용된다. 



### CodeSandbox

<img src="https://github.com/ysjhmtb/blog_images/blob/master/documents/VIVA%20BRUTE%20FORCE/CODING/React/%EB%B3%B8%EA%B2%A9%EC%A0%81%EC%9D%B8%20%EB%A6%AC%EC%95%A1%ED%8A%B8%20%EC%BD%94%EB%93%9C%20%EC%9E%91%EC%84%B1%ED%95%98%EA%B8%B0%20&%20JSX/CodeSandbox.png?raw=true">



[React Basics](https://codesandbox.io/s/4r6lqrlvj9)



```javascript
//App.js

//리액트 모듈에서 리액트를 불러와 사용하겠다.
import React, { Component } from 'react';

//클래스를 사용해 컴포넌트를 만드는 방식.
class App extends Component {
 
    //render 메소드에서는 반드시 JSX 형태를 반환해야 한다. 이제 JSX에 대해 알아보자.
  render() {
    return (
      <div>
        <h1>안녕하세요 리액트</h1>
      </div>
    );
  }
}

export default App;
```







### JSX 기본 문법 알아보기 1

JSX는 HTML 같지만 자바스크립트로 변환이 된다. 이는 리액트 컴퍼넌트를 사용할 때 사용되는 문법이다. HTML이랑 비슷하지만 지켜야 할 규칙이 있다. [3편: JSX](https://react-anyone.vlpt.us/03.html)





#### 태그는 꼭 닫혀 있어야 한다.



 <div>가 있으면 반드시 </div>가 있어야 한다. 

```javascript
render() {
    return (
      <div>
        //<input type="text" /> 가 옳은 형태이다.
        <input type="text">
      </div>
    );
  }
```

이렇게 하면 에러가 발생한다. 





#### 두개 이상의 엘리먼트는 무조건 하나의 엘리먼트로 감싸져있어야 한다.



```javascript
class App extends Component {
  render() {
    return (
      <div>Hello1</div>
      <div>Hello2</div>
    );
  }
}
```

 

위와 같이 작성하면 에러가 발생한다. 따라서 다음처럼 작성해야 한다.

```javascript
import React, { Component } from 'react';

class App extends Component {
  render() {
    return (
      <div>
        <div>Hello1</div>
        <div>Hello2</div>
      </div>
    );
  }
}

export default App;




// 혹은 다음처럼 작성.
import React, { Component, Fragment } from 'react';

class App extends Component {
  render() {
    return (
      <Fragment>
        <div>Hello1</div>
        <div>Hello2</div>
      </Fragment>
    );
  }
}

export default App;

```





#### JSX 안에서 자바스크립트 값 사용하기



```javascript
import React, { Component, Fragment } from 'react';

class App extends Component {
  render() {
    const name = "react!";

    return (
     <div>
      hello {name}
     </div>
    );
  }
}

export default App;


// var
function foo(){
  var a = 'hello';

  if(true){
    var a = 'bye';
    console.log(a); // bye
  }

  console.log(a);   // bye가 출력되는 문제 발생.
  // a의 스코프가 함수 영역이기 때문에 발생.
}

// let
function foo() {
  let a = 'hello';

  if (true) {
    let a = 'bye';
    console.log(a); // bye
  }

  console.log(a);   // hello
  //let과 const의 경우에는 스코프가 블럭 단위로 되어 있다.
}

// var는 이제 지양하자. const는 한번 선언 후 고정적인 값에 
// 사용하며, let은 유동적인 값에 상용하자.
```





#### 조건부 렌더링 



```javascript
import React, { Component, Fragment } from 'react';

class App extends Component {
  render() {
    const name = "react!";

    return (
     <div>
      {
        1 + 1 === 3
        ? '맞다'
        : '틀리다'
      } // 틀리다
     </div>
    );
  }
}

export default App;
```



```javascript
import React, { Component, Fragment } from 'react';

class App extends Component {
  render() { 
    const name = "react!";

    return (
     <div>
      {
       name === 'react!' && <div>React</div>
       // 화면에 React 가 나타난다.
      }
     </div>
    );
  }
}

export default App;


```



```javascript
import React, { Component, Fragment } from 'react';

class App extends Component {
  render() { 
    const value = 1;

    return (
      //일반적인 방법은 아니다.
     <div>
      {
        //함수를 선언한 다음에 바로 호출하기.
        (function(){
          if(value === 1) return <div>1이다</div>
          if (value === 2) return <div>2이다</div>
          if (value === 3) return <div>3이다</div>
          return <div>없다</div>
        })()
      }
     </div>
    );
  }
}

export default App;

/* 

<div>
      {
        //함수를 선언한 다음에 바로 호출하기.
        (() => {
            if (value === 1) return <div>1이다</div>
            if (value === 2) return <div>2이다</div>
            if (value === 3) return <div>3이다</div>
            return <div>없다</div>
        })()
      }
</div>
도 가능하다. 
*/
```







