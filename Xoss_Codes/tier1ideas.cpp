//same'ish' thing
for (int i = 0; i < n; i++); for (auto e : a);
//traverses full array and adds only those to t which m > e is true
t += max(m - e, 0LL); if (m > e) { t += m - e; }
//initializes all element of an array a with k
memset(a, 0, sizeof(a));
//iota function initializes elements with consecutive values, starting from k.
iota(a.begin(), a.end(), k);
//stable_sort maintains the relative order of equal elements during sorting.
stable_sort(a.begin(), a.end());
