# http://pythonstudy.xyz/python/article/510-%EC%A7%81%EB%A0%AC%ED%99%94%EC%99%80-%EC%97%AD%EC%A7%81%EB%A0%AC%ED%99%94

import _pickle

class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.area = width * height


rect = Rectangle(10, 20)
rect2 = Rectangle(11, 21)
rectArr = []

# 사각형 rect 객체를 직렬화 (Serialization)
with open('rect.data', 'wb') as f:
    _pickle.dump(rect, f)
    _pickle.dump(rect2, f)

# 역직렬화 (Deserialization)
with open('rect.data', 'rb') as f:
    r = _pickle.load(f)
    rectArr.append(r)
    r = _pickle.load(f)
    rectArr.append(r)

print("%d x %d" % (rectArr[0].width, rectArr[0].height))
print("%d x %d" % (r.width, r.height))
