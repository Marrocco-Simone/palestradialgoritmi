// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, P;
    cin >> N >> P;

    vector<int> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    vector<int> F(N);
    for (int i = 0; i < N; ++i)
        cin >> F[i];

    int Q;
    cin >> Q;

    vector<int> l(Q), r(Q), k(Q);
    for (int i = 0; i < Q; ++i)
        cin >> l[i] >> r[i] >> k[i];

    vector<string> answer(Q);

    // INSERT YOUR CODE HERE
    vector<int> filtered;
    for (int i = 0; i < N; i++)
    {
        if (F[i] != P)
            continue;
        filtered.push_back(S[i]);
    }

    sort(filtered.begin(), filtered.end());
    N = filtered.size();

    for (int q = 0; q < Q; q++)
    {
        int min = 0, max = N;
        while (min < max)
        {
            int mid = (min + max) / 2;
            if (filtered[mid] < l[q])
                min = mid + 1;
            else
                max = mid;
        }
        int left = min;

        min = 0;
        max = N;
        while (min < max)
        {
            int mid = (min + max) / 2;
            if (filtered[mid] <= r[q])
                min = mid + 1;
            else
                max = mid;
        }
        int right = min;

        int count = right - left;
        if (count >= k[q])
            answer[q] = "YES";
        else
            answer[q] = "NO";
    }

    for (int i = 0; i < Q; ++i)
        cout << answer[i] << endl;

    return 0;
}
