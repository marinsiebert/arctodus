#pragma once

#include "Material.h"
#include "RankTwoTensor.h"
#include "UserObjectInterface.h"
#include "Function.h"
#include "arctodusFluidDensity.h"
#include "arctodusFluidViscosity.h"
#include "arctodusPermeability.h"
#include "arctodusPorosity.h"
#include "arctodusScaling.h"

class arctodusMaterialBase : public Material
{
public:
  static InputParameters validParams();
  arctodusMaterialBase(const InputParameters & parameters);
  static MooseEnum materialType();

protected:
  virtual void initQpStatefulProperties();
  void computeGravity();
  void computeRotationMatrix();
  Real computeQpScaling();
  bool _has_scaled_properties;
  Real _rho0_f;
  Real _rho0_s;
  Real _phi0;
  bool _has_gravity;
  Real _g;
  Real _scaling_factor0;
  const Function * _function_scaling;
  Real _alpha_T_f;
  Real _alpha_T_s;
  const arctodusFluidDensity * _fluid_density_uo;
  const arctodusFluidViscosity * _fluid_viscosity_uo;
  const arctodusPermeability * _permeability_uo;
  const arctodusPorosity * _porosity_uo;
  const arctodusScaling * _scaling_uo;
  MooseEnum _material_type;
  MaterialProperty<Real> & _scaling_factor;
  MaterialProperty<Real> & _porosity;
  MaterialProperty<Real> & _fluid_density;
  MaterialProperty<Real> & _fluid_viscosity;
  RealVectorValue _gravity;
  RankTwoTensor _rotation_matrix;
};