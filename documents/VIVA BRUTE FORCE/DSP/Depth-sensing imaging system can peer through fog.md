<br>

> [Depth-sensing imaging system can peer through fog](http://news.mit.edu/2018/depth-sensing-imaging-system-can-peer-through-fog-0321 )
>
> Computational photography could solve a problem that bedevils self-driving cars.



심층 탐지 시스템은 안개를 투시해서 볼 수 있다. 

계산 촬영 기법은 자율주행차를 괴롭혀 왔던 문제를 해결해 낼 수 있다.

<br>



Larry Hardesty | MIT News Office 
March 20, 2018

<br>



> MIT researchers have developed a system that can produce images of objects shrouded by fog so thick that human vision can’t penetrate it. It can also gauge the objects’ distance.



MIT 연구진은 짙은 안개에 덮혀서 사람이 볼 수 없는 물체의 이미지를 만들어 낼 수 있는  시스템을 개발해 냈다. 이 시스템은 또한 물체까지의 거리도 측정할 수 있다.

<br>



> An inability to handle misty driving conditions has been one of the chief obstacles to the development of autonomous vehicular navigation systems that use visible light, which are preferable to radar-based systems for their high resolution and ability to read road signs and track lane markers. So, the MIT system could be a crucial step toward self-driving cars.



안개 낀 주행 조건을 다룰 수 없는 미숙함은 가시광선을 사용하는 자율 주행 차 개발의 장애물 중 하나였다. 가시광선을 사용하는 방식은 높은 해상도와 도로 표지판과 차선을 읽을 수 있는 능력 때문에 레이더 기반 시스템보다 선호된다. 따라서 MIT의 시스템은 자율주행차를 향한 중요한 진일보일 수 있다.

<br>



> The researchers tested the system using a small tank of water with the vibrating motor from a humidifier immersed in it. In fog so dense that human vision could penetrate only 36 centimeters, the system was able to resolve images of objects and gauge their depth at a range of 57 centimeters.



연구진들은 작은 물탱크와 여기에 들어 있는 가습기의 진동 모터를 사용해서 시스템을 시험했다.  아주 짙은 안개 속에서 사람의 시력은 단지 36센티미터만을 볼 수 있던 반면, 시스템은 57센티미터 떨어진 물체를 판별하고 거리를 파악할 수 있었다.  

<br>



> Fifty-seven centimeters is not a great distance, but the fog produced for the study is far denser than any that a human driver would have to contend with; in the real world, a typical fog might afford a visibility of about 30 to 50 meters. The vital point is that the system performed better than human vision, whereas most imaging systems perform far worse. A navigation system that was even as good as a human driver at driving in fog would be a huge breakthrough.



57센티미터가 아주 긴 거리는 아니다. 하지만 실험을 위해 만들어진 안개는 사람이 운전하면서 마주해야 할 것보다 훨씬 짙다. 실제 세계에서 전형적인 안개는 30~50 센티미터 정도의 가시거리를 갖는다. 중요한 지점은 시스템은 사람의 시각보다 뛰어난 수행 능력을 보였던 반면 대부분의 영상 시스템은 훨씬 더 나쁜 수행 능력을 보였다. 심지어 안개 속에서 주행하는 사람만큼 뛰었났던 항법 시스템에게도 중요한 돌파구가 될 것이다.   

<br>



> “I decided to take on the challenge of developing a system that can see through actual fog,” says Guy Satat, a graduate student in the MIT Media Lab, who led the research. “We’re dealing with realistic fog, which is dense, dynamic, and heterogeneous. It is constantly moving and changing, with patches of denser or less-dense fog. Other methods are not designed to cope with such realistic scenarios.”



“나는 실제 안개 속을 볼 수 있는 시스템을 개발하는 도전을 하기로 결정했다.”라고 연구를 이끌었던 MIT 미디어 랩 대학원생 Guy Satat이 말했다. “우리는 밀고가 높고, 역동적이고, 다양한 요소들로 이루어진 실제 안개를 다루고 있다. 이것은 지속적으로 움직이고 더 짙게 혹은 더 옅은 안개로 변화한다. 다른 방법론들은 그런 현실적인 시나리오들에 대처하도록 설계되지 않았다. 

<br>



> Satat and his colleagues describe their system in a paper they’ll present at the International Conference on Computational Photography in May. Satat is first author on the paper, and he’s joined by his thesis advisor, associate professor of media arts and sciences Ramesh Raskar, and by Matthew Tancik, who was a graduate student in electrical engineering and computer science when the work was done.



Satat과 그의 동료들은 5월에 ICCP에서 발표할 논문에서 그들의 시스템에 대해 기술한다. Satat은 논문의 제1저자이고, 이 프로젝트에는 논문 지도 교수이자 미디어 아트와 과학과의 조교수인 Ramesh Raskar와 프로젝트가 완료되었을 때 전기공학과 컴퓨터과학과의 대학원생이었던 Matthew Tancik에 의해 참여하게 되었다.

<br>



> Playing the odds

확률 다루기

<br>



> Like many of the projects undertaken in Raskar’s Camera Culture Group, the new system uses a time-of-flight camera, which fires ultrashort bursts of laser light into a scene and measures the time it takes their reflections to return.



RCCG에서 착수된 많은 프로젝트처럼, 이 새로운 시스템도 초단파 레이저 빛을 사물에 쏘아서 빛이 반사되는 시간을 측정해내는  time-of-flight 카메라를 사용했다. 

<br>



> On a clear day, the light’s return time faithfully indicates the distances of the objects that reflected it. But fog causes light to “scatter,” or bounce around in random ways. In foggy weather, most of the light that reaches the camera’s sensor will have been reflected by airborne water droplets, not by the types of objects that autonomous vehicles need to avoid. And even the light that does reflect from potential obstacles will arrive at different times, having been deflected by water droplets on both the way out and the way back.



맑은 날, 빛의 반사되어 돌아오는 시간은 물체까지의 거리를 확실하게 나타낸다. 그러나 안개는 빛을 산란시키거나 무작위적인 방향으로 보내게 만든다. 안개 낀 날씨에서,  카메라 센서에 도달하는 대부분의 빛은 자율주행차가 피할 필요가 있는 물체에 의한 것이 아니라  공기 중에 떠 있는 물방울들에 의해  반사된 것일 것이다. 그리고 심지어 잠재적인 장애물에서 반사되고 물방울 들에 의해 빛이 나갔다가 들어오는 두 방향 모두에서 방향이 바뀐 빛은 다른 시간에 도착할 것이다.

<br>



> The MIT system gets around this problem by using statistics. The patterns produced by fog-reflected light vary according to the fog’s density: On average, light penetrates less deeply into a thick fog than it does into a light fog. But the MIT researchers were able to show that, no matter how thick the fog, the arrival times of the reflected light adhere to a statistical pattern known as a gamma distribution.



MIT의 시스템은 통계학을 사용하여 이 문제를 해결한다. 안개에 반사된 빛이 만들어 내는 패턴은 안개의 밀도에 따라 다양하다. 평균적으로, 빛은 짙은 안개를 옅은 것보다 덜 깊게 관통한다. 하지만 연구진은 안개가 얼마나 두껍냐에 관계없이 반사된 빛이 도달하는 시간이 감마 분포라고 알려진 패턴을 고수하는 것을 발견하는 것이 가능했다.

<br>



> Gamma distributions are somewhat more complex than Gaussian distributions, the common distributions that yield the familiar bell curve: They can be asymmetrical, and they can take on a wider variety of shapes. But like Gaussian distributions, they’re completely described by two variables. The MIT system estimates the values of those variables on the fly and uses the resulting distribution to filter fog reflection out of the light signal that reaches the time-of-flight camera’s sensor.



감마 분포는 친숙한 벨 커브를 만들어내는 가우시안 분포보다 다소 더 복잡하다. 이것은 비대칭적일 수 있고, 더 다양한 모습을 띌 수 있다. 하지만 가우시안 분포처럼 감마 분포는 두 변수에 의해 완벽히 기술될 수 있다. MIT 시스템은 동적으로 이들 변수의 값을 측정하고, 결과로 얻은 분포를 카메라 센서에 도달하는 광신호 범위 밖의 안개의 추정치를 필터링하는데  사용한다.

<br>



> Crucially, the system calculates a different gamma distribution for each of the 1,024 pixels in the sensor. That’s why it’s able to handle the variations in fog density that foiled earlier systems: It can deal with circumstances in which each pixel sees a different type of fog.



결정적으로, 이 시스템은 센서의 1,024 픽셀 각각의 다른 감마 분포를 계산한다. 이 부분이 예전 시스템을 좌절시켰던 안개 밀도의 분포를 다룰 수 있는 비결이다.  각 픽셀이 다양한 안개의 종류를 판별하게 되고, 다양한 상황들을 다룰 수 있게 된다.

<br>



> Signature shapes

특징의 모양

<br>



> The camera counts the number of light particles, or photons, that reach it every 56 picoseconds, or trillionths of a second. The MIT system uses those raw counts to produce a histogram — essentially a bar graph, with the heights of the bars indicating the photon counts for each interval. Then it finds the gamma distribution that best fits the shape of the bar graph and simply subtracts the associated photon counts from the measured totals. What remain are slight spikes at the distances that correlate with physical obstacles.



카메라는 56 피코세컨마다 도달하는 광자의 수를 계측한다. MIT의 시스템은 이렇게 계측된 초기 데이터를 히스토그램, 즉 각 인터벌 동안의 광자의 수를 바의 높이로 나타내는 바 그래프를 만드는데 사용한다. 이후 바 그래프의 모양에 가장 적합한 감마 분포를 찾는다 그리고 측정된 총량에서 센 관련된 광자들을 뺀다. 남아있는 것은 물리적 장애물과 관련있는 거리에서 약간 치솟은 부분이다.

<br>



> “What’s nice about this is that it’s pretty simple,” Satat says. “If you look at the computation and the method, it’s surprisingly not complex. We also don’t need any prior knowledge about the fog and its density, which helps it to work in a wide range of fog conditions.”



“이 점이 좋은 것은 상당히 간단하다는 점입니다. 만일 수행된 계산과 방법론들을 본다면, 의외로 복잡하지 않다는 것을 알 수 있습니다. 우리는 다양한 안개의 상태에 따라 시스템이 작동하도록 만드는 안개와 그 밀도에 대한 어떠한 선행지식도 필요하지 않습니다.

<br>



> Satat tested the system using a fog chamber a meter long. Inside the chamber, he mounted regularly spaced distance markers, which provided a rough measure of visibility. He also placed a series of small objects — a wooden figurine, wooden blocks, silhouettes of letters — that the system was able to image even when they were indiscernible to the naked eye.



Satat은 1미터 길일의 안개 챔버를 사용하여 시스템을 테스트했다. 챔버 내부에서, 그는 일정한 간격으로 거리 표시 장치를 위치시켰다. 이 표시 장치를 통해 대략적인 가시성을 나타냈다. 또한 나무로 만든 작은 조각상, 나무 블록,  문자의 실루엣 같은 작은 물체들도 위치시켰다.  시스템은 심지어 육안으로 알아볼 수 없는 상황에서도 물체를 이미지로 만들 수 있었다. 

<br>



> There are different ways to measure visibility, however: Objects with different colors and textures are visible through fog at different distances. So, to assess the system’s performance, he used a more rigorous metric called optical depth, which describes the amount of light that penetrates the fog.



그러나 가시성을 측정하는 다른 방식들이 존재한다. 물체의 색과 질감에 따라 안개 속에서 볼 수 있는 거리가 다르다. 따라서 시스템의 성능을 평가하기 위해서, 그는 광학적 깊이라고 불리는 더 엄격한 미터법을 사용했다.  광학적 깊이는 안개를 투과하는 빛의 양을 나타낸다.

<br>



> Optical depth is independent of distance, so the performance of the system on fog that has a particular optical depth at a range of 1 meter should be a good predictor of its performance on fog that has the same optical depth at a range of 30 meters. In fact, the system may even fare better at longer distances, as the differences between photons’ arrival times will be greater, which could make for more accurate histograms.



광학적 깊이는 거리에 독립적이다. 따라서 안개 속 1미터 거리에서 특정한 광학적 깊이를 갖는 시스템의 성능은 안개 속 30미터 거리에서 같은 광학적 깊이를 갖는 시스템 성능의 좋은 예측 변수가 될 것이다. 사실 시스템은 심지어 더 긴 거리에서 더 나은 성능을 발휘할 수도 있다. 왜냐하면 더 정확한 히스토그램을 만들 수 있는 광자의 도착 시간 간의 차이가 더 중요하기 때문이다.

<br>



> “Bad weather is one of the big remaining hurdles to address for autonomous driving technology,” says Srinivasa Narasimhan, a professor of computer science at Carnegie Mellon University. “Guy and Ramesh’s innovative work produces the best visibility enhancement I have seen at visible or near-infrared wavelengths and has the potential to be implemented on cars very soon.”



“악천후는 자율 주행 기술을 위해 해결해야 할 큰 난제 중 하나이다.”라고 카네기 멜론 대학교 컴퓨터과학과의 Srinivasa Narasimhan 교수가 말했다.  “Guy와 Ramesh의 혁신적인 성과가  최고의 가시성 보강 알고리즘을 만들었고, 곧 자동차에 적용될 잠재력을 가지고 있다.”



<br>

