// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> D(N);
    for (int i = 0; i < N; ++i)
        cin >> D[i];

    for (int i = 1; i < N; ++i)
        if (D[i - 1] > D[i])
            throw invalid_argument("overflow");

    vector<int> ultima(N);

    // INSERT YOUR CODE HERE
    for (int partenza = 0; partenza < N; partenza++)
    {
        vector<bool> distrutta(N, false);
        int attuale = partenza;
        int attuale_precedente;

        for (int intere = N; intere > 0; intere--)
        {
            attuale_precedente = attuale;
            distrutta[attuale] = true;
            int prima = attuale - 1;
            while (prima >= 0 && distrutta[prima])
                prima--;
            int dopo = attuale + 1;
            while (dopo < N && distrutta[dopo])
                dopo++;

            int distanza_prima = -1;
            if (prima >= 0)
                distanza_prima = D[attuale] - D[prima];
            int distanza_dopo = -1;
            if (dopo < N)
                distanza_dopo = D[dopo] - D[attuale];

            if (distanza_prima < 0)
                attuale = dopo;
            else if (distanza_dopo < 0)
                attuale = prima;
            else if (distanza_prima <= distanza_dopo)
                attuale = prima;
            else
                attuale = dopo;
        }

        ultima[partenza] = attuale_precedente;
    }

    for (int i = 0; i < N; ++i)
        cout << ultima[i] << " ";
    cout << endl;

    return 0;
}
