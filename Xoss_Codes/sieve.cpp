#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieveOfAtkin(int limit) {
    vector<bool> isPrime(limit + 1, false);
    vector<int> primes;

    // Sieve of Atkin implementation
    int sqrtLimit = sqrt(limit);
    for (int x = 1; x <= sqrtLimit; x++) {
        for (int y = 1; y <= sqrtLimit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                isPrime[n] = !isPrime[n];

            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                isPrime[n] = !isPrime[n];

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                isPrime[n] = !isPrime[n];
        }
    }

    for (int n = 5; n <= sqrtLimit; n++) {
        if (isPrime[n]) {
            int sqrN = n * n;
            for (int k = sqrN; k <= limit; k += sqrN)
                isPrime[k] = false;
        }
    }

    primes.push_back(2);
    primes.push_back(3);
    for (int i = 5; i <= limit; i += 2) {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

int main() {
    int limit;
    cout << "Enter the limit to find prime numbers up to: ";
    cin >> limit;

    vector<int> primes = sieveOfAtkin(limit);

    cout << "Prime numbers up to " << limit << " are:\n";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
