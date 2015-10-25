#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
  int sz = 1000;
  bool cstyle = true;
  if (argc >= 2) sz = atoi(argv[1]);
  if (argc > 2 && strcmp(argv[2], "file") == 0) {
    cstyle = false;
  }
  
  vector<unordered_set<int> > v(sz);
  srand(time(0));
  int amount = 0;
  while (amount < sz) {
    int upper = min((int)ceil(rand()%((int)sqrt(sz))), (sz-amount));
    for (int i = 0; i < upper; i++) {
        int n = rand() % 5;
        for (int j = 0; j < n; j ++) {
          int nn = rand() % (upper);
          v[i+amount].insert(nn+amount);
          v[nn+amount].insert(i+amount);
        }
      }
    amount += upper;
  }
  
  for (int i = 0; i < sz; i++) {
    if (cstyle) cout << "User(" << i << ",{";
    else cout << i << " ";
    size_t ss = v[i].size();
    for (auto uu : v[i]) {
      cout << uu;
      if (--ss != 0) cout << ",";
    }
    if (cstyle) {
      cout << "})";
      if (i != sz-1) cout << ",";
    } else {
      cout << endl;
    }
    
  }
}