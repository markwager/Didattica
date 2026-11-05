
for i in range(3,1000):
    for j in range(i):
        if((i+j)%2==0 and (i+j)%3==0):
            continue
        else:
            print(i+j)
