somma=0
for i in range(3, 1000, 2):
    for j in range(3, int(i**0.5)+1, 2): #se un numero non è primo deve per forza avere almenoi un divisore che sia <= alla sua radice quadrata
        print(j) 
        if(i%j==0):
            break
    somma+=i

print("La somma dei numeri primi compresi tra 3 e 999 è: ", somma)
