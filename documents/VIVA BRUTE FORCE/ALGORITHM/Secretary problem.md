<br>



> Secretary problem
>
> <br>
>
> Although there are many variations, the basic problem can be stated as follows:
>
> - There is a single position to fill.
>
> - There are n applicants for the position, and the value of n is known.
>
> - The applicants, if seen altogether, can be ranked from best to worst unambiguously.
>
> - The applicants are interviewed sequentially in random order, with each order being equally likely.
>
> - Immediately after an interview, the interviewed applicant is
>   either accepted or rejected, and the decision is irrevocable.
>
> - The decision to accept or reject an applicant can be based only on the relative ranks
>   of the applicants interviewed so far.
>
> - The objective of the general solution is to have the highest probability of selecting
>   the best applicant of the whole group.
>   This is the same as maximizing the expected payoff, with payoff defined to be one
>   for the best applicant and zero otherwise.
>
>
> Terminology: A candidate is defined as an applicant who, when interviewed, is better than all the applicants
> interviewed previously. Skip is used to mean "reject immediately after the interview".
>
> Clearly, since the objective in the problem is to select the single best applicant,
> only candidates will be considered for acceptance. The "candidate" in this context corresponds
> to the concept of record in permutation.
>
> https://en.wikipedia.org/wiki/Secretary_problem



<br>



다음과 같은 방법을 생각해 보았다.



```
1. 지원자가 3명인 경우를 가정하자. 이후 지원자의 수가 늘어난 경우 늘어난 수를 가정하면 된다. 
   물론 계산해야 할 경우의 수는 증가할 것이다.

2. 숫자로 지원자의 역량이 표시된다. 예를 들어서 3명의 그룹 중 최대역량은 3, 최소역량은 1로 나타난다.

3. 1번 지원자만 탈락시킨 경우와 2번 지원자까지 탈락시킨 경우를 비교해서 어떤 경우에 3이 포함될 확률이 큰 지를 비교하면 된다.
```



<br>

```python
import copy


# permute(['1','2','3'], 0, storageList)

def permute(numberList, i, storageList):
    if i == len(numberList) - 1:
        tempList = copy.deepcopy(numberList)
        storageList.append(tempList)
    else:
        for j in range(i, len(numberList)):
            numberList[i], numberList[j] = numberList[j], numberList[i]
            permute(numberList, i + 1, storageList)
            numberList[i], numberList[j] = numberList[j], numberList[i]


# findMax(storageList, 검사해야 할 행, 시작 지점, 끝날 지점)

def findMax(storageList, iIndex, start, end):
    maxNumber = 0
    for i in range(start, end + 1):
        if storageList[iIndex][i] > maxNumber:
            maxNumber = storageList[iIndex][i]
    return maxNumber


# drawProbability([ [1,2,3]... ], 1)

def drawProbability(storageList, nthFail):
    successCount = 0
    for i in range(len(storageList)):
        for j in range(nthFail, len(storageList[0])):
            if j != len(storageList[0]) - 1 and \
                    findMax(storageList, i, 0, nthFail - 1) < storageList[i][j] \
                    < findMax(storageList, i, j + 1, len(storageList[0]) - 1):
                break;

            elif storageList[i][j] == len(storageList[0]):
                successCount += 1

    result = successCount / len(storageList)
    return result


numberList = [1, 2, 3]
storageList = []
permute(numberList, 0, storageList)

print(storageList)
print(drawProbability(storageList, 1))  # 0.5
print(drawProbability(storageList, 2))  # 0.33333

```



<br>

위와 같이 파이썬을 이용해서 작성해 보았는데, 부족한 예외처리 등으로 인해 버그가 존재할 것 같다. 추후 다시 검토할 것이다.















