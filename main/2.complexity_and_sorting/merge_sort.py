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

def unisci_ordinati(A, B): # A e B sono gia' ordinati
    C = []
    index_a = 0
    index_b = 0
    while (len(C) < len(A) + len(B)):
        if (
            index_b >= len(B) or # B è finito, quindi aggiungo solo da A
            (index_a < len(A) and A[index_a] < B[index_b])# A non è finito ed ha l'elemento piu' piccolo
        ):
            C.append(A[index_a])
            index_a += 1
        else:
            C.append(B[index_b])
            index_b += 1
    return C

def dividi_e_riunisci_ordinato(C):
    if len(C) == 1: return C
    lunghezza = len(C)//2 # divisione intera
    A = C[:lunghezza] # prima meta'
    B = C[lunghezza:] # seconda meta'
    A = dividi_e_riunisci_ordinato(A)
    B = dividi_e_riunisci_ordinato(B)
    C = unisci_ordinati(A, B)
    return C

def ordina():
    global N, D
    D = dividi_e_riunisci_ordinato(D)

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
