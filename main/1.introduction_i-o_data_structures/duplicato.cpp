#include <stdio.h>
#include <assert.h>
#include <algorithm>
#define MAXN 100000

/*
Soluzioni possibili:
1: due cestini, mettiamo un numero nuovo nel primo cestino in maniera ordinata, se c'e' gia' (controllando efficientemente) lo mettiamo nel secondo in maniera ordinata. alla fine sommo ogni elemento di ogni cestino e faccio la differenza.
2: ordino tutte le mia pagine e poi controllo finche' non trovo quello da solo
3: per ogni numero, guardo in tutta la lista se ne trovo due
*/
int trova(int N, int P[])
{
    // Mettete qui il codice della soluzione
    int pagina_unica = 0;
    int L = 2 * N - 1;
    // Soluzione 3
    for (int i = 0; i < L; i = i + 1)
    {
        int contatore = 0;
        for (int j = 0; j < L; j++)
        {
            if (P[i] == P[j])
            {
                contatore++;
            }
            if (contatore > 1)
                break;
        }
        if (contatore == 1)
        {
            pagina_unica = P[i];
        }
    }
    return pagina_unica;

    std::sort(P, P + L);
    for (int i = 0; i < L; i = i + 2)
    {
        if (P[i] != P[i + 1])
        {
            return P[i];
        }
    }
    return P[L - 1];
}

int P[2 * MAXN];
int main()
{
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for (i = 0; i < 2 * N - 1; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", trova(N, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
