#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    const unsigned charCount = 'z' - 'a' + 1;
    vector<unsigned> charMap1(charCount), charMap2(charCount);
    auto prev = &charMap1, current = &charMap2;
    bool ok;

    unsigned t, n;
    string line;

    cin >> t;
    while (t-- > 0) {

        ok = true;
        cin >> n;

        if (n-- > 0) {
            cin >> line;
            
            std::fill(current->begin(), current->end(), 0);
            for (auto c : line) (*current)[c - 'a']++;
        }

        while (n-- > 0) {
            cin >> line;
            if (ok) {
                swap(current, prev);
                
                std::fill(current->begin(), current->end(), 0);
                for (auto c : line) (*current)[c - 'a']++;
                
                for (unsigned i = 0, sumPrev = 0, sumCurrent = 0; 
                        i < charCount; i++) {
                    sumCurrent += (*current)[i];
                    sumPrev += (*prev)[i];
                    if (sumPrev < sumCurrent) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}