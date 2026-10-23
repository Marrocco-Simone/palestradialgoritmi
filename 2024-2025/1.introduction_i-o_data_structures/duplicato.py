import sys

# Redirect input/output da/a file
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

# Soluzioni possibili:
# 1: due cestini, mettiamo un numero nuovo nel primo cestino in maniera ordinata, se c'e' gia' (controllando efficientemente) lo mettiamo nel secondo in maniera ordinata. alla fine sommo ogni elemento di ogni cestino e faccio la differenza.
# 2: ordino tutte le mia pagine e poi controllo finche' non trovo quello da solo
# 3: per ogni numero, guardo in tutta la lista se ne trovo due


def trova(N, P):
    # Mettete qui il codice della soluzione
    L = 2 * N - 1
    # Soluzione 2
    P.sort()
    for i in range(0, L - 1, 2):
        if P[i] != P[i + 1]:
            return P[i]
    return P[L - 1]


N = int(input())
pagine = input().split()
P = []
for i in range(2 * N - 1):
    P.append(int(pagine[i]))

print(trova(N, P))
