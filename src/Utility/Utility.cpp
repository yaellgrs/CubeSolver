
#include "Utility/Utility.h"

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
