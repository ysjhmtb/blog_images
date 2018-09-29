a = [1,2,3]
for i in range(len(a)):
    if(i==0):
        del a[0]
    print(i)

print(a)