## props와 state



```javascript
//MyName.js

import React, { Component } from 'react';

class MyName extends Component{

  static defaultProps = {
    name: '기본이름'
  }

  render(){

    return(
      <div>
        안녕하세요! 제 이름은
      <b>{this.props.name}</b> 입니다.
    </div>
    )
    
  }
}


// MyName.defaultProps = {
//   name: '기본이름'
// };

export default MyName;
```



```javascript
//App.js

import React, { Component } from 'react';
import MyName from './MyName';

class App extends Component {
  render() {

    return <MyName name="리액트" />;
  }
}

export default App;


```





-----

함수형 컴퍼넌트로 작성할 수도 있다. (약간 더 빠르다.)



```javascript
const object = {a:1, b:2};

const a = object.a; const b = object.b; 도 가능하지만 
const {a,b} = object; 도 가능하다.

이를 함수에도 적용할 수 있다.

function sayHello({name, age}){
    console.log(name + '의 나이는' + age);
}

sayHello({name:'react', age:'1'})




// MyName.js
import React from 'react';

const MyName = ({name}) => {
  return <div>안녕하세요! 제 이름은 {name} 입니다. </div>
};

MyName.defaultProps = {
  name: 'basic name'
}

export default MyName;
```





----

