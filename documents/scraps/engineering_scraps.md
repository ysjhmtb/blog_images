

<br>



<br>



<br>



<br>



<br>



<br>

[PAPERS WE LOVE](https://github.com/papers-we-love/papers-we-love)

<br>

[THE SUPER TINY COMPILER](https://github.com/jamiebuilds/the-super-tiny-compiler)

<br>

[Disable tailspind and spindump to Speed Up your Mac](https://www.macobserver.com/tips/how-to/disable-tailspind-spindump-macos-cpu-speed/)

<br>

[How I Became a Better Programmer](https://jlongster.com/How-I-Became-Better-Programmer)

<br>

[[번역] 나는 어떻게 더 나은 프로그래머가 되었는가](https://medium.com/@rinae/%EB%B2%88%EC%97%AD-%EB%82%98%EB%8A%94-%EC%96%B4%EB%96%BB%EA%B2%8C-%EB%8D%94-%EB%82%98%EC%9D%80-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EA%B0%80-%EB%90%98%EC%97%88%EB%8A%94%EA%B0%80-b84c45d8bf98)

> 하지만 방금 말씀드린 유형의 사람들을 맹목적으로 따르면 안됩니다. 트위터에서 보면 엄청나보이는 사람도 **실제로 일하는 모습을 보면 우리가 일하는 모습과 그리 다르지 않습니다.** 모든 수단과 방법을 가리지 않고 작동하는 코드를 쓰려 합니다(Hacks everywhere). 우리는 그저 더 나은 방법을 위해 계속 실험하고 있는겁니다.

> 제 생각에 가장 좋은 아이디어들 중 일부는 비교적 새로운 프로그래머들로부터 나옵니다. 그 사람들은 기존 기술의 발전을 지켜보면서도 이미 틀에 박힌 의견을 보지 않는 사람들인 경우가 많습니다.

> 매일 등장하는 대부분의 새로운 라이브러리 등은 그저 기존에 있던 같은 아이디어의 재탕입니다. **진정 혁명적인 물건은 몇 년에 한번씩 나타납니다.** 이 내용에 대한 좋은 발표가 있습니다. 제목은 [해먹 주도 개발(Hammock Driven Development)](https://youtu.be/f84n5oFoZBc)입니다.

> 그렇다면 “자잘한 게” 뭘까요? 여러분이 생각하시기 나름입니다만, 제가 자잘한 것이라 생각하는 몇 가지 예를 드리겠습니다. 언어의 문법, 라이브러리의 API, 빌드 도구의 설정 방법, ES7 이후의 자바스크립트 문법 등을 익히는 일은 **컴파일러의 동작원리 등을 익히는 일에 비교하면** 여러분을 더 좋은 개발자로 만들어주지 않습니다. 기존에 있던 아이디어를 새로운 API 로 구현해 놓은 수준의 라이브러리를 채택해서 쓰는 일은 그닥 도움이 되지 않습니다. 물론 위에 서술한 모든 것들이 도움이 되긴 합니다만, 심층적인 내용에 시간을 **더**투자하길 권합니다. 그러면 몇년 뒤에 큰 도움이 됩니다.
>
> 여러분께 질문을 드려봅니다. 대부분의 시간을 코드가 “깔끔하게” 보이는데 쓰고 있나요? 그렇다면 그러지 마시길 권합니다. 어차피 여러분의 코드는 여러 번에 걸쳐 변하게 되어있습니다. 해결하고자 하는 문제 및 추상화 계층에 많은 시간과 노력을 들이는게 더 낫습니다. 모든 문제가 정리되었다면 약간의 시간을 들여서 코드를 정리하는 작업을 하면 됩니다. (DRY 원칙에 위배될 수 있습니다만, **일단 너무 걱정하지 마시고 마음 내키는대로 중복 코드를 작성해보세요**)

> 어떤 아이디어가 떠올라서 바로 작업에 착수하고 싶어질 떄가 있습니다. 하지만 기존에 다른 사람들이 그 문제를 어떻게 해결했는지 간단히라도 살펴보기 전 까지는 무작정 시작하지 마세요. **특정 주제를 며칠 정도 조사해보는 버릇은 언제나 문제를 해결하는 방법을 송두리째 바꿔줍니다.**
>
> 논문을 읽는 방법을 배우는 것도 좋습니다. 저는 수학적 의미론/조작적 의미론 등의 용어는 하나도 몰라서 읽을 수 없는 논문이 많습니다. 하지만 수학 용어 대신 코드로 이루어진 논문도 많으며 읽는 것도 그리 어렵지 않습니다. 과거 30 년간 *엄청난*양의 지식이 논문을 통해 축적되었습니다. **여기서 필요한 지식을 잘 추출하는 능력만 기르면 금세 지식을 선도하는 사람(thought-leader)이 될 수 있습니다.**
>
> [Prettier](https://github.com/prettier/prettier)는 위에 설명드린 팁의 완벽한 예시입니다. 저는 제가 뭘 하고 싶은지는 알겠는데 구현하는 방법은 전혀 떠올리지 못했습니다. 조사를 좀 해보니 [이런 논문](http://homepages.inf.ed.ac.uk/wadler/papers/prettier/prettier.pdf)을 발견했고, 며칠 뒤 뭘 해야하는지 정확히 파악할 수 있었습니다. 그러고 나니 기본적인 작업은 1 주일만에 끝났습니다. 만약 사전에 조사해보지 않았다면 훨씬 오래 걸렸을겁니다.
>
> 혹시 논문을 찾아보고 싶으시다면 [Papers We Love](https://github.com/papers-we-love/papers-we-love)라는 훌륭한 Github 저장소부터 살펴보시길 바랍니다.

>무언가를 익히는데 직접 경험하는 것 보다 더 나은 수단은 없습니다. 모든 사람들이 뛰어들 수 있진 않지만, 만약 시간이 있다면 큰 프로젝트를 맡아보세요. **굳이 끝까지 마칠 필요는 없습니다. 그냥 컴파일러 작성을 해보는데 머리를 싸매다 보면 몇 주만에 아주 많은 것을 배울 수 있습니다.**
>
>저는 솔직히 복잡한 문제를 해결하고 싶은데 하나도 모르는 기분이 싫습니다. (익숙지 않아서) 불편합니다. 문제 해결의 실마리라도 얻으려면 많은 양의 조사를 하고 배워야 한다는 것도 압니다. 하지만 이 모든 과정을 거치고 나면 저는 언제나 더 나은 프로그래머가 됩니다.

>몇 가지 추천할만한 방법들을 리스트로 추려 보았습니다. 이 모든 방법들은 제 프로그래머 커리어에 커다란 영향을 주었습니다. 대부분은 지금도 다양한 형태로 도움이 되고 있으며 새로운 아이디어를 깊게 분석하는데 도움이 됩니다. **좋은 프로그래머가 되기 위해 아래 모든 일을 다 할 필요는 없습니다.**그리고 분명 여러분의 성장을 도울 수 있는 다른 방법들이 있습니다. 그저 저에게 도움이 되었던 방법을 말씀드려 보겠습니다.
>
>- **C 배우기**- 아직 해보신 적 없다면 기본만 살펴보시기 바랍니다. 왜 모두들 C 를 가지고 불평하는지 이해할만한 가치는 있다고 생각합니다.
>- **컴파일러 작성해보기**- 아마 익숙하지 않은 일을 하면서 배우는 방법 중 최고봉일겁니다. [Super Tiny Compiler](https://github.com/thejameskyle/the-super-tiny-compiler)를 살펴보세요.
>- **매크로를 배우기**- Scheme, Lisp, Clojure(Script)를 살펴보세요. 매크로는 코드를 보는 방법을 크게 바꾸어줍니다.
>- **SICP**- [SICP](https://mitpress.mit.edu/sites/default/files/sicp/index.html)는 아주 오래된 책이지만 여전히 유용한 정보를 담고 있는 책이라고 생각합니다. (그렇게 생각하지 않는 사람들도 있습니다) 이 책은 프로그래밍 지식이 아주 얕은 독자를 대상으로 [meta-circular evaluator](https://en.m.wikipedia.org/wiki/Meta-circular_evaluator)와 컴파일러를 구현하는 방법을 처음부터 끝까지 알려줍니다. 제가 재밌게 읽으면서 컴파일러를 더 깊이 알아볼 수 있던 책은 [Lisp In Small Pieces](https://www.amazon.com/Lisp-Small-Pieces-Christian-Queinnec/dp/0521545668)였습니다.
>- **Continuation 을 이해하기**- [Continuation](https://en.wikipedia.org/wiki/Continuation)은 저수준의 제어 흐름 원리입니다. Scheme 은 이를 유일하게 구현한 언어이며, 실무에 사용할 일은 전혀 없을테지만 제어 흐름을 생각하는 방식을 바꿔줄겁니다. 저는 이 내용을 설명하기 위해 [블로그 포스트](http://jlongster.com/Whats-in-a-Continuation)도 작성했습니다.
>- **아무거나 새로운 프로그래밍 언어 배우기**- 무엇을 하시던지 다른 언어를 배우시는게 좋습니다. 제가 추천하는 언어는 Clojure, Rust, Elm, OCaml/Reason, Go, Scheme 입니다. 이 모든 언어들은 각자 고유한 기능이 있으며 그 기능을 통해 새로운 사고방식을 배우도록 만들어줍니다.

<br>

> 朴聖國, Shawn @sungkkshawnpark
>
> 이것의 일부는 deliberate learning에 속한다. 단순 반복과는 확실히 다르다. 그 다름을 유지하는 것이 학습의 비결 아닐까 한다. 모든 반복을 의미있게 하려고 노력해야 한다.
>
> [오후 1:01 - 2018년 6월 5일](https://twitter.com/sungkkshawnpark/status/1004090800303587328)
>
> 朴聖國, Shawn @sungkkshawnpark
>
> 최근 일주일 학습 과정에서 얻은 통찰들:
> 1. 안다고 생각하는 것은 실행하는데 필요한 앎에 비하면 부족하다.
> 2. 따라서 이를 실제로 써먹으려면 최소 한 두 번은 시연해봐야 한다.
> 3. 의도치 않더라도 최근의 학습을 즉시 적용해 이득을 얻을 수 있다.
>
> [오전 8:47 - 2017년 6월 25일](https://twitter.com/sungkkshawnpark/status/879003048088973312)

<br>

[Zen of Analog Circuit Design](https://www.amazon.com/Analog-Circuit-Design-Anand-Udupa-ebook/dp/B00YQ6XTW0)

<br>

[Git Cheat Sheet](https://www.git-tower.com/blog/git-cheat-sheet)

<br>

[Vim Cheat Sheet](https://vim.rtorr.com/)

<br>

[A QUICK CHEAT SHEET TO THE UNIX/MAC TERMINAL](https://learntocodewith.me/command-line/unix-command-cheat-sheet/)

<br>

[The evidence that shows Iron Dome is not working](https://thebulletin.org/evidence-shows-iron-dome-not-working7318)

<br>

[How to Install and Configure Apache Tomcat 9 on Ubuntu 18.04 LTS](https://www.howtoforge.com/tutorial/ubuntu-apache-tomcat/)

<br>

[How can vim make you a better developer](https://dev.to/pmihaylov/how-can-vim-make-you-a-better-developer-2c3i)

<br>

[Javascript in one pic](https://github.com/coodict/javascript-in-one-pic/blob/master/README.md)

<br>

[In Linux directories are basically files. How is it in Windows?](https://www.quora.com/In-Linux-directories-are-basically-files-How-is-it-in-Windows/answer/Vern-Hart?share=541e3d01&srid=XAfq)

<br>

[Build Your Own Container Using Less than 100 Lines of Go](https://www.infoq.com/articles/build-a-container-golang)

<br>

[Docker and Go: why did we decide to write Docker in Go?](https://www.slideshare.net/jpetazzo/docker-and-go-why-did-we-decide-to-write-docker-in-go)

<br>

[Frontend 지원 테스트 2](https://github.com/purpleworks/coding_test/blob/master/Frontend/Test2/README.md)

<br>

[AI Winter Is Well On Its Way](https://blog.piekniewski.info/2018/05/28/ai-winter-is-well-on-its-way/)

<br>

[Get a full fake REST API with zero coding in less than 30 seconds (seriously)](https://github.com/typicode/json-server)

<br>

[jQuery 보다 먼저 알았으면 좋았을 것들](http://blog.jeonghwan.net/2018/01/25/before-jquery.html)

<br>

[Hedy Lamarr – the 1940s ‘bombshell’ who helped invent wifi](https://www.theguardian.com/film/2018/mar/08/hedy-lamarr-1940s-bombshell-helped-invent-wifi-missile)

<br>

부분에 대한 완급 조절과 꾸준함 그리고 여유로운 검색.

<br>

> JP.Jung_대마왕 @JPcorps
>
> 이제부터 열심히 하겠다는 말을 별로 안 믿는 편인데 보통 열심히라는건 갑자기 되는게 아니라 평소 생활 습관에 가깝고 평소 열심히 살았던 사람들은 뭐가 되었건 뭐라도 하나 이미 잘 하고 있음. 주변에서는 그런 사람들을 보고 재능있다라고 얘기하지.
>
> [오전 1:06 - 2018년 5월 27일](https://twitter.com/JPcorps/status/1000649463503859712)
>
> 
>
> JP.Jung_대마왕 @JPcorps
>
> 2개씩이나 잘하는 것이 있다면 3개씩이나 더 필요할 리가 없습니다. 그 3개는 잘하는 다른 사람에게 맡기고 본인은 2개만 할 수 있게 해주는 회사가 성공할 회사입니다.

<br>

> énie @enie_latente
>
> 딸아, 수학 공부는 벼락치기로는 안된단다. 네 이해력이 아무리 좋다해도 문제를 풀면서 직접 연습하는게 쌓이지 않으면 시험에서 네 손이 움직이지 않을 것이고, 계산만 연습하면 생각하는 훈련이 되지 않아서 조금만 문제가 어려워도 머리가 멈추지.
>
> [오전 11:47 - 2018년 5월 21일](https://twitter.com/enie_latente/status/998636340521635841)
>
> énie @enie_latente
>
> 시험 전 날 열시간을 공부해도 머리에 남지 않는게 수학이야. 
> 음악 연습이랑 같아. 평소에 연습이 되어 있지 않으면 음악이 흐를 수가 없잖아. 
>
> 연습은 매일 조금씩 하는 거야. 수학도 음악도 운동도. 반복된 시간이 흐르고 쌓여서 깊어지는 너의 생각을 직접 체험하기를.
>
> [오전 11:49 - 2018년 5월 21일](https://twitter.com/enie_latente/status/998636862033014784)

<br>

[Apple’s earbuds were inspired by the dark side, says chief designer Jony Ive](https://www.theverge.com/2017/7/26/16031546/apple-earbuds-stormtroopers-star-wars-jonathan-ive)

<br>

[신규 Web 서비스시 고려해 볼 사항](http://kwonnam.pe.kr/wiki/web/%EC%8B%A0%EA%B7%9C%EC%84%9C%EB%B9%84%EC%8A%A4)

<br>

[Top SQL Interview Questions And Answers](https://intellipaat.com/interview-question/sql-interview-questions/)

<br>

[45 Essential SQL Interview Questions](https://www.toptal.com/sql/interview-questions)

<br>

[50 Servlet Interview Questions and Answers](https://www.journaldev.com/2015/servlet-interview-questions-and-answers)

<br>

[HTTrack WEBSITE COPIER](https://www.httrack.com/)

<br>

[STRML : Projects and Work](http://strml.net/)

<br>

> 朴聖國, Shawn @sungkkshawnpark
>
> 의미 있는(meaningful) 삶은 개인이 추구하는 가치와 행동의 정합성이 높은 삶. 다시 말해, 개인이 아는 것과 행동하는 것이 일치하는 삶. 대부분의 인간들이 욕심쟁이나 허풍쟁이인 것은 대개 자신이 중요하다고 생각하는 것을 “얻는(acquire)” 방향으로 행동하지 않기 때문이다. 대개 원하기만 한다.
>
> [오후 10:06 - 2018년 5월 23일](https://twitter.com/sungkkshawnpark/status/999517040011456512)

<br>

> 안희종  @heejongahn
>
> 중학생 땐 나름 중등부 화학 올림피아드 금상까지 타고, 과학고 가서도 화학 전공하고, 심지어는 잠깐이지만 대학에서도 화학과였던 때가 있는데 지금은 너무 놀라울 정도로 전부 까먹었다. 친구들 만나서 종종 얘기하다 보면 중학교 내용도 전혀 기억 못하는 나에게 좀 놀란다. 신기하고 좀 슬프기도.
>
> [오전 7:18 - 2018년 5월 22일](https://twitter.com/heejongahn/status/998931062762844161)

유능한 분도 시간이 지나면 잊기 마련인데, 나같은 사람이 망각하는 것은 너무나 당연한 일.

<br>

[Relation and difference between Fourier, Laplace and Z transforms](https://electronics.stackexchange.com/questions/86489/relation-and-difference-between-fourier-laplace-and-z-transforms)

<br>

[JSP Interview Questions and Answers](https://www.journaldev.com/2110/jsp-interview-questions-and-answers)

<br>

[Scientists: Ozone-Eating Chemical Mysteriously Rising](https://learningenglish.voanews.com/a/scientists-say-ozone-eating-chemical-is-mysteriously-rising/4398631.html)

<br>

[30 Seconds of CSS](https://atomiks.github.io/30-seconds-of-css/)

<br>

[Information wars: How Europe became the world’s data police](https://www.ft.com/content/1aa9b0fa-5786-11e8-bdb7-f6677d2e1ce8)

<br>

[Chart Models click to load an editable example](http://nvd3.org/livecode/)

<br>

[D3 Tips and Tricks v3.x](https://leanpub.com/D3-Tips-and-Tricks)

<br>

[The Big List of D3.js Examples](http://christopheviau.com/d3list/)

<br>

[Learn to Create D3.js Data Visualizations by Example](https://www.sitepoint.com/d3-js-data-visualizations/)

<br>

[Shuji Nakamura - Facts](https://www.nobelprize.org/nobel_prizes/physics/laureates/2014/nakamura-facts.html)

<br>

[Smarter brains run on sparsely connected neurons](https://www.sciencedaily.com/releases/2018/05/180517102236.htm)

> Date: May 17, 2018 <br>
> Source: Ruhr-University Bochum <br>
> Summary: <br>
> The more intelligent a person, the fewer connections there are between the neurons in his cerebral cortex. This is the result of a study conducted by neuroscientists; the study was performed using a specific neuroimaging technique that provides insights into the wiring of the brain on a microstructural level. <br>

<br>

[Front-end Job Interview Questions](https://github.com/h5bp/Front-end-Developer-Interview-Questions)

<br>

[Learn D3.js in 5 minutes](https://medium.freecodecamp.org/learn-d3-js-in-5-minutes-c5ec29fb0725)

<br>

> 朴聖國, Shawn @sungkkshawnpark
>
> 앞으로 게임을 이해하고 만들 사람들은 한국어에 빚질 것이 없거나 적다. 언어 면에서 게임을 이해하거나 만드는데 필요한 원자료는 한국어로 작성된 것이 거의 없다. 프로그래머만 해도 영어 문서를 독해하는 능력이 없다면 생산성은 끔찍하게 낮다. 소규모 게임을 만드는 커뮤니티는 멸종 상태이다.
>
> [오전 6:53 - 2018년 4월 25일](https://twitter.com/sungkkshawnpark/status/989140354250162177)

<br>

> 朴聖國, Shawn @sungkkshawnpark
>
> 텍스트를 읽거나 기술을 공부했으면 반드시 흔적을 남겨야 한다. 노트라도 남기거나 아니면 뭐라도 만들던가. 안 그러면 학습의 근거가 되는 “반영구적인 변화”에 도달하기 어렵다. 매번 읽었던 책으로 되돌아가 같은 문제 의식만 되새길 거면 책은 안 읽는 편이 낫다. 읽을 때만 알 것 같은 건 착각.
>
> [오후 10:11 - 2018년 5월 16일](https://twitter.com/sungkkshawnpark/status/996981632799096833)
>
> 朴聖國, Shawn @sungkkshawnpark
>
> 그러나 여기서도 노트를 남기거나 뭔갈 만드는 과정이 “그대로 옮기는(tracing)” 방식이어서는 안 된다. 그러면 공부가 끝나고 나서 머릿속에 아무 것도 남질 않는다. 그 공부는 학습이 아닌 노동일 뿐이다. 자신의 수준보다 낮은 문제들만 골라 풀며 자위하는 것도 마찬가지다. 차라리 쉬는 게 낫다.
>
> 朴聖國, Shawn @sungkkshawnpark
>
> 그림 그리는 것도 다르지 않다. Tracing은 기계적인 노동일 뿐이다. Figure drawing은 대상의 동세와 형태, 비례, 구도를 종합적으로 훈련하며 백지를 채워나가는 활동. 당연히 전자보다 후자가 학습 주체에게 더 불안하고 허공에서 줄타기를 하는 듯한 스트레스를 준다. 하지만 후자가 학습에 가깝다.

<br>

<img src="https://dzone.com/storage/temp/5464204-enterprise-vs-startup-journey-to-cloud.png">

<br>

[Algorithms Behind Modern Storage Systems](https://queue.acm.org/detail.cfm?id=3220266)

<br>

[Converting a Node List to an Array](http://www.jstips.co/en/javascript/converting-a-node-list-to-an-array/)

<br>

[PacVim – A CLI Game To Learn Vim Commands](https://www.ostechnix.com/pacvim-a-cli-game-to-learn-vim-commands/)

<br>

[[JS #4] Array 메서드들: concat, join, indexOf, slice, sort, push, …](https://medium.com/@hongkevin/js-4-array-%EB%A9%94%EC%84%9C%EB%93%9C%EB%93%A4-concat-join-indexof-slice-sort-push-4eec70d564e7)

<br>

[regex 101](https://regex101.com/)

<br>

[RegexOne](https://regexone.com/)

<br>

[combineLatest vs merge](http://reactive.how/)

<br>

[A fun and colorful explanation of how DNS works.](https://howdns.works/)

<br>

[Let’s Make a Map](https://bost.ocks.org/mike/map/)

<br>

[[D3.js] 배우는 방법](http://mobicon.tistory.com/275)

<br>

[D3 Workshop](https://bost.ocks.org/mike/d3/workshop/#0)

<br>

[Eigenvectors and Eigenvalues](http://setosa.io/ev/eigenvectors-and-eigenvalues/)

<br>

[JSP Tutorial for Beginners: Learn in 7 Days](https://www.guru99.com/jsp-tutorial.html)

<br>

[[HTML5] 꼼꼼히 살펴보는 SCRIPT 엘리먼트](https://taegon.kim/archives/6804)

<br>

[Google Maps JavaScript API](https://developers.google.com/maps/documentation/javascript/tutorial?hl=ko)

<br>

[SVG, JS, CSS로 만드는 라이언 로그인 폼](https://taegon.kim/archives/9658)

<br>

[훌륭한 소프트웨어 엔지니어란? 답: 카멜레온 개발자](https://medium.com/@kpak/%ED%9B%8C%EB%A5%AD%ED%95%9C-%EC%86%8C%ED%94%84%ED%8A%B8%EC%9B%A8%EC%96%B4-%EC%97%94%EC%A7%80%EB%8B%88%EC%96%B4%EB%9E%80-%EB%8B%B5-%EC%B9%B4%EB%A9%9C%EB%A0%88%EC%98%A8-%EA%B0%9C%EB%B0%9C%EC%9E%90-b73502a63016)

> 탁월한 개발자는 주어진 문제에 최상의 해결책을 파악하고 그 해결책이 커뮤니케이션이든 개발이든 리더십이든 단시간내에 부족한 부분은 빨리 배우고 익히며 자신을 변화시켜 그 상황에 최적화된 모습을 갖춘다. 이 글의 제목처럼 카멜레온같은 개발자가 되야 한다.

> 과거에 내가 약간 복잡한 알고리듬을 만들어서 실리콘밸리에 있는 개발자들에게 Swift 코드로 구현하라고 한적이 있다. 나름 복잡하고 테스트를 많이 해야하는 것이라서 대충 3주의 스케쥴로 잡았는데 2주만에 끝내서 상당히 기뻐했다. 다음에 같은 알고리듬을 중국에 있는 팀에게 Java 로 구현하라고 했는데 딱 3일 걸렸다. 나는 미국의 동부, 서부, 인도, 중국, 파키스탄, 한국등의 개발자들과 일을 해봤는데 실리콘밸리나 타지역이나 평균개발자들의 능력은 전혀 차이가 없다. 그런데 일반적인 시각은 실리콘밸리의 개발자들이 보다 더 나은 개발자들이라는 인식이 있다. 왜 그럴까? 실리콘밸리가 타지역과 가장 큰 차이점은 극소수의 천재들이 있다는 것이다. 그런 천재들이 구글같은 회사도 만들고 AWS 같은 기술들을 만들어서 어마어마한 마켓을 만들어 준다. 그리고 그 조직에 속해있는 일반 개발자들은 거기에 그냥 묻혀가는 면이 있다.

<br>

[How to create an OS from scratch](https://github.com/cfenollosa/os-tutorial)

<br>

[파싱이론 이야기 2](https://daesan.com/2018/05/parsing-theory-story-2)

<br>

[게임 서버 프로그래밍을 시작하는 분들을 위한 몇가지 문서들 ](http://blog.naver.com/imays/221274562819)

<br>

[BUILD YOUR OWN X](https://github.com/danistefanovic/build-your-own-x)

> "What I cannot create, I do not understand." - Richard Feynman

<img src="https://github.com/danistefanovic/build-your-own-x/raw/master/feynman.png">

<br>

[Welcome to Project Soli](https://www.youtube.com/watch?v=0QNiZfSsPc0&feature=youtu.be)

<br>

[Getting Started With WebAssembly](https://tutorialzine.com/2017/06/getting-started-with-web-assembly)

<br>

[궁극의 프로그래밍 언어 1](https://daesan.com/2018/05/ultimate-programming-language-1)

> 우리는 이제 궁극의 언어가 갖춰야할 두가지 조건을 찾았다. 바로 1) 코드를 데이터로 다루는 기능과 2) 로우레벨 접근성이다. 그리고 마침, 이 두가지 조건을 완벽하게 갖추고 있는 프로그래밍 언어가 있다. 어떤 언어냐고? 바로 어셈블리어다.
>
> 어셈블리어에서 코드를 데이터로 취급할 수 있다고? 당연하다. (기계어로 변환된) 어셈블리어 코드는 그냥 바이너리 데이터이기 때문이다. 예를 들어, 특정 데이터 영역(즉 메모리)에 “기계어” 를 저장하고, PC 레지스터에 해당 영역의 주소를 입력하는 순간, 그 데이터는 이제 CPU 인스트럭션 코드의 나열로 인식되며 순차적으로 IR 레지스터로 카피돼 CPU 에서 실행되기 시작할 것이다.
>
> 로우레벨 접근성은 두말할 필요도 없다. 어셈블리어와 로우레벨은 마치 동의어나 다름없기 때문이다. 이제 적어도 리스프 보다는 어셈블리어가 “궁극의 프로그래밍 언어” 에 한발짝 더 가까이 다가서게 되었다.

<br>

[당신과 당신의 연구](http://ropas.snu.ac.kr/~kwang/quote/hamming.html)

> 내가 벨 연구소로 올 때, 내가 소속된 연구부서에서는 연구결과를 왕성히 쏟아내고 있었습니다. 보드(Bode)가 당시 부서장이었습니다. 샤논(Shannon)이 그 부서에 있었고, 그 외의 사람들이 있었습니다. 나는 계속 질문들을 했지요, "왜?", "그 차이가 무엇일까?" 그리고는 인물서, 자서전을 읽었고, 사람들에게 물어봤습니다: "어떻게 이 일을 하게 되었나요?" 차이점들이 뭔지를 알아내려고 노렸했습니다. 이 이야기가 바로 그것에 대한 이야기입니다.

<br>

> 예를 들어, 빌 팬(Bill Pfann)이라는 친구가 있었습니다. 존 멜팅(zone melting)이라는 분야를 일군 사람입니다. 그가 어느날 내 연구실로 왔었습니다. 그가 원하는 바에 대해서 희미하게 아이디어가 있었고 어떤 방정식이 있었습니다. 이 사람이 수학은 잘 모른 다는 게 내게 분명했지요 그리고 그는 그렇게 썩 명료하게 말하는 모습이 아니었습니다. 그가 가지고 온 문제가 재미있어 보여서 집에 가지고 와서 약간 살펴보고 작업해 봤지요. 최종적으로 그에게 어떻게 컴퓨터를 돌리면 그가 바라는 방식의 답을 얻을 수 있는 지를 보여 주었습니다. 그에게 계산하는 능력을 전수해 준 것이지요. 그는 계속 진행했고요. 그의 부서에서는 거의 알아주지도 않는 것이었습니다. 그런데, 결국에는 그는 그 분야의 모든 상을 휩쓸었습니다. 한번 시작이 잘 되니까, 그의 소극적인 부끄럼, 이상스러움, 명료하지 못함 등은 모두 떨구어지고 여러방면으로 굉장이 많은 성과를 내게 되었습니다. 확실히 엄청나게 명료해지기도 했고요.

<br>

> 비슷하게, 또 다른 사람의 예가 있습니다. 여기 청중중에 없다고 믿는데요. 클럭스톤(Clogston)이라는 친구입니다. 내가 그를 만난건 내가 존 피어스(John Pierce)의 그룹에서 어떤 문제를 풀고 있던 때 였습니다. 나는 그가 별볼일 없다고 생각했어요. 그와 같이 학교를 다녔던 친구들에게 물어봤지요. "대학원때도 제는 저랬냐?" 그들 대답은 "예스"였지요. 나는 아마도 그 친구를 해고했을 겁니다. 그러나 피어스(John Pierce)는 현명하게도 그를 계속 멤버로 가지고 있었습니다. 클럭스턴은 결국에는 "클럭스턴 케이블"이라는 것을 해 냅니다. 그 이후로는 꾸준히 좋은 아이디어들이 흘려 나왔지요. 하나의 성공이 그에게 자신감과 용기를 가져다 준 겁니다.

<br>

> 성공적인 과학자의 특징중 하나는 용기를 가지고 있다는 것입니다. 용기가 붇돋워지면 중요한 문제들을 풀 수 있다고 믿게되고 그러면 해내게 됩니다. 못할 거라고 생각하면 거의 분명히 못하게 됩니다. 용기는 샤논(Shannon)이 엄청 가지고 있던 특징들 중의 하나지요. 그의 주요 이론을 상기하면 됩니다. 그것에 대한 이야기입니다. 코딩의 방법을 만들고 싶어합니다 그런데 어떻게 해야할 지를 모릅니다 그래서 무작위로 코딩합니다. 그리고 벽에 부딛칩니다. 그리고는 불가능한 질문을 합니다, "무작위 코드들이 평균적으로 하는 일이 뭘까?" 그리고는 그는 증명합니다. 평균 코드는 아무렇게해도 좋은 코드다. 그렇다면, 그러므로 좋은 코드는 적어도 하나는 존재한다. 이런 식의 생각들을 감히 할 수 있다는 것이 무한대의 용기를 가지지 않고서는 누가 할 수 있는 생각이겠어요? 이게 바로 위대한 과학자들의 성격입니다. 용기를 가지고 있지요. 믿기지 않는 상황에서도 계속 갑니다; 생각하고 생각하고 계속 생각합니다.

<br>

> 유명해지면 조그만 문제를 연구하는 것이 어려워집니다. 이게 바로 샤논(Shannon)을 잡아먹은 거지요. 정보 이론 이후에 다음으로 또 한 껀 뭘 할까? 위대한 과학자들이 이러한 실수를 합니다. 시작을 작게 하지 못하게 됩니다. 미래에 엄청난 아름드리 참나무로 자라게 될 아주 작은 도토리를 심지 못하는 것이지요. 처음부터 커다란 것을 곧바로 하려고 듭니다. 그런데 이것은 일이 되는 방식이 아니랍니다. 이게 바로 우리가 일찌감치 인정을 받으면 그 이후로는 아무 성과가 없게되고마는 이유이기도 하지요. 
>
> <br>
>
> When you are famous it is hard to work on small problems. This is what did Shannon in. After information theory, what do you do for an encore? The great scientists often make this error. They fail to continue to plant the little acorns from which the mighty oak trees grow. They try to get the big thing right off. And that isn't the way things go. So that is another reason why you find that when you get early recognition it seems to sterilize you. 
>
> You and Your Research

<br>

> 이 이야기때문에, 순서가 뒤바뀐 듯 하지만, 연구하는 환경에 대한 이야기를 하게되겠네요. 대부분의 사람들이 생각하는 최고의 연구환경은 최고의 연구환경이 아닙니다. 분명히 아닙니다. 왜냐하면 자주 있는 일인데, 사람들이 연구 성과가 제일 좋은 때는 연구환경이 나빴을 때입니다. 캠브리지 물리학 연구실(Cambridge Physical Laboratories)이 좋았던 시절 중 하나는 연구실들이 그야말로 판자집이었을 때 였습니다. 그 때 그들은 지금까지 중 최고의 물리학 성과를 일구어냈지요.

<br>

> 보드(Bode)가 말하던 것은 이겁니다. "지식과 연구 생산성은 복리의 이자와 같은 거다." 거의 같은 능력의 두 사람이 있다고 합시다. 한 사람은 다른 사람보다 10% 더 공부한다고 해요. 그러면 그 사람은 다른 사람보다 2배의 더 연구결과를 만들어 낼 겁니다. 더 알면 알 수록 더 많이 배우게 됩니다; 더 많이 배울 수록 더 많은 일을 할 수 있게되고, 더 많이 일을 할 수 있게되면 기회는 더 많아 집니다. 복리 이자와 아주 비슷하지요. 이자율을 말 하고 싶지는 않고, 아뭏튼 굉장히 높은 이자률이지요. 완전히 같은 능력의 두 사람이 있다고 하면, 매일 생각을 1시간 더 하게되면 평생 엄청나게 더 많은 연구결과를 낼 겁니다. 나는 보드(Bode)의 말을 가슴에 새겼습니다; 몇년간은 좀더 열심히 더 많은 시간을 연구에 투자하려고 노력했지요. 그러니 알게 되더라고요, 내가 한 일이 좀더 많구나. 내 아내 앞에서는 말하고 싶지 않지만, 때로는 아내가 안중에도 없었었습니다; 나는 공부하는 게 필요했어요. 우리가 원하는 바를 이룰려면 많은 것들을 무시해야하지요. 이와 관련해서는 의문의 여지가 없을 것입니다.

<br>

[개발자를 위한 웹 기술](https://developer.mozilla.org/ko/docs/Web)

<br>

[Exporting Data from PDFs with Python](https://www.blog.pythonlibrary.org/2018/05/03/exporting-data-from-pdfs-with-python/)

<br>

[What is 1.1.1.1?](https://www.cloudflare.com/learning/dns/what-is-1.1.1.1/)

<br>

[하지만 그 사람의 활동과 커리어를 존경한다.](https://twitter.com/adhrinae/status/994369305885077505)

<br>

> Rinae @adhrinae
>
> 어떤 개발자 선배님은 알고 보니 나의 고등학교 후배님이었다.
> 심지어 내가 모교에 교생실습을 가던 해에 그 학교에 학생으로 재학하고 있을 정도로 나이차이가 났다. 하지만 그 사람의 활동과 커리어를 존경한다.
> 그만큼 나이따윈 중요한게 아니다.
>
> 오후 5:11 - 2018년 5월 9일

<br>

[Clean architectures in Python: a step-by-step example](http://blog.thedigitalcatonline.com/blog/2016/11/14/clean-architectures-in-python-a-step-by-step-example/)

<br>



> Rinae @adhrinae
>
> 가끔은 ‘팀에 퍼블리셔가 필요하지 않겠느냐’ 라는 질문을 받곤 한다.
> 물론 숙련된 퍼블리셔의 크로스플랫폼 지원을 위한 CSS 설정 및 시맨틱 태그 기반의 미려한 페이지 구축은 힘들 수 있지만, 프론트엔드 개발자라면 응당 일정 수준 이상의 마크업(HTML, CSS) 스킬은 가지고 있어야한다고 생각한다.
>
> Rinae @adhrinae
>
> 어차피 Vue, React 등으로 프론트엔드 개발을 하다보면 퍼블리셔와의 협업은 문제가 된다. 이상적인것도 아니고 최저 한도로 협업을 할 수 있는 퍼블리셔의 최저 한도는 ‘한 페이지에서 공통적으로 재사용 가능하거나 별도로 구축되어야 하는 컴포넌트의 단위를 나눌 수 있는 안목이 있는 사람’ 같다.
>
> Rinae @adhrinae
>
> 솔직히 나도 마크업 역량이 내 개발 역량 중에서 제일 낮은 수치이긴 하지만, 최소한의 디자인 가이드라인이 제공되면 최대한 그 디자인에 가깝게 페이지를 그려낼 수준은 된다(검색해서 구현하는 것 포함). 이것도 못하겠다고 하면 대체 자신을 어떻게 프론트엔드 개발자라고 소개한단 말인가?
>
> [오전 4:40 - 2018년 5월 9일](https://twitter.com/adhrinae/status/994180184545767424)



<br>

[ES6 문법 정리](https://jsdev.kr/t/es6/2944)

<br>



> Chris Ohk  @utilforever
>
> 삽질을 매우매우 많이 합니다만, 매번 느끼는 점은 비슷합니다. 남들이 하지 않았던 무언가를 하려면 굉장히 많은 삽질을 해야된다. 설명서도 잘 나와있지 않아 몇 일 내내 이리저리 바꿔가면서 시도해야 할 수도 있다. 하지만 해냈을 때의 성취감은 말할 수 없으며, 온전히 나의 지식이 된다.
>
> [오전 6:22 - 2018년 5월 8일](https://twitter.com/utilforever/status/993843648675528704)



<br>

[py2exe와 py2app을 통한 Windows/OS X용 실행파일 만들기](https://spoqa.github.io/2013/05/21/py2exe-and-py2app.html)

<br>

[성공적으로 재택근무 시스템을 도입하는 방법](http://ppss.kr/archives/88997)

<br>

[Discover the world by Software](https://lqez.github.io/blog/discover-the-world-by-software.html)

<br>

> asbubam	@asbubam
>
> 지하철이 한강을 지나면, 미세먼지를 눈으로 확인한다. 그러다 문득 십분전, 삼십분 전, 한 시간 전에 해당 위치에 당도했던 사람들이 전해주는 정보를 지역기반으로 정리해서 제공해주면 어떨까 하는 생각이 들었다. 잠실 마약빵집 십분전에 들렸는데 사람이 많아 대기했어요. 처럼 근현재의 정보공유
>
> [오후 3:01 - 2018년 5월 8일](https://twitter.com/asbubam/status/993974313505112064)



<br>

[Learn these neat JavaScript tricks in less than 5 minutes](https://medium.freecodecamp.org/9-neat-javascript-tricks-e2742f2735c3)

<br>

[Akin's Laws of Spacecraft Design](http://spacecraft.ssl.umd.edu/akins_laws.html)

<br>

[Pure Python vs NumPy vs TensorFlow Performance Comparison](https://realpython.com/numpy-tensorflow-performance/)

<br>

[Multi Thread 환경에서의 올바른 Singleton](https://medium.com/@joongwon/multi-thread-%ED%99%98%EA%B2%BD%EC%97%90%EC%84%9C%EC%9D%98-%EC%98%AC%EB%B0%94%EB%A5%B8-singleton-578d9511fd42)

<br>

[AI researchers allege that machine learning is alchemy](http://www.sciencemag.org/news/2018/05/ai-researchers-allege-machine-learning-alchemy)

<br>

>Rahimi offers several suggestions for learning which algorithms work best, and when. For starters, he says, researchers should conduct "ablation studies" like those done with the translation algorithm: deleting parts of an algorithm one at a time to see the function of each component. He calls for "sliced analysis," in which an algorithm's performance is analyzed in detail to see how improvement in some areas might have a cost elsewhere. And he says researchers should test their algorithms with many different conditions and settings, and should report performances for all of them.
>
>Ben Recht, a computer scientist at the University of California, Berkeley, and coauthor of Rahimi's alchemy keynote talk, says AI needs to borrow from physics, where researchers often shrink a problem down to a smaller "toy problem." "Physicists are amazing at devising simple experiments to root out explanations for phenomena," he says. Some AI researchers are already taking that approach, testing image recognition algorithms on small black-and-white handwritten characters before tackling large color photos, to better understand the algorithms' inner mechanics.

<br>

> Not everyone agrees with Rahimi and Recht's critique. Yann LeCun, Facebook's chief AI scientist in New York City, worries that shifting too much effort away from bleeding-edge techniques toward core understanding could slow innovation and discourage AI's real-world adoption. "It's not alchemy, it's engineering," he says. "Engineering is messy."

<br>

[이벤트 버블링, 이벤트 캡처 그리고 이벤트 위임까지](https://joshua1988.github.io/web-development/javascript/event-propagation-delegation/)

<br>

> 얼마 전 Vanilla JS로 꽤 복잡한 웹 애플리케이션을 구현할 일이 생겨 오랜만에 순수 자바스크립트를 들여다보게 되었습니다. 구현 과정에서 이벤트 캡쳐와 버블링에 대해 정확히 지식이 정리가 되어 있지 않다는 것을 깨닫고 아래와 같이 정리하게 되었네요. 브라우저에서 어떻게 특정 화면 요소의 이벤트를 감지하는지 그리고 그 이벤트를 어떻게 다른 화면 요소에 전파하는지 같이 알아보겠습니다.

<br>

[Self-driving cars are useless without specialized maps—this invention could free them](https://www.technologyreview.com/the-download/611093/self-driving-cars-are-useless-without-specialized-maps-this-invention-could-free/)

<br>

> **Some background**: Autonomous cars currently undergoing testing drive only on streets with meticulously labeled maps that take up huge amounts of storage space. “Maps for even a small city tend to be gigabytes; to scale to the whole country, you’d need incredibly high-speed connections and massive servers,” said Teddy Ort, a grad student at MIT’s computer science and artificial intelligence lab (CSAIL).
>
> **The solution**: A new, more adaptable approach by the CSAIL team, called MapLite, uses simple GPS data to plot a path to the vehicle’s destination, and LIDAR sensors to navigate along the way. The sensors estimate curb distances and the road conditions more than 100 feet ahead of the vehicle.



<br>

> redacted @29979245oo
>
> 화상으로 홍콩에 있는 지원자 면접. 이렇게 바로 외국 출신도 면접을 보나보다. 물론 머신러닝 전공이니 가능. 일반 엔지니어는 요즘 비자가 하도 어려워서 해외 채용은 안 함. 모바일은 가능한 듯.
>
> [오전 9:29 - 2018년 5월 7일](https://twitter.com/29979245oo/status/993528229636931584)

<br>



> 기계인간 @John_Grib
>
> 구체수학 2장 2절 공부. 6페이지 읽는데 6일이나 걸렸지만 아무튼 이번 챕터도 해냈다!!
>
> https://johngrib.github.io/wiki/c-m-02-Sums-02/
>
> [오전 5:12 - 2018년 5월 7일](https://twitter.com/John_Grib/status/993463472322068480)



<br>

[Comparing the Performance between Native iOS (Swift) and React-Native](https://medium.com/the-react-native-log/comparing-the-performance-between-native-ios-swift-and-react-native-7b5490d363e2)

<br>

> React-Native is a cross-platform mobile framework that lets you build apps using only JavaScript. However, unlike other hybrid mobile technologies you are not building a “mobile Web App” (Web App wrapped in a native container). In the end, you get the real thing. Your JavaScript codebase is compiled to a mobile app indistinguishable from an iOS app built using Objective-C or an Android app using Java. This means that React-Native provides the benefits from both Native and Hybrid Mobile Apps.

<br>

> The mobile applications I made for Swift and React-Native are almost identical in their physical appearance. As you can see from the data I collected through measuring both of the application’s CPU, GPU, and Memory during the tasks in each of the four tabs, the apps are also almost identical in how they perform. Swift won overall in the CPU category, React-Native won the GPU category (barely), and React-Native won big time in the Memory category. I can infer from this data that Swift uses the CPU of the iPhone more efficiently than React-Native, React-Native uses the GPU of the iPhone slightly more effectively than Swift, and that React-Native somehow leverages the iPhone’s memory much more effectively than Swift does. React-Native, winning two out of three categories, comes in first place as the better performing platform.

<br>

> I am now more convinced than ever that React-Native is the framework of the future — it has so many advantages and so few disadvantages. React-Native can be written in Javascript (a language so many developers already know), its codebase can be deployed to both iOS and Android platforms, it is faster and cheaper to produce apps, and developers can push updates directly to users so that users do not have to worry about downloading updates. Best of all, at only a year old, React-Native is already outperforming native iOS Swift applications.



<br>

[Minimal Viable Product](https://blog.deming.org/2014/11/minimal-viable-product/)

<br>

[프로그래머로서의 성장을 도왔던 태도들](http://ahnheejong.name/articles/becoming-better-programmer/)



<br>

>어떤 리소스를 주로 참고하냐고 물어도 1. 각 기술의 공식문서를 본다 2. MDN 자주 본다 3. 기술 뉴스레터 몇 개를 받아본다 정도. 계속 성장하고 있다 느끼지만 그 성장이 구체적으로 어떻게 이루어지는지 평소에 의식을 잘 못 하고 있는 것도 같다.

<br>

> 프로그래밍 언어를 배운다고 하자. A는 코드는 한 줄도 짜지 않고 스펙을 처음부터 끝까지 전부 읽는다. 한참 후 스펙 읽기를 마쳤지만 간단한 프로그램 하나를 짜는데도 고생한다. 반면 B는 기본 문법만 배운 후 곧바로 문서를 치우고 프로그래밍에 들어간다. 높은 확률로, 문서를 한 번만 읽었어도 안 했을 고생을 헤쳐나가느라 엄청난 시간을 쓰게 된다.
>
> 효율적인 학습을 위해선 A나 B처럼 이론과 실제 코딩 중 한 쪽으로 치우치는 것보다는 이론적인 배경을 쌓는 공부와 그렇게 쌓은 지식을 활용하는 실습, 두 상태를 빠르게 오가는 것이 도움이 된다. 이렇게 학습의 단계를 잘게 나누는 것이 도움이 되는 이유는 크게 두 가지 정도다.
>
> 
>
> 먼저 **짧은 주기의 반복을 통해 빠른 피드백을 얻을 수 있다**. 또한 피드백을 통해 잘못된 결정 – 실제로 무언가를 만들려고 봤더니 잘못된 부분을 보고 있었다든지, 이 도구가 사실 내가 풀려는 문제에 대한 해결책을 풀기에 올바른 솔루션이 아니라든지 등 – 으로부터 빠르게 복구하고 다른 방향을 향할 수 있다. 이런 피드백이 빠르게 일어날수록 더 큰 낭비를 방지할 수 있다.
>
> 둘째로, 이론 – 실습 주기를 한 번 반복 할 때마다 **돌아올 수 있는 체크포인트가 생긴다**. git의 커밋을 생각하면 쉽다. 학습에 있어 주도적으로 이런저런 시도를 해보는 과정은 필수적이다. 게임에서도 체크포인트가 촘촘히 있으면 도전적인 플레이가 가능하듯, 아무리 큰 실수를 해도 돌아올 수 있는 지점이 가까이 있다는 심리적 안정감이 제공되면 더 대범하게 다양한 시도를 해보며 학습할 수 있다.
>
> 앞서 언급한 두 가지 장점을 극대화하기 위해서는 각 이론 – 실습 주기를 끝낸 시점에서 늘 통합 테스트가 가능하도록 학습의 단계를 설계해야 한다. 다르게 표현하자면, 이론을 배우고 해당 이론을 이용해 무언가를 구현했을 때, 구현해낸 결과물이 ‘동작하는’ 상태여야 한다.



<br>

<img src="https://blog.deming.org/wp-content/uploads/2014/11/minimal-viable-product-henrik-kniberg.png">

<br>

> 원해서든 원치 않아서든 코드 리뷰를 받을 상황에 놓였다면, 코드에 대한 비판은 사람에 대한 비판이 아니라는 점을 유념해야 한다. 코드에 대한 정당한 지적을 개인적으로 받아들이지 않고 더 나은 코드를 작성하기 위한 발판으로 삼을 수 있는 사람은 그렇지 않은 이보다 훨씬 빠르게 성장할 수 있다. 또한 전혀 그럴 이유가 없음에도 시간과 노력을 내어 나의 코드를 더 낫게 만들 방법을 같이 고민해준 리뷰어에게 존중과 감사의 마음을 표하는 것을 잊지 말자.

<br>

> 때로는 코드를 작성하는 것보다 코드를 읽는 과정에서 훨씬 많은 것을 배울 수 있다. 이 때 유명한 라이브러리나 언어의 소스 코드, 그리고 표준 라이브러리를 비롯한 API는 쉽게 접근 가능한 좋은 소스다.

<br>

> 개인적으로 언어의 기능만을 이용해서 쉽게 구현할 수 있는 일에 써드파티 라이브러리를 사용하는 걸 싫어하는 것도 이런 이유에서다. 시시각각 바뀌는 세상 속에서 프로그램이 오래 동작하기 위해선 그 모든 구성 부품이 변화에 기민하게 대응해야 한다. 헌데 프로그램이 의존하는 써드파티 라이브러리의 수가 늘수록 그러기가 기하급수적으로 어려워진다. 라이브러리가 제공하는 편리함에는 채무증서가 따라온다.

<br>

> 무언가 배울 때에 가장 근원이 되는 소스 – 소스 코드, 언어 스펙, 라이브러리 공식 문서, 어떤 개념을 처음으로 주창한 이의 글 – 를 찾아보는 습관을 들이는 것이 한 방법이 된다. 무언가를 ‘쉽게’ ‘풀어서’ 설명해주는 블로그 글에는 필연적으로 저자의 재해석이 들어간다. 무엇을 말하고 무엇을 말하지 않을지에 대한 결정은 차치하더라도, 재해석의 단계가 깊어질수록 가장 사실에 가까운 정보로부터 무언가 어긋날 확률이 높아진다.
>
> 자동화할 수 있는 검증의 책무를 사람이 아닌 기계에게 맡기는 것 또한 도움이 된다. 사람이 ‘이 풀 리퀘스트는 기존의 기능을 깨먹지 않았습니다’고 말하는 것을 믿는 대신, 자동화된 회귀 테스트가 검증하게 한다. 문서에 적힌 ‘이 함수를 이런 파라미터를 받습니다’라는 정보를 믿기보다는 정말 그러한지, 혹 잘못 사용하고 있는 곳은 없는지 타입 체커가 자동으로 검사하게 만들면 더 안심할 수 있다.

<br>

> 마지막으로 가장 중요하다 생각하는 내용이다. 어차피 학습에 있어 병목은 나의 시간, 에너지, 이해력이지 외부 정보량이 아니다. 따라서 더 많은 소스 확보가 아니라 큐레이션에 집중해야 한다. 들어오는 정보량이 얼마나 많은지는 중요하지 않은 경우가 많으므로, 인터넷에 올라오는 모든 링크를 읽고 모든 라이브러리에 별을 찍기 위해 집착할 필요가 없다.

<br>

> 그런 좋은 동료를 만나는 데에는 분명 운도 많이 작용한다. 하지만 노력으로 만들 수 있는 변화도 분명 있다. 많은 방법 중 특히 스스로 먼저 좋은 친구가 되려 노력하는 것이 도움이 된다고 생각한다. 내가 원하는 동료를 생각하고, 남들에게 그런 동료가 되기 위해선 어떻게 할 수 있을지 생각해보면 자연스레 ‘다른 이를 돕고, 고통을 덜어줄 수 있는 방법이 뭐가 있을까?’를 고민하게 된다.



<br>

[Deep Learning meets Physics: Restricted Boltzmann Machines Part I](https://towardsdatascience.com/deep-learning-meets-physics-restricted-boltzmann-machines-part-i-6df5c4918c15)

<br>

[An introduction to Python bytecode](https://opensource.com/article/18/4/introduction-python-bytecode)

<br>

[Web Developer Security Checklist](https://medium.com/simple-security/web-developer-security-checklist-f2e4f43c9c56)

<br>

[Real Python](https://realpython.com/)

<br>

[HTTPS는 HTTP보다 빠르다](https://tech.ssut.me/2017/05/07/https-is-faster-than-http/)

<br>

[[NDC 18] ‘모두가 망했다고 했다’, 쿠키런 오븐브레이크의 이유있는 역주행](http://thisisgame.com/webzine/gameevent/nboard/227/?n=82240)

<br>

[Inside the Linux boot process](https://www.ibm.com/developerworks/library/l-linuxboot/)

<br>

[Create TUI on Python](https://medium.com/@bad_day/create-tui-on-python-71377849879d)

<br>

[23 JavaScript design patterns](https://boostlog.io/@sonuton/23-javascript-design-patterns-5adb006847018500491f3f7f)

<br>

[Mustard UI is a starter CSS framework that actually looks good.](https://mustard-ui.com/)

<br>

[Making art with SSH key randomart](https://blog.benjojo.co.uk/post/ssh-randomart-how-does-it-work-art)

<br>

[TIC-80 tiny computer](https://tic.computer/)

<br>

[Parsing JSON is a Minefield](http://seriot.ch/parsing_json.php)

<br>

[윈도우 백업 시스템, 아직도 애플 타임머신을 따라잡지 못하는 이유](http://www.itworld.co.kr/news/109192)

<br>

[I interviewed at five top companies in Silicon Valley in five days, and luckily got five job offers](https://medium.com/@XiaohanZeng/i-interviewed-at-five-top-companies-in-silicon-valley-in-five-days-and-luckily-got-five-job-offers-25178cf74e0f)

<br>

[C Is Not a Low-level Language](https://queue.acm.org/detail.cfm?id=3212479)

<br>

[530 Free Online Programming & Computer Science Courses You Can Start in May](https://medium.freecodecamp.org/530-free-online-programming-computer-science-courses-you-can-start-in-may-5e82f5307867)

<br>

[How I went from 33-year-old museum tour guide to professional Web Developer & UX Designer: My 18-month coding journey](https://medium.freecodecamp.org/the-post-i-hoped-to-write-for-18-months-2902d074f5ba)

<br>

[Want to be a top developer? You should build things. Here’s another list to get you started.](https://medium.freecodecamp.org/the-secret-to-being-a-top-developer-is-building-things-d3d058e4e472)

<br>

[10 Common Data Structures Explained with Videos + Exercises](https://medium.freecodecamp.org/10-common-data-structures-explained-with-videos-exercises-aaff6c06fb2b)

<br>

[Can anyone at Google or Amazon share what algorithms you find most useful over the years of your career?](https://www.quora.com/Can-anyone-at-Google-or-Amazon-share-what-algorithms-you-find-most-useful-over-the-years-of-your-career/answer/Eugene-Yarovoi?share=dc5052f3)

<br>

[[B급 프로그래머] (Quora) 구글 또는 아마존에 다니는 경력 개발자들이 가장 유용하다고 생각하는 자료 구조는?](http://jhrogue.blogspot.kr/2018/04/b-quora.html)

<br>

[What happens before main() function is executed in C and why is it important?](http://mymicrocontroller.com/2018/04/03/what-happens-before-main-function-is-executed-in-c-and-why-is-it-important/)

<br>

[파싱이론 이야기 1](https://daesan.com/2018/05/parsing-theory-story-1)

> 대학교 3학년을 마치고 1년 휴학을 하고 여름방학부터 1년 3개월 내내 컴퓨터 책만 읽었다. 물론 컴퓨터 책이라고 항상 다 명료하게 쓰여진건 아니었지만, 나는 다른 어느 과학이나 공학 분야보다 컴퓨터 책들이 잘 쓰여진 편이라고 생각한다. 어떻게 보면 내가 진로를 바꾼 가장 큰 이유가 이런 공부의 ROI 차이 때문이었을 것이다.

<br>

[After All These Years, the World is Still Powered by C Programming](https://www.toptal.com/c/after-all-these-years-the-world-is-still-powered-by-c-programming)

<br>

[크롬 개발자 도구를 이용한 자바스크립트 디버깅](https://subicura.com/2018/02/14/javascript-debugging.html)

<br>

[프로그래밍은 레고 조립이 아니다](https://daesan.com/2018/05/programming-is-not-lego)

>프로그래밍은 물론 어렵다. 알고리즘을 익히는 것도, 알고리즘을 구현하는 것도, 컴퓨터 공학의 추상적인 개념들을 이해하는 것도, 프로그래밍 언어 사용에 능숙해지는 것도, 각종 문서를 섭렵하고 다양한 프레임워크와 툴들을 익히는 것도 이미 충분히 어렵다.

<br>

> 결국 스타트업은 산업의 맹점 영역에서 태동할 수 밖에 없다. 미래를 보는 것만으로는 충분하지 않다. 남들이 보지 못하는 미래를 봐야 한다. 그래서 피터 틸은 “당신과 동의하는 사람들이 거의 없는 중요한 진실을 알고 있는게 있느냐?” 고 질문하는 것이다.

<br>

> 해결할만한 가치가 있는 문제란 과연 무엇일가? 내가 사용하는 정의는 “그것을 해결하면 세상이 실제로 바뀌는 문제” 이다. 세상에는 다양한 가치있는 문제들이 많이 있지만, 이 관점에서 해결할만한 가치가 있는 문제는 생각보다 많지 않다.
>
> 좀더 구체적으로 이야기하자면, 해결할만한 가치가 있는 문제란 적지 않은 숫자의 사람들이 실제로 가지고 있는 꽤 커다란 개인적인 문제이다. 중요한 것은 1) 문제의 보편성(=문제를 가진 사람들의 숫자) 2) 문제의 시급성(=새로운 제품이나 서비스를 찾는 사람들의 적극성) 3) 문제의 개인성(=사람들이 자신의 문제로 받아들이는가) 등이다.

<br>

> 예를 들어, 우리 회사가 현재 직면한 두가지 기술적 문제가 있는데, 하나는 리액트 네이티브라는 앱 개발 프레임워크의 안정성/성능 문제 때문에 이 문제를 확실히 해결할 수 있는 대체 프레임워크를 만들어야 한다는 것이고, 다른 하나는 구글 지도 sdk 의 API 가 너무 제한적이라 역시 대체 sdk 를 만들어야 한다는 것이다. 두가지 문제 다 우리가 운영하고 있는 서비스가 기성 레고블록을 outgrow 한 경우이다.
>
> 스타트업에서 문제해결 능력이 중요하다고 말할 때, 개발자에게 요구되는 문제해결 능력이란 이런 것들이다.

<br>

[Studytonight](https://www.studytonight.com/)

<br>

[Pure CSS Francine](https://github.com/cyanharlow/purecss-francine)

<br>

[How to Efficiently Master the CSS Grid — in a Jiffy](https://medium.com/flexbox-and-grids/how-to-efficiently-master-the-css-grid-in-a-jiffy-585d0c213577)

<br>

[Understanding Flexbox: Everything you need to know](https://medium.freecodecamp.org/understanding-flexbox-everything-you-need-to-know-b4013d4dc9af)

<br>

[Bootstrap 4: Everything You Need to Know](https://medium.freecodecamp.org/bootstrap-4-everything-you-need-to-know-c750991f6784)

<br>

["Von Neumann’s First Computer Program"](https://twitter.com/fermatslibrary/status/991301499799195648)

> Fermat's Library  @fermatslibrary
>
> PAPER
>
> "Von Neumann’s First Computer Program" by Donald Knuth
>
> In 1945 Von Neumann wrote a sorting algorithm for the EDVAC (Electronic Discrete Variable Automatic Computer)
> This sorting algorithm later became known as Merge sort
>
> Paper here: http://fermatslibrary.com/s/von-neumanns-first-computer-program 



<br>

[Shallow vs Deep Copying of Python Objects](https://realpython.com/copying-python-objects/)

<br>

[Python 3's pathlib Module: Taming the File System](https://realpython.com/python-pathlib/)

<br>

[TOR Anonymity: Things Not To Do While Using TOR](https://fossbytes.com/tor-anonymity-things-not-using-tor/)

<br>

[프론트엔드 개발자는 왜 구하기 어렵나요?](https://taegon.kim/archives/4810)

<br>

[Numerical Methods using Python (scipy)](https://www.southampton.ac.uk/~fangohr/teaching/python/book/html/16-scipy.html)

<br>

[우리 회사의 개발자 인터뷰](http://blog.kivol.net/post/138587457933/%EC%9A%B0%EB%A6%AC-%ED%9A%8C%EC%82%AC%EC%9D%98-%EA%B0%9C%EB%B0%9C%EC%9E%90-%EC%9D%B8%ED%84%B0%EB%B7%B0)

<br>

[좋은 기술 인터뷰 질문은 어떤 질문인가](http://blog.kivol.net/post/173442457743/%EC%A2%8B%EC%9D%80-%EA%B8%B0%EC%88%A0-%EC%9D%B8%ED%84%B0%EB%B7%B0-%EC%A7%88%EB%AC%B8%EC%9D%80-%EC%96%B4%EB%96%A4-%EC%A7%88%EB%AC%B8%EC%9D%B8%EA%B0%80)

<br>

[파이썬 패키지](https://wikidocs.net/1418)

<br>

[HTML5 Video Destruction](http://craftymind.com/factory/html5video/CanvasVideo.html)

<br>

[HTTPS와 SSL 인증서](https://opentutorials.org/course/228/4894)

<br>

[개발자 비급(祕笈) – 1. 연봉은 실력의 결과가 아니다](http://channy.creation.net/blog/1186)

<br>

[IntelliJ 의 JShell Console 을 활용하자](https://www.popit.kr/intellij-%EC%9D%98-jshell-console-%EC%9D%84-%ED%99%9C%EC%9A%A9%ED%95%98%EC%9E%90/)

<br>

[How Does Spotify Know You So Well?](https://medium.com/s/story/spotifys-discover-weekly-how-machine-learning-finds-your-new-music-19a41ab76efe)

<br>

[Chrome DevTools](https://developers.google.com/web/tools/chrome-devtools/?hl=ko)

<br>

[Is FreeBSD faster than Linux?](https://www.quora.com/Is-FreeBSD-faster-than-Linux/answer/Ben-Lunsford?share=772c16a9&srid=XAfq)

<br>

[You don’t need a CS degree to be a successful engineer, but it helps.](https://www.reddit.com/r/programming/comments/8g2v6b/you_dont_need_a_cs_degree_to_be_a_successful/?st=JGND4TSJ&sh=dc88a01d)

<br>

[Object-Oriented Programming (OOP) in C](https://www.codementor.io/michaelsafyan/object-oriented-programming-in-c-du1081gw2)

<br>

[Let’s Make the Tiniest Blockchain Bigger](https://medium.com/crypto-currently/lets-make-the-tiniest-blockchain-bigger-ac360a328f4d)

<br>

[Let’s Build the Tiniest Blockchain](https://medium.com/crypto-currently/lets-build-the-tiniest-blockchain-e70965a248b)

<br>

[Hash Algorithms – How does SQL Server store Passwords?](http://sqlity.net/en/2460/sql-password-hash/)

<br>

[http-hash-server](https://github.com/Matt-Esch/http-hash-server)

<br>

[Introductory Circuit Analysis ](https://www.amazon.com/Introductory-Circuit-Analysis-Robert-Boylestad/dp/0133923606)

<br>

[First IC :)](http://sam.zeloof.xyz/first-ic/)

<br>

[맥을 사용한다면 외워야 할 단축키 12](https://www.huffingtonpost.kr/2014/04/17/story_n_5157924.html)

<br>

[Born vs Made Programmers](https://webapplog.com/born-vs-made-programmers/)

<br>

[Modern Theory of Deep Learning: Why Does It Work so Well](https://medium.com/mlreview/modern-theory-of-deep-learning-why-does-it-works-so-well-9ee1f7fb2808)

<br>

[Teach Yourself Computer Science](https://teachyourselfcs.com/)

<br>

[Could AI have saved the cyclist (had I programmed the Uber car)?](https://medium.com/@rebane/could-ai-have-saved-the-cyclist-had-i-programmed-the-uber-car-6e899067fefe)

<br>

[ Bool 변수 이름 제대로 짓기 위한 최소한의 영어 문법 ](https://soojin.ro/blog/naming-boolean-variables)

<br>

[ [실리콘밸리의 한국인 2018] 이 시대의 카멜레온 - 박기상(LinkedIn 시니어 엔지니어) ](http://tv.naver.com/v/2993159)

> [실리콘밸리의 한국인 2018] 이 시대의 카멜레온 - 박기상(LinkedIn 시니어 엔지니어)
>
> - Adaptability - 세상이 너무나 빠르게 변하기 때문에 적응력이 중요하다.
>
> - 적응력을 극대화하기 위한 카멜레온 S-Curve.
>
> <br>
>
> Step #1: Jump
> ‘다양한’ 경험을 쉽게 할 수 있는 곳에 들어간다. 마이너리그여도 상관없다.
>
> 대학 졸업 직후 입사한 회사 XERIUM. 9년 재직함.
> 외주를 주었던 제품에 대한 하드웨어와 소프트웨어 전체를 재설계하기로 결정.
>
> 회사에서의 활동:  <br>
> 기계공학자 <br>
> 전자공학자 <br>
> 소프트웨어 엔지니어 <br>
> Development Engineer ?!?! <br>
> 엔지니어링 매니저 <br>
> 개인 사무실 제공 <br>
> 개인 차량 장기간 지원 <br>
> C-Level 임원들과 잦은 미팅, 출장 <br>
> 대학원 학비 무제한 전액지원 <br>
> 퇴사 후에도 advisor로 월금의 1/2 계속 받음 <br>
> 제1회 혁신상 수상(Chairman’s Innovation Award) <br>
> 특허 3개 출원 <br>
> 무한 자신감 <br>
>
> <br>
>
> Step #2: Growth
> 우리의 감(feelings)은 틀리다. 모든 것은 이론화 되어있다.
>
> 이론: Divide and Conquer
>
> <br>
>
> Step #3: New Opportunities
> 사이드 프로젝트가 당신의 날개가 된다.
>
> 사이드로 만들었던 게임을 통해서 eBay 모바일 부문에 입사.
> 마찬가지로 집에서 사용되는 임베디드 기기 사이트 프로젝트(회로 설계도 직접했고, 특허도 있음)를 통해 Intel의 wearable division에 입사.
>
> “It’s a common catch-22: for jobs that require prior experience, how do you get the experience for the first time? My solution: do the job for free on the side.:
>
> 
>
> - “It is not the strongest of the species that survives, nor the most intelligent that survives. It is the one that is most adaptable to change."
>
> 





<br>

