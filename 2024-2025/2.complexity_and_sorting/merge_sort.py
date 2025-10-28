import random
import time
import math

MAXN = 10000000

N = 0
D = []

def prendi_tempo():
    return time.time()

def differenza_tempo(start, end):
    return end - start

def crea_numeri_casuali():
    global D
    for i in range(N):
        D.append(random.randint(0, 2**31 - 1))

def controlla_ordinamento():
    for i in range(N - 1):
        if D[i] > D[i + 1]:
            return False
    return True

def merge(arr, i, m, f):
    n1 = m - i + 1
    n2 = f - m

    L = [0] * n1
    R = [0] * n2

    for x in range(n1):
        L[x] = arr[i + x]
    for y in range(n2):
        R[y] = arr[m + 1 + y]

    x = 0
    y = 0
    z = i

    while x < n1 and y < n2:
        if L[x] <= R[y]:
            arr[z] = L[x]
            x += 1
        else:
            arr[z] = R[y]
            y += 1
        z += 1

    while x < n1:
        arr[z] = L[x]
        x += 1
        z += 1

    while y < n2:
        arr[z] = R[y]
        y += 1
        z += 1

def mergeSort(arr, i, f):
    if i < f:
        m = i + (f - i) // 2

        mergeSort(arr, i, m)
        mergeSort(arr, m + 1, f)

        merge(arr, i, m, f)

def ordina():
    # implementa qui l'algoritmo di ordinamento
    # D.sort()
    mergeSort(D, 0, N - 1)

def main():
    global N, D
    N = 1000000
    if N > MAXN:
        print("N troppo grande")
        return 1
    else:
        print(f"N = 10^{math.log10(N)}")

    before = prendi_tempo()

    crea_numeri_casuali()
    start = prendi_tempo()
    print(f"Numeri generati in {differenza_tempo(before, start)} secondi")

    # modifica questa funzione
    ordina()
    end = prendi_tempo()
    print(f"Array ordinato in {differenza_tempo(start, end)} secondi")

    ordinato = controlla_ordinamento()
    after = prendi_tempo()
    print(f"Controllo ordinamento in {differenza_tempo(end, after)} secondi")

    print(f"Tempo totale: {differenza_tempo(before, after)} secondi")

    if not ordinato:
        print("Array non ordinato")
    else:
        print("Array ordinato")

if __name__ == "__main__":
    main()
