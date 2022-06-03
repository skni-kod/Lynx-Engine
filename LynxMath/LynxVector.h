#pragma once
#include <math.h>
#define degtorad  0.01745329251994329576923690768489f // its equal pi/180

  
union Vector2
{
    struct
    {
        double x, y;
    };
    struct
    {
        double width, height;
    };
    struct
    {
        double left, right;
    };
    double element[2];
    inline double &operator[]( int &Index)
    {
        return element[Index];
    }
};
union Vector3
{
    struct
    {
        double x, y, z;
    };
    struct
    {
        double R, G, B;
    };
    double element[3];
    Vector3();
    Vector3(double *arr);
    Vector3(double x, double y, double z);
    Vector3 operator+( Vector3 right);
    Vector3 cross(Vector3 right);
    inline  double &operator[]( int &Index)
    {
        return element[Index];
    }
    void normalize();
};
union Vector4
{
    struct
    {
        double x, y, z, w;
    };
    struct
    {

        double r, g, b, a;
    };
    struct
    {
        double element[4];
    };
    Vector4();
    Vector4(Vector3 vec);
    Vector4(double *arr);
    Vector4(double x, double y, double z, double w);

    Vector3 vec3();
    inline  double &operator[]( int &Index)
    {
        return element[Index];
    }
    void normalize();
};
struct Quaternion
{
	//about quaternions https://www.weizmann.ac.il/sci-tea/benari/sites/sci-tea.benari/files/uploads/softwareAndLearningMaterials/quaternion-tutorial-2-0-1.pdf 
	//and wiki 
	//w - real part, x,y,z -  imaginary part (of for vector convertion x,y,z are coordinates of axes )
	double x, y, z,w;
    Quaternion(double x, double y, double z,double w);
    Quaternion();
    Quaternion(Vector3 vect);
    Vector3 rotateVector(Vector3);
    //this is a hamilton product of q v q^(-1) whitch is rotation of vector 
    Vector3 operator*(Vector3 bec); 
    Quaternion operator*(Quaternion left); 
    Quaternion& operator*=(Quaternion right); 
    void rotate_IN_Euler(Vector3 rot);
    void normalize();
    void convertFromEuler(Vector3 rot);
};

