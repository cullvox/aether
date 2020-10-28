#ifndef __AERO_AETHER_H__
#define __AERO_AETHER_H__


#include <stdint.h>


#define DEG2RAD (3.141593f / 180)

/* TRIGONOMETRIC FUNCTIONS */
extern float aether_cos(float x);
extern float aether_sin(float x);
extern float aether_tan(float x);
extern float aether_acos(float x);
extern float aether_asin(float x);
extern float aether_atan(float x);
extern float aether_atan2(float x, float y);

/* HYPERBOLIC FUNCTIONS */
extern float aether_cosh(float x);
extern float aether_sinh(float x);
extern float aether_tanh(float x);
extern float aether_acosh(float x);
extern float aether_asinh(float x);
extern float aether_atanh(float x);

/* EXPONENTIAL AND LOGARITHMIC FUNCTIONS */
extern float aether_exp(float x);
extern float aether_exp2(float x);
extern float aether_log(float x); /* Computes with the natural log */
extern float aether_logb(float x, float base);
/* TODO: Add more functions that are on the standard */

/* POWER FUNCTIONS */
extern float aether_pow(float base, float exponent);
extern float aether_sqrt(float x); /* Square root */
extern float aether_cbrt(float x); /* Cubic root */


/* EXTRAS */
extern float aether_clamp(float x, float min, float max); /* Makes sure a float is within limits, returns clamped result */
extern float aether_normalize(float x, float min, float max); /* Normalizes a float between two numbers and scales it from 0 to 1 */

#define aether_max(left, right) (left > right ) ? left : right
#define aether_min(left, right) (left > right) ? right : left


/* VECTORS */
typedef int vec2i[2];
typedef float vec2f[2];

typedef int vec3i[3];
typedef float vec3f[3];

typedef int vec4i[4];
typedef float vec4f[4];


extern void vec2i_add(int* left, int* right, int* res);
extern void vec2f_add(float* left, float* right, float* res);

extern void vec2i_sub(int* left, int* right, int* res);
extern void vec2f_sub(float* left, float* right, float* res);

extern void vec2i_mul(int* left, int* right, int* res);
extern void vec2f_mul(float* left, float* right, float* res);

extern void vec2i_div(int* left, int* right, int* res);
extern void vec2f_div(float* left, float* right, float* res);


extern void vec3i_add(int* left, int* right, int* res);
extern void vec3f_add(float* left, float* right, float* res);

extern void vec3i_sub(int* left, int* right, int* res);
extern void vec3f_sub(float* left, float* right, float* res);

extern void vec3i_mul(int* left, int* right, int* res);
extern void vec3f_mul(float* left, float* right, float* res);

extern void vec3i_div(int* left, int* right, int* res);
extern void vec3f_div(float* left, float* right, float* res);


extern void vec4i_add(int* left, int* right, int* res);
extern void vec4f_add(float* left, float* right, float* res);

extern void vec4i_sub(int* left, int* right, int* res);
extern void vec4f_sub(float* left, float* right, float* res);

extern void vec4i_mul(int* left, int* right, int* res);
extern void vec4f_mul(float* left, float* right, float* res);

extern void vec4i_div(int* left, int* right, int* res);
extern void vec4f_div(float* left, float* right, float* res);


extern void vec3i_dot(int* left, int* right, int* res);
extern void vec3f_dot(float* left, float* right, float* res);

extern int vec3i_distance(int* x, int* y);
extern float vec3f_distance(float* x, float* y);

extern float vec3f_angle(float* first, float* second); /* Gets the angle between two vectors */

extern void vec4i_dot(int* left, int* right, int* res);
extern void vec4f_dot(float* left, float* right, float* res);



/* QUATERNIONS */
typedef float quatf[4];

extern void quatf_from_vec3f(float* vec, float a, float* res);



/* MATRIX */
typedef float mat3f[9];
typedef float mat4f[16];

extern void mat3f_add(float* left, float* right, float* res);
extern void mat3f_sub(float* left, float* right, float* res);
extern void mat3f_mul(float* left, float* right, float* res);
extern void mat3f_mul_scalar(float* left, float right, float* res);

extern void mat3f_getColumn(float* mat, int32_t column, float* res);
extern void mat3f_getRow(float* mat, int32_t row, float* res);
extern void mat3f_identity(float* res); /* resurns a basic matrix that can be used to do anything */
extern const char* mat3f_to_string(float* mat);


extern void mat4f_add(float* left, float* right, float* res);
extern void mat4f_sub(float* left, float* right, float* res);
extern void mat4f_mul(float* left, float* right, float* res);

extern void mat4f_getColumn(float* mat, int column, float* res);
extern void mat4f_getRow(float* mat, int row, float* res);
extern void mat4f_identity(float* res); /* resurns a basic matrix that can be used to do anything */
extern const char* mat4f_to_string(float* mat);

extern void mat4f_translate(float x, float y, float z, float* res);
extern void mat4f_rotate(float x, float y, float z, float angle, float* res);
extern void mat4f_rotate_x(float angle, float* res);
extern void mat4f_rotate_y(float angle, float* res);
extern void mat4f_rotate_z(float angle, float* res);
extern void mat4f_rotate_euler(float x, float y, float z, float* res);

extern void mat4f_frustum(float left, float right, float bottom, float top, float near, float far, float* res);
extern void mat4f_perspective(float fov_y, float aspect_ratio, float near, float far, float* res);
extern void mat4f_orthographic(float left, float right, float bottom, float top, float near, float far, float* res);


#endif /* __AERO_AETHER_H__ */