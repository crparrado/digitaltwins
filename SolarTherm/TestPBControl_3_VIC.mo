within SolarTherm;
model TestPBControl_3_VIC
extends Modelica.Icons.Example;
parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, T = from_degC(290), nPorts = 2, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-86, -58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{-18, -8}, {-6, 4}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{-18, -36}, {-6, -24}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary hot_tank(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-88, -2}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.TestPBMasterControl_3_VIC control_3_VIC(Kp = 100, Td = 1e-6, Ti = 0.5e8, uMax = 1600, uMin = 0)  annotation(
    Placement(visible = true, transformation(origin = {-24, 42}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
  SolarTherm.TestPBTransient_fix powerblock annotation(
    Placement(visible = true, transformation(origin = {75, -29}, extent = {{-33, -33}, {33, 33}}, rotation = 0))); 
equation
  connect(cold_tank.ports[1], pumpSimple.fluid_a) annotation(
    Line(points = {{-76, -58}, {-58, -58}, {-58, -30}, {-18, -30}, {-18, -30}}, color = {0, 127, 255}));
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-78, -2}, {-34, -2}, {-34, -2}, {-18, -2}, {-18, -2}}, color = {0, 127, 255}));
  connect(control_3_VIC.m_flow_hot, pumpHot.m_flow) annotation(
    Line(points = {{-34, 36}, {-46, 36}, {-46, 12}, {-12, 12}, {-12, 4}, {-12, 4}}, color = {0, 0, 127}));
  connect(control_3_VIC.m_flow_cold, pumpSimple.m_flow) annotation(
    Line(points = {{-34, 48}, {-52, 48}, {-52, -20}, {-12, -20}, {-12, -26}, {-12, -26}, {-12, -24}}, color = {0, 0, 127}));
  connect(pumpHot.fluid_b, powerblock.fluid_a) annotation(
    Line(points = {{-6, -2}, {26, -2}, {26, -18}, {60, -18}}, color = {0, 127, 255}));
  connect(pumpSimple.fluid_b, powerblock.fluid_a2) annotation(
    Line(points = {{-6, -30}, {58.5, -30}}, color = {0, 127, 255}));
  connect(powerblock.T_amb, T_amb.y) annotation(
    Line(points = {{68, -9}, {68, 36}, {46, 36}, {46, 90}, {42, 90}}, color = {0, 0, 127}));
  connect(parasites.y, powerblock.parasities) annotation(
    Line(points = {{78, 88}, {68, 88}, {68, 62}, {82, 62}, {82, -9}}, color = {0, 0, 127}));
  connect(control_3_VIC.T_mea, powerblock.T) annotation(
    Line(points = {{-14, 42}, {14, 42}, {14, -36}, {58, -36}, {58, -37}, {57, -37}}, color = {0, 0, 127}));
  connect(powerblock.fluid_b, cold_tank.ports[2]) annotation(
    Line(points = {{56, -44}, {18, -44}, {18, -60}, {-76, -60}, {-76, -58}}, color = {0, 127, 255}));
  annotation(
    experiment(StartTime = 0, StopTime = 86400, Tolerance = 1e-6, Interval = 0.1));
end TestPBControl_3_VIC;