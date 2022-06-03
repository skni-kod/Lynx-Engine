#include "LynxVector.h"
class Matrix3
{
public:
    double field[9];
    // constructors
    /* Matrix with 1 on diagonal*/
    Matrix3();
    // constructor for testing purposes
    Matrix3(double *var);
    /* Matrix filled with variable*/
    Matrix3(double &var);
    /* Columns filled with value of field of vector x -> 0, y -> 1, z->2*/
    Matrix3(Vector3 &vect);
    /* Coppy matrix to this matrix */
    Matrix3(Matrix3 *mat);

    // methods
    /* matrix scaled by vector x -> 0, y -> 1, z->2*/
    void scale(Vector3 &vect);
    /* matrix scaled by variable */
    void scale(double &var);
    /* matrix dot vector */
    void dot(Vector3 &vect);
    /* matrix multiplied */
    void multiply(Matrix3 *mat);
    /*add variable to each field of matrix */
    void add(double var);
    /*add to matrix a vector x -> 0, y -> 1, z->2 */
    void add(Vector3 &vect);
    /*add matrix to matrix */
    void add(Matrix3 *mat);
    /*matrix determinant */
    double det();

    // operators
    /*add matrix to matrix */
    Matrix3 operator+(Matrix3 &right);
    /*Multiplication*/
    Matrix3 operator*(Matrix3 &right);
    Vector3 operator*(Vector3 &right);
    Matrix3 operator*(double &right);
    /*substraction  */
    Matrix3 operator-(Matrix3 &right);
    /*get value of index*/
    Vector3 operator[](int x);
};

class Matrix4
{
public:
    double field[16];

    // constructors
    /* Matrix with 1 on diagonal*/
    Matrix4();
    // constructor for testing purposes
    Matrix4(double *var);
    /* Matrix filled with variable*/
    Matrix4(double &var);
    /* Columns filled with value of field of vector x -> 0, y -> 1, z->2*/
    Matrix4(Vector4 &vect);
    /* Coppy matrix to this matrix */
    Matrix4(Matrix4 *mat);
    ~Matrix4();
    // methods
    /* matrix scaled by vector x -> 0, y -> 1, z->2*/
    void scale(Vector4 &vect);
    /* matrix scaled by variable */
    void scale(double &var);

    /* matrix multiplied */
    void multiply(Matrix4 *mat);
    /*add variable to each field of matrix */
    void add(double var);
    /*add to matrix a vector x -> 0, y -> 1, z->2 */
    void add(Vector4 &vect);
    /*add matrix to4 matrix */
    void add(Matrix4 *mat);
    /*matrix determinant */
    double det();

    // operators
    /*add matrix to matrix */
    Matrix4 operator+(Matrix4 &right);
    /*Multiplication*/
    Matrix4 operator*(Matrix4 right);
    Vector4 operator*(Vector4 right);
    Matrix4 operator*(double right);
    Matrix4 operator*(Matrix4 *right);
    Matrix4 &operator*=(Matrix4 *right);
    /*substraction  */
    Matrix4 operator-(Matrix4 &right);
    /*get value of index*/
    Vector4 operator[](int x);
};
class Transform : public Matrix4
{
    Quaternion rotation;
    Vector3 fScale;
    Vector3 position;

public:
    Transform();
    Transform(Vector3 pos, Vector3 rot, Vector3 sca);
    Transform(Vector3 pos);
    ~Transform();
    void setRotation(Vector3 rot);
    void rotate(Vector3 rot);
    Quaternion getRotation();

    void scale(Vector3 sc);
    ;
    void setScale(Vector3 sc);
    Vector3 getScale();

    void Repostion(Vector3 trans);
    void setPostion(Vector3 trans);
    Vector3 getPosition();
    Matrix4 *createTranMatrix();
};
Vector4 operator*(Matrix4 *left, Vector4 right);