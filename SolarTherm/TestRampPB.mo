within SolarTherm;

model TestRampPB
extends Modelica.Icons.Example;
parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.Models.PowerBlocks.PowerBlockAcciona powerBlock annotation(
    Placement(visible = true, transformation(origin = {80, -30}, extent = {{-30, -30}, {30, 30}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true)  annotation(
    Placement(visible = true, transformation(origin = {-34, 16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {-40, -38}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 185.2083, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(source_cold.ports[1], powerBlock.fluid_a2) annotation(
    Line(points = {{-24, 16}, {6, 16}, {6, -31}, {65, -31}}, color = {0, 127, 255}));
  connect(cold_tank.ports[1], powerBlock.fluid_b) annotation(
    Line(points = {{-30, -38}, {15.5, -38}, {15.5, -43}, {63, -43}}, color = {0, 127, 255}));
  connect(T_amb.y, powerBlock.T_amb) annotation(
    Line(points = {{41, 90}, {74, 90}, {74, -12}}, color = {0, 0, 127}));
  connect(parasites.y, powerBlock.parasities) annotation(
    Line(points = {{77, 88}, {86, 88}, {86, -12}}, color = {0, 0, 127}));
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-70, 24}, {-44, 24}, {-44, 24}, {-44, 24}}, color = {0, 0, 127}));
  annotation(
    experiment(StartTime = 0, StopTime = 3600, Tolerance = 1e-6, Interval = 0.1));


end TestRampPB;