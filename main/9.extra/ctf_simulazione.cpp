#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++)
  {
    long long N;
    cin >> N;
    queue<long long> cerchio;
    for (long long i = 1; i <= N; i++)
      cerchio.push(i);
    while (cerchio.size() > 1)
    {
      long long ladro = cerchio.front();
      cerchio.pop();
      cerchio.pop();
      cerchio.push(ladro);
    }
    cout << cerchio.front() << "\n";
  }
}
