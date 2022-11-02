#include "arctodusFluidDensityConstant.h"

registerMooseObject("arctodusApp", arctodusFluidDensityConstant);

InputParameters
arctodusFluidDensityConstant::validParams()
{
  InputParameters params = arctodusFluidDensity::validParams();
  params.addClassDescription("Constant fluid density formulation.");
  return params;
}

arctodusFluidDensityConstant::arctodusFluidDensityConstant(const InputParameters & parameters)
  : arctodusFluidDensity(parameters)
{
}

Real
arctodusFluidDensityConstant::computeDensity(Real, Real, Real rho0) const
{
  return rho0;
}

Real arctodusFluidDensityConstant::computedDensitydT(Real, Real, Real) const { return 0.0; }

Real arctodusFluidDensityConstant::computedDensitydp(Real, Real) const { return 0.0; }