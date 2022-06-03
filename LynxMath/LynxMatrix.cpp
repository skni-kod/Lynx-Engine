#include "LynxMatrix.h"
//for test 
#include <iostream>
//not for test
Matrix3::Matrix3()
{
    for (int i; i < 9; ++i)
    {
        field[i] = 0;
    }
    field[0] = 1;
    field[4] = 1;
    field[8] = 1;
}
/* Matrix filled with variable*/
Matrix3::Matrix3(double *var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] = var[i];
    }
}
Matrix3::Matrix3(double &var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] = var;
    }
}
/* Columns filled with value of field of vector x -> 0, y -> 1, z->2*/
Matrix3::Matrix3(Vector3 &vect)
{

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            field[j * 3 + i] = vect[j];
        }
    }
}
/* Coppy matrix to this matrix */
Matrix3::Matrix3(Matrix3 *mat)
{
    for (int j = 0; j < 9; j++)
    {
        field[j] = mat->field[j];
    }
}
// methods
/* matrix scaled by vector x -> 0, y -> 1, z->2*/
void Matrix3::scale(Vector3 &vect)
{
    for (int i = 0; i < 3; ++i)
    {
        this->field[3 * i] *= vect[i];
        this->field[3 * i + 1] *= vect[i];
        this->field[3 * i + 2] *= vect[i];
    }
}
/* matrix scaled by variable */
void Matrix3::scale(double &var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] *= var;
    }
}
/* matrix multiplied */
void Matrix3::multiply(Matrix3 *mat)
{
    Matrix3 tmp(this->field);
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 3; ++i)
        {
            field[j * 3 + i] = tmp.field[i * 3] * mat->field[j] + tmp.field[i * 3 + 1] * mat->field[j + 3] + tmp.field[i * 3 + 2] * mat->field[j + 6];
        }
    }
}
/*add variable to each field of matrix */
void Matrix3::add(double var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] += var;
    }
}
/*add to matrix a vector x -> 0, y -> 1, z->2 */
void Matrix3::add(Vector3 &vect)
{
    for (int i = 0; i < 3; ++i)
    {
        this->field[3 * i] += vect[i];
        this->field[3 * i + 1] += vect[i];
        this->field[3 * i + 2] += vect[i];
    }
}
/*add matrix to matrix */
void Matrix3::add(Matrix3 *mat)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] += mat->field[i];
    }
}
/*matrix determinant */
double Matrix3::det()
{
    return field[0] * (field[4] * field[8] - field[7] * field[5]) - field[1] * (field[3] * field[8] - field[6] * field[5]) + field[2] * (field[3] * field[7] - field[6] * field[4]);
}
// operators
/*add matrix to matrix */
Matrix3 Matrix3::operator+(Matrix3 &right)
{
    Matrix3 tmp = this;
    for (int i = 0; i < 9; ++i)
    {
        tmp.field[i] += right.field[i];
    }
    return tmp;
}
/* multiplication */
Matrix3 Matrix3::operator*(Matrix3 &right)
{
    Matrix3 tmp;
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 3; ++i)
        {
            tmp.field[j * 3 + i] = field[i * 3] * right.field[j] + field[i * 3 + 1] * right.field[j + 3] + field[i * 3 + 2] * right.field[j + 6];
        }
    }

    return tmp;
}
Vector3 Matrix3::operator*(Vector3 &right)
{
    Vector3 tmp;
    for (int i = 0; i < 3; ++i)
    {
        tmp[i] = field[i * 3] * right[i] + field[i * 3 + 1] * right[i] + field[i * 3 + 2] * right[i];
    }

    return tmp;
}
Matrix3 Matrix3::operator*(double &right)
{
    Matrix3 tmp;
    for (int i = 0; i < 9; ++i)
    {

        tmp.field[i] = field[i] * right;
    }

    return tmp;
}
/*substraction  */
Matrix3 Matrix3::operator-(Matrix3 &right)
{
    Matrix3 tmp = this;
    for (int i = 0; i < 9; ++i)
    {
        tmp.field[i] -= right.field[i];
    }
    return tmp;
}
/*get value of index*/
Vector3 Matrix3::operator[](int x)
{
    Vector3 tmp = Vector3(field[x], field[3 + x], field[6 + x]);
    return tmp;
}

