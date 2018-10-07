# 파이썬에서 List와 JSON 사용하기

 <br>

대량의 계산을 해야 하는 작업에 앞서서 JSON을 사용할 필요가 있어, 이에 대한 정리.

<br>

```python

#jsonTest1.py

'''
파이썬으로 JSON 만들기
http://parkjuwan.dothome.co.kr/wordpress/2017/03/22/make-json-py/

'''

import json
from collections import OrderedDict

# Ready for data
group_data = OrderedDict()
albums = OrderedDict()

group_data["name"] = "여자친구"
group_data["members"] = ["소원", "예린", "은하", "유주", "신비", "엄지"]

albums["EP 1집"] = "Season of Glass"
albums["EP 2집"] = "Flower Bud"
albums["EP 3집"] = "Snowflake"
albums["정규 1집"] = "LOL"
albums["EP 4집"] = "THE AWAKENING"

group_data["albums"] = albums

# Print JSON
print(json.dumps(group_data, ensure_ascii=False, indent="\t"))

''''

{
    "name": "여자친구",
    "members": [
        "소원",
        "예린",
        "은하",
        "유주",
        "신비",
        "엄지"
    ],
    "albums": {
        "EP 1집": "Season of Glass",
        "EP 2집": "Flower Bud",
        "EP 3집": "Snowflake",
        "정규 1집": "LOL",
        "EP 4집": "THE AWAKENING"
    }
}



'''

# Write JSON
with open('gfriend.json', 'w', encoding="utf-8") as make_file:
    json.dump(group_data, make_file, ensure_ascii=False, indent="\t")
    make_file.close()

```

<br>

다음과 같은 결과.

<br>

```json
{
	"name": "여자친구",
	"members": [
		"소원",
		"예린",
		"은하",
		"유주",
		"신비",
		"엄지"
	],
	"albums": {
		"EP 1집": "Season of Glass",
		"EP 2집": "Flower Bud",
		"EP 3집": "Snowflake",
		"정규 1집": "LOL",
		"EP 4집": "THE AWAKENING"
	}
}
```

<br>

```python

#jsonTest2.py

import json
from pprint import pprint

with open('gfriend.json') as data_file:
    data = json.load(data_file)
    data_file.close()



from collections import OrderedDict

# Ready for data
# group_data = OrderedDict()
# albums = OrderedDict()

group_data = {}
albums = {}

group_data["name"] = "GF2"
group_data["members"] = ["fr1", "fr2", "fr3", "fr4", "fr5", "fr6"]

albums["ab1"] = "title1"
albums["ab2"] = "title2"
albums["ab3"] = "title3"
albums["ab4"] = "title4"
albums["ab5"] = "title5"

group_data["albums"] = albums

# 리스트에 두 딕셔너리 담기
dataList=[]
dataList.append(data)
dataList.append(group_data)

pprint(dataList[0])
pprint(dataList[1])



# Write JSON
with open('gfriend.json', 'w', encoding="utf-8") as make_file:
    json.dump(dataList, make_file, ensure_ascii=False, indent="\t")
    make_file.close()
```

<br>

다음과 같은 결과.

<br>

```json
[
	{
		"name": "여자친구",
		"members": [
			"소원",
			"예린",
			"은하",
			"유주",
			"신비",
			"엄지"
		],
		"albums": {
			"EP 1집": "Season of Glass",
			"EP 2집": "Flower Bud",
			"EP 3집": "Snowflake",
			"정규 1집": "LOL",
			"EP 4집": "THE AWAKENING"
		}
	},
	{
		"name": "GF2",
		"members": [
			"fr1",
			"fr2",
			"fr3",
			"fr4",
			"fr5",
			"fr6"
		],
		"albums": {
			"ab1": "title1",
			"ab2": "title2",
			"ab3": "title3",
			"ab4": "title4",
			"ab5": "title5"
		}
	}
]
```

<br>

```python


#jsonTest3.py

import json
from pprint import pprint

with open('gfriend.json') as data_file:
    data = json.load(data_file)
    data_file.close()

pprint(data[1])
```

<br>

다음과 같은 결과

<br>

```json
{'albums': {'ab1': 'title1',
            'ab2': 'title2',
            'ab3': 'title3',
            'ab4': 'title4',
            'ab5': 'title5'},
 'members': ['fr1', 'fr2', 'fr3', 'fr4', 'fr5', 'fr6'],
 'name': 'GF2'}

```

<br>

이제 작업의 다음 단계를 진행할 수 있게 됐다.