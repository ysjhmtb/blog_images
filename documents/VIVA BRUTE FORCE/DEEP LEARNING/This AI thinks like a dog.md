<br>



> [This AI thinks like a dog](https://www.technologyreview.com/s/610775/this-ai-thinks-like-a-dog/)



이 인공지능은 개처럼 생각한다.

<br>



> It won’t lick your face, but a new artificial-intelligence system mimics canine behavior to make dog-like decisions. Other animals could be next.



당신의 얼굴을 핥지는 않을테지만, 새로운 인공지능 시스템은 개처럼 의사결정을 내리기 위해 개의 행동을 흉내낸다. 다른 동물들도 이 시스템의 다음 대상이 될 수 있다.

<br>



> by Emerging Technology from the arXiv  April 11, 2018

<br>



> All dog owners can testify to the powerful intelligence of their four-legged friends. Indeed, many dogs provide important services, such as guiding people who are visually impaired, finding lost individuals, or sniffing out drugs and other contraband.



모든 개의 주인들은 네발 달린 친구의 엄청난 지능에 대해 증언할 수 있다. 정말로 많은 개들은 시각장애인을 안내한다든가, 실종자를 찾는 다든가, 마약이나 밀수품들을 후각으로 찾는 것과 같은 중요한 서비스들을 제공한다.

<br>



> These abilities are beyond even the most powerful artificial intelligence. And yet AI researchers have yet to take advantage of them in training AI systems to be more capable.



이런 능력들은 심지어 가장 강력한 인공지능을 능가하는 것이다. 그리고 인공지능 연구자들은 인공지능 시스템의 능력을 배양시키는데 아직 그들을 활용하지 않았다.

<br>



> Today that changes thanks to the work of Kiana Ehsani at the University of Washington in Seattle and colleagues, who have gathered a unique data set of canine behavior and used it to train an AI system to make dog-like decisions. Their approach opens up a new area of AI research that studies the capabilities of other intelligent beings on our planet.



오늘날 워싱턴대의 Kiana Ehsani와 그의 동료들의 연구덕에 이런 상황은 변하고 있다. 그들은 개들 행동의 독특한 데이터 집합을 모으고, 이를 인공지능 시스템이 개와 같은 의사결정을 하도록 훈련시키는데 활용했다. 지구상의 다른 지적 생명체의 능력을 연구하는 그들의 접근은 인공지능 연구의 새로운 영역을 열었다.

<br>



> The team begin by building a database of dog behavior. They do this by kitting out a single dog with inertial measurement units on its legs, tail, and body to record their relative angle and the animal’s absolute position.



연구진은 개의 행동에 대한 데이터베이스를 만드는 작업으로 시작했다. 한 마리의 개에게 장비를 입힘으로서 데이터를 모았다. 개의 상대각도와 절대위치를 기록하기 위해 다리와 꼬리와 몸에는 관성 측정 장비를 부착했다.

<br>



> They also fitted a GoPro camera to the dog’s head to record the visual scene, sampled at a rate of five frames per second, and a microphone on the dog’s back to record sound. The data was recorded by an Arduino unit on the dog’s back.



또한 개의 머리에는 시각에 대한 정보를 얻기 위해, 초당 다섯 개의 프레임으로 샘플링되는 고프로 카메라를 부착했고, 소리를 기록하기 위하여 개의 등에는 마이크로폰을 달았다. 데이터는 개의 등에서 아두이노를 통해 기록되었다.

<br>



> In total, the team gathered some 24,500 video frames with synchronized body position and movement data. They used 21,000 of these frames for AI training and the rest for validation and testing of the AI system.



모두 합해서 개의 위치와 움직임 데이터와 연동된 24,500개의 비디오 프레임을 모았다. 연구진은 AI를 훈련시키기 위해 이중 21,000개의 프레임을 사용했고, 나머지는 시스템을 평가하고 테스트하는데 사용했다.

<br>



> The team investigated how to act like a dog, how to plan like a dog, and how to learn from a dog.



연구팀은 개가 움직이는 방법, 개처럼 계획하는 법, 그리고 개로부터 학습하는 법을 조사했다.

<br>



> In the first task, the goal was to predict the future movements of the dog given a sequence of images. The AI does this by looking at video frames and studying what the dog did next.



첫번째 과제에서는 일련의 이미지가 주어졌을 때, 개의 미래 움직임을 예측하는 것이 목표였다. AI는 비디오 프레임을 보고 개가 다음 행동으로 무엇을 하는지를 연구함으로서 이 작업을 진행했다.

<br>



> By learning in this way, the system becomes good at accurately predicting the next five movements after seeing a sequence of five images. “Our model correctly predicts the future dog movements by only observing the images the dog observed in the previous time steps,” say Ehsani and co.



이런 방식으로 학습한 결과, 시스템은 처음 다섯 개의 이미지를 본 후에 다음 다섯 개의 동작 이미지를 정확하게 예측할 수 있게 되었다. "우리의 모델은 이전 시간 동안 개가 보았던 이미지들을 단순히 관찰함으로서 개의 미래 움직임을 정확히 예측합니다."라고 연구진은 밝혔다.

<br>



> The planning task is a little more difficult. The goal here is to find a sequence of actions that move the dog between the locations of a given pair of images. The AI again learns this by studying the actions associated with a wide range of sequential video frames.



계획에 대한 과제는 좀 더 어려웠다. 여기서 목표는 주어진 여러 이미지들의 지점들 사이에서 개를 이동시킨 행적의 순열을 찾는 것이다. 다시 AI는 광범위한 비디오 프레임 배열과 연관된 행동들을 연구함으로서 이를 학습한다.

<br>



> Once again, the system performs well. “Our results show that our model outperforms these baselines in the challenging task of planning like a dog both in terms of accuracy and perplexity,” say the team.



이번에도 시스템은 좋은 성능을 보여줬다. "우리의 결과는 우리의 모델이 개처럼 계획하는 도전적인 과제의 기준선을 정확성과 어려운 상황에서의 해결능력이라는 측면 모두에서 능가한다는 점을 보여줍니다."라고 연구진은 밝혔다.

<br>



> The final task is to learn from dog behavior. One thing dogs learn is where they can and can’t walk. So the team use the database to train the AI to recognize what kinds of surfaces are walkable and to label these in new images.



마지막 과제는 개의 행동으로 부터 학습하는 것이다. 개가 학습하는 것중 하나는 그들이 걸을 수 있는 곳과 그렇지 않은 곳을 구별하는 것이다. 따라서 연구팀은 데이터베이스를 AI가 어떤 종류의 표면이 걸을 수 있는지 인식하고, 이 기준에 따라 새로운 이미지를 분류시키는 작업을 훈련시키는데 사용했다.

<br>



> That’s interesting work that shows how AI systems can match certain types of animal performance. “Our model learns from ego-centric video and movement information to act and plan like a dog would in the same situation,” they say.



그것은 시스템이 어떻게 특정한 종류의 동물 행동들을 연결시키는지를 보여주는 흥미로운 연구이다. "우리의 모델은 자기중심적인 비디오와 행동 정보를 통해 개가 같은 상황에서 할 행동과 계획하는 법을 배운다."

<br>



> Of course, there is plenty of work ahead. For example, this work gathers data from a single dog. So the team would like to study data gathered from a wide range of dogs. That would allow them to compare their behavior and understand canine visual intelligence in more detail.  



물론 앞으로 진행해야 할 연구가 많이 남아 있다. 예를 들어서, 이번 연구는 한 마리의 개에게서만 데이터를 모은다. 따라서 연구진은 광범위한 개들로부터 수집된 데이터를 연구하길 희망한다. 이렇게 된다면 그들의 행동을 비교하여 개들의 시각적인 지능을 더 자세히 이해하는 것이 가능할 것이다.

<br>



> But there is no reason why the approach should be limited to dogs. There would be much to learn by gathering similar data sets for monkeys, farm animals, and all kinds of animals in the wild. As Ehsani and co put it: “We hope this work paves the way towards better understanding of visual intelligence and of the other intelligent beings that inhabit our world.”



그러나 이러한 접근법이 개에게만 제한되어야 할 이유는 없다. 연구진이 다음과 같이 밝힌 것처럼 "우리는 이 연구가 세상에 사는 지적인 동물과 그들의 시각적인 지능을 더 잘 이해하게 되는 길에 대한 좋은 출발이기를 희망합니다.", 원숭이, 농장동물, 야생의 여러 동물로부터 비슷한 종류의 데이터를 수집해서 학습해야 할 것들이 많을 것이다. 

<br>



> Ref: arxiv.org/abs/1803.10827 : Who Let The Dogs Out? Modeling Dog Behavior From Visual Data 

<br>

