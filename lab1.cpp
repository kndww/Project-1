#include <iostream>
using namespace std;

int main()
{
  cout << "enter number: ";

  int K = 0;
  cin >> K;

  for (int a = 0; a < K; a++)
  {
    for (int b = K; b >= a; b--)
    {
      cout << " ";
    }
    for (int b = 0; b <= a; b++)
    {
      cout << a;
    }
    for (int b = 0; b < a; b++)
    {
      cout << b;
    }
    cout << endl;
  }
}