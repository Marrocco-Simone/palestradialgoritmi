import sys

# Redirect input from file
sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

K = int(input())

quasi_isogrammi = 0

for k in range(K):
    S = input()

    # Conta la frequenza di ogni carattere (minuscole e maiuscole sono uguali)
    frequenza = {}
    for carattere in S:
        if carattere >= 'a' and carattere <= 'z':
            c = carattere
            if c not in frequenza:
                frequenza[c] = 0
            frequenza[c] += 1
        elif carattere >= 'A' and carattere <= 'Z':
            c = chr(ord(carattere) + (ord('a') - ord('A')))
            if c not in frequenza:
                frequenza[c] = 0
            frequenza[c] += 1

    # Controlla se e' un quasi-isogramma (ogni lettera appare al massimo 2 volte)
    e_quasi_isogramma = True
    for carattere in frequenza:
        volte = frequenza[carattere]
        if volte > 2:
            e_quasi_isogramma = False
            break

    if e_quasi_isogramma:
        quasi_isogrammi += 1

print(quasi_isogrammi)
