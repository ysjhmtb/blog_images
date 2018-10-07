
#jsonTest3.py

import json
from pprint import pprint

with open('gfriend.json') as data_file:
    data = json.load(data_file)
    data_file.close()

pprint(data[1])