# Legge i tre valori interi
A = int(input())
B = int(input())
C = int(input())

# Mettiamo le lunghezze in un set per eliminare i duplicati
lunghezze_distinte = len({A, B, C})

# Calcoliamo il numero di rettangoli in base a quante lunghezze distinte ci sono
if lunghezze_distinte == 1:
    print(1)
elif lunghezze_distinte == 2:
    print(3)
else:
    print(6)