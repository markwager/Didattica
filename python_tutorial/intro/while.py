num_x = int(input('Quante volte devo stampare la X? '))
to_print = ''
# concatena X a to_print per num_x volte
i=0;
while i<num_x:
    to_print+="X"
    i+=1;
print(to_print)

# In[]

#Trova un intero positivo divisibile sia per 11 che per 12
x=1
while True:
	if x%11==0 and x%12==0:
		break
	x+=1
print(x, 'è divisibile per 11 e per 12')

# In[]

L=[]
disp=[]
i=0
while i<10:
	n=input("Inserisci 10 numeri interi: ")
	n=int(n)
	L.append(n)
	i+=1

disp=[]

for i in L:
	if i%2!=0:
		disp.append(i)

if(len(disp)>=1):
	print(max(disp))
else:
	print("non hai inserito nessun numero dispari")
# %%
