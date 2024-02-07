// se asume un array ordenado a[n]
// x = el elemento a buscar

int l=0, m, r=n-1;
while (l <= r) {
  m = (l + r) / 2;
  if (a[m] > x ) r = m-1;
  else l = m+1
}

int l=0;
for (int m=n/2; m >= 1; m /= 2)
  while (l+m < n && a[l+m] <= x)
    l += m;
