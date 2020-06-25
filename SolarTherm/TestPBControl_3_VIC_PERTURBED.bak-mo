within SolarTherm;
model TestPBControl_3_VIC_PERTURBED
extends Modelica.Icons.Example;
parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  Modelica.Fluid.Sources.FixedBoundary cold_tank(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-86, -58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  SolarTherm.TestPBMasterControl testPBMasterControl(Kp = -10, T_ref = from_degC(300),Td = 1e-8, Ti = 0.5e8, uMax = 1690, uMin = -600)  annotation(
    Placement(visible = true, transformation(origin = {16, 36}, extent = {{-10, -10}, {10, 10}}, rotation = 180)));
  SolarTherm.TestPBTransient testPBTransient annotation(
    Placement(visible = true, transformation(origin = {73, -47}, extent = {{-33, -33}, {33, 33}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-44, -12}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 3600, height = 100, offset = 290, startTime = 250000) annotation(
    Placement(visible = true, transformation(origin = {-132, -8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_hot(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-52, 56}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp1(duration = 3600, height = 100, offset = 565, startTime = 3600) annotation(
    Placement(visible = true, transformation(origin = {-132, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(cold_tank.ports[1], testPBTransient.fluid_b) annotation(
    Line(points = {{-76, -58}, {-14, -58}, {-14, -62}, {54, -62}}, color = {0, 127, 255}));
  connect(T_amb.y, testPBTransient.T_amb) annotation(
    Line(points = {{42, 90}, {66, 90}, {66, -27}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient.parasities) annotation(
    Line(points = {{78, 88}, {78, 30.5}, {80, 30.5}, {80, -27}}, color = {0, 0, 127}));
  connect(ramp.y, source_cold.T_in) annotation(
    Line(points = {{-121, -8}, {-56, -8}}, color = {0, 0, 127}));
  connect(ramp1.y, source_hot.T_in) annotation(
    Line(points = {{-121, 60}, {-64, 60}}, color = {0, 0, 127}));
  connect(testPBMasterControl.m_flow_cold, source_cold.m_flow_in) annotation(
    Line(points = {{6, 41}, {-22, 41}, {-22, 12}, {-84, 12}, {-84, -4}, {-54, -4}}, color = {0, 0, 127}));
  connect(testPBMasterControl.m_flow_hot, source_hot.m_flow_in) annotation(
    Line(points = {{5, 30}, {-84, 30}, {-84, 64}, {-62, 64}}, color = {0, 0, 127}));
  connect(testPBMasterControl.T_mea, testPBTransient.T) annotation(
    Line(points = {{26, 36}, {36, 36}, {36, -54}, {54, -54}, {54, -54}}, color = {0, 0, 127}));
  connect(source_hot.ports[1], testPBTransient.fluid_a) annotation(
    Line(points = {{-42, 56}, {46, 56}, {46, -36}, {58, -36}, {58, -36}, {58, -36}}, color = {0, 127, 255}));
  connect(source_cold.ports[1], testPBTransient.fluid_a2) annotation(
    Line(points = {{-34, -12}, {-4, -12}, {-4, -44}, {56, -44}, {56, -48}, {56, -48}}, color = {0, 127, 255}));
  annotation(
    experiment(StartTime = 0, StopTime = 3600, Tolerance = 1e-6, Interval = 0.1));
end TestPBControl_3_VIC_PERTURBED;