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

title: Introduzione, Input/Output & Data Structures
---

# Introduzione, Input/Output & Data Structures

Basato su [Competitive Programmer's Handbook](https://github.com/Marrocco-Simone/palestradialgoritmi/blob/master/risorse/Competitive%20Programmer%E2%80%99s%20Handbook.pdf), [Dispense del prof. Bugatti](https://github.com/Marrocco-Simone/palestradialgoritmi/blob/master/risorse/Dispense%20prof%20Bugatti.pdf) e [Halim's Competitive Programming 3](https://github.com/Marrocco-Simone/palestradialgoritmi/blob/master/risorse/competitive%20programming%203_1.pdf)

---

# Diteci qualcosa di voi

## [https://tinyurl.com/pda2425](https://tinyurl.com/pda2425)

---

# Obiettivi

Gli obiettivi delle competizioni di programmazione sono

- Pensare a soluzioni efficienti per un problema
- Pensare velocemente a soluzioni
- Scrivere velocemente le soluzioni

---

# Prerequisiti

Per motivi vari, il corso è tenuto in C++. Un linguaggio a basso livello vi permette di pensare meglio a strutture dati, gestione memoria ed efficienza di esecuzione.

È supposto voi sappiate:

- tipi di dato base: int, char, array, boolean
- condizioni: if, else, switch
- cicli: for, while, do_while

---

# No ingegneria del software

Per motivi pratici e mancanza di tempo, userete tattiche sconsigliate se mai lavorerete a codice che necessita di essere mantenuto.

- variabili globali
- poche funzioni o modularità
- abbreviazioni di costrutti comuni
- scelta accurata delle librerie

---

# Template base

```c++
#include <bits/stdc++.h> // tutte le librerie di C/C++, filtrate poi dal compilatore
using namespace std;

int N, K; // variabili input globali
int main() {
    ios::sync_with_stdio(0); // input/output più veloce
    cin.tie(0); // input/output più veloce

    freopen("input.txt", "r", stdin); // sovrascrivi il flusso di input da file
    freopen("output.txt", "w", stdout); // sovrascrivi il flusso di output su file

    cin >> N >> K; // salta spazi e "a capo" (newlines) fino a prossimo valore
    cout << N + K << "\n"; // "\n" è più veloce di endl (flush)
}
```

---

# Int & Floats

- int: da `-2^31` a `2^31 - 1`, circa da `-2 * 10^9` a `2 * 10^9`
- long long: da `-2^63` a `2^63 - 1`, circa da `-9 * 10^18` a `2 * 10^18`
  - potete accorciarlo se scrivere in cima `typedef long long ll;`
  - `long long x = 3` --> `ll x = 3`
- float & double: numeri decimali, ma attenti ad errori di arrotondamento
  - `if(a < b)` --> `if(abs(a-b) < 1e-9)`

---

# Modules

Il modulo `%` è l'operazione che ritorna il resto di una divisione

`13 / 5 = 2` con resto di 3 --> `13 % 5 = 3`

- `(a + b) % m = (a % m + b % m) % m`
- `(a * b) % m = (a % m * b % m) % m`
- `(a - b) % m = (a % m - b % m) % m`
  - se minore di zero, aggiungete `m`

---

# Stringhe

```c++
string s; // meglio di char[], abbiamo più funzioni
int main() {
  // stesso codice di sopra...

  getline(cin, s);
}
```
