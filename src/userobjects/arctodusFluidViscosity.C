#include "arctodusFluidViscosity.h"

InputParameters
arctodusFluidViscosity::validParams()
{
  InputParameters params = GeneralUserObject::validParams();
  params.addClassDescription(
      "arctodus Fluid Viscosity base class. Override the virtual functions in your class.");
  params.addParam<UserObjectName>("scaling_uo", "The name of the scaling user object.");
  return params;
}

arctodusFluidViscosity::arctodusFluidViscosity(const InputParameters & parameters)
  : GeneralUserObject(parameters),
    _has_scaled_properties(isParamValid("scaling_uo")),
    _scaling_uo(_has_scaled_properties ? &getUserObject<arctodusScaling>("scaling_uo") : NULL)
{
}