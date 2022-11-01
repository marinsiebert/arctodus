#pragma once

#include "GeneralUserObject.h"
#include "arctodusScaling.h"

class arctodusFluidViscosity : public GeneralUserObject
{
public:
  static InputParameters validParams();
  arctodusFluidViscosity(const InputParameters & parameters);
  void initialize() {}
  void execute() {}
  void finalize() {}
  virtual Real computeViscosity(Real temperature, Real rho, Real mu0) const = 0;
  virtual Real computedViscositydT(Real temperature, Real rho, Real drho_dT, Real mu0) const = 0;
  virtual Real computedViscositydp(Real temperature, Real rho, Real drho_dp) const = 0;

protected:
  bool _has_scaled_properties;
  const arctodusScaling * _scaling_uo;
};