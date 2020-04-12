within SolarTherm;

model TestTwoTanks
  import SolarTherm.{Models,Media};
  import SI = Modelica.SIunits;
  import Modelica.SIunits.Conversions.*;
  import Modelica.Constants.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  parameter SI.Temperature T_inlet = from_degC(565);
  parameter SI.Temperature T_amb_des = from_degC(25);
  parameter SI.Pressure p_inlet = 1e5;
  parameter SI.Pressure p_amb_des = 1e5;
  parameter SI.MassFlowRate m_flow_des = 1600;
  SolarTherm.Models.Storage.Tank.Tank tank1 annotation(
    Placement(visible = true, transformation(origin = {0, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary source(replaceable package Medium = Medium, T = T_inlet, nPorts = 1, p = p_inlet, use_T = true, use_p = true) annotation(
    Placement(visible = true, transformation(origin = {-82, 6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression Tamb(y = T_amb_des) annotation(
    Placement(visible = true, transformation(origin = {-24, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression Pamb(y = p_amb_des) annotation(
    Placement(visible = true, transformation(origin = {22, 20}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T sink(replaceable package Medium = Medium, nPorts = 1) annotation(
    Placement(visible = true, transformation(origin = {46, -6}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_flow(y = m_flow_des) annotation(
    Placement(visible = true, transformation(origin = {84, 2}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpIn annotation(
    Placement(visible = true, transformation(origin = {-42, 6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_flow_in(y = m_flow_des) annotation(
    Placement(visible = true, transformation(origin = {-78, 40}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(Tamb.y, tank1.T_amb) annotation(
    Line(points = {{-13, 20}, {-4, 20}, {-4, 10}}, color = {0, 0, 127}));
  connect(Pamb.y, tank1.p_top) annotation(
    Line(points = {{10, 20}, {4, 20}, {4, 10}, {4, 10}}, color = {0, 0, 127}));
  connect(tank1.fluid_b, sink.ports[1]) annotation(
    Line(points = {{10, -6}, {36, -6}}, color = {0, 127, 255}));
  connect(sink.m_flow_in, m_flow.y) annotation(
    Line(points = {{56, 2}, {72, 2}, {72, 2}, {74, 2}}, color = {0, 0, 127}));
  connect(pumpIn.fluid_a, source.ports[1]) annotation(
    Line(points = {{-52, 6}, {-72, 6}}, color = {0, 127, 255}));
  connect(pumpIn.fluid_b, tank1.fluid_a) annotation(
    Line(points = {{-32, 6}, {-10, 6}}));
  connect(m_flow_in.y, pumpIn.m_flow) annotation(
    Line(points = {{-66, 40}, {-42, 40}, {-42, 14}, {-42, 14}}, color = {0, 0, 127}));
end TestTwoTanks;