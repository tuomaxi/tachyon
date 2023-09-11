#ifndef TACHYON_CC_MATH_ELLIPTIC_CURVES_POINT_CONVERSIONS_H_
#define TACHYON_CC_MATH_ELLIPTIC_CURVES_POINT_CONVERSIONS_H_

#include <stddef.h>

#include <type_traits>

#include "tachyon/cc/math/elliptic_curves/point_traits.h"
#include "tachyon/cc/math/finite_fields/prime_field_conversions.h"
#include "tachyon/math/geometry/point2.h"
#include "tachyon/math/geometry/point3.h"
#include "tachyon/math/geometry/point4.h"

namespace tachyon::cc::math {

template <typename CPointTy,
          typename CurvePointTy = typename PointTraits<CPointTy>::CurvePointTy,
          typename BaseField = typename CurvePointTy::BaseField>
CurvePointTy ToAffinePoint(const CPointTy& point_in) {
  tachyon::math::Point2<BaseField> point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  return CurvePointTy(point, point.x.IsZero() && point.y.IsZero());
}

template <typename CPointTy,
          typename CurvePointTy = typename PointTraits<CPointTy>::CurvePointTy,
          typename BaseField = typename CurvePointTy::BaseField>
CurvePointTy ToProjectivePoint(const CPointTy& point_in) {
  tachyon::math::Point3<BaseField> point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  point.z = BaseField::FromMontgomery(ToBigInt(point_in.z));
  return CurvePointTy(point);
}

template <typename CPointTy,
          typename CurvePointTy = typename PointTraits<CPointTy>::CurvePointTy,
          typename BaseField = typename CurvePointTy::BaseField>
CurvePointTy ToJacobianPoint(const CPointTy& point_in) {
  tachyon::math::Point3<BaseField> point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  point.z = BaseField::FromMontgomery(ToBigInt(point_in.z));
  return CurvePointTy(point);
}

template <typename CPointTy,
          typename CurvePointTy = typename PointTraits<CPointTy>::CurvePointTy,
          typename BaseField = typename CurvePointTy::BaseField>
CurvePointTy ToPointXYZZ(const CPointTy& point_in) {
  tachyon::math::Point4<BaseField> point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  point.z = BaseField::FromMontgomery(ToBigInt(point_in.zz));
  point.w = BaseField::FromMontgomery(ToBigInt(point_in.zzz));
  return CurvePointTy(point);
}

template <typename CPointTy,
          typename PointTy = typename PointTraits<CPointTy>::PointTy,
          typename BaseField = typename PointTy::value_type>
PointTy ToPoint2(const CPointTy& point_in) {
  PointTy point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  return point;
}

template <typename CPointTy,
          typename PointTy = typename PointTraits<CPointTy>::PointTy,
          typename BaseField = typename PointTy::value_type>
PointTy ToPoint3(const CPointTy& point_in) {
  PointTy point;
  point.x = BaseField::FromMontgomery(ToBigInt(point_in.x));
  point.y = BaseField::FromMontgomery(ToBigInt(point_in.y));
  point.z = BaseField::FromMontgomery(ToBigInt(point_in.z));
  return point;
}

template <typename CPointTy, typename PointTy,
          typename BaseField = typename PointTy::BaseField,
          size_t LimbNums = BaseField::kLimbNums>
CPointTy* CreateCPoint3Ptr(const PointTy& point) {
  CPointTy* ret = new CPointTy;
  memcpy(&ret->x, point.x().value().limbs, sizeof(uint64_t) * LimbNums);
  memcpy(&ret->y, point.y().value().limbs, sizeof(uint64_t) * LimbNums);
  memcpy(&ret->z, point.z().value().limbs, sizeof(uint64_t) * LimbNums);
  return ret;
}

}  // namespace tachyon::cc::math

#endif  // TACHYON_CC_MATH_ELLIPTIC_CURVES_POINT_CONVERSIONS_H_