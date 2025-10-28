#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// input data
int K;
string S;
int frequenza[26]; // array per contare le 26 lettere, inizializzato a zero

int main()
{
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> K;
    cin.ignore();

    int quasi_isogrammi = 0;

    for (int k = 0; k < K; k++)
    {
        // Resetta l'array per la nuova frase
        for (int i = 0; i < 26; i++)
        {
            frequenza[i] = 0;
        }

        getline(cin, S);
        bool e_quasi_isogramma = true;

        // Conta la frequenza di ogni carattere
        for (int i = 0; i < S.size(); i++)
        {
            char c = S[i];
            if (c >= 'a' && c <= 'z')
            {
                frequenza[c - 'a']++;
                if (frequenza[c - 'a'] == 3)
                    e_quasi_isogramma = false;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                frequenza[c - 'A']++;
                if (frequenza[c - 'A'] == 3)
                    e_quasi_isogramma = false;
            }
        }

        if (e_quasi_isogramma)
        {
            quasi_isogrammi++;
        }
    }

    cout << quasi_isogrammi << endl;
    return 0;
}
