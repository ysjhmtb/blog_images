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


C(S,t)  is the value at time t of a call option and P(S,t) is the value at time t of a put option.

C(S, t) = S N(d1) - K { e^{-r (T - t) } } N(d2)

P(S, t) = K { e^{-r (T - t)} } N(-d2) - S N(-d2)




where


d1 = { ln(S/K) + ( r +  { {sigma^2} / 2 } ) * (T - t) } /
        { sigma * sqrt(T - t) }


d2 = d1 - sigma * sqrt(T - t) =
                { ln(S/K) + ( r -  { {sigma^2} / 2 } ) * (T - t) }  /
                { sigma * sqrt(T - t) }











'''











