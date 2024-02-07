int n;
int primes = n-1;
vb sieve(n+1, true);
sieve[0] = sieve[1] = false;

for (int i=2; i <= n; i++)
  if (sieve[i] && (ll)i*i <= n)
    for (int j=i*i; j <= n; j += i) {
      sieve[j] = false;
      primes--;  
    }
