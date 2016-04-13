#ifndef MAT3_H__
#define MAT3_H__

#ifdef __linux__
  #include <GL/gl.h>
#endif
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#endif

#include <cassert>

class Mat3{
  public:
    Mat3();
    Mat3(GLfloat _s=1.0f);
    Mat3(float input[9]);
    Mat3(const Mat3 &_r)=default;
    //void operator *=(const Mat3 &_rhs);
    //Vec3 operator *(Vec3 &_rhs) const;
    //Mat3 operator *(const Mat3 &_rhs) const;
    //void identity();
    //const Mat3& transpose();
    GLfloat & operator [](int _i);
  union
  {
    float m_m[3][3];
    float m_openGL[9];
    struct{
      GLfloat m_00;
      GLfloat m_01;
      GLfloat m_02;
      GLfloat m_10;
      GLfloat m_11;
      GLfloat m_12;
      GLfloat m_20;
      GLfloat m_21;
      GLfloat m_22;
    };
  };
};


#endif
