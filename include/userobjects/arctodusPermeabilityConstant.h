#pragma once

#include "arctodusPermeability.h"

class arctodusPermeabilityConstant : public arctodusPermeability
{
public:
  static InputParameters validParams();
  arctodusPermeabilityConstant(const InputParameters & parameters);
  std::vector<Real>
  computePermeability(std::vector<Real> k0, Real phi0, Real porosity, Real aperture) const;
  std::vector<Real>
  computedPermeabilitydev(std::vector<Real> k0, Real phi0, Real porosity, Real dphi_dev) const;
  std::vector<Real>
  computedPermeabilitydpf(std::vector<Real> k0, Real phi0, Real porosity, Real dphi_dpf) const;
  std::vector<Real>
  computedPermeabilitydT(std::vector<Real> k0, Real phi0, Real porosity, Real dphi_dT) const;
};