within SolarTherm;

model TestRampPB
extends Modelica.Icons.Example;
parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, nPorts = 1) annotation(
    Placement(visible = true, transformation(origin = {-40, -38}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 185.2083, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(T = from_degC(290), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-34, 16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.TestPBTransient testPBTransient annotation(
    Placement(visible = true, transformation(origin = {54, 4}, extent = {{-34, -34}, {34, 34}}, rotation = 0)));
equation
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-70, 24}, {-44, 24}, {-44, 24}, {-44, 24}}, color = {0, 0, 127}));
  connect(source_cold.ports[1], testPBTransient.fluid_a) annotation(
    Line(points = {{-24, 16}, {39, 16}}, color = {0, 127, 255}));
  connect(cold_tank.ports[1], testPBTransient.fluid_b) annotation(
    Line(points = {{-30, -38}, {-10, -38}, {-10, -12}, {34, -12}, {34, -11}}, color = {0, 127, 255}));
  connect(T_amb.y, testPBTransient.T_amb) annotation(
    Line(points = {{42, 90}, {48, 90}, {48, 24}, {47, 24}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient.parasities) annotation(
    Line(points = {{78, 88}, {61, 88}, {61, 24}}, color = {0, 0, 127}));
protected
  annotation(
    experiment(StartTime = 0, StopTime = 3600, Tolerance = 1e-6, Interval = 0.1));


end TestRampPB;