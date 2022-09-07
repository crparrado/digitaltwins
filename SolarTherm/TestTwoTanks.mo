within SolarTherm;

model TestTwoTanks
  extends Modelica.Icons.Example;
  import SolarTherm.{Models,Media};
  import SI = Modelica.SIunits;
  import Modelica.SIunits.Conversions.*;
  import Modelica.Constants.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  parameter SI.Temperature T_in = from_degC(565);
  parameter SI.Temperature T_amb = from_degC(25);
  parameter SI.Pressure p_in = 1.01325e5;
  parameter SI.Pressure p_amb = 1.01325e5;
  parameter SI.MassFlowRate m_des = 1600;
  SolarTherm.Models.Storage.Tank.Tank tank1(replaceable package Medium = Medium, use_p_top = true) annotation(
    Placement(visible = true, transformation(origin = {0, 2}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary source1(replaceable package Medium = Medium, T = T_in, nPorts = 1, p = p_in, use_T = true, use_p = true) annotation(
    Placement(visible = true, transformation(origin = {-86, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression Tamb(y = T_amb) annotation(
    Placement(visible = true, transformation(origin = {-26, 84}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression Pamb(y = p_amb) annotation(
    Placement(visible = true, transformation(origin = {32, 84}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_o1(y = -m_des) annotation(
    Placement(visible = true, transformation(origin = {51, 18}, extent = {{7, -10}, {-7, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpRec1(replaceable package Medium = Medium) annotation(
    Placement(visible = true, transformation(origin = {-52, 8}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_rec(y = m_des) annotation(
    Placement(visible = true, transformation(origin = {-86, 33}, extent = {{-6, -9}, {6, 9}}, rotation = 0)));
  SolarTherm.Models.Storage.Tank.Tank tank2(replaceable package Medium = Medium, use_p_top = true) annotation(
    Placement(visible = true, transformation(origin = {0, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_o2(y = -m_des) annotation(
    Placement(visible = true, transformation(origin = {51, -30}, extent = {{7, -10}, {-7, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Valves.ValveControl valveControl(replaceable package Medium = Medium) annotation(
    Placement(visible = true, transformation(origin = {-24, 0}, extent = {{-10, 0}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_tk1(y = 0.2 * m_des) annotation(
    Placement(visible = true, transformation(origin = {-57, 54}, extent = {{-7, -10}, {7, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple annotation(
    Placement(visible = true, transformation(origin = {38, -4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple1 annotation(
    Placement(visible = true, transformation(origin = {38, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary sink1(replaceable package Medium = Medium, nPorts = 1) annotation(
    Placement(visible = true, transformation(origin = {94, -50}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  //  Modelica.Fluid.Sources.FixedBoundary sink2(replaceable package Medium = Medium, nPorts = 1) annotation(
  //    Placement(visible = true, transformation(origin = {76, -50}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Fittings.TeeJunctionIdeal tee annotation(
    Placement(visible = true, transformation(origin = {64, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(Tamb.y, tank1.T_amb) annotation(
    Line(points = {{-15, 84}, {-4, 84}, {-4, 12}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Pamb.y, tank1.p_top) annotation(
    Line(points = {{21, 84}, {4.5, 84}, {4.5, 12}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(pumpRec1.fluid_a, source1.ports[1]) annotation(
    Line(points = {{-62, 8}, {-76, 8}}, color = {0, 127, 255}));
  connect(m_rec.y, pumpRec1.m_flow) annotation(
    Line(points = {{-79, 33}, {-52, 33}, {-52, 17}}, color = {0, 0, 127}));
  connect(tank2.T_amb, Tamb.y) annotation(
    Line(points = {{-4, -34}, {-4, -20}, {-15, -20}, {-15, 84}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(valveControl.fluid_b1, tank1.fluid_a) annotation(
    Line(points = {{-19, 7}, {-10, 7}}, color = {0, 127, 255}));
  connect(pumpRec1.fluid_b, valveControl.fluid_a) annotation(
    Line(points = {{-42, 8}, {-41, 8}, {-41, 7}, {-29, 7}}, color = {0, 127, 255}));
  connect(m_tk1.y, valveControl.m_flow) annotation(
    Line(points = {{-49, 54}, {-24, 54}, {-24, 10}}, color = {0, 0, 127}));
  connect(valveControl.fluid_b2, tank2.fluid_a) annotation(
    Line(points = {{-24, 0}, {-24, -39}, {-10, -39}}));
  connect(tank2.p_top, Pamb.y) annotation(
    Line(points = {{4.5, -34}, {4.5, -20}, {20, -20}, {20, 84}, {21, 84}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(tank1.fluid_b, pumpSimple.fluid_a) annotation(
    Line(points = {{10, -4}, {28, -4}, {28, -4}, {28, -4}}, color = {0, 127, 255}));
  connect(tank2.fluid_b, pumpSimple1.fluid_a) annotation(
    Line(points = {{10, -50}, {28, -50}}, color = {0, 127, 255}));
  connect(m_o1.y, pumpSimple.m_flow) annotation(
    Line(points = {{43, 18}, {38, 18}, {38, 4}}, color = {0, 0, 127}));
  connect(m_o2.y, pumpSimple1.m_flow) annotation(
    Line(points = {{43, -30}, {38, -30}, {38, -42}}, color = {0, 0, 127}));
//  connect(pumpSimple.fluid_b, sink1.ports[1]) annotation(
//    Line(points = {{48, -4}, {66, -4}, {66, -4}, {66, -4}}, color = {0, 127, 255}));
//  connect(pumpSimple1.fluid_b, sink2.ports[1]) annotation(
//    Line(points = {{48, -50}, {64, -50}, {64, -50}, {66, -50}}, color = {0, 127, 255}));
  connect(pumpSimple1.fluid_b, tee.port_1) annotation(
    Line(points = {{48, -50}, {54, -50}, {54, -50}, {54, -50}}, color = {0, 127, 255}));
  connect(pumpSimple.fluid_b, tee.port_3) annotation(
    Line(points = {{48, -4}, {64, -4}, {64, -40}, {64, -40}}, color = {0, 127, 255}));
  connect(tee.port_2, sink1.ports[1]) annotation(
    Line(points = {{74, -50}, {84, -50}}, color = {0, 127, 255}));
  annotation(
    Diagram(coordinateSystem(extent = {{-120, -100}, {120, 100}})),
    Icon(coordinateSystem(extent = {{-120, -100}, {120, 100}})));
end TestTwoTanks;