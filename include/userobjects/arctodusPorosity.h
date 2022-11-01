#pragma once

#include "GeneralUserObject.h"

class arctodusPorosity : public GeneralUserObject
{
public:
  static InputParameters validParams();
  arctodusPorosity(const InputParameters & parameters);
  void initialize() {}
  void execute() {}
  void finalize() {}
  virtual Real computePorosity(Real phi_old,
                               Real dphi_dev,
                               Real dphi_dpf,
                               Real dphi_dT,
                               Real dev,
                               Real dpf,
                               Real dT) const = 0;
  virtual Real computedPorositydev(Real phi_old, Real biot) const = 0;
  virtual Real computedPorositydpf(Real phi_old, Real biot, Real Ks) const = 0;
  virtual Real computedPorositydT(Real phi_old, Real biot, Real beta_f, Real beta_s) const = 0;
};