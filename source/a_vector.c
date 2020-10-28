#include "aether/aether.h"

void vec2i_add(int* left, int* right, int* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] + right[i];

}

void vec2f_add(float* left, float* right, float* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] + right[i];

}


void vec2i_sub(int* left, int* right, int* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] - right[i];

}

void vec2f_sub(float* left, float* right, float* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] - right[i];

}


void vec2i_mul(int* left, int* right, int* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] * right[i];

}

void vec2f_mul(float* left, float* right, float* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] * right[i];

}


void vec2i_div(int* left, int* right, int* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] / right[i];

}

void vec2f_div(float* left, float* right, float* res)
{

    for(int i = 0; i < 2; i++)
        res[i] = left[i] / right[i];

}


    
void vec3i_add(int* left, int* right, int* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] + right[i];

}

void vec3f_add(float* left, float* right, float* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] + right[i];

}


void vec3i_sub(int* left, int* right, int* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] - right[i];

}

void vec3f_sub(float* left, float* right, float* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] - right[i];

}


void vec3i_mul(int* left, int* right, int* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] * right[i];

}

void vec3f_mul(float* left, float* right, float* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] * right[i];

}


void vec3i_div(int* left, int* right, int* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] / right[i];

}

void vec3f_div(float* left, float* right, float* res)
{

    for(int i = 0; i < 3; i++)
        res[i] = left[i] / right[i];

}



void vec4i_add(int* left, int* right, int* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] + right[i];

}

void vec4f_add(float* left, float* right, float* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] + right[i];

}


void vec4i_sub(int* left, int* right, int* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] - right[i];

}

void vec4f_sub(float* left, float* right, float* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] - right[i];

}


void vec4i_mul(int* left, int* right, int* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] * right[i];

}

void vec4f_mul(float* left, float* right, float* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] * right[i];

}


void vec4i_div(int* left, int* right, int* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] / right[i];

}

void vec4f_div(float* left, float* right, float* res)
{

    for(int i = 0; i < 4; i++)
        res[i] = left[i] / right[i];

}



void vec3i_dot(int* left, int* right, int* res)
{
    *res = (left[0] * right[0]) + (left[1] * right[1]) + (left[2] * right[2]);
}

void vec3f_dot(float* left, float* right, float* res)
{
    *res = (left[0] * right[0]) + (left[1] * right[1]) + (left[2] * right[2]);
}


int vec3i_distance(int* x, int* y)
{

    /* sqrt((x2 - x1)^{2} + (y2-y1)^{2} + (z2-z1)^{2}) */
    return (int)aether_sqrt( aether_pow((float)y[0] - (float)x[0], 2) + aether_pow((float)y[1] - (float)x[1], 2) + aether_pow((float)y[2] - (float)x[2], 2) );

}

float vec3f_distance(float* x, float* y)
{
/* sqrt((x2 - x1)^{2} + (y2-y1)^{2} + (z2-z1)^{2}) */
    return aether_sqrt( aether_pow(y[0] - x[0], 2) + aether_pow(y[1] - x[1], 2) + aether_pow(y[2] - x[2], 2) );
}


float vec3f_angle(float* first, float* second)
{
    return aether_acos((first[0] * second[0]) + (first[1] * second[1]) + (first[2] * second[2])) / (aether_sqrt(aether_pow(first[0], 2) + aether_pow(first[1], 2) + aether_pow(first[0], 2)) * aether_sqrt(aether_pow(second[0], 2) + aether_pow(second[1], 2) + aether_pow(second[0], 2)));
}

void vec4i_dot(int* left, int* right, int* res)
{
    *res = (left[0] * right[0]) + (left[1] * right[1]) + (left[2] * right[2]) + (left[3] * right[3]);
}

void vec4f_dot(float* left, float* right, float* res)
{
    *res = (left[0] * right[0]) + (left[1] * right[1]) + (left[2] * right[2]) + (left[3] * right[3]);
}