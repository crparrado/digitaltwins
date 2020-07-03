within SolarTherm;

model TestPBMasterControl_3_CRI_cold
  extends SolarTherm.Icons.Control;
  parameter SI.MassFlowRate m_flow_min = 0 "Mass flow rate when control off";
  parameter SI.MassFlowRate m_flow_max = 700 "Maximum mass flow rate";
  parameter Real Kp = -10 "Proportional constant";
  parameter Real y_start = 0 "Initial value of output";
  parameter Real Ti = 100 "Integer constant";
  parameter Real Td = 10 "";
  parameter Real Nd = 10 "";
  // parameter SI.Temperature T_ref = from_degC(300) "Setpoint of temperature";
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real uMax, uMin;
  parameter SI.Temperature T_ref = from_degC(400);
  //parameter SI.Temperature T_ref2 = from_degC(565);
  //parameter SI.Temperature t_max = from_degC(290);
  //Real m_flow;
  //New variable
  //Modelica.Blocks.Interfaces.RealInput L_mea_tk2;
  Modelica.Blocks.Continuous.LimPID limPID(Td = Td, Ti = Ti, controllerType = Modelica.Blocks.Types.SimpleController.PI, k = Kp, limitsAtInit = true, yMax = uMax, yMin = uMin, y_start = y_start) annotation(
    Placement(visible = true, transformation(origin = {18, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(extent = {{-112, 18}, {-72, 58}}, rotation = 0), iconTransformation(extent = {{-112, 18}, {-72, 58}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{78, 10}, {118, 50}}, rotation = 0), iconTransformation(extent = {{84, -74}, {124, -34}}, rotation = 0)));
  Modelica.Blocks.Logical.Switch switch annotation(
    Placement(visible = true, transformation(extent = {{60, 70}, {72, 82}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_flow_off_input(y = 0) annotation(
    Placement(visible = true, transformation(extent = {{-18, 48}, {8, 72}}, rotation = 0)));
  SolarTherm.Logictest logictest annotation(
    Placement(visible = true, transformation(origin = {-54, 6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(extent = {{-86, -56}, {-66, -36}}, rotation = 0)));
equation
// LimPID_PB.y = m_flow;
  connect(m_flow_off_input.y, switch.u3) annotation(
    Line(points = {{9, 60}, {44, 60}, {44, 71}, {59, 71}}, color = {0, 0, 127}));
  connect(T_mea, logictest.T_mea) annotation(
    Line(points = {{-92, 38}, {-84, 38}, {-84, 6}, {-64, 6}}, color = {0, 0, 127}));
  connect(T_mea, limPID.u_m) annotation(
    Line(points = {{-92, 38}, {-20, 38}, {-20, -32}, {18, -32}, {18, -8}, {18, -8}}, color = {0, 0, 127}));
  connect(logictest.y, switch.u2) annotation(
    Line(points = {{-43, 6}, {-28, 6}, {-28, 76}, {59, 76}}, color = {255, 0, 255}));
  connect(limPID.y, switch.u1) annotation(
    Line(points = {{30, 4}, {42, 4}, {42, 81}, {59, 81}}, color = {0, 0, 127}));
  connect(switch.y, m_flow_cold) annotation(
    Line(points = {{72, 76}, {80, 76}, {80, 56}, {54, 56}, {54, 30}, {98, 30}}, color = {0, 0, 127}));
  connect(T_ref_input.y, limPID.u_s) annotation(
    Line(points = {{-64, -46}, {-12, -46}, {-12, 4}, {6, 4}, {6, 4}}, color = {0, 0, 127}));
  annotation(
    uses(SolarTherm(version = "0.2"), Modelica(version = "3.2.3")));
end TestPBMasterControl_3_CRI_cold;