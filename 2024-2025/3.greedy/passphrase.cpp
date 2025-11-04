/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// input data
int N, K;
string passphrase;

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    cin >> N >> K;
    cin >> passphrase;

    for (int rimosse = 0; rimosse < K; rimosse++)
    {
        int da_togliere = N - 1 - rimosse;
        for (int i = 0; i < N - 1; i++)
        {
            if (passphrase[i] < passphrase[i + 1])
            {
                da_togliere = i;
                break;
            }
        }

        passphrase.erase(da_togliere, 1);
    }

    cout << passphrase << endl; // print the result
    return 0;
}
