#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  //one needs to be sorted ascending and the other descending in order to get the smallest product
  vector<long long> v1, v2;
  //t - number of test cases, n - count of numbers in each vector
  int t, n;
  long long tempNumber, sum;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    sum = 0;
    v1.clear();
    v2.clear();
    cin >> n;
    for (size_t j = 0; j < n; j++)
    {
      cin >> tempNumber;
      v1.push_back(tempNumber);
    }
    sort(v1.begin(), v1.end());
    for (size_t j = 0; j < n; j++)
    {
      cin >> tempNumber;
      v2.push_back(tempNumber);
    }
    sort(v2.begin(), v2.end(), greater<int>());
    //calculating the product
    for (size_t j = 0; j < n; j++)
    {
      sum += v1[j] * v2[j];
    }
    cout << "Case #" << i + 1 << ": " << sum << endl;
  }
  return 0;
}
