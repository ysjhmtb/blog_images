
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