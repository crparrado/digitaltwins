within SolarTherm;
model TestReceiverTransient
extends Modelica.Icons.Example;
import Modelica.SIunits.Conversions.*;

replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;

//Receiver
  SolarTherm.Models.CSP.CRS.Receivers.ReceiverTransient1D receiver(
		redeclare package Medium = Medium,
		H_rcv = 14.63, D_rcv = 14,
		N_pa = 22,
		t_tb = 1.25e-3,
		D_tb = 50e-3,
		em = 0.88,
		ab = 0.94) annotation(
    Placement(visible = true, transformation(origin = {-9, 29}, extent = {{-19, -19}, {19, 19}}, rotation = 0)));
  //La altura es 18.4 pero la altura efectiva es 14.63 m
  //Entradas y salidas
  Modelica.Fluid.Sources.Boundary_pT sink(replaceable package Medium = Medium, nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {30, 38}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source(replaceable package Medium = Medium, T = from_degC(290), nPorts = 1, use_m_flow_in = true)  annotation(
    Placement(visible = true, transformation(origin = {36, 2}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
//Temperatura ambiente
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {-38, 78}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
//Entrada de calor heliostatos
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow fieldPort annotation(
    Placement(visible = true, transformation(origin = {-52, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression Wind_speed(y = 14) annotation(
    Placement(visible = true, transformation(origin = {-38, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 1800,height = 196.3e6,offset = 0, startTime = 1800)  annotation(
    Placement(visible = true, transformation(origin = {-84, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp1(duration = 1800, height = 447, offset = 0, startTime = 1800) annotation(
    Placement(visible = true, transformation(origin = {80, 10}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
equation
  connect(source.ports[1], receiver.fluid_a) annotation(
    Line(points = {{26, 2}, {-6, 2}, {-6, 12}, {-6, 12}}, color = {0, 127, 255}));
  connect(receiver.fluid_b, sink.ports[1]) annotation(
    Line(points = {{-2, 38}, {20, 38}}, color = {0, 127, 255}));
  connect(T_amb.y, receiver.Tamb) annotation(
    Line(points = {{-27, 78}, {-8, 78}, {-8, 44}}, color = {0, 0, 127}));
  connect(fieldPort.port, receiver.heat) annotation(
    Line(points = {{-42, 34}, {-28, 34}, {-28, 34}, {-28, 34}}, color = {191, 0, 0}));
  connect(Wind_speed.y, receiver.Wspd) annotation(
    Line(points = {{-26, 60}, {-12, 60}, {-12, 44}, {-12, 44}}, color = {0, 0, 127}));
  connect(ramp.y, fieldPort.Q_flow) annotation(
    Line(points = {{-72, 34}, {-62, 34}, {-62, 34}, {-62, 34}}, color = {0, 0, 127}));
  connect(source.m_flow_in, ramp1.y) annotation(
    Line(points = {{46, 10}, {68, 10}, {68, 10}, {70, 10}}, color = {0, 0, 127}));
  annotation(
    experiment(StartTime = 0, StopTime = 7200, Tolerance = 1e-06, Interval = 0.1));
end TestReceiverTransient;