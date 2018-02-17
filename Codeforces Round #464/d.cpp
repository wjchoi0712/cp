/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];
int par[26];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < 26; i++) par[i] = i;
  vector<pair<int, int>> ans;
  int n;
  scanf("%d %s %s", &n, a, b);
  for (int i = 0; i < n; i++) {
    a[i] -= 'a';
    b[i] -= 'a';
    if (find(a[i]) != find(b[i])) {
      merge(a[i], b[i]);
      ans.emplace_back(a[i], b[i]);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%c %c\n", it.first + 'a', it.second + 'a');
  return 0;
}
