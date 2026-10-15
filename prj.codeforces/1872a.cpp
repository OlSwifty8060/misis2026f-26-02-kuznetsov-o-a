#include <iostream>

int main() {
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int diff = std::abs(a - b);
        int ans = (diff + 2 * c - 1) / (2 * c);
        
        std::cout << ans << '\n';
    }
    
    return 0;
}