import sys

# Redirect input from file
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

N = int(input())
distanze = input().split()
D = []
for i in range(N):
    D.append(int(distanze[i]))

# Controlla che il vettore sia ordinato
for i in range(1, N):
    if D[i - 1] > D[i]:
        print("Errore: overflow of input")
        sys.exit(1)

ultima = []

# Per ogni villaggio di partenza
for partenza in range(N):
    distrutta = []
    for i in range(N):
        distrutta.append(False)

    attuale = partenza
    attuale_precedente = 0

    # Distruggi N villaggi
    for intere in range(N, 0, -1):
        attuale_precedente = attuale
        distrutta[attuale] = True

        # Trova il villaggio prima non distrutto
        prima = attuale - 1
        while prima >= 0 and distrutta[prima]:
            prima -= 1

        # Trova il villaggio dopo non distrutto
        dopo = attuale + 1
        while dopo < N and distrutta[dopo]:
            dopo += 1

        # Calcola distanze
        infinito = 10**18
        distanza_prima = infinito
        if prima >= 0:
            distanza_prima = D[attuale] - D[prima]

        distanza_dopo = infinito
        if dopo < N:
            distanza_dopo = D[dopo] - D[attuale]

        # Vai al piu' vicino (preferisci sinistra se uguale)
        if distanza_prima <= distanza_dopo:
            attuale = prima
        else:
            attuale = dopo

    ultima.append(attuale_precedente)

# Stampa risultati
for i in range(N):
    print(ultima[i], end=" ")
print()
