#include "aether/aether.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"


void mat3f_add(float* left, float* right, float* res)
{
    
    /*
        Matrix Addition
            Matxix addition is just adding the matrix values
    */


    for(int i = 0; i < 9; i++)
    {
        res[i] = left[i] + right[i];
    }

}

void mat3f_sub(float* left, float* right, float* res)
{

    /*
        Matrix Subtraction
            Matxix subtraction is just subtracting the matrix values
    */

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            res[i + j] = left[i + j] - right[i + j];
        }
    }

}

void mat3f_mul(float* left, float* right, float* res)
{

/* 
    Matrix Multiplication

        Take the dot product of the left column by the right row
                
                
        [ 7, 4, 9 ]     [ 1, 3, 5 ]         [ 65, 72, 106 ]
        [ 3, 3, 2 ]  *  [ 1, 6, 2 ]    =    [ 18, 33, 35 ]
        [ 4, 3, 6 ]     [ 6, 3, 7 ]         [ 43, 48, 68 ]

        [ (7 * 1) + (4 * 1) + (9 * 6), (7 * 3) + (4 * 6) + (9 * 3), (7 * 5) + (4 * 2) + (9 * 7) ] 
        [ (3 * 1) + (3 * 1) + (2 * 6), (3 * 3) + (3 * 6) + (2 * 3), (3 * 5) + (3 * 2) + (2  * 7) ] 
        [ (4 * 1) + (3 * 1) + (6 * 6), (4 * 3) + (3 * 6) + (6 * 3), (4 * 5) + (3 * 2) + (6 * 7)]
*/

    for(int i = 0; i < 3; i++)
    {
        vec3f row;
        mat3f_getRow(left, i, row);

        for(int j = 0; j < 3; j++)
        {
            vec3f column;
            mat3f_getColumn(right, j, column);

            vec3f_dot(row, column, &res[(i * 3) + j]);
        }
    }

}

void mat3f_mul_scalar(float* left, float right, float* res)
{

/*
    Matrix Scalar Multipication
        Multiplying matrix values across with the scalar value
*/

    for(int i = 0; i < 9; i++)
    {
        res[i] = left[i] * right;
    }

}

void mat3f_getColumn(float* mat, int32_t column, float* res)
{

/*
    0 1 2
    3 4 5
    6 7 8
*/

    int column_first = column;

    res[0] = mat[column_first + 0];
    res[1] = mat[column_first + 3];
    res[2] = mat[column_first + 6];

}

void mat3f_getRow(float* mat, int32_t row, float* res)
{

/*
    0 1 2
    3 4 5
    6 7 8
*/

    int row_first = (row * 3);

    res[0] = mat[row_first + 0];
    res[1] = mat[row_first + 1]; 
    res[2] = mat[row_first + 2];

}

void mat3f_identity(float* res)
{

    res[0] = 1;
    res[1] = 0;
    res[2] = 0;
    res[3] = 0;
    res[4] = 1;
    res[5] = 0;
    res[6] = 0;
    res[7] = 0;
    res[8] = 1;

}

#define MATRIX_STRING_MAX_DECIMALS 14

const char* mat3f_to_string(float* mat)
{

    char* res = malloc((sizeof(char) * MATRIX_STRING_MAX_DECIMALS) * 9);
    aero_memset(res, MATRIX_STRING_MAX_DECIMALS * 9, '\0');

    for(int i = 0; i < 9; i++)
    {
        
        snprintf(res, MATRIX_STRING_MAX_DECIMALS, "%f%s ", mat[i], ((i % 3) == 0) ? ", \n\0" : ", \0");

    }

    return res;

}


void mat4f_add(float* left, float* right, float* res)
{
    for(int i = 0; i < 16; i++)
    {
        res[i] = left[i] + right[i];
    }
}

void mat4f_sub(float* left, float* right, float* res)
{
    for(int i = 0; i < 16; i++)
    {
        res[i] = left[i] - right[i];
    }
}

