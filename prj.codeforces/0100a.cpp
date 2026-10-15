#include <iostream>
#include <cstdlib>

int main() {
    
    int n, k, n1;
    std::cin >> n >> k >> n1;
    int need = (n + n1 - 1) / n1;
    
    if (k >= need * need) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}