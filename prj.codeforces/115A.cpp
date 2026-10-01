#include <iostream>

int main() {
  
    int n;
    std::cin >> n;
    
    int p[2005];
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = i;
        int depth = 0;
        
        while (cur != -1) {
            ++depth;
            cur = p[cur];
        }
        
        if (depth > ans) ans = depth;
    }
    
    std::cout << ans << '\n';
    return 0;
}