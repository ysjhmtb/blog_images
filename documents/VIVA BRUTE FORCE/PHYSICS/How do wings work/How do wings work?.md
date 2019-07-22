# [How do wings work?](https://iopscience.iop.org/article/10.1088/0031-9120/38/6/001)

<br>

### 비행기에서

얼마 전 비행기에서 동생이 양력 발생의 원리를 물어서 베르누이 정리로 설명을 해주었는데, [How do wings work?](https://iopscience.iop.org/article/10.1088/0031-9120/38/6/001) 에서는 대중적으로 알려진 그 내용이 사실이 아니라는 의외의 사실을 알게 되었다. 다음은 문헌의 주요 내용이다.

<br>

### The popular explanation

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig1.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig1.png">

<br>

Figure 1은 전형적인 aerofoil의 모습을 보여준다. 그림을 보면 윗면의 길이가 아랫면의 길이보다 길고, 따라서 S에서 분리된 입자가 T에서 만난다고 가정하면, 윗면의 속도가 아랫면의 속도보다 빨라야 한다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig2.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig2.png">

<br>

여기서 베르누이 방정식이 등장한다. Figure 2가 그리고 있는 것처럼, 더 높은 속도는 더 낮은 압력을 의미하고, 이로 인해 상향 알짜힘이 발생하게 되며, 결국 양력이 발생하게 된다는 것이다.

<br>

이상의 설명은 광범위하게 퍼져 있으며, 많은 교과서에서도 발견된다. 하지만 이런 설명은 어느 정도의 진실을 담고 있지만, 수많은  중요 지점에서 부정확하다.

<br>

## What's wrong with the popular explanation?

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig3.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig3.png">

<br>

Figure 1에서 S와 T 사이의 윗면이 더 길지만, 이것이 양력의 필수 조건은 아니다. Figure 3의 돛은 수직날개라고 볼 수 있다. Figure 3을 보면 윗, 아랫면의 길이가 같음을 알 수 있으며, 윗, 아랫면의 거리 차이가 양력 발생에서 필요요소가 아님을 확인할 수 있다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig4.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig4.png">

<br>

Figure 4를 보면 윗면을 통과하는 입자가 아랫면을 통과하는 입자보다 먼저 trailing edge에 도달함을 알 수 있다. 즉 이 두 입자는 만나지 않고 비행시간도 다르다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig5.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig5.png">

<br>

Figure 5를 보면 속도차가 존재함에도 양면의 압력은 같고, 양력도 나타나지 않는다.

<br>

## An alternative explanation for lift

<br>

물체 주변의 유체 흐름을 이해하는 키는 개별 유체 입자에 작용하는 힘의 파악과 뉴튼의 운동 법칙을 적용하는 것이다. 

우선 경계층에서 주로 고려하게 될 마찰력은 없다고 가정하자. 또 유체의 흐름이 안정적이라고 가정하자.

이들 가정을 바탕으로 유체 운동을 지배하는 법칙의 도출이 가능하다. 유체 방향에 작용하는 힘은 유체 입자의 속도를 변하게 한다. 반면 그 외의 방향으로 작용하는 힘은 streamline curvature를 만든다. 

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig6.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig6.png">

<br>

Figure 6에서와 같이 일정하지 않은 속도로 직선 운동하는 유체 입자를 상상해보자. 그리고 입자의 운동 방향을 x축이라 하자.

입자가 압력이 변화하는 지역에 있고, 입자의 크기가 유한한 크기 l이라면, 입자의 전면부는 후면부와 다른 압력을 마주하게 될 것이다. 즉 x축의 압력이 감소하면, 후면부의 압력은 전면부의 그것보다 높게 되고 입자는 positive net force를 받게 된다. 뉴튼의 제2법칙에 따르면, 입자가 streamline을 따라 운동할 때, 이 힘은 가속을 유발하고 입자의 속도는 증가하게 된다. 

<br>

**If the pressure drops along a streamline, the velocity increases and vice versa.**

<br>

그러나, 베르누이 방정식은 오직 streamline에만 적용할 수 있다. 주변의 streamlines에는 압력과 속도 사이의 명시적 관계가 존재하지 않는다. 

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig7.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig7.png">

<br>

이제 curved streamline을 운동하는 입자를 생각해 보자. 입자의 속도는 상수라고 가정한다.

입자가 방향을 바꾸고 있기 때문에, 분명 구심력이 존재할 것이고, 이 힘은 오직 압력 차이에 의해서만 발생할 수 있다. 이는 입자의 한쪽면의 압력이 다른쪽보다 크다는 것을 암시한다. 

<br>

**If a streamline is curved, there must be a pressure gradient across the streamline, with the pressure increasing in the direction away from the centre of curvature.**

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig8.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig8.png">

<br>

pressure field와 flow curvature 사이의 관계는 유체역학을 이해하는데 매우 유용하다. 베르누이 방정식과 함께 이 관계는 the pressure field와 the flow velocity filed 사이의 관계를 기술한다. 이에 대한 좋은 예는 토네이도이다.

Figure 8에 볼 수 있는 것처럼 이상적인 소용돌이는 concentric circles of streamlines로 구성되어 있다. 

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig9.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig9.png">

<br>

이제 원래 문제로 돌아오자. Figure 9은 가장 간단한 형태의 aerofoil(a curved plate) 주변의 streamlines를 보여준다. 멀리 떨어져 있는 공기층은 날개의 모양에 따라 분포해 있지 않다. 이제 A 지점에서 표면으로 운동하는 것을 고려해보자. A 지점에서 시작할 때는 streamlines가 직선이고 병렬적임을 알 수 있고, 따라서 압력 경사도는 존재하지 않는다.  하지만 aerofoil에 가까이 갈수록 streamlines는 휘어져 있고, 이제 압력 경사도가 존재함을 알 수 있다. B 지점에 도달하게 되면 확실히 A 지점보다 압력이 낮다.

마찬가지로 C에서 D 지점으로 운동하는 경우를 생각할 수 있다. 이번에는 aerofoil에 다가갈수록 점점 더 휘어있는 streamlines가 존재한다. 하지만 이번에는 날개로 다가갈수록 압력이 증가한다. 따라서 D의 압력은 C보다 크다. 

결과적으로 D의 압력은 B의 압력보다 크게 되고, 이는 양력을 발생시키게 된다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/FIg10.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/FIg10.png">

<br>

Figure 10에서 thin aerofoil은 thick aerofoil보다 양력 발생에 유리하다. 하지만 제작의 어려움과 연료 저장 등의 이유로 
thick aerofoil이 많이 사용된다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/FIg11.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/FIg11.png">

<br>

빈번한 질문 중 하나는 비행기가 어떻게 비행 고도를 조절하느냐 이다. Figure 11은 angles of attack에 따른 차이를 보여준다. 
이런 유체 흐름의 차이를 통해 고도가 조정될 수 있다.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/Fig12.png](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/Fig12.png">

<br>

Figure 12를 보면 날개의 angle of attack이 증가할수록, 날개의 윗부분에 더 많은 flow curvature가 나타나고, 따라서 더 많은 양력이 발생하게 된다. 하지만 angle of attack이 과도하게 증가하면 오히려 양력을 잃게 된다.

<br>

-----

다음은 streamlines에 작용하는 힘들에 대한 수리적인 유도과정이다.

<br>



<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/PHYSICS/How%20do%20wings%20work/apdix1.jpg](https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/apdix1.jpg">

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA BRUTE FORCE/PHYSICS/How do wings work/apdix2.jpg">

<br>