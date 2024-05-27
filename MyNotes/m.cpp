#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    for (int p = 2; p * p <= n; p += 1) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

vector<int> findDivisors(int num) {
    vector<int> divisors;
    vector<int> primes = sieve(num); // Generate primes up to num
    divisors.push_back(1); // 1 is always a divisor
    for (int i = 0; i < primes.size(); i++) {
        if (num % primes[i] == 0) {
            int currentSize = divisors.size();
            for (int j = 0; j < currentSize; j++) {
                int newDivisor = divisors[j] * primes[i];
                if (newDivisor <= num && num % newDivisor == 0) // Check if new divisor is valid
                    divisors.push_back(newDivisor);
            }
        }
    }
    divisors.push_back(num); // num is always a divisor of itself
    return divisors;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    vector<int> divisors = findDivisors(number);

    cout << "Divisors of " << number << " are: ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}