// matrix4
Matrix4::Matrix4()
{
    for (int i; i < 16; ++i)
    {
        field[i] = 0.0;
    }
    field[0] = 1;
    field[5] = 1;
    field[10] = 1;
    field[15] = 1;

}
// put an array to fill the matrix
Matrix4::Matrix4(double *var)
{
    for (int i = 0; i < 16; ++i)
    {
        field[i] = var[i];
    }
}
/* Matrix filled with variable*/
Matrix4::Matrix4(double &var)
{
    for (int i = 0; i < 16; ++i)
    {
        field[i] = var;
    }
}
/* Columns filled with value of field of vector x -> 0, y -> 1, z->2 w->3*/
Matrix4::Matrix4(Vector4 &vect)
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            field[j * 4 + i] = vect[j];
        }
    }
}
/* Coppy matrix to this matrix */
Matrix4::Matrix4(Matrix4 *mat)
{
    for (int j = 0; j < 16; j++)
    {
        field[j] = mat->field[j];
    }
}
Matrix4::~Matrix4(){

}
/* matrix scaled by vector x -> 0, y -> 1, z->2 w->3*/
void Matrix4::scale(Vector4 &vect)
{
    for (int i = 0; i < 4; ++i)
    {
        this->field[3 * i] *= vect[i];
        this->field[3 * i + 1] *= vect[i];
        this->field[3 * i + 2] *= vect[i];
        this->field[3 * i + 3] *= vect[i];
    }
}
/* matrix scaled by variable */
void Matrix4::scale(double &var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] *= var;
    }
}
/* matrix multiplied times matrix */
void Matrix4::multiply(Matrix4 *mat)
{
}
/*add variable to each field of matrix */
void Matrix4::add(double var)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] += var;
    }
}
/*add to matrix a vector x -> 0, y -> 1, z->2 */
void Matrix4::add(Vector4 &vect)
{
    for (int i = 0; i < 3; ++i)
    {
        this->field[3 * i] += vect[i];
        this->field[3 * i + 1] += vect[i];
        this->field[3 * i + 2] += vect[i];
    }
}
/*add matrix to4 matrix */
void Matrix4::add(Matrix4 *mat)
{
    for (int i = 0; i < 9; ++i)
    {
        field[i] += mat->field[i];
    }
}
// to do
/*matrix determinant */
double Matrix4::det()
{
    return field[0] * (field[4] * field[8] - field[7] * field[5]) - field[1] * (field[3] * field[8] - field[6] * field[5]) + field[2] * (field[3] * field[7] - field[6] * field[4]);
}

// operators
/*add matrix to matrix */
Matrix4 Matrix4::operator+(Matrix4 &right)
{
    Matrix4 tmp = this;
    for (int i = 0; i < 16; ++i)
    {
        tmp.field[i] += right.field[i];
    }
    return tmp;
}
/*Multiplication*/
Matrix4 Matrix4::operator*(Matrix4 right)
{
    Matrix4 tmp;
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            tmp.field[j * 4 + i] = field[i * 4] * right.field[j] + field[i * 4 + 1] * right.field[j + 4] + field[i * 4 + 2] * right.field[j + 8] + field[i * 4 + 3] * right.field[j + 12];
        }
    }

    return tmp;
}
Matrix4 Matrix4::operator*(Matrix4 *right)
{
        Matrix4 tmp;
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            tmp.field[j * 4 + i] = field[i * 4] * right->field[j] + field[i * 4 + 1] * right->field[j + 4] + field[i * 4 + 2] * right->field[j + 8] + field[i * 4 + 3] * right->field[j + 12];
        }
    }

    return tmp;
}
Matrix4& Matrix4::operator*=(Matrix4 *right)
{
    Matrix4 tmp;
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            tmp.field[j * 4 + i] = field[i * 4] * right->field[j] + field[i * 4 + 1] * right->field[j + 4] + field[i * 4 + 2] * right->field[j + 8] + field[i * 4 + 3] * right->field[j + 12];
        }
    }
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
        field[j * 4 + i] =  tmp.field[j * 4 + i];
        }
    }
    return *this;
}
Vector4 operator*(Matrix4 *left, Vector4 right)
{
    Vector4 tmp;
    for (int i = 0; i < 4; ++i)
    {
        tmp[i] = left->field[i * 4] * right.x + left->field[i * 4 + 1] * right.y + left->field[i * 4 + 2] * right.z + left->field[i * 4 + 3] * right.w;
    }

    return tmp;
}

