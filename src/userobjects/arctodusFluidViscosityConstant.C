#include "arctodusFluidViscosityConstant.h"

registerMooseObject("arctodusApp", arctodusFluidViscosityConstant);

InputParameters
arctodusFluidViscosityConstant::validParams()
{
  InputParameters params = arctodusFluidViscosity::validParams();
  params.addClassDescription("Constant fluid viscosity formulation.");
  return params;
}

arctodusFluidViscosityConstant::arctodusFluidViscosityConstant(const InputParameters & parameters)
  : arctodusFluidViscosity(parameters)
{
}

Real
arctodusFluidViscosityConstant::computeViscosity(Real, Real, Real mu0) const
{
  return mu0;
}

Real arctodusFluidViscosityConstant::computedViscositydT(Real, Real, Real, Real) const { return 0.0; }

Real arctodusFluidViscosityConstant::computedViscositydp(Real, Real, Real) const { return 0.0; }