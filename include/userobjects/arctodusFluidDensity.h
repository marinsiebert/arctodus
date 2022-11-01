#pragma once

#include "GeneralUserObject.h"
#include "arctodusScaling.h"

class arctodusFluidDensity : public GeneralUserObject
{
public:
  static InputParameters validParams();
  arctodusFluidDensity(const InputParameters & parameters);
  void initialize() {}
  void execute() {}
  void finalize() {}
  virtual Real computeDensity(Real pressure, Real temperature, Real rho0) const = 0;
  virtual Real computedDensitydT(Real pressure, Real temperature, Real rho0) const = 0;
  virtual Real computedDensitydp(Real pressure, Real temperature) const = 0;

protected:
  bool _has_scaled_properties;
  const arctodusScaling * _scaling_uo;
};