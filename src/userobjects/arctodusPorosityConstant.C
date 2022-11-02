#include "arctodusPorosityConstant.h"

registerMooseObject("arctodusApp", arctodusPorosityConstant);

InputParameters
arctodusPorosityConstant::validParams()
{
  InputParameters params = arctodusPorosity::validParams();
  params.addClassDescription("Constant Porosity formulation.");
  return params;
}

arctodusPorosityConstant::arctodusPorosityConstant(const InputParameters & parameters)
  : arctodusPorosity(parameters)
{
}

Real
arctodusPorosityConstant::computePorosity(Real phi_old, Real, Real, Real, Real, Real, Real) const
{
  return phi_old;
}

Real arctodusPorosityConstant::computedPorositydev(Real, Real) const { return 0.0; }

Real arctodusPorosityConstant::computedPorositydpf(Real, Real, Real) const { return 0.0; }

Real arctodusPorosityConstant::computedPorositydT(Real, Real, Real, Real) const { return 0.0; }