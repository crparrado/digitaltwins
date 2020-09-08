within SolarTherm;
model TestPBControl
extends Modelica.Icons.Example;
parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-34, 16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-80, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 100, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{32, -6}, {44, 6}}, rotation = 0)));
  SolarTherm.TestPBMasterControl testPBMasterControl annotation(
    Placement(visible = true, transformation(origin = {18, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary hot_tank(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-58, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Models.PowerBlocks.PowerBlockAcciona powerBlock annotation(
    Placement(visible = true, transformation(origin = {80, -30}, extent = {{-30, -30}, {30, 30}}, rotation = 0)));
equation
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-70, 24}, {-44, 24}, {-44, 24}, {-44, 24}}, color = {0, 0, 127}));
  connect(testPBMasterControl.m_flow, pumpHot.m_flow) annotation(
    Line(points = {{30, 30}, {38, 30}, {38, 6}, {38, 6}, {38, 6}}, color = {0, 0, 127}));
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-48, 60}, {-12, 60}, {-12, 0}, {32, 0}, {32, 0}, {32, 0}}, color = {0, 127, 255}));
  connect(powerBlock.T, testPBMasterControl.T_mea) annotation(
    Line(points = {{64, -36}, {-4, -36}, {-4, 32}, {6, 32}, {6, 34}, {8, 34}}, color = {0, 0, 127}));
  connect(pumpHot.fluid_b, powerBlock.fluid_a) annotation(
    Line(points = {{44, 0}, {54, 0}, {54, -20}, {67, -20}}, color = {0, 127, 255}));
  connect(parasites.y, powerBlock.parasities) annotation(
    Line(points = {{77, 88}, {86, 88}, {86, -12}}, color = {0, 0, 127}));
  connect(T_amb.y, powerBlock.T_amb) annotation(
    Line(points = {{41, 90}, {74, 90}, {74, -12}}, color = {0, 0, 127}));
  connect(cold_tank.ports[1], powerBlock.fluid_b) annotation(
    Line(points = {{-70, -44}, {15.5, -44}, {15.5, -43}, {63, -43}}, color = {0, 127, 255}));
  connect(source_cold.ports[1], powerBlock.fluid_a2) annotation(
    Line(points = {{-24, 16}, {6, 16}, {6, -31}, {65, -31}}, color = {0, 127, 255}));

annotation(
    experiment(StartTime = 0, StopTime = 3600, Tolerance = 1e-6, Interval = 0.1));
end TestPBControl;