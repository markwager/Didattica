#Trova la radice cubica di un cubo perfetto
#lo si fa con enumerazione esaustiva: enumeriamo tutte le possibilità finchè non arriviamo a quella giusta
x = int(input('Inserisci un intero: '))
ans = 0
while ans**3 < abs(x):
    ans = ans + 1
    print(ans)
if ans**3 != abs(x):
    print(x, 'non è un cubo perfetto')
else:
    if x < 0:
        ans = -ans
    print('La radice cubica di', x, 'è', ans)

# In[]

x = int(input('Inserisci un intero: '))
if(round(x**0.3)==3): #round mi fa un'appross. per eccesso, int lo fa per difetto
    print("wooow")
# In[]

# Verifica se un int > 2 è primo. Se non lo è, stampa
# il più piccolo dei suoi divisori
x = int(input('Inserisci un intero maggiore di 2: '))
smallest_divisor = None
if x%2 == 0:
    smallest_divisor = 2
else:
    for guess in range(3, x, 2):
        if x%guess == 0:
            smallest_divisor = guess
            break
if smallest_divisor != None:
    print('Il più piccolo divisore di', x,\
        'è', smallest_divisor)
else:
    print(x, 'è un numero primo')