#pragma once

#include "arctodusMaterialBase.h"

class arctodusMaterialT : public arctodusMaterialBase
{
public:
  static InputParameters validParams();
  arctodusMaterialT(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();

  bool _has_T_source_sink;
  Real _lambda_f;
  Real _lambda_s;
  Real _c_f;
  Real _c_s;
  Real _T_source_sink;
  MaterialProperty<Real> & _T_kernel_diff;
  MaterialProperty<Real> * _T_kernel_source;
  MaterialProperty<Real> * _T_kernel_time;
};