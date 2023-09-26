// Copyright 2022 arkworks contributors
// Use of this source code is governed by a MIT/Apache-2.0 style license that
// can be found in the LICENSE-MIT.arkworks and the LICENCE-APACHE.arkworks
// file.

#ifndef TACHYON_MATH_FINITE_FIELDS_QUADRATIC_EXTENSION_FIELD_TRAITS_H_
#define TACHYON_MATH_FINITE_FIELDS_QUADRATIC_EXTENSION_FIELD_TRAITS_H_

#include "tachyon/math/finite_fields/fp2_forward.h"

namespace tachyon::math {

template <typename T>
struct QuadraticExtensionFieldTraits;

template <typename _Config>
struct QuadraticExtensionFieldTraits<Fp2<_Config>> {
  using Config = _Config;
};

}  // namespace tachyon::math

#endif  // TACHYON_MATH_FINITE_FIELDS_QUADRATIC_EXTENSION_FIELD_TRAITS_H_