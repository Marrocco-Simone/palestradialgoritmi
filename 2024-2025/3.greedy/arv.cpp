#include <bits/stdc++.h>
#define MAXD 1000000

using namespace std;

int myFun_neg(vector<int>& P, unsigned long long difference){
	//sum_prod < NK
	sort(P.begin(), P.end());
	int conuter_num_changed = 0;

	for (int i = 0; i < P.size() && difference > 0; ++i) {
		unsigned long long addizionale = (MAXD - P[i])*1ULL;
        unsigned long long increment = min(difference, addizionale)*1ULL;
        P[i] = min((int)(P[i] + increment), MAXD);
        difference -= increment;
        ++conuter_num_changed;

		/*int addizionale =  MAXD - P[i];
		unsigned long long increment = (difference >= addizionale ? (unsigned long long) addizionale : difference);
        if (P[i] <= difference) {//tipo: ... 3 ... e diff=3mil
			//ex: P[i]=1mil-1 and diff=1mil --> addiz=1; ok
			P[i] += increment;//Pi = Pi+1mil-Pi iif incr==addiz; ok
			difference-=increment;//diff=diff-1; ok

			//ex: P[i]=1 and diff=1mil --> addiz=999k; ok
			//incr==addiz --> Pi=1+999k; ok
			//diff=999k-999k; ok
        } else {//tipo: ...1mil ... e diff=1, e addiz=0
            P[i] += increment;
            difference = 0;
        }
        ++conuter_num_changed;*/
    }
    return conuter_num_changed;
}

int myFun(vector<int>& P, unsigned long long difference) {
    //sum_prod > NK
    sort(P.rbegin(), P.rend());//decrescente
	int conuter_num_changed = 0;

	for (int i = 0; i < P.size() && difference > 0; ++i) {
		unsigned long long less_then_Pi = (P[i]-1)*1ULL;
        unsigned long long decrement = min(difference, less_then_Pi)*1ULL;
        P[i] = max((int)(P[i] - decrement), 1);
        difference -= decrement;
        ++conuter_num_changed;

        /*if (P[i] <= difference) {
            difference -= P[i] - 1;//reduce up to 1
            P[i] = 1;
        } else {
            P[i] -= difference;
            difference = 0;
        }
        ++conuter_num_changed;*/
    }
    return conuter_num_changed;
}

int main() {
	ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, K;
	unsigned long long sum_prod=0;

    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; ++i){
        cin >> P[i];
		sum_prod+=P[i];
	}

    sum_prod*=1ULL;
	unsigned long long NK= 1ULL*N*K;// !!! 1ULL !!!
	
	if(sum_prod<NK){
		cout << myFun_neg(P, (NK-sum_prod)*1ULL);
	} else if(sum_prod==NK){
		cout << 0;
	} else{
		cout << myFun(P, (sum_prod-NK)*1ULL);
	}
	return 0;
}