void mat4f_mul(float* left, float* right, float* res)
{
    mat4f temp = { 0 };
    aero_memcpy(temp, sizeof(mat4f), res, sizeof(mat4f));

    for(int i = 0; i < 4; i++)
    {
        vec4f row;
        mat4f_getRow(left, i, row);

        for(int j = 0; j < 4; j++)
        {
            vec4f column;
            mat4f_getColumn(right, j, column);

            vec4f_dot(row, column, &temp[(i * 4) + j]);
        }
    }

    aero_memcpy(res, sizeof(mat4f), temp, sizeof(mat4f));
}

void mat4f_getColumn(float* mat, int column, float* res)
{
    res[0] = mat[column + 0];
    res[1] = mat[column + 4];
    res[2] = mat[column + 8];
    res[3] = mat[column + 12];
}

void mat4f_getRow(float* mat, int row, float* res)
{
    res[0] = mat[(row * 4) + 0];
    res[1] = mat[(row * 4) + 1];
    res[2] = mat[(row * 4) + 2];
    res[3] = mat[(row * 4) + 3];
}

void mat4f_identity(float* res)
{
    res[0] = 1;
    res[1] = 0;
    res[2] = 0;
    res[3] = 0;
    res[4] = 0;
    res[5] = 1;
    res[6] = 0;
    res[7] = 0;
    res[8] = 0;
    res[9] = 0;
    res[10] = 1;
    res[11] = 0;
    res[12] = 0;
    res[13] = 0;
    res[14] = 0;
    res[15] = 1;
}

const char* mat4f_to_string(float* mat)
{
    char* res = malloc((sizeof(char) * MATRIX_STRING_MAX_DECIMALS) * 16);
    aero_memset(res, MATRIX_STRING_MAX_DECIMALS * 16, '\0');

    for(int i = 0; i < 16; i++)
    {
        
        snprintf(res, MATRIX_STRING_MAX_DECIMALS, "%f%s ", mat[i], ((i % 4) == 0) ? ", \n\0" : ", \0");

    }

    return res;
}

void mat4f_translate(float x, float y, float z, float* res)
{
    mat4f temp = { 0 };
    aero_memcpy(temp, sizeof(mat4f), res, sizeof(mat4f));

    temp[0] += res[3] * x; temp[4] += res[7] * x; temp[8] += res[11] * x; temp[12] += res[15] * x;
    temp[1] += res[3] * y; temp[5] += res[7] * y; temp[9] += res[11] * y; temp[13] += res[15] * y;
    temp[2] += res[3] * z; temp[6] += res[7] * z; temp[10] += res[11] * z; temp[14] += res[15] * z;
        
    aero_memcpy(res, sizeof(mat4f), temp, sizeof(mat4f));
}

void mat4f_rotate(float x, float y, float z, float angle, float* res)
{
    float c = aether_cos(angle * DEG2RAD);
    float s = aether_sin(angle * DEG2RAD);
    float c1 = 1.0f - c;
        float m0 = res[0],  m4 = res[4],  m8 = res[8],  m12= res[12],
              m1 = res[1],  m5 = res[5],  m9 = res[9],  m13= res[13],
              m2 = res[2],  m6 = res[6],  m10= res[10], m14= res[14];

    // build rotation matrix
    float r0 = x * x * c1 + c;
    float r1 = x * y * c1 + z * s;
    float r2 = x * z * c1 - y * s;
    float r4 = x * y * c1 - z * s;
    float r5 = y * y * c1 + c;
    float r6 = y * z * c1 + x * s;
    float r8 = x * z * c1 + y * s;
    float r9 = y * z * c1 - x * s;
    float r10= z * z * c1 + c;

    // multiply rotation matrix
    res[0] = r0 * m0 + r4 * m1 + r8 * m2;
    res[1] = r1 * m0 + r5 * m1 + r9 * m2;
    res[2] = r2 * m0 + r6 * m1 + r10* m2;
    res[4] = r0 * m4 + r4 * m5 + r8 * m6;
    res[5] = r1 * m4 + r5 * m5 + r9 * m6;
    res[6] = r2 * m4 + r6 * m5 + r10* m6;
    res[8] = r0 * m8 + r4 * m9 + r8 * m10;
    res[9] = r1 * m8 + r5 * m9 + r9 * m10;
    res[10]= r2 * m8 + r6 * m9 + r10* m10;
    res[12]= r0 * m12+ r4 * m13+ r8 * m14;
    res[13]= r1 * m12+ r5 * m13+ r9 * m14;
    res[14]= r2 * m12+ r6 * m13+ r10* m14;
}

