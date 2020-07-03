within SolarTherm;

model pba
 import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.TestPBTransient_fix testPBTransient_fix annotation(
    Placement(visible = true, transformation(origin = {52, -12}, extent = {{-32, -32}, {32, 32}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(0), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-32, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 0, offset = 0, startTime = 0) annotation(
    Placement(visible = true, transformation(origin = {-82, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25)) annotation(
    Placement(visible = true, transformation(origin = {8, 84}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7) annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, T = from_degC(0), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-80, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 Modelica.Blocks.Sources.Ramp ramp1(duration = 4200, height = 0, offset = 0, startTime = 0) annotation(
    Placement(visible = true, transformation(origin = {-82, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 Modelica.Fluid.Sources.MassFlowSource_T massFlowSource_T(redeclare package Medium = Medium, T = from_degC(0), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-28, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-71, 8}, {-42, 8}}, color = {0, 0, 127}));
  connect(T_amb.y, testPBTransient_fix.T_amb) annotation(
    Line(points = {{20, 84}, {46, 84}, {46, 7}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient_fix.parasities) annotation(
    Line(points = {{78, 88}, {58, 88}, {58, 7}}, color = {0, 0, 127}));
  connect(testPBTransient_fix.fluid_b, cold_tank.ports[1]) annotation(
    Line(points = {{34, -26}, {-46, -26}, {-46, -44}, {-70, -44}, {-70, -44}}, color = {0, 127, 255}));
  connect(source_cold.ports[1], testPBTransient_fix.fluid_a) annotation(
    Line(points = {{-22, 0}, {30, 0}, {30, -2}, {38, -2}, {38, -2}}, color = {0, 127, 255}));
 connect(ramp1.y, massFlowSource_T.m_flow_in) annotation(
    Line(points = {{-70, 54}, {-38, 54}, {-38, 54}, {-38, 54}}, color = {0, 0, 127}));
 connect(massFlowSource_T.ports[1], testPBTransient_fix.fluid_a2) annotation(
    Line(points = {{-18, 46}, {0, 46}, {0, -12}, {36, -12}, {36, -12}}, color = {0, 127, 255}));
end pba;