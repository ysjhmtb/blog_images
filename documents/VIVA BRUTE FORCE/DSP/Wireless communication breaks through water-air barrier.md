



> [Wireless communication breaks through water-air barrier](http://news.mit.edu/2018/wireless-communication-through-water-air-0822)   
>
> In a novel system developed by MIT researchers, underwater sonar signals cause vibrations that can be decoded by an airborne receiver.

   

수중과 대기 사이에 존재하는 무선 통신 장벽에 대한 돌파구가 마련되다     

MIT 연구진이 개발한 새로운 시스템에서는 수중 소나 신호가 대기 중의 수신기가 해석할 수 있는 진동을 만들어 낸다.   



Rob Matheson | MIT News Office 
August 22, 2018   



> MIT researchers have taken a step toward solving a longstanding challenge with wireless communication: direct data transmission between underwater and airborne devices.   
>
> Today, underwater sensors cannot share data with those on land, as both use different wireless signals that only work in their respective mediums. Radio signals that travel through air die very rapidly in water. Acoustic signals, or sonar, sent by underwater devices mostly reflect off the surface without ever breaking through. This causes inefficiencies and other issues for a variety of applications, such as ocean exploration and submarine-to-plane communication.   

   

수중과 대기의 기기들 사이의 직접 통신이라는 무선통신의 오래된 과제를 해결할 수 있는 첫걸음을 MIT 연구자들이 내딛었다.   



오늘날, 수중 센서는 지상의 센서와 데이터를 공유할 수 없다. 왜냐하면 두 기기는 제한된 영역에서만 동작하는 서로 다른 무선 신호를 사용하기 때문이다. Radio 신호는 공기 중을 움직이다가 물속에서는 바로 사라진다. Acoustic 신호나 소나는 대부분 수면을 투과하지 못하고 대부분 반사된다. 이런 특성은 통신 불능 외에도 해양탐사나 잠수함과 항공기 사이의 통신 같은 영역에서 여러 문제점을 초래했다.   



> In a paper being presented at this week’s SIGCOMM conference, MIT Media Lab researchers have designed a system that tackles this problem in a novel way. An underwater transmitter directs a sonar signal to the water’s surface, causing tiny vibrations that correspond to the 1s and 0s transmitted. Above the surface, a highly sensitive receiver reads these minute disturbances and decodes the sonar signal.   
>
> “Trying to cross the air-water boundary with wireless signals has been an obstacle. Our idea is to transform the obstacle itself into a medium through which to communicate,” says Fadel Adib, an assistant professor in the Media Lab, who is leading this research. He co-authored the paper with his graduate student Francesco Tonolini.   

   

이번 주 SIGCOMM conference에서 소개되는 논문에서, MIT 미디어 랩의 연구진들은 이 문제를 새로운 방식으로 대응할 시스템을 설계했다. 수중의 송신기가 수면으로 소나 신호를 보내면, 1과 0으로 해석되는 작은 진동을 발생시킨다. 수면 위에서,  고감도 수신기가 이 극히 작은 진동을 읽고 소나 신호를 해석한다.   



연구를 이끌고 있는 미디어 랩의 조교수 Fadel Adib은 다음과 같이 말했다. "무선 신호로 대기와 수중 표면을 통과하려 했던 시도는 그동안 진보를 막는 장애물이었습니다. 우리의 아이디어는 장애물 자체를 통신에 사용할 수단으로 바꾸자는 것입니다." 그는 대학원생인  Francesco Tonolini와 논문을 공동저술하였다.   



> The system, called “translational acoustic-RF communication” (TARF), is still in its early stages, Adib says. But it represents a “milestone,” he says, that could open new capabilities in water-air communications. Using the system, military submarines, for instance, wouldn’t need to surface to communicate with airplanes, compromising their location. And underwater drones that monitor marine life wouldn’t need to constantly resurface from deep dives to send data to researchers.  
>
> Another promising application is aiding searches for planes that go missing underwater. “Acoustic transmitting beacons can be implemented in, say, a plane’s black box,” Adib says. “If it transmits a signal every once in a while, you’d be able to use the system to pick up that signal.”   

   

"수중 무선 간 통신"(TARF)라 불리는 시스템은 아직 초기 단계이다. 하지만 수중-대기 통신을 해낼 수 있는 중요한 지점에 도달했다. 예를 들어서, 시스템을 사용하게 되면 군용 잠수함은 비행기와 통신하기 위해 위치를 드러낼 가능성이 있는 수면으로의 부상을 하지 않아도 된다. 그리고 해양 생물을 조사하는 수중 드론은 연구자에게 데이터를 전송하기 위해서 심해에서 표면으로 반복적으로 부상하지 않아도 될 것이다.   

또 다른 유망한 적용 분야는 수중으로 실종된 항공기의 탐색을 돕는 것이다. Adib은 "수중 전송 신호기는 비행기의 블랙 박스에 구현될 수 있다. 이 장치가 주기적으로 신호를 보낸다면, 그 신호를 포착하는 시스템을 사용하는 것이 가능할 것이다"라고 밝혔다.  



> **Decoding vibrations**    
>
> Today’s technological workarounds to this wireless communication issue suffer from various drawbacks. Buoys, for instance, have been designed to pick up sonar waves, process the data, and shoot radio signals to airborne receivers. But these can drift away and get lost. Many are also required to cover large areas, making them impracticable for, say, submarine-to-surface communications.   



**진동을 해석하기**      

현재의 이 무선 통신 이슈에 대한 기술적 차선책들은 다양한 결점을 가지고 있다. 예를 들어서 부표는 소나 파장을 포착하고, 데이터를 처리하며, 무선신호를 대기 중의 수신기로 발신하도록 설계되어왔다. 하지만 떠내려가 유실될 수 있다. 또한 넓은 범위를 커버하기 위해서는 많은 부표가 필요해서 잠수함과 수면 간 통신에서는 실현되기 어렵다.   



> TARF includes an underwater acoustic transmitter that sends sonar signals using a standard acoustic speaker. The signals travel as pressure waves of different frequencies corresponding to different data bits. For example, when the transmitter wants to send a 0, it can transmit a wave traveling at 100 hertz; for a 1, it can transmit a 200-hertz wave. When the signal hits the surface, it causes tiny ripples in the water, only a few micrometers in height, corresponding to those frequencies.   
>
> To achieve high data rates, the system transmits multiple frequencies at the same time, building on a modulation scheme used in wireless communication, called orthogonal frequency-division multiplexing. This lets the researchers transmit hundreds of bits at once.   



TARF는 표준 수중 스피커를 사용하여 소나 신호를 전송하는 수중 음향 전송기를 장착하고 있다. 신호는 각각의 데이터 비트에 해당하는 각각의 주파수를 갖는 파장을 가지고 수중을 통과한다. 예를 들어서, 전송기가 0을 전송하고 싶다면, 100헤르츠로 진동하는 파장을 보낼 수 있다. 그리고 1을 전송하고자 한다면 200 헤르츠의 파장을 전송할 수 있다. 신호가 수면을 치면, 물속에서 그들 주파수에 일치하면서 높이는 마이크로미터 단위인  작은 잔물결을 만든다.   

높은 데이터 전송률을 확보하기 위해 전송기는 orthogonal frequency-division multiplexing이라고도 불리는 무선통신에서 사용되는 modulation scheme을 기반으로 하여  동시에 여러 주파수들을 전송한다. 이를 통해 연구자들은 한번에 수백개의 비트들을 전송한다.  



> Positioned in the air above the transmitter is a new type of extremely-high-frequency radar that processes signals in the millimeter wave spectrum of wireless transmission, between 30 and 300 gigahertz. (That’s the band where the upcoming high-frequency 5G wireless network will operate.)  
>
> The radar, which looks like a pair of cones, transmits a radio signal that reflects off the vibrating surface and rebounds back to the radar. Due to the way the signal collides with the surface vibrations, the signal returns with a slightly modulated angle that corresponds exactly to the data bit sent by the sonar signal. A vibration on the water surface representing a 0 bit, for instance, will cause the reflected signal’s angle to vibrate at 100 hertz.  
>
> “The radar reflection is going to vary a little bit whenever you have any form of displacement like on the surface of the water,” Adib says. “By picking up these tiny angle changes, we can pick up these variations that correspond to the sonar signal.”  

   

30에서 300 기가 헤르츠 대역의 밀리미터 파형 스펙트럼 무선 전파 형태의 신호를 처리하는 새로운 형태의 고주파 레이더가 대기 중에 위치해 있다.   

원뿔의 집합체처럼 보이는 레이더는 수면에 도달한 후 레이더로 돌아오는 무선 신호를 전송한다. 신호가 수면에 충돌하는 방식 때문에, 소나 신호가 보낸 데이터 비트에 정확히 일치하는 다소 변조된 각도로 신호는 돌아온다. 예를 들어서 0 비트에 해당하는 수면의 진동은 100 헤르츠로 진동하는 반사된 신호의 각도를 만들어낼 것이다.   

Adib은 "수면에 대응하는 다양한 치환 방식을 설정할 때마다 레이데 반사는 약간씩 달라질 것이다. 이 작은 각도 변화를 포착함으로서 소나 신호에 대응하는 이 진동들을 포착할 수 있다."라고 밝혔다.  



>  **Listening to “the whisper”**     
>
> A key challenge was helping the radar detect the water surface. To do so, the researchers employed a technology that detects reflections in an environment and organizes them by distance and power. As water has the most powerful reflection in the new system’s environment, the radar knows the distance to the surface. Once that’s established, it zooms in on the vibrations at that distance, ignoring all other nearby disturbances.    
>
> The next major challenge was capturing micrometer waves surrounded by much larger, natural waves. The smallest ocean ripples on calm days, called capillary waves, are only about 2 centimeters tall, but that’s 100,000 times larger than the vibrations. Rougher seas can create waves 1 million times larger. “This interferes with the tiny acoustic vibrations at the water surface,” Adib says. “It’s as if someone’s screaming and you’re trying to hear someone whispering at the same time.”    
>
> To solve this, the researchers developed sophisticated signal-processing algorithms. Natural waves occur at about 1 or 2 hertz — or, a wave or two moving over the signal area every second. The sonar vibrations of 100 to 200 hertz, however, are a hundred times faster. Because of this frequency differential, the algorithm zeroes in on the fast-moving waves while ignoring the slower ones.    

  

**속삭임을 포착하기**   

핵심적인 과제 중 하나는 레이더가 수면을 탐지하도록 만드는 것이었다. 이를 위해, 거리와 전력을 이용해 주변 환경의 모습을 탐지하고 운용하는 기술을 차용했다. 새로운 시스템 환경에서는 물이 가장 강력한 상을 갖기 때문에, 레이더는 수면까지의 거리를 알 수 있다. 설치된 후에는 주변의 모든 소란은 무시하고 해당하는 거리에 위치하는 진동들에만 집중한다.  

다음의 주요 과제는 훨씬 크고 자연스러운 파장에 둘러싸인 마이크로미터 파장을 포착하는 일이었다.  고요한 날, capillary waves라 불리는 대양의 가장 작은 잔파도는 대략 2센티미터의 높이이다. 하지만 신호를 담고 있는 진동보다는 100,000배 더 크다. 더 거친 바다는 백만 배 더 큰 파도를 만들어 낼 수 있다. "이런 파도들은 수면의 작은 음향 진동을 간섭합니다. 이는 마치 누군가 소리치는 상황 속에서 다른 사람이 속삭이는 것을 들으려 하는 것과 같습니다."    

이 문제를 해결하기 위해, 연구진은 정교한 신호처리 알고리즘을 개발했다. 자연 상태의 파도는 1~2 헤르츠 파장으로 발생하거나 매초마다 하나나 두개의 파도가 신호영역을 이동하면서 덮게 된다. 하지만 100에서 200 헤르츠의 소나 진동을 백배 더 빠르다. 이 주파수 차이 때문에, 알고리즘은 느린 파도들을 무시하면서 빠르게 움직이는 파장을 겨냥하게 된다.  



> Testing the waters
>
> The researchers took TARF through 500 test runs in a water tank and in two different swimming pools on MIT’s campus.
>
> In the tank, the radar was placed at ranges from 20 centimeters to 40 centimeters above the surface, and the sonar transmitter was placed from 5 centimeters to 70 centimeters below the surface. In the pools, the radar was positioned about 30 centimeters above surface, while the transmitter was immersed about 3.5 meters below. In these experiments, the researchers also had swimmers creating waves that rose to about 16 centimeters.
>
> In both settings, TARF was able to accurately decode various data — such as the sentence, “Hello! from underwater” — at hundreds of bits per second, similar to standard data rates for underwater communications. “Even while there were swimmers swimming around and causing disturbances and water currents, we were able to decode these signals quickly and accurately,” Adib says.
>
> In waves higher than 16 centimeters, however, the system isn’t able to decode signals. The next steps are, among other things, refining the system to work in rougher waters. “It can deal with calm days and deal with certain water disturbances. But [to make it practical] we need this to work on all days and all weathers,” Adib says.
>
> “TARF is the first system that demonstrates that it is feasible to receive underwater acoustic transmissions from the air using radar,” says Aaron Schulman, an assistant professor of computer science and engineering at the University of California at San Diego. “I expect this new radar-acoustic technology will benefit researchers in fields that depend on underwater acoustics (for example, marine biology), and will inspire the scientific community to investigate how to make radar-acoustic links practical and robust.”
>
> The researchers also hope that their system could eventually enable an airborne drone or plane flying across a water’s surface to constantly pick up and decode the sonar signals as it zooms by.
>
> The research was supported, in part, by the National Science Foundation.

  




