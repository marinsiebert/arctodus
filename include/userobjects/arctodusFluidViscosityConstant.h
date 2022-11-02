#pragma once

#include "arctodusFluidViscosity.h"

class arctodusFluidViscosityConstant : public arctodusFluidViscosity
{
public:
  static InputParameters validParams();
  arctodusFluidViscosityConstant(const InputParameters & parameters);
  Real computeViscosity(Real, Real, Real mu0) const;
  Real computedViscositydT(Real, Real, Real, Real) const;
  Real computedViscositydp(Real, Real, Real) const;
};