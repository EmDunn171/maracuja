//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "maracujaTestApp.h"
#include "maracujaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
maracujaTestApp::validParams()
{
  InputParameters params = maracujaApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

maracujaTestApp::maracujaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  maracujaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

maracujaTestApp::~maracujaTestApp() {}

void
maracujaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  maracujaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"maracujaTestApp"});
    Registry::registerActionsTo(af, {"maracujaTestApp"});
  }
}

void
maracujaTestApp::registerApps()
{
  registerApp(maracujaApp);
  registerApp(maracujaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
maracujaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maracujaTestApp::registerAll(f, af, s);
}
extern "C" void
maracujaTestApp__registerApps()
{
  maracujaTestApp::registerApps();
}
