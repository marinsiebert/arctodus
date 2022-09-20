//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "arctodusTestApp.h"
#include "arctodusApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
arctodusTestApp::validParams()
{
  InputParameters params = arctodusApp::validParams();
  return params;
}

arctodusTestApp::arctodusTestApp(InputParameters parameters) : MooseApp(parameters)
{
  arctodusTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

arctodusTestApp::~arctodusTestApp() {}

void
arctodusTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  arctodusApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"arctodusTestApp"});
    Registry::registerActionsTo(af, {"arctodusTestApp"});
  }
}

void
arctodusTestApp::registerApps()
{
  registerApp(arctodusApp);
  registerApp(arctodusTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
arctodusTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  arctodusTestApp::registerAll(f, af, s);
}
extern "C" void
arctodusTestApp__registerApps()
{
  arctodusTestApp::registerApps();
}
