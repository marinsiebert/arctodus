//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "arctodusDryDensity.h"

registerMooseObject("arctodusApp", arctodusDryDensity);

InputParameters
arctodusDryDensity::validParams()
{
  InputParameters params = PorousFlowTotalGravitationalDensityBase::validParams();
  params.addRequiredRangeCheckedParam<Real>(
      "rho_s", "rho_s >= 0", "The density of the solid matrix");
  params.addClassDescription(
      "This Material calculates the porous medium dry density from porosity "
      "and a constant grain density."
      "density = rho_k * (1 - phi)");
  return params;
}

arctodusDryDensity::arctodusDryDensity(const InputParameters & parameters)
  : PorousFlowTotalGravitationalDensityBase(parameters),
   _rho_s(getParam<Real>("rho_s")),
    _porosity_qp(getMaterialProperty<Real>("PorousFlow_porosity_qp")),
    _dporosity_qp_dvar(getMaterialProperty<std::vector<Real>>("dPorousFlow_porosity_qp_dvar"))


{


  if (_nodal_material == true)
    mooseError("PorousFlowTotalGravitationalDensityFullySaturatedFromPorosity is only defined for "
               "at_nodes = false");
               
}


void
arctodusDryDensity::initQpStatefulProperties()
{
  const unsigned ph = 0;
  _gravdensity[_qp] = (_rho_s * (1.0 - _porosity_qp[_qp]));
}

void
arctodusDryDensity::computeQpProperties()
{
  const unsigned ph = 0;
  _gravdensity[_qp] = (_rho_s * (1.0 - _porosity_qp[_qp]));

  _dgravdensity_dvar[_qp].resize(_num_var);
  for (unsigned int v = 0; v < _num_var; ++v)
  {
    _dgravdensity_dvar[_qp][v] = ((1 - _porosity_qp[_qp]) * _rho_s);
  }



}
