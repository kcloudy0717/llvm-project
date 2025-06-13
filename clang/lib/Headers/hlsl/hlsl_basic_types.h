//===----- hlsl_basic_types.h - HLSL definitions for basic types ----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _HLSL_HLSL_BASIC_TYPES_H_
#define _HLSL_HLSL_BASIC_TYPES_H_

namespace hlsl {
// built-in scalar data types:

/// \typedef template<typename Ty, int Size> using vector = Ty
/// __attribute__((ext_vector_type(Size)))
///
/// \tparam Ty The base type of the vector may be any builtin integral or
/// floating point type.
/// \tparam Size The size of the vector may be any value between 1 and 4.

#ifdef __HLSL_ENABLE_16_BIT
// 16-bit integer.
typedef unsigned short uint16_t;
typedef short int16_t;

// 16-bit floating point.
typedef half float16_t;
#endif

// 32-bit integer.
typedef int int32_t;

// unsigned 32-bit integer.
typedef unsigned int uint;
typedef unsigned int uint32_t;

// 32-bit floating point.
typedef float float32_t;

// 64-bit integer.
typedef unsigned long uint64_t;
typedef long int64_t;

// 64-bit floating point
typedef double float64_t;

// built-in vector data types:

#ifdef __HLSL_ENABLE_16_BIT
typedef vector<int16_t, 1> int16_t1;
typedef vector<int16_t, 2> int16_t2;
typedef vector<int16_t, 3> int16_t3;
typedef vector<int16_t, 4> int16_t4;
typedef vector<uint16_t, 1> uint16_t1;
typedef vector<uint16_t, 2> uint16_t2;
typedef vector<uint16_t, 3> uint16_t3;
typedef vector<uint16_t, 4> uint16_t4;
#endif
typedef vector<bool, 1> bool1;
typedef vector<bool, 2> bool2;
typedef vector<bool, 3> bool3;
typedef vector<bool, 4> bool4;
typedef vector<int, 1> int1;
typedef vector<int, 2> int2;
typedef vector<int, 3> int3;
typedef vector<int, 4> int4;
typedef vector<uint, 1> uint1;
typedef vector<uint, 2> uint2;
typedef vector<uint, 3> uint3;
typedef vector<uint, 4> uint4;
typedef vector<int32_t, 1> int32_t1;
typedef vector<int32_t, 2> int32_t2;
typedef vector<int32_t, 3> int32_t3;
typedef vector<int32_t, 4> int32_t4;
typedef vector<uint32_t, 1> uint32_t1;
typedef vector<uint32_t, 2> uint32_t2;
typedef vector<uint32_t, 3> uint32_t3;
typedef vector<uint32_t, 4> uint32_t4;
typedef vector<int64_t, 1> int64_t1;
typedef vector<int64_t, 2> int64_t2;
typedef vector<int64_t, 3> int64_t3;
typedef vector<int64_t, 4> int64_t4;
typedef vector<uint64_t, 1> uint64_t1;
typedef vector<uint64_t, 2> uint64_t2;
typedef vector<uint64_t, 3> uint64_t3;
typedef vector<uint64_t, 4> uint64_t4;

typedef vector<half, 1> half1;
typedef vector<half, 2> half2;
typedef vector<half, 3> half3;
typedef vector<half, 4> half4;
typedef vector<float, 1> float1;
typedef vector<float, 2> float2;
typedef vector<float, 3> float3;
typedef vector<float, 4> float4;
typedef vector<double, 1> double1;
typedef vector<double, 2> double2;
typedef vector<double, 3> double3;
typedef vector<double, 4> double4;

#ifdef __HLSL_ENABLE_16_BIT
typedef vector<float16_t, 1> float16_t1;
typedef vector<float16_t, 2> float16_t2;
typedef vector<float16_t, 3> float16_t3;
typedef vector<float16_t, 4> float16_t4;
#endif

typedef vector<float32_t, 1> float32_t1;
typedef vector<float32_t, 2> float32_t2;
typedef vector<float32_t, 3> float32_t3;
typedef vector<float32_t, 4> float32_t4;
typedef vector<float64_t, 1> float64_t1;
typedef vector<float64_t, 2> float64_t2;
typedef vector<float64_t, 3> float64_t3;
typedef vector<float64_t, 4> float64_t4;

// built-in matrix data types:

#define DECLARE_MATRIX_TYPE_ALIAS(type)                                        \
  typedef matrix<type, 1, 1> type##1x1;                                        \
  typedef matrix<type, 1, 2> type##1x2;                                        \
  typedef matrix<type, 1, 3> type##1x3;                                        \
  typedef matrix<type, 1, 4> type##1x4;                                        \
  typedef matrix<type, 2, 1> type##2x1;                                        \
  typedef matrix<type, 2, 2> type##2x2;                                        \
  typedef matrix<type, 2, 3> type##2x3;                                        \
  typedef matrix<type, 2, 4> type##2x4;                                        \
  typedef matrix<type, 3, 1> type##3x1;                                        \
  typedef matrix<type, 3, 2> type##3x2;                                        \
  typedef matrix<type, 3, 3> type##3x3;                                        \
  typedef matrix<type, 3, 4> type##3x4;                                        \
  typedef matrix<type, 4, 1> type##4x1;                                        \
  typedef matrix<type, 4, 2> type##4x2;                                        \
  typedef matrix<type, 4, 3> type##4x3;                                        \
  typedef matrix<type, 4, 4> type##4x4

DECLARE_MATRIX_TYPE_ALIAS(int);
DECLARE_MATRIX_TYPE_ALIAS(uint);
DECLARE_MATRIX_TYPE_ALIAS(float);
DECLARE_MATRIX_TYPE_ALIAS(double);
#undef DECLARE_MATRIX_TYPE_ALIAS

// built-in raytracing constants:

enum RAY_FLAG : uint {
  RAY_FLAG_NONE = 0x00,
  RAY_FLAG_FORCE_OPAQUE = 0x01,
  RAY_FLAG_FORCE_NON_OPAQUE = 0x02,
  RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH = 0x04,
  RAY_FLAG_SKIP_CLOSEST_HIT_SHADER = 0x08,
  RAY_FLAG_CULL_BACK_FACING_TRIANGLES = 0x10,
  RAY_FLAG_CULL_FRONT_FACING_TRIANGLES = 0x20,
  RAY_FLAG_CULL_OPAQUE = 0x40,
  RAY_FLAG_CULL_NON_OPAQUE = 0x80,
  RAY_FLAG_SKIP_TRIANGLES = 0x100,
  RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES = 0x200,
};

enum RAYQUERY_FLAG : uint {
  RAYQUERY_FLAG_NONE = 0x00, // default
  RAYQUERY_FLAG_ALLOW_OPACITY_MICROMAPS = 0x01,
};

enum COMMITTED_STATUS : uint {
  COMMITTED_NOTHING,
  COMMITTED_TRIANGLE_HIT,
  COMMITTED_PROCEDURAL_PRIMITIVE_HIT,
};

enum CANDIDATE_TYPE : uint {
  CANDIDATE_NON_OPAQUE_TRIANGLE,
  CANDIDATE_PROCEDURAL_PRIMITIVE,
};

static constexpr uint HIT_KIND_NONE = 0;
static constexpr uint HIT_KIND_TRIANGLE_FRONT_FACE = 0xfe;
static constexpr uint HIT_KIND_TRIANGLE_BACK_FACE = 0xff;

static constexpr uint
    STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS = 0x1;
static constexpr uint
    STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS = 0x2;
static constexpr uint STATE_OBJECT_FLAG_ALLOW_STATE_OBJECT_ADDITIONS = 0x4;

static constexpr uint RAYTRACING_PIPELINE_FLAG_NONE = 0x0;
static constexpr uint RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES = 0x100;
static constexpr uint RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES =
    0x200;
static constexpr uint RAYTRACING_PIPELINE_FLAG_ALLOW_OPACITY_MICROMAPS = 0x400;

// built-in sampler feedback constants:

static constexpr uint SAMPLER_FEEDBACK_MIN_MIP = 0;
static constexpr uint SAMPLER_FEEDBACK_MIP_REGION_USED = 1;

// built-in barrier constants:

enum MEMORY_TYPE_FLAG : uint {
  UAV_MEMORY = 0x00000001,
  GROUP_SHARED_MEMORY = 0x00000002,
  NODE_INPUT_MEMORY = 0x00000004,
  NODE_OUTPUT_MEMORY = 0x00000008,
  ALL_MEMORY = 0x0000000f,
};

enum BARRIER_SEMANTIC_FLAG : uint {
  GROUP_SYNC = 0x00000001,
  GROUP_SCOPE = 0x00000002,
  DEVICE_SCOPE = 0x00000004,
};

struct RayDesc {
  float3 Origin;
  float TMin;
  float3 Direction;
  float TMax;
};

struct BuiltInTriangleIntersectionAttributes {
  float2 barycentrics;
};

} // namespace hlsl

#endif //_HLSL_HLSL_BASIC_TYPES_H_
