#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --) 
    {
       int n, x;
       cin >> n >> x;
       
       vector<int> a(n); 
       for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());
        
        int v = 1;
        for (int place : a){
            if (place == v) {
                v++;
            } else if (place > v)
            {
                int gap = place - v;
                if (x >= gap){
                    x -= gap;
                    v= place + 1;
                } else {v += x;
                x=0;
            break;}
            }
            



        }
    
        v += x;
        cout << v- 1 << endl;
    }
    

    return 0;

}

