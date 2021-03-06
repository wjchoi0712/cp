#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
string str = "RBYG";
map<char, int> mp;
int ans[4];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < str.size(); i++) mp[str[i]] = i;
  
  vector<int> isi;
  for (int i = 0; i < 4; i++) {
    int cnt = 0, all = 0;
    char c = ' ';
    for (int j = i; j < n; j += 4) {
      all++;
      if (s[j] != '!') {
        cnt++;
        c = s[j];
      }
    }    
    if (cnt == 0) {
      isi.push_back(all);
    } else {
      ans[mp[c]] = all - cnt;
    }
  }
  int j = 0;
  for (int i = 0; i < 4; i++) {
    if (ans[i] != -1) {
      printf("%d\n", ans[i]);
    } else {
      printf("%d\n", isi[j++]);
    }
  }
  return 0;
}
