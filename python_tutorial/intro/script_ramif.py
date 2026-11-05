#FATTO USO DI FUNZIONI NON SPIEGATE ANCORA

x=2
y=7
z=18

#oggetto non scalare: lista
L=[x,y,z]
disp=[]

for i in L:
    if(i%2!=0):
        disp.append(i)

print(max(disp))

# In[]
#versione alternativa

x=2
y=7
z=18

#oggetto non scalare: lista
L=[x,y,z]
max_disp=1;

for i in L:
    if(i%2!=0):
        if(i>max_disp):
            max_disp=i;
print(max_disp)

# In[]

#espressioni condizionali
x=3
y=5
z=2

print(x if x>z else y) #stampo x se si verifica x>z, altrimenti stampo y