#ifndef BGFX_MATH_H
#define BGFX_MATH_H

#include <math.h>

// Definitions
#define Sin(v) sinf(v)
#define Cos(v) cosf(v)
#define Tan(v) tanf(v)

// Types
typedef union vec2 {
  struct {
    f32 x, y;
  };
  struct {
    f32 u, v;
  };
  f32 e[2];
} vec2;

typedef union vec3 {
  struct {
    f32 x, y, z;
  };
  struct {
    f32 u, v, w;
  };
  struct {
    f32 r, g, b;
  };
  struct {
    f32 red, green, blue;
  };
  f32 e[3];
} vec3;

typedef union vec4 {
  struct {
    f32 x, y, z, w;
  };
  struct {
    f32 r, g, b, a;
  };
  struct {
    f32 red, green, blue, alpha;
  };
  f32 e[4];
} vec4;

typedef union mat4 {
  float elements[4][4];
  vec4 columns[4];
} mat4;

// Functions
root_function vec2 Vec2(f32 x, f32 y);
root_function vec2 Vec2Add(vec2 a, vec2 b);
root_function vec2 Vec2AddF(vec2 v, f32 f);
root_function vec2 Vec2Sub(vec2 a, vec2 b);
root_function vec2 Vec2MulF(vec2 v, f32 f);

root_function vec3 Vec3(f32 x, f32 y, f32 z);
root_function vec3 Vec3Add(vec3 a, vec3 b);
root_function vec3 Vec3AddF(vec3 v, f32 f);
root_function vec3 Vec3Sub(vec3 a, vec3 b);
root_function vec3 Vec3MulF(vec3 v, f32 f);

root_function vec4 Vec4(f32 x, f32 y, f32 z, f32 w);
root_function vec4 Vec4Add(vec4 a, vec4 b);
root_function vec4 Vec4AddF(vec4 v, f32 f);
root_function vec4 Vec4Sub(vec4 a, vec4 b);
root_function vec4 Vec4MulF(vec4 v, f32 f);

root_function mat4 Mat4Identity();
root_function mat4 Mat4Mul(mat4 a, mat4 b);
root_function mat4 Mat4MulV(mat4 m, vec4 v);
root_function mat4 Mat4Translate();
root_function mat4 Mat4Scale();
root_function mat4 Mat4Rotate();
root_function mat4 Mat4Inverse();
root_function mat4 Perspective();
root_function mat4 Orthographic();

#endif