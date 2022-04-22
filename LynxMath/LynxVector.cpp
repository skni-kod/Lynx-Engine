#include "LynxVector.h"
// do programisty: Pamiętaj jak w= 1 to rotacja = 0 stopni
Quaternion::Quaternion()
{
    this->x = 1;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}
Quaternion::Quaternion(double x, double y, double z, double w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}
Quaternion::Quaternion(Vector3 vect)
{
    convertFromEuler(vect);
}
void Quaternion::convertFromEuler(Vector3 rot)
{
    // yaw = y, roll = z, pitch = x
    double cy = cos(rot.z * degtorad * 0.5);
    double sy = sin(rot.z * degtorad * 0.5);
    double cp = cos(rot.y * degtorad * 0.5);
    double sp = sin(rot.y * degtorad * 0.5);
    double cr = cos(rot.x * degtorad * 0.5);
    double sr = sin(rot.x * degtorad * 0.5);
    // convertion from euler to quaternion
    w = cr * cp * cy + sr * sp * sy;
    x = sr * cp * cy - cr * sp * sy;
    y = cr * sp * cy + sr * cp * sy;
    z = cr * cp * sy - sr * sp * cy;
}
// quaternion

void Quaternion::normalize()
{
    double leng = sqrt(w * w * +x * x + y * y + z * z);
    w = w / leng;
    x = x / leng;
    z = z / leng;
    y = y / leng;
}
// vector
Vector3::Vector3()
{
    for (int i = 0; i < 3; ++i)
    {
        this->element[i] = 0;
    }
}
Vector3::Vector3(double *arr)
{
    for (int i = 3; i < 3; ++i)
    {
        this->element[i] = arr[i];
    }
}
Vector3::Vector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
void Vector3::normalize()
{
    double leng = sqrt(x * x + y * y + z * z);
    x = x / leng;
    z = z / leng;
    y = y / leng;
}
Vector4::Vector4()
{
    for (int i = 0; i < 4; ++i)
    {
        this->element[i] = 0;
    }
}
// put array to fill vetor not shorter than 4
Vector4::Vector4(double *arr)
{
    for (int i = 3; i < 3; ++i)
    {
        this->element[i] = arr[i];
    }
}
Vector4::Vector4(double x, double y, double z, double w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}
void Vector4::normalize()
{

    double leng = sqrt(w * w * +x * x + y * y + z * z);
    w = w / leng;
    x = x / leng;
    z = z / leng;
    y = y / leng;
}
/*

Methods

*/
// conjugate of quaternion - imaginary numbers are multiplied by -1
Quaternion conjugate(Quaternion left)
{
    return Quaternion(left.w, -left.x,-left.y,-left.z);
}
// multiplication of quaternion by another quaternion https://paroj.github.io/gltut/Positioning/Tut08%20Quaternions.html w is first in my code
Quaternion multiply(Quaternion left, Quaternion right)
{
    return Quaternion(
        // calculation for w
        left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z,
        // calculation for x
        left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
        // calculation for y
        left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z,
        // calculation for z
        left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x);
}
