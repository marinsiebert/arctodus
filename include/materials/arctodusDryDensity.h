#pragma once

#include "PorousFlowTotalGravitationalDensityBase.h"
/**
*A Basic Material that calculates the dry density depending on
*grain density and porosity
 */

class arctodusDryDensity : public PorousFlowTotalGravitationalDensityBase
{
public:
  static InputParameters validParams();

  arctodusDryDensity(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties() override;
  virtual void computeQpProperties() override;

  ///Solid density
  const Real _rho_s;

  /// Porosity
  const MaterialProperty<Real> & _porosity_qp;

  /// d(porosity)/d(PorousFlow variable)
  const MaterialProperty<std::vector<Real>> & _dporosity_qp_dvar;
};
