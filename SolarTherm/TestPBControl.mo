within SolarTherm;
model TestPBControl
extends Modelica.Icons.Example;
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.Models.PowerBlocks.PowerBlockAcciona powerBlock annotation(
    Placement(visible = true, transformation(origin = {78, -28}, extent = {{-30, -30}, {30, 30}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_hot(redeclare package Medium = Medium, T = from_degC(565), nPorts = 1, use_m_flow_in = true)  annotation(
    Placement(visible = true, transformation(origin = {-34, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source_cold(redeclare package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true)  annotation(
    Placement(visible = true, transformation(origin = {-34, 16}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary sink(redeclare package Medium = Medium, nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {-34, -30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {30, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasites(y = 1.4e7)  annotation(
    Placement(visible = true, transformation(origin = {88, 88}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp m_source_hot(duration = 1800, height = 1400, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 1800, height = 500, offset = 0, startTime = 0)  annotation(
    Placement(visible = true, transformation(origin = {-82, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  TestPBMasterControl testPBMasterControl annotation(
    Placement(visible = true, transformation(origin = {6, 30}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{32, -6}, {44, 6}}, rotation = 0)));
equation
  connect(source_cold.ports[1], powerBlock.fluid_a2) annotation(
    Line(points = {{-24, 16}, {6, 16}, {6, -29}, {63, -29}}, color = {0, 127, 255}));
  connect(sink.ports[1], powerBlock.fluid_b) annotation(
    Line(points = {{-24, -30}, {15.5, -30}, {15.5, -41}, {61, -41}}, color = {0, 127, 255}));
  connect(T_amb.y, powerBlock.T_amb) annotation(
    Line(points = {{41, 90}, {72, 90}, {72, -10}}, color = {0, 0, 127}));
  connect(parasites.y, powerBlock.parasities) annotation(
    Line(points = {{77, 88}, {84, 88}, {84, -10}}, color = {0, 0, 127}));
  connect(m_source_hot.y, source_hot.m_flow_in) annotation(
    Line(points = {{-70, 60}, {-46, 60}, {-46, 60}, {-44, 60}}, color = {0, 0, 127}));
  connect(ramp.y, source_cold.m_flow_in) annotation(
    Line(points = {{-70, 24}, {-44, 24}, {-44, 24}, {-44, 24}}, color = {0, 0, 127}));
  connect(testPBMasterControl.T_mea, powerBlock.T) annotation(
    Line(points = {{-4, 34}, {-14, 34}, {-14, -34}, {62, -34}, {62, -34}, {62, -34}}, color = {0, 0, 127}));
  connect(pumpHot.fluid_b, powerBlock.fluid_a) annotation(
    Line(points = {{44, 0}, {54, 0}, {54, -18}, {64, -18}, {64, -18}}, color = {0, 127, 255}));
  connect(testPBMasterControl.m_flow, pumpHot.m_flow) annotation(
    Line(points = {{18, 30}, {38, 30}, {38, 6}, {38, 6}}, color = {0, 0, 127}));
  connect(source_hot.ports[1], pumpHot.fluid_a) annotation(
    Line(points = {{-24, 52}, {-10, 52}, {-10, 0}, {32, 0}, {32, 0}}, color = {0, 127, 255}));
end TestPBControl;