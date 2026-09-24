#include <iostream>
#include <cstdlib>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
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