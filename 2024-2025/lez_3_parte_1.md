---
marp: true
theme: gaia
_class: lead
paginate: true
author: Palestra di Algoritmi 2024/2025
description: Palestra di Algoritmi 2024/2025
lang: italian
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')

title: Greedy Algorithms parte 2
---
# Algoritmi Greedy 
#### . . .
## Seconda Parte

---

# Precise Average

Il tuo amico John lavora in un negozio che vende _N_ prodotti, numerati da 0 a N-1.
Ogni prodotto di indice _i_, costa _P[i]_ bytedollari, ogni é P[i]>0.
Il governo impone una nuova legge per il negozio.
La legge recita **"la media di tutti i prezzi deve essere esattamente K"**, con K>0.
La capa di John gli chiede di cambiare i prezzi dei prodotti, tale per cui rispettino la nuova legge.

Fonte: [https://training.olinfo.it/task/ois_avg/](https://training.olinfo.it/task/ois_avg/)

---
John è pigro e vuole fare il minimo di cambi possibili: 
> qual è il **numero minimo** di cambiamenti che deve effettuare?

**Il prezzo di un prodotto può diventare QUALSIASI prezzo positivo (niente roba gratis)**


---

#### Vincoli (solo IN INPUT --> non vale per output):
• 1 ≤ N ≤ 200 000.
• 1 ≤ K ≤ 1 000 000.
• 1 ≤ Pi ≤ 1 000 000 per ogni i = 0 ... N−1.



### Esempi

| Input            | Output      |
|-------------     |-------------|
| K=3; 10, 6       | 2           |
| K=9;  2,10, 1    | 1    		 |
---
#### Soluzione && Codice

```c++
#define MAXD 1000000*1ULL
typedef unsigned long long ull;

int average(vector<ull>& P, ull sum_prod, ull NK){//O(n * logn) ... perché non O(n)?
    if(sum_prod<NK) return 1;//perché sempre 1?
    else if(sum_prod==NK) return 0;//perche?

    sort(P.rbegin(), P.rend());//decrescente, O(n * logn)?, perché ordinare al contrario?
    ull difference=sum_prod-NK;//a cosa serve?
    int counter_num_changed = 0;//tengo conto di quanti cambiamenti ho fatto

    for (int i = 0; i < P.size() && difference > 0; ++i){//O(n)
	ull maximum_change = (P[i]-1);//a cosa serve?
        ull decrement = min(difference, less_then_Pi);//perché min()
        P[i] = max((P[i] - decrement), 1ULL);//a cosa serve?
        difference -= decrement;//aggiorno la  difference, perché qualcosa l'ho "consumato"
        ++counter_num_changed;
    }
    return counter_num_changed;
}
```

---
### Complessità?

```c++
/*ogni istruzione prima del sort --> O(1)*/
```

```c++
sort(P.rbegin(), P.rend()); //--> O(n * logn)
```

```c++
for (int i = 0; i < P.size(); ++i) //--> O(P.size), ovvero O(n)
```

```c++
/*ogni istruzione dentro il for-loop --> O(1)*/
```

```c++
/*costo finale for-loop: O(n)*O(1)--> O(n*1)--> O(n)*/
```

**Costo finale:** O(n * logn) + O(n) --> **O(n * logn)**

---
#### Codice commentato

```c++
if(sum_prod<NK) return 1;//perché sempre 1?
```
Immaginiamo di avere: K=9 e P: 2,10, 1.
Ricordiamo che: **difference = sum_prod - NK**
Allora N=3, K=9 --> NK=27, sum_prod=13 --> 
difference=13-27= **-** 14.  Ora significa che dobbiamo **aumentare** di 14, ma **possiamo aumentare un qualsiasi prodotto** di 14, visto che il prezzo deve essere almeno positivo **E** perché il **vincolo di massimo 1 milione vale solo per i dati iniziali e non finali**.
Quindi **SEMPRE** serve aumentare un valore a caso, ergo un solo cambiamento.

---

```c++
else if(sum_prod==NK) return 0;//perche?
```
Immaginiamo di avere: K=2 e P: 3,1.
Allora N=2, K=2 --> NK=4, sum_prod=4 --> difference=4-4= 0 --> rispetto già la legge.

Semplice vedere che se la media nostra è già uguale a K, allora rispettiamo già la legge, ergo **NON DEVO fare nulla e quindi zero cambiamenti**.

---

```c++
sort(P.rbegin(), P.rend());//perché ordinare al contrario?
```
Ora stiamo **assumendo che sum_prod > NK**, ergo il nostro valore/media è maggiore di quanto dovrebbe essere per legge. 
Quindi devo **_sottrarre_**.
Sia K=3 e P: 10, 6.
Allora N=2, K=3 --> NK=6, sum_prod=16 --> difference=16-6= **+** 10.
Ergo _dovremmo_ **togliere** esattamente 10 e quindi, per intuito greedy, **togliamo il più possibile al numero più grande --> ergo devo sapere quale sia il più grande, perciò ordino e so subito trovare il massimo in O(1) pagando una volta O(n * logn)**.
Quindi, dopo aver ordinato, tolgo a P[0](ovvero 10) il più possibile di _difference_.


---

```c++
ull difference=sum_prod-NK; //a cosa serve?
```
Se siamo arrivatu fin qui vuol dire che _difference_ è positivo, ovvero (per intenderci), che dobbiamo togliere una parte positiva di prezzo ai nostri prodotti.

Usiamo un **unsigned long long** perché nel caso pessimo avremmo 1'000'000 * 200'000 - 200'000 * 1, ovvero 199'999'800'000. Però con "solo" un unsigned int posso rappresentare solo fino a 4'294'967'295

---

```c++
ull maximum_change = P[i]-1;//a cosa serve?
```
Serve per dopo dove facciamo:
```c++
ull decrement = min(difference, maximum_change);//perché min()
```
Ovvero dove scegliamo _solo_ il minimo tra l'attuale _difference_
Sia P = [10, 20, 30] e un difference = 15.
- maximum_change = P[0] - 1 = 9 (massimo decremento possibile è 9, portando P[0] da 10 a 1).
- decrement = min(15, 9) = 9 (decrementiamo di 9 perché è il massimo consentito da maximum_change).


---

```c++
P[i] = max((P[i] - decrement), 1ULL);//a cosa serve?
```

Prendiamo il massimo tra 1 (1ULL significa 1 visto come ull) e il valore P[i] meno quello che dovrei togliere.

Perché se decrement fosse maggiore di P[i], allora NON vogliamo scegliere un valore negativo (per vincolo).

Notare che se decrement fosse uguale a P[i] allora avremmo 0 come valore finale, cosa che non vogliamo, quindi Prendiamo 1.
