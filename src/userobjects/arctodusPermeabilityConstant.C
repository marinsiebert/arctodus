#include "arctodusPermeabilityConstant.h"

registerMooseObject("arctodusApp", arctodusPermeabilityConstant);

InputParameters
arctodusPermeabilityConstant::validParams()
{
  InputParameters params = arctodusPermeability::validParams();
  params.addClassDescription("Constant Permeability formulation.");
  return params;
}

arctodusPermeabilityConstant::arctodusPermeabilityConstant(const InputParameters & parameters)
  : arctodusPermeability(parameters)
{
}

std::vector<Real>
arctodusPermeabilityConstant::computePermeability(std::vector<Real> k0, Real, Real, Real) const
{
  return k0;
}

std::vector<Real>
arctodusPermeabilityConstant::computedPermeabilitydev(std::vector<Real> k0, Real, Real, Real) const
{
  std::vector<Real> dk_dev(k0.size(), 0.0);
  return dk_dev;
}

std::vector<Real>
arctodusPermeabilityConstant::computedPermeabilitydpf(std::vector<Real> k0, Real, Real, Real) const
{
  std::vector<Real> dk_dpf(k0.size(), 0.0);
  return dk_dpf;
}

std::vector<Real>
arctodusPermeabilityConstant::computedPermeabilitydT(std::vector<Real> k0, Real, Real, Real) const
{
  std::vector<Real> dk_dT(k0.size(), 0.0);
  return dk_dT;
}