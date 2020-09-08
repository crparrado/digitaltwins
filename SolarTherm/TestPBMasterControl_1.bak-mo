within SolarTherm;
model TestPBMasterControl_1

extends SolarTherm.Icons.Control;
  parameter SI.MassFlowRate m_flow_min=0 "Mass flow rate when control off";
  parameter SI.MassFlowRate m_flow_max=700 "Maximum mass flow rate";
  parameter Real Kp=-10 "Proportional constant";
  parameter Real y_start=300 "Initial value of output";
  parameter Real Ti=100 "Integer constant";
  parameter Real Td=100 "";
  parameter Real Nd=10 "";
  parameter SI.Temperature T_ref=from_degC(400) "Setpoint of temperature";
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real uMax, uMin;
  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{92, -20}, {132, 20}})));
  //New variable
  //Modelica.Blocks.Interfaces.RealInput L_mea_tk2;
  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(extent = {{-124, 12}, {-84, 52}}, rotation = 0), iconTransformation(extent = {{-124, 12}, {-84, 52}}, rotation = 0)));
 
  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(extent = {{-42, -10}, {-22, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Feedback feedback annotation(
    Placement(visible = true, transformation(extent = {{-8, 10}, {12, -10}}, rotation = 0)));
 SolarTherm.NewPI pid1(Kp = Kp, Nd = Nd, Td = Td, Ti = Ti, k = Kp, uMax = uMax, uMin = uMin)  annotation(
    Placement(visible = true, transformation(origin = {50, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(T_ref_input.y, feedback.u1) annotation(
    Line(points = {{-21, 0}, {-6, 0}}, color = {0, 0, 127}));
  connect(T_mea, feedback.u2) annotation(
    Line(points = {{-104, 32}, {2, 32}, {2, 8}}, color = {0, 0, 127}));
 connect(feedback.y, pid1.u) annotation(
    Line(points = {{12, 0}, {38, 0}, {38, 0}, {38, 0}}, color = {0, 0, 127}));
 connect(pid1.y, m_flow) annotation(
    Line(points = {{62, 0}, {96, 0}, {96, 0}, {112, 0}}, color = {0, 0, 127}));
  annotation(
    uses(SolarTherm(version = "0.2"), Modelica(version = "3.2.3")));
end TestPBMasterControl_1;