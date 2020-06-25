within SolarTherm;

model pba1
 import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.TestPBTransient_fix testPBTransient_fix annotation(
    Placement(visible = true, transformation(origin = {50, -14}, extent = {{-32, -32}, {32, 32}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25)) annotation(
    Placement(visible = true, transformation(origin = {8, 84}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7) annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
 SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot annotation(
    Placement(visible = true, transformation(extent = {{-24, 34}, {-12, 46}}, rotation = 0)));
 Modelica.Fluid.Sources.FixedBoundary hot_tank(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-80, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 SolarTherm.TestPBMasterControl_3_CRI_hot testPBMasterControl_3_CRI_hot(Kp = 100, Td = 1e-6, Ti = 0.5e8, uMax = 600, uMin = 0)  annotation(
    Placement(visible = true, transformation(origin = {16, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
 Modelica.Fluid.Sources.FixedBoundary fixedBoundary(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-36, -66}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple annotation(
    Placement(visible = true, transformation(extent = {{-22, -10}, {-10, 2}}, rotation = 0)));
 Modelica.Fluid.Sources.FixedBoundary fixedBoundary1(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-78, -4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 SolarTherm.TestPBMasterControl_3_CRI_cold testPBMasterControl_3_CRI_cold(Kp = 100, Td = 1e-6, Ti = 0.5e8, uMax = 185.188)  annotation(
    Placement(visible = true, transformation(origin = {-14, 22}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
equation
  connect(T_amb.y, testPBTransient_fix.T_amb) annotation(
    Line(points = {{20, 84}, {44, 84}, {44, 5}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient_fix.parasities) annotation(
    Line(points = {{78, 88}, {56, 88}, {56, 5}}, color = {0, 0, 127}));
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-70, 58}, {-44, 58}, {-44, 40}, {-24, 40}}, color = {0, 127, 255}));
  connect(testPBTransient_fix.T, testPBMasterControl_3_CRI_hot.T_mea) annotation(
    Line(points = {{32, -21}, {18, -21}, {18, 30}, {36, 30}, {36, 58}, {26, 58}}, color = {0, 0, 127}));
  connect(testPBMasterControl_3_CRI_hot.m_flow_hot, pumpHot.m_flow) annotation(
    Line(points = {{6, 52}, {-18, 52}, {-18, 46}, {-18, 46}}, color = {0, 0, 127}));
  connect(pumpHot.fluid_b, testPBTransient_fix.fluid_a2) annotation(
    Line(points = {{-12, 40}, {10, 40}, {10, -15}, {34, -15}}, color = {0, 127, 255}));
  connect(fixedBoundary.ports[1], testPBTransient_fix.fluid_b) annotation(
    Line(points = {{-26, -66}, {20, -66}, {20, -28}, {32, -28}, {32, -28}}, color = {0, 127, 255}));
 connect(fixedBoundary1.ports[1], pumpSimple.fluid_a) annotation(
    Line(points = {{-68, -4}, {-22, -4}, {-22, -4}, {-22, -4}}, color = {0, 127, 255}));
 connect(pumpSimple.fluid_b, testPBTransient_fix.fluid_a) annotation(
    Line(points = {{-10, -4}, {34, -4}, {34, -4}, {36, -4}}, color = {0, 127, 255}));
 connect(testPBMasterControl_3_CRI_cold.T_mea, testPBTransient_fix.T) annotation(
    Line(points = {{-5, 18}, {6, 18}, {6, -20}, {32, -20}, {32, -21}}, color = {0, 0, 127}));
 connect(testPBMasterControl_3_CRI_cold.m_flow_cold, pumpSimple.m_flow) annotation(
    Line(points = {{-24, 28}, {-38, 28}, {-38, 6}, {-16, 6}, {-16, 2}, {-16, 2}}, color = {0, 0, 127}));
end pba1;