#pragma once

#include "Kernel.h"
#include "DerivativeMaterialInterface.h"

class arctodusKernelT : public DerivativeMaterialInterface<Kernel>
{
public:
  static InputParameters validParams();
  arctodusKernelT(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int) override;

  bool _has_pf;
  bool _has_disp;
  const MaterialProperty<Real> & _scaling_factor;
  const MaterialProperty<Real> & _T_kernel_diff;
  const MaterialProperty<Real> & _dT_kernel_diff_dT;
  const MaterialProperty<Real> & _dT_kernel_diff_dpf;
  const MaterialProperty<Real> & _dT_kernel_diff_dev;
  const MaterialProperty<Real> & _T_kernel_source;

private:
  unsigned int _pf_var;
  unsigned int _ndisp;
  std::vector<unsigned int> _disp_var;
};