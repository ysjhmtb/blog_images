# 37 Essential JavaScript Interview Questions 

 수업과 프로젝트를 통해 자바스크립트를 접하고 있는데, 우연히 [37 Essential JavaScript Interview Questions *](https://www.toptal.com/javascript/interview-questions) 를 접하게 되었고 이런 기회를 통해 자바스크립트라는 언어에 대한 이해가 더 깊어지길 희망한다.  



-----



#### 1) `typeof bar === "object"` 같은 방법을 통해 `bar` 가 객체인지 확인하게 되면 어떤 잠재적인 위험이 존재하며, 어떻게 이런 문제를 피할 수 있을까? 



 위의 방법을 사용하게 되면 자바스크립트에서는 **null** 도 객체로 인식하게 된다. 따라서 다음과 같은 결과를 얻게 된다.

```javascript
var bar = null;
console.log(typeof bar === "object");  // logs true!
```

   nulls, arrays, functions에는 객체가 아니라는 점을 확인하면서(false), 객체에는 true를 반환받고 싶다면 다음과 같은 방법이 있다.

```javascript
console.log((bar !== null) && (bar.constructor === Object));
```

  jQuery라면 

```javascript
console.log((bar !== null) && (typeof bar === "object") && (! $.isArray(bar)));
```

 ES5라면

```javascript
console.log(Array.isArray(bar));
```



----



#### 2) 다음의 코드는 어떤 이유로 어떤 결과를 출력하게 될까? 

 ```javascript
(function(){
  var a = b = 3;
})();

console.log("a defined? " + (typeof a !== 'undefined'));
console.log("b defined? " + (typeof b !== 'undefined'));
 ```



 결과는

```javascript
a defined? false
b defined? true
```

이다.   

 왜냐하면 함수 내부에 위치한 `var a = b = 3;` 는 `b = 3;` 과 `var a = b;` 를 의미하여 결국 **b** 는 전역변수가 된다.   



---



#### 3) 다음의 코드는 무슨 이유로 어떤 결과를 출력하게 되는가?

```javascript
var myObject = {
    foo: "bar",
    func: function() {
        var self = this;
        console.log("outer func:  this.foo = " + this.foo);
        console.log("outer func:  self.foo = " + self.foo);
        (function() {
            console.log("inner func:  this.foo = " + this.foo);
            console.log("inner func:  self.foo = " + self.foo);
        }());
    }
};
myObject.func();
```

 

  결과는 다음과 같다.

```javascript
outer func:  this.foo = bar
outer func:  self.foo = bar
inner func:  this.foo = undefined
inner func:  self.foo = bar
```

 외곽함수에서 this와 self는 **myObject** 를 가리킨다. 반면에 내부의 함수에서는 this가 더 이상 myObject를 가리키지 않으며, self는 내부의 함수에서도 접근이 가능하다.  



---



#### 4) 함수 블럭에서 자바스크립트 코드 전체를 감싸는 것의 중요성과 이유는 무엇인가? 

 이런 방법은 독자적인 네임스페이스를 만들게 함으로서 다른 자바스크립트 모듈 혹은 라이브러리 사이에서 발생할 수 있는 변수 중복을 막을 수 있다.  (클로져)

 또한 전역변수에 대한 참조할 수 있는 가명을 허용하게 된다. jQuery.noConflict()를 생각해 보자.   



---

**다시 확인하는 클로져!**   

[자바스크립트 클로저 쉽게 이해하기](http://chanlee.github.io/2013/12/10/understand-javascript-closure/)

```javascript
function showName(firstName, lastName) {
    var nameIntro = "Your name is ";
    // 이 내부 함수는 외부함수의 변수뿐만 아니라 파라미터 까지 사용할 수 있습니다.
    function makeFullName() {
        return nameIntro + firstName + " " + lastName;
    }
    return makeFullName();
}
showName("Michael", "Jackson"); // Your name is Michael Jackson

```

```javascript
$(function() {
    var selections = [];
    $(".niners").click(function() { // 이 클로저는 selections 변수에 접근합니다.
        selections.push(this.prop("name")); // 외부 함수의 selections 변수를 갱신함
    });
});
```



---

**jQuery.noConflict()**   



[Tips > 다른 라이브러리, 다른 버전의 jQuery와 충돌 방지하기 - $.noConflict();](https://www.cmsfactory.net/node/10494) 



```javascript
$.noConflict();
jQuery( document ).ready(function( $ ) {
  // AAA
});
// BBB

// AAA에서는 jQuery가 $를 사용하고, BBB에서는 다른 라이브러리가 $를 사용하게 된다.
```

혹은

```javascript
var jb = jQuery.noConflict();
// 이제 $ 대신 jb를 jQuery의 alias로 사용하게 된다.
```



---

#### 5) 자바스크립트 파일의 시작 부분에 `use strict` 를 사용하는 이점은?



 이 명령어를 사용하지 않았다면 무시되거나 조용히 문제가 생길 코드 에러들을 드러나게 해주는 효과를 얻을 수 있다.   

 디버깅을 쉽게 해주고, 의도하지 않은 전역변수의 선언을 억제한다.   

 또 null이나 정의되지 않은 것의 **this** 에 대한 참조를 하게 되면 에러를 발생시켜 준다.   

 그리고 `unction foo(val1, val2, val1){}` 처럼 중복되는 매개변수를 사용하는 것을 막아준다.  

 **eval()** 함수의 사용을 더 안전하게 만들어 준다. eval() 내부에 선언된 변수와 함수들이 해당 스코프에서 만들어 지는 것을 막는다.  

 객체에서 프로퍼티를 제거해 주는 데 사용되는 **delete** 연산자의 유효하지 않는 사용이 있을 때 에러를 발생시킨다.  

---

[eval() 사용법](http://chachahoya.tistory.com/62)

```javascript
var x = 2;

var y = 39;

var z = "42";

eval("x + y + 1"); // returns 42

eval(z); // returns 42
```

[delete 연산자(JavaScript)](https://msdn.microsoft.com/ko-kr/library/2b2z052x(v=vs.94).aspx)

 ```javascript
// Create an array.
var ar = new Array (10, 11, 12, 13, 14);

// Remove an element from the array.
delete ar[1];

// Print the results.
document.write ("element 1: " + ar[1]);
document.write ("<br />");
document.write ("array: " + ar);
// Output:
//  element 1: undefined
//  array: 10,,12,13,14
 ```

[JavaScript 객체의 속성을 제거할 때 delete 연산자보다 undefined 나 null 값으로 만드는 것이 낫다](https://medium.com/@laziel/javascript-%EA%B0%9D%EC%B2%B4%EC%9D%98-%EC%86%8D%EC%84%B1%EC%9D%84-%EC%A0%9C%EA%B1%B0%ED%95%A0-%EB%95%8C-delete-%EC%97%B0%EC%82%B0%EC%9E%90%EB%B3%B4%EB%8B%A4-undefined-%EB%82%98-null-%EA%B0%92%EC%9C%BC%EB%A1%9C-%EB%A7%8C%EB%93%9C%EB%8A%94-%EA%B2%83%EC%9D%B4-%EB%82%AB%EB%8B%A4-2db597f64514)

>  delete 는 단순히 객체와 속성과의 연결을 끊을 뿐 실제로 메모리에서 제거하는 것은 아니다



---



















 