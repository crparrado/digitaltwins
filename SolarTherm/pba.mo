within SolarTherm;

model pba
 import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.TestPBTransient_fix testPBTransient_fix annotation(
    Placement(visible = true, transformation(origin = {52, -12}, extent = {{-32, -32}, {32, 32}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-32, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 185.188, offset = 0, startTime = 0) annotation(
    Placement(visible = true, transformation(origin = {-80, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25)) annotation(
    Placement(visible = true, transformation(origin = {8, 84}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7) annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-80, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 Models.Fluid.Pumps.PumpSimple pumpHot annotation(
    Placement(visible = true, transformation(extent = {{-24, 34}, {-12, 46}}, rotation = 0)));
 Modelica.Fluid.Sources.FixedBoundary hot_tank(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-80, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 TestPBMasterControl_3_CRI_hot testPBMasterControl_3_CRI_hot(Kp = 100, Td = 1e-6, Ti = 0.5e8, uMax = 600, uMin = 0) annotation(
    Placement(visible = true, transformation(origin = {16, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
equation
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-69, 8}, {-42, 8}}, color = {0, 0, 127}));
  connect(T_amb.y, testPBTransient_fix.T_amb) annotation(
    Line(points = {{20, 84}, {46, 84}, {46, 7}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient_fix.parasities) annotation(
    Line(points = {{78, 88}, {58, 88}, {58, 7}}, color = {0, 0, 127}));
  connect(testPBTransient_fix.fluid_b, cold_tank.ports[1]) annotation(
    Line(points = {{34, -26}, {-46, -26}, {-46, -44}, {-70, -44}, {-70, -44}}, color = {0, 127, 255}));
  connect(source_cold.ports[1], testPBTransient_fix.fluid_a) annotation(
    Line(points = {{-22, 0}, {30, 0}, {30, -2}, {38, -2}, {38, -2}}, color = {0, 127, 255}));
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-70, 58}, {-44, 58}, {-44, 40}, {-24, 40}}, color = {0, 127, 255}));
  connect(testPBMasterControl_3_CRI_hot.m_flow_hot, pumpHot.m_flow) annotation(
    Line(points = {{6, 52}, {-18, 52}, {-18, 46}, {-18, 46}}, color = {0, 0, 127}));
 connect(pumpHot.fluid_b, testPBTransient_fix.fluid_a2) annotation(
    Line(points = {{-12, 40}, {2, 40}, {2, -12}, {36, -12}, {36, -12}}, color = {0, 127, 255}));
 connect(testPBMasterControl_3_CRI_hot.T_mea, testPBTransient_fix.T) annotation(
    Line(points = {{26, 58}, {38, 58}, {38, 2}, {10, 2}, {10, -20}, {34, -20}, {34, -20}}, color = {0, 0, 127}));
end pba;