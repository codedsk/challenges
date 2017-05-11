// http://floating-point-gui.de/errors/comparison/

#include <stdlib.h>
#include <float.h>
#include <math.h>

bool nearlyEqual(float a, float b, float epsilon) {
    float absA = fabsf(a);
    float absB = fabsf(b);
    float diff = fabsf(a - b);

    if (a == b) {
        // shortcut, handles infinities
        return true;
    } else if (a == 0 || b == 0 || diff < FLT_EPSILON) {
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < epsilon;
    } else {
        // use relative error
        return (diff / fminf((absA + absB), FLT_MAX)) < epsilon;
    }
}
