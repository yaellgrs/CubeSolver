
#include "Utility/Utility.h"

#include <stdexcept>

int puissance(int x, int exposant) {
    if (exposant == 0) {
        return 1;
    }
    int tmp = puissance(x, exposant / 2);
    if (exposant % 2 == 0) {
        return tmp * tmp;
    }
    return x * tmp * tmp;

}


int factorielle(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorielle(n-1);
}


std::vector<std::vector<int>> triangle_pascal(int n, int k) { //construit de le triangle de 0 à n et de 0 a k
    std::vector<std::vector<int>> resultat;
    if (k > n) {
        throw std::invalid_argument("k ne peut pas être plus grand que n");
    }

    for (int i = 0; i <= n; i++) {
        resultat.push_back({});
        for (int j = 0; j <= i; j++) {
            if ( j > k) {
                break;
            }
            resultat[i].push_back((factorielle(i) / (factorielle(j) * factorielle(i - j))));
        }
    }
    return resultat;

}