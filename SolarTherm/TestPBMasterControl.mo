model TestPBMasterControl
extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{92, -20}, {132, 20}})));
  //New variable
  Modelica.Blocks.Interfaces.RealInput L_mea_tk2;
  SolarTherm.Models.Control.PID_AW_reset3 PI(Kp = Kp, Ti = Ti, Tt = 1, initType = Modelica.Blocks.Types.InitPID.InitialOutput, uMax = m_flow_max, uMin = m_flow_min, y_start = y_start) annotation(
    Placement(visible = true, transformation(extent = {{34, -10}, {54, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(extent = {{-124, 12}, {-84, 52}}, rotation = 0), iconTransformation(extent = {{-124, 12}, {-84, 52}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(extent = {{-42, -10}, {-22, 10}}, rotation = 0)));
  Modelica.Blocks.Math.Feedback feedback annotation(
    Placement(visible = true, transformation(extent = {{-8, 10}, {12, -10}}, rotation = 0)));
equation
  connect(T_ref_input.y, feedback.u1) annotation(
    Line(points = {{-21, 0}, {-6, 0}}, color = {0, 0, 127}));
  connect(PI.u, feedback.y) annotation(
    Line(points = {{32, 0}, {11, 0}}, color = {0, 0, 127}));
  connect(T_mea, feedback.u2) annotation(
    Line(points = {{-104, 32}, {2, 32}, {2, 8}}, color = {0, 0, 127}));
  connect(PI.y, m_flow) annotation(
    Line(points = {{56, 0}, {96, 0}, {96, 0}, {112, 0}}, color = {0, 0, 127}));
  annotation(
    uses(SolarTherm(version = "0.2"), Modelica(version = "3.2.3")));
end TestPBMasterControl;