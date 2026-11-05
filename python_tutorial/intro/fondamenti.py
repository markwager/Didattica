print("ciao sono vally")

#oggetti scalari: indivisibili
a=2
b=3.5
c=True
d=False
e=None

print("Somma", a+b) #restituisce un float
print(type(a+b)) #ti dice il tipo di oggetto
print(type(a))

# In[]

#operatori su oggetti non scalari
i=10
j=6.7
print(type(i+j))
print(type(i-j))
print(type(i*j))
print(type(i/j))
print(i//j,type(i//j))
print(type(i%j))
print(type(i**j))

a=True
b=False
print(a and b)
print(a or b)

# In[]

#es 
pi = 3
radius = 11
print(radius)
area = pi * (radius**2)
print(area)
radius = 14
print(radius)
print(area)
# In[]

#assegnazioni multiple
x,y=2,3
print("x: ",x)
print("y: ", y)
x,y=y,x
print("x: ",x)
print("y: ", y)

