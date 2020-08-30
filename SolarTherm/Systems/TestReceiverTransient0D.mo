within SolarTherm.Systems;
model TestReceiverTransient0D
extends Modelica.Icons.Example;
import Modelica.SIunits.Conversions.*;

replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;

//Receiver
  SolarTherm.Models.CSP.CRS.Receivers.ReceiverTransient receiver(
		redeclare package Medium = Medium,
		H_rcv = 18.4, 
		D_rcv = 20.59,
		N_pa = 22,
		t_tb = 1.651e-3,
		D_tb = 50e-3,
		em = 0.88,
		ab = 0.94) annotation(
    Placement(visible = true, transformation(origin = {-9, 29}, extent = {{-19, -19}, {19, 19}}, rotation = 0)));
//Entradas y salidas
  Modelica.Fluid.Sources.Boundary_pT sink(replaceable package Medium = Medium, nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {30, 38}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source(replaceable package Medium = Medium, T = from_degC(288), nPorts = 1, use_m_flow_in = true)  annotation(
    Placement(visible = true, transformation(origin = {36, 2}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
//Temperatura ambiente
  Modelica.Blocks.Sources.RealExpression T_amb(y = from_degC(15.83))  annotation(
    Placement(visible = true, transformation(origin = {24, 82}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
//Entrada de calor heliostatos
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow fieldPort annotation(
    Placement(visible = true, transformation(origin = {-52, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.TimeTable timeTable(table = [0, 0; 612, 0; 1188, 0; 1800, 23.4e6; 2412, 80.8e6; 2988, 138.6e6; 3600, 196.36e6; 4212, 254.1e6; 7200, 254.1e6])  annotation(
    Placement(visible = true, transformation(origin = {-86, 34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.TimeTable timeTable1(table = [0, 0; 612, 0; 1188, 0; 1800, 0; 2412, 0; 2988, 591.7; 3600, 447; 4212, 599.6; 7200, 599.6]) annotation(
    Placement(visible = true, transformation(origin = {80, 10}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.TimeTable timeTable2(table = [0, 1.3583; 420, 1.3666; 1320, 1.2583; 2220, 1.15; 3120, 1.0416; 4020, 0.9333; 4920, 0.7916; 5820, 0.65; 7200, 0.65]) annotation(
    Placement(visible = true, transformation(origin = {-58, 74}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(source.ports[1], receiver.fluid_a) annotation(
    Line(points = {{26, 2}, {-6, 2}, {-6, 12}, {-6, 12}}, color = {0, 127, 255}));
  connect(receiver.fluid_b, sink.ports[1]) annotation(
    Line(points = {{-2, 38}, {20, 38}}, color = {0, 127, 255}));
  connect(T_amb.y, receiver.Tamb) annotation(
    Line(points = {{13, 82}, {-8, 82}, {-8, 44}}, color = {0, 0, 127}));
  connect(fieldPort.port, receiver.heat) annotation(
    Line(points = {{-42, 34}, {-28, 34}, {-28, 34}, {-28, 34}}, color = {191, 0, 0}));
  connect(timeTable.y, fieldPort.Q_flow) annotation(
    Line(points = {{-74, 34}, {-64, 34}, {-64, 34}, {-62, 34}}, color = {0, 0, 127}));
  connect(timeTable1.y, source.m_flow_in) annotation(
    Line(points = {{69, 10}, {46, 10}}, color = {0, 0, 127}));
  connect(timeTable2.y, receiver.Wspd) annotation(
    Line(points = {{-47, 74}, {-12, 74}, {-12, 44}}, color = {0, 0, 127}));
  annotation(
    experiment(StartTime = 0, StopTime = 7200, Tolerance = 1e-06, Interval = 0.1));

end TestReceiverTransient0D;
