'''

https://aaronschlegel.me/black-scholes-formula-python.html


#

S, the spot price of the asset at time t
T, the maturity of the option. Time to maturity is defined as T−t
K, strike price of the option
r, the risk-free interest rate, assumed to be constant between t and T
σ, volatility of underlying asset, the standard deviation of the asset returns


#

N(d)  is the cumulative distribution of the standard normal variable Z

N(d) = {1 / sqrt(2 * pi)} * { integral[-inf, d] e ^ { (-1 / 2) * x^2 } } dx


C(S,t)  is the value at time t of a call option and P(S,t)
is the value at time t of a put option.

C(S, t) = S N(d1) - K { e^{-r (T - t) } } N(d2)

P(S, t) = K { e^{-r (T - t)} } N(-d2) - S N(-d2)




where


d1 = { ln(S/K) + ( r +  { {sigma^2} / 2 } ) * (T - t) } /
        { sigma * sqrt(T - t) }


d2 = d1 - sigma * sqrt(T - t) =
                { ln(S/K) + ( r -  { {sigma^2} / 2 } ) * (T - t) }  /
                { sigma * sqrt(T - t) }




'''


'''

미국의 트레이더였던 제시 리버모어는 큰 돈을 벌다가 결국 파산을 했는데, 
거래 방법 자체가 잘못된 것이었을까요? 
아니면 방법은 옳았지만 베팅비율 조절에 실패한 것일까요?

개골
베팅 실패는 운의 문제가 제일 크죠. 컨트롤할 수 없는 운 요소를 빼놓고 생각하면 
결국 파산까지 이른 베팅 비율이 문제일듯요.

https://ask.fm/cfr0g/answers/150326757866





안녕하세요 개골님. 기초자산 가격이 주어졌을 때, 
그 가격에 상응하는 옵션의 가격을 추론할 수 있을까요? 
그렇게 하려면 어떤 방법론을 사용해야 할까요? 
사용되는 확률 분포가 있을까요? 추천해 주실 문헌이 있는지요? 
읽어주셔서 감사합니다.

개골
옵션 가격 계산은 블랙숄즈 방정식부터 공부하시면 됩니다.

https://ask.fm/cfr0g/answers/150649228522





우선 답변해 주셔서 감사합니다, 개골님. 그런데 제가 질문드렸던 부분은 
기초자산의 가격 데이터만 있는 상황에서 
옵션 시장에서는 옵션이 어느 가격에서 거래될 것인가가 궁금한 것인데, 
이 경우에도 결국 옵션가격을 계산하는 
것이므로 블랙숄즈 모형에서 시작하라는 말씀이신 것이지요?

개골
시장가는 예측이 어렵습니다. 여기에 대해선 수많은 이론이 있지만 예측을 완벽하게 하는 건 없죠. 
(한다해도 게임이론의 게임상태라 모두가 예측가능한 가격은 불가능합니다) 
하지만 옵션가격은 일단 블랙숄즈의 계산값 근처에서 움직이므로 이걸 모르고는 이야기가 안될거에요.

https://ask.fm/cfr0g/answers/150652223466


'''


'''

1) 기초자산 데이터를 바탕으로 옵션 가격 데이터를 생성.
2) 이를 바탕으로 시뮬레이션.

'''











