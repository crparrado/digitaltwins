within SolarTherm;

model pba1
 import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
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
  Modelica.Fluid.Sources.FixedBoundary fixedBoundary(redeclare package Medium = Medium, T = from_degC(0), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-36, -66}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple annotation(
    Placement(visible = true, transformation(extent = {{-22, -8}, {-10, 4}}, rotation = 0)));
 Modelica.Fluid.Sources.FixedBoundary fixedBoundary1(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-78, -4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 SolarTherm.TestPBMasterControl_3_CRI_cold testPBMasterControl_3_CRI_cold(Kp = 100, Td = 1e-6, Ti = 0.5e8, uMax = 185.188)  annotation(
    Placement(visible = true, transformation(origin = {-14, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
 SolarTherm.TestPBT_OM testPBT_OM annotation(
    Placement(visible = true, transformation(origin = {60, -12}, extent = {{-28, -28}, {28, 28}}, rotation = 0)));
equation
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-70, 58}, {-44, 58}, {-44, 40}, {-24, 40}}, color = {0, 127, 255}));
  connect(testPBMasterControl_3_CRI_hot.m_flow_hot, pumpHot.m_flow) annotation(
    Line(points = {{6, 52}, {-18, 52}, {-18, 46}, {-18, 46}}, color = {0, 0, 127}));
 connect(fixedBoundary1.ports[1], pumpSimple.fluid_a) annotation(
    Line(points = {{-68, -4}, {-45, -4}, {-45, -2}, {-22, -2}}, color = {0, 127, 255}));
 connect(testPBMasterControl_3_CRI_cold.m_flow_cold, pumpSimple.m_flow) annotation(
    Line(points = {{-24, 25}, {-38, 25}, {-38, 6}, {-16, 6}, {-16, 3}}, color = {0, 0, 127}));
 connect(testPBT_OM.fluid_b, fixedBoundary.ports[1]) annotation(
    Line(points = {{44, -24}, {18, -24}, {18, -66}, {-26, -66}, {-26, -66}}, color = {0, 127, 255}));
 connect(pumpSimple.fluid_b, testPBT_OM.fluid_a) annotation(
    Line(points = {{-10, -2}, {48, -2}}, color = {0, 127, 255}));
 connect(pumpHot.fluid_b, testPBT_OM.fluid_a2) annotation(
    Line(points = {{-12, 40}, {12, 40}, {12, -12}, {46, -12}, {46, -12}}, color = {0, 127, 255}));
 connect(testPBT_OM.T, testPBMasterControl_3_CRI_cold.T_mea) annotation(
    Line(points = {{44, -18}, {6, -18}, {6, 16}, {-5, 16}}, color = {0, 0, 127}));
 connect(testPBMasterControl_3_CRI_hot.T_mea, testPBT_OM.T) annotation(
    Line(points = {{26, 58}, {32, 58}, {32, 22}, {8, 22}, {8, -18}, {44, -18}, {44, -18}}, color = {0, 0, 127}));
 connect(parasites.y, testPBT_OM.parasities) annotation(
    Line(points = {{78, 88}, {66, 88}, {66, 4}, {66, 4}}, color = {0, 0, 127}));
 connect(testPBT_OM.T_amb, T_amb.y) annotation(
    Line(points = {{54, 4}, {52, 4}, {52, 84}, {20, 84}, {20, 84}}, color = {0, 0, 127}));
protected
end pba1;