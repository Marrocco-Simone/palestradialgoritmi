# lettura e scrittura da file (opzionale)
# with open("input.txt", "r") as f:
#     lines = f.readlines()

# with open("output.txt", "w") as f:

# Lettura input
N = 5
N = int(input())

D = []
for _ in range(N):
    D.append(input().strip())

vel = 0       # contatore Velocità
hcount = 0    # contatore di 'H' presenti
swap = 0      # numero di elementi swappati
imp = False

for i in range(N):
    if D[i] == 'D':
        vel += 9
    elif D[i] == 'U':
        vel += -11
    elif D[i] == 'B':
        vel += 10
    elif D[i] == 'H':
        hcount += 1

    while vel <= 0:
        if hcount > 0:
            hcount -= 1
            swap += 1
            vel += 10
        else:
            imp = True
            break

    if imp:
        break

if imp:
    print("-1")
else:
    print(swap)
