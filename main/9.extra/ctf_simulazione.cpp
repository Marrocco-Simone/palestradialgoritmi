#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++)
  {
    long long N;
    cin >> N;
    vector<bool> inGara(N, true);
    long long rimasti = N;
    long long i = 0;
    while (rimasti > 1)
    {
      long long j = (i + 1) % N;
      while (!inGara[j])
        j = (j + 1) % N;
      inGara[j] = false;
      rimasti--;
      i = (j + 1) % N;
      while (!inGara[i])
        i = (i + 1) % N;
    }
    cout << i + 1 << "\n";
  }
}
