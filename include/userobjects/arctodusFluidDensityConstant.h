#pragma once

#include "arctodusFluidDensity.h"

class arctodusFluidDensityConstant : public arctodusFluidDensity
{
public:
  static InputParameters validParams();
  arctodusFluidDensityConstant(const InputParameters & parameters);
  Real computeDensity(Real, Real, Real rho0) const;
  Real computedDensitydT(Real, Real, Real) const;
  Real computedDensitydp(Real, Real) const;
};