Matrix4 Matrix4::operator*(double right)
{
    Matrix4 tmp;
    for (int i = 0; i < 16; ++i)
    {

        tmp.field[i] = field[i] * right;
    }

    return tmp;
}
/*substraction  */
Matrix4 Matrix4::operator-(Matrix4 &right)
{
    Matrix4 tmp = this;
    for (int i = 0; i < 9; ++i)
    {
        tmp.field[i] -= right.field[i];
    }
    return tmp;
}
/*get value of index*/
Vector4 Matrix4::operator[](int x)
{
    Vector4 tmp = Vector4(field[x], field[4 + x], field[8 + x], field[12 + x]);
    return tmp;
}

/* 

Transformation matrixes

*/
Transform::Transform() 
{
    rotation = Quaternion(Vector3(0,0,0));
    fScale = Vector3(0,0,0);
    position = Vector3(0,0,0);

}
Transform::Transform(Vector3 pos, Vector3 rot, Vector3 sca) : Matrix4()
{
    rotation = Quaternion(rot); 
    fScale = Vector3(sca.x, sca.y, sca.z);
    position = pos;
}
Transform::Transform(Vector3 pos)
{
    rotation = Quaternion(Vector3(0,0,0));
    fScale = Vector3(1,1,1);
    position = pos;
}
Transform::~Transform() 
{

}
void Transform::setRotation(Vector3 rot)
{
    this->rotation = Quaternion(rot);
}
void Transform::rotate(Vector3 rot)
{
    this->rotation*=Quaternion(rot);
}
Quaternion Transform::getRotation()
{
    return this->rotation;
}

void Transform::scale(Vector3 sc)
{

    this->fScale = fScale+sc;
}
void Transform::setScale(Vector3 sc)
{
    this->fScale = sc;
}
Vector3 Transform::getScale()
{
 return this->fScale;
}
void Transform::Repostion(Vector3 trans){
    position = position+trans;
}
void Transform::setPostion(Vector3 trans){
    position = trans;
}
Vector3 Transform::getPosition(){
    return this->position;
}

//to get transform matrix you need to call this function and use returned pointer. I think its faster 
Matrix4* Transform::createTranMatrix()
{
    this->field[0] = this->fScale.x *(1-2* rotation.y*rotation.y-2*rotation.z*rotation.z);
    this->field[4] = this->fScale.x *(2* rotation.x*rotation.y-2*rotation.z*rotation.w);
    this->field[8] = this->fScale.x *(2* rotation.x*rotation.z+2*rotation.y*rotation.w);

    this->field[1] = this->fScale.y *(2* rotation.x*rotation.y+2*rotation.z*rotation.w);
    this->field[5] = this->fScale.y *(1-2* rotation.x*rotation.x-2*rotation.z*rotation.z);
    this->field[9] = this->fScale.y *(2* rotation.y*rotation.z-2*rotation.x*rotation.w);

    this->field[2] = this->fScale.z *(2* rotation.x*rotation.z-2*rotation.y*rotation.w);
    this->field[6] = this->fScale.z *(2* rotation.y*rotation.z+2*rotation.x*rotation.w);
    this->field[10] =this->fScale.z *(1-2* rotation.x*rotation.x-2*rotation.y*rotation.y);

    this->field[3] = position.x;
    this->field[7] = position.y;
    this->field[11] = position.z;
    return dynamic_cast<Matrix4*>(this);
}

/*
Quaterion to transf matrix
https://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/geometric/orthogonal/index.htm   
https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/index.htm
https://sound.eti.pg.gda.pl/student/so/02-Transformacje.pdf
*/