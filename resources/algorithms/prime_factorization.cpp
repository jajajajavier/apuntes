map<int, int> factorization(int n) {
  map<int, int> fact;
  for (int i=2; i*i <= n; i++)
    while (n % i == 0) {
      fact[i] += 1;
      n /= i;
    }
  if (n > 1)
    fact[n] += 1;
  return fact;
}
