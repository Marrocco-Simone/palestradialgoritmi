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
# Greedy Algorithms 
#### . . .
## Second Part

---

# Precise Average

Your friend John works at a shop that sells _N_ types of products, numbered from 0 to N − 1. Product _"i"_ has a price of _P[i]_ bytedollars, where P[i]>0.
The government of Byteland has created a new law for shops. 
The law states that **the average of the prices of all products in a shop should be exactly K**, where K>0. 
John’s boss gave him the task to change the prices of the products so the shop would comply with the new law.

Source: [https://training.olinfo.it/task/ois_avg/](https://training.olinfo.it/task/ois_avg/)

---
He has lots of other stuff to do, so he asked you for help: 
what is the **minimum number** of products whose prices should be changed? 
**A product’s price can be changed to _ANY_ (!!!) positive integer amount of bytedollars.**


P.S.: pals ... when I say "ANY" I literally mean "plz look ahead that P[i] initially **has to be less** than 1 million, BUT it **could be**, AFTER, **higher**"

---

### Constraints (ONLY IN INPUT --> not valid for output):
• 1 ≤ N ≤ 200 000.
• 1 ≤ K ≤ 1 000 000.
• 1 ≤ Pi ≤ 1 000 000 for each i = 0 . . . N − 1.



### Examples

| Input            | Output      |
|-------------     |-------------|
| K=3; 10, 6       | 2           |
| K=9;  2,10, 1    | 1    		 |
---
#### Solution && Code

```c++
#define MAXD 1000000*1ULL
typedef unsigned long long ull;

int average(vector<ull>& P, ull sum_prod, ull NK){//O(n * logn) ... why not O(n)?
    if(sum_prod<NK) return 1;//why only "1" every time?
    else if(sum_prod==NK) return 0;//why so?

    sort(P.rbegin(), P.rend());//decrescente, complexity?, why sorting?
    ull difference=sum_prod-NK;//what to use it for?
    int counter_num_changed = 0;

    for (int i = 0; i < P.size() && difference > 0; ++i){//O(n)
	ull less_then_Pi = (P[i]-1);
        ull decrement = min(difference, less_then_Pi);
        P[i] = max((P[i] - decrement), 1ULL);//explain why and what is it usefull for
        difference -= decrement;
        ++counter_num_changed;
    }
    return counter_num_changed;
}
```

---
# Complexity?



##### We let you tell it to us ;)

---