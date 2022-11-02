#pragma once

#include "arctodusPorosity.h"

class arctodusPorosityConstant : public arctodusPorosity
{
public:
  static InputParameters validParams();
  arctodusPorosityConstant(const InputParameters & parameters);
  Real computePorosity(Real phi_old, Real, Real, Real, Real, Real, Real) const;
  Real computedPorositydev(Real, Real) const;
  Real computedPorositydpf(Real, Real, Real) const;
  Real computedPorositydT(Real, Real, Real, Real) const;
};