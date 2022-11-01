#include "arctodusPermeability.h"

InputParameters
arctodusPermeability::validParams()
{
  InputParameters params = GeneralUserObject::validParams();
  params.addClassDescription(
      "arctodus Permeability base class. Override the virtual functions in your class.");
  return params;
}

arctodusPermeability::arctodusPermeability(const InputParameters & parameters)
  : GeneralUserObject(parameters)
{
}