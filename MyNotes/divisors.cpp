#include <iostream>
#include <vector>
using namespace std;

// Function to find all prime divisors of a number
vector<int> findPrimeDivisors(int n) {
    vector<int> primeDivisors;
    // Find all 2's that divide n
    while (n % 2 == 0) {
        primeDivisors.push_back(2);
        n /= 2;
    }
    // n must be odd at this point, so we can skip one element (i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, append i and divide n
        while (n % i == 0) {
            primeDivisors.push_back(i);
            n /= i;
        }
    }
    // If n is a prime greater than 2
    if (n > 2)
        primeDivisors.push_back(n);
    return primeDivisors;
}

// Function to find all divisors of a number using prime divisors
vector<int> findDivisors(int n) {
    vector<int> primeDivisors = findPrimeDivisors(n);
    vector<int> divisors;
    // Start with 1 as a divisor
    divisors.push_back(1);
    int numDivisors = primeDivisors.size();
    // Generate divisors by multiplying combinations of prime divisors
    for (int i = 0; i < (1 << numDivisors); i++) {
        int divisor = 1;
        for (int j = 0; j < numDivisors; j++) {
            if (i & (1 << j)) {
                divisor *= primeDivisors[j];
            }
        }
        divisors.push_back(divisor);
    }
    return divisors;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    set<int> divisors = findDivisors(num);
    cout << "Divisors of " << num << " are:\n";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;
    return 0;
}
