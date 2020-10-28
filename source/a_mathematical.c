#include "aether/aether.h"

#include "math.h"


float aether_cos(float x)
{
    return cosf(x);
}

float aether_sin(float x)
{
    return sinf(x);
}

float aether_tan(float x)
{
    return tanf(x);
}

float aether_acos(float x)
{
    return acosf(x);
}

float aether_asin(float x)
{
    return asinf(x);
}

float aether_atan(float x)
{
    return atanf(x);
}

float aether_atan2(float x, float y)
{
    return atan2f(x, y);
}


float aether_cosh(float x)
{
    return coshf(x);
}

float aether_sinh(float x)
{
    return sinhf(x);
}  

float aether_tanh(float x)
{
    return tanhf(x);
}

float aether_acosh(float x)
{
    return acoshf(x);
}

float aether_asinh(float x)
{
    return asinf(x);
}

float aether_atanh(float x)
{
    return atanhf(x);
}



float aether_exp(float x)
{
    return expf(x);
}

float aether_exp2(float x)
{
    return exp2f(x);
}

float aether_log(float x)
{
    return logf(x);
}

float aether_logb(float x, float base)
{
    return aether_log(x) / aether_log(base);
}


float aether_pow(float base, float exponent)
{
    return powf(base, exponent);
}

float aether_sqrt(float x)
{
    return sqrtf(x);
}

float aether_cbrt(float x)
{
    return cbrtf(x);
}


/* https://stackoverflow.com/a/16659263
    Very simple and provides very simple assembly, completly branchless
*/
float aether_clamp(float x, float min, float max)
{
    const float t = x  < min ? min : x;
    return t > max ? max : t;
}

/* http://answers.unity.com/answers/275649/view.html 
    Another simple function that can be very useful
*/
float aether_normalize(float x, float min, float max)
{
    return ((x - min) / (max - min));
}