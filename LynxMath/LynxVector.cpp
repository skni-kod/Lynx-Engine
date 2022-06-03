#include "LynxVector.h"
// conjugate of quaternion - imaginary numbers are multiplied by -1
Quaternion conjugate(Quaternion left)
{
    return Quaternion(-left.x, -left.y, -left.z,left.w);
}
// multiplication of quaternion by another quaternion https://paroj.github.io/gltut/Positioning/Tut08%20Quaternions.html w is first in my code
Vector4 multiply(Quaternion left, Quaternion right)
{
    return Vector4(
        // calculation for x
        left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
        // calculation for y
        left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z,
        // calculation for z
        left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x,
        // calculation for w
        left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z);
}
Vector4 multiply(Quaternion left, Vector4 right)
{
    return Vector4(
        // calculation for x
        left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
        // calculation for y
        left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z,
        // calculation for z
        left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x,
        // calculation for w
        left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z);
}
Vector4 multiply(Vector4 left, Quaternion right)
{
    return Vector4(
      

        // calculation for x
        left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
        // calculation for y
        left.w * right.y + left.y * right.w + left.z * right.x - left.x * right.z,
        // calculation for z
        left.w * right.z + left.z * right.w + left.x * right.y - left.y * right.x,
        // calculation for w
        left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z);
}

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
    if(!x && !y && !z)
    {
        x =1;
    }
    else{
        double leng = sqrt(x * x + y * y + z * z +w*w);
    x = x / leng;
    z = z / leng;
    y = y / leng;
    w = w / leng;
    }
    

}
Vector3 Quaternion::operator*(Vector3 right)
{
    Vector4 tmp = multiply(multiply(Quaternion(x, y, z, w), Vector4(right)), conjugate(Quaternion(x, y, z, w)));
    return tmp.vec3();
}

Quaternion Quaternion::operator*(Quaternion right)
{

    return Quaternion(   
     w * right.x + x * right.w + y * right.z - z * right.y,
    // cation for y
     w * right.y + x * right.z + y * right.w - z * right.x,
    // cation for z
     w * right.z + z * right.w - x * right.y + y * right.x,
     w * right.w - x * right.x - y * right.y - z * right.z);
}

Quaternion& Quaternion::operator*=(Quaternion right)
{
    Quaternion tmp = Quaternion(this->x,this->y, this->z, this->w);
    w = tmp.w * right.w - tmp.x * right.x - tmp.y * right.y - tmp.z * right.z;
    // cation for xt.
    x = tmp.w * right.x + tmp.x * right.w + tmp.y * right.z - tmp.z * right.y;
    // cation for y
    y = tmp.w * right.y + tmp.x * right.z + tmp.y * right.w - tmp.z * right.x;
    // cation for z
    z = tmp.w * right.z + tmp.z * right.w - tmp.x * right.y + tmp.y * right.x;
    return *this;
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
    if(leng == 0)
    {
        x = 0;
        y = 0;
        z = 0;
    }
    else{
        x = x / leng;
        z = z / leng;
        y = y / leng;
    }
}
Vector3 Vector3::operator+(Vector3 right)
{
    return Vector3(x + right.x, y + right.y, z + right.z);
}
Vector3 Vector3::cross(Vector3 right)
{
    return Vector3(
        y*right.z-z*right.y,
        z*right.x-x*right.z,
        x*right.y-y*right.x
    );
}
Vector4::Vector4(Vector3 vec)
{
    x= vec.x;
    y=vec.y;
    z=vec.z;
    w = 0;
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
Vector3 Vector4::vec3()
{
    return Vector3(x, y, z);
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