void mat4f_rotate_x(float angle, float* res)
{
    float c = aether_cos(angle * DEG2RAD);
    float s = aether_sin(angle * DEG2RAD);
    float m1 = res[1],  m2 = res[2],
          m5 = res[5],  m6 = res[6],
          m9 = res[9],  m10= res[10],
          m13= res[13], m14= res[14];

    res[1] = m1 * c + m2 *-s;
    res[2] = m1 * s + m2 * c;
    res[5] = m5 * c + m6 *-s;
    res[6] = m5 * s + m6 * c;
    res[9] = m9 * c + m10*-s;
    res[10]= m9 * s + m10* c;
    res[13]= m13* c + m14*-s;
    res[14]= m13* s + m14* c;
}

void mat4f_rotate_y(float angle, float* res)
{
    float c = aether_cos(angle * DEG2RAD);
    float s = aether_sin(angle * DEG2RAD);
    float m0 = res[0],  m2 = res[2],
          m4 = res[4],  m6 = res[6],
          m8 = res[8],  m10= res[10],
          m12= res[12], m14= res[14];

    res[0] = m0 * c + m2 * s;
    res[2] = m0 *-s + m2 * c;
    res[4] = m4 * c + m6 * s;
    res[6] = m4 *-s + m6 * c;
    res[8] = m8 * c + m10* s;
    res[10]= m8 *-s + m10* c;
    res[12]= m12* c + m14* s;
    res[14]= m12*-s + m14* c;
}

void mat4f_rotate_z(float angle, float* res)
{
    float c = aether_cos(angle * DEG2RAD);
    float s = aether_sin(angle * DEG2RAD);
    float m0 = res[0],  m1 = res[1],
          m4 = res[4],  m5 = res[5],
          m8 = res[8],  m9 = res[9],
          m12= res[12], m13= res[13];

    res[0] = m0 * c + m1 *-s;
    res[1] = m0 * s + m1 * c;
    res[4] = m4 * c + m5 *-s;
    res[5] = m4 * s + m5 * c;
    res[8] = m8 * c + m9 *-s;
    res[9] = m8 * s + m9 * c;
    res[12]= m12* c + m13*-s;
    res[13]= m12* s + m13* c;
}

void mat4f_rotate_euler(float x, float y, float z, float* res)
{
    mat4f_rotate_x(x, res);
    mat4f_rotate_y(y, res);
    mat4f_rotate_z(z, res);
}


void mat4f_frustum(float left, float right, float bottom, float top, float near, float far, float* res)
{
    res[0] = 2 * near / (right - left);
    res[5] = 2 * near / (top - bottom);
    res[8] = (right + left) / (right - left);
    res[9] = (top + bottom) / (top - bottom);
    res[10] = -(far + near) / (far - near);
    res[11] = -1;
    res[14] = -(2 * far * near) / (far - near);
    res[15] = 0;
}

void mat4f_perspective(float fov_y, float aspect_ratio, float near, float far, float* res)
{
    float tangent = aether_tan(fov_y / 2 * DEG2RAD);
    float height = near * tangent;
    float width = height * aspect_ratio;

    mat4f_frustum(-width, width, -height, height, near, far, res);
}

void mat4f_orthographic(float left, float right, float bottom, float top, float near, float far, float* res)
{
    res[0] = 2 / (right - left);
    res[5] = 2 / (top - bottom);
    res[10] = -2 / (far - near);
    res[12] = -(right + left) / (right - left);
    res[13] = -(top  + bottom) / (top - bottom);
    res[14] = -(far + near) / (far - near);
}

