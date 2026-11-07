#trova la radice cubica di un cubo perfetto
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

# controlla se un int>2 è primo. Se non lo è, stampa
# il più piccolo dei suoi divisori
x = int(input('Inserisci un intero > 2: '))
lil_divisor = None
for indovina in range(3, x, 2):
    if x%indovina==0:
        lil_divisor=indovina
        break
if lil_divisor != None:
    print('Il più piccolo divisore di', x,\
        'è', lil_divisor)
else:
    print(x, 'è un numero primo')

# In[]

# controlla se un int > 2 è primo. Se non lo è, stampa
# il più grande dei suoi divisori
x = int(input('Inserisci un intero maggiore di 2: '))
biggest_divisor = None
for guess in range(3, x, 2):
    if x%guess == 0:
        biggest_divisor = guess
if biggest_divisor!= None:
    print('Il più grande divisore di', x,\
        'è', biggest_divisor)
else:
    print(x, 'è un numero primo')

# In[]

"""
Chiedere all’utente di inserire un intero e stampa due interi, root e pwr, tali che 1 < pwr < 6
e root**pwr uguale all’intero inserito dall’utente. Se non esiste una coppia di interi che rispettano queste condizioni,
stampare un messaggio che lo segnali.
"""

