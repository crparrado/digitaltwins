within SolarTherm;
model TestPBControl_2
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
  Modelica.Blocks.Sources.Ramp ramp(duration = 4200, height = 185.0823, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{30, -8}, {42, 4}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary hot_tank(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, p = 1e5) annotation(
    Placement(visible = true, transformation(origin = {-58, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.TestPBTransient testPBTransient annotation(
    Placement(visible = true, transformation(origin = {73, -43}, extent = {{-33, -33}, {33, 33}}, rotation = 0)));
  SolarTherm.TestPBMasterControl_1 testPBMasterControl_1 annotation(
    Placement(visible = true, transformation(origin = {19, 27}, extent = {{-13, -13}, {13, 13}}, rotation = 0)));
equation
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-70, 24}, {-44, 24}, {-44, 24}, {-44, 24}}, color = {0, 0, 127}));
  connect(hot_tank.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-48, 60}, {-12, 60}, {-12, -2}, {30, -2}}, color = {0, 127, 255}));
  connect(cold_tank.ports[1], testPBTransient.fluid_b) annotation(
    Line(points = {{-70, -44}, {-14, -44}, {-14, -58}, {54, -58}}, color = {0, 127, 255}));
  connect(pumpHot.fluid_b, testPBTransient.fluid_a) annotation(
    Line(points = {{42, -2}, {50, -2}, {50, -32}, {58, -32}, {58, -32}, {58, -32}}));
  connect(T_amb.y, testPBTransient.T_amb) annotation(
    Line(points = {{42, 90}, {68, 90}, {68, -14}, {66, -14}, {66, -24}, {66, -24}}, color = {0, 0, 127}));
  connect(parasites.y, testPBTransient.parasities) annotation(
    Line(points = {{78, 88}, {74, 88}, {74, -2}, {80, -2}, {80, -22}, {80, -22}, {80, -24}}, color = {0, 0, 127}));
  connect(source_cold.ports[1], testPBTransient.fluid_a2) annotation(
    Line(points = {{-24, 16}, {-16, 16}, {-16, -32}, {18, -32}, {18, -44}, {56, -44}, {56, -44}, {56, -44}}, color = {0, 127, 255}));
  connect(testPBTransient.T, testPBMasterControl_1.T_mea) annotation(
    Line(points = {{54, -50}, {-10, -50}, {-10, 32}, {6, 32}, {6, 32}}, color = {0, 0, 127}));
  connect(testPBMasterControl_1.m_flow, pumpHot.m_flow) annotation(
    Line(points = {{34, 28}, {36, 28}, {36, 4}, {36, 4}}, color = {0, 0, 127}));
  protected
  annotation(
    experiment(StartTime = 0, StopTime = 3600, Tolerance = 1e-6, Interval = 0.1));
end TestPBControl_2;