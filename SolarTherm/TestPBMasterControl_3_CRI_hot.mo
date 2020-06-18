within SolarTherm;

model TestPBMasterControl_3_CRI_hot
  extends SolarTherm.Icons.Control;
  parameter SI.MassFlowRate m_flow_min = 0 "Mass flow rate when control off";
  parameter SI.MassFlowRate m_flow_max = 700 "Maximum mass flow rate";
  parameter Real Kp = -10 "Proportional constant";
  parameter Real y_start = 0 "Initial value of output";
  parameter Real Ti = 100 "Integer constant";
  parameter Real Td = 10 "";
  parameter Real Nd = 10 "";
  parameter SI.Temperature T_ref = from_degC(400) "Setpoint of temperature";
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real uMax, uMin;
  //Real m_flow;
  Modelica.Blocks.Interfaces.RealInput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{60, 52}, {100, 92}}, rotation = 0), iconTransformation(extent = {{86, 42}, {126, 82}}, rotation = 0)));
  //New variable
  //Modelica.Blocks.Interfaces.RealInput L_mea_tk2;
  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(extent = {{-124, -24}, {-84, 16}}, rotation = 0), iconTransformation(extent = {{-124, -24}, {-84, 16}}, rotation = 0)));
  Modelica.Blocks.Continuous.LimPID LimPID_PB(Td = Td, Ti = Ti, controllerType = Modelica.Blocks.Types.SimpleController.PI, k = Kp, limitsAtInit = true, yMax = uMax, yMin = uMin, y_start = y_start) annotation(
    Placement(visible = true, transformation(origin = {2, 2}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(extent = {{-78, 24}, {-58, 44}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_flow_off_input(y = 0) annotation(
    Placement(visible = true, transformation(extent = {{-22, 52}, {4, 76}}, rotation = 0)));
  Modelica.Blocks.Logical.Switch switch annotation(
    Placement(visible = true, transformation(origin = {39, 81}, extent = {{-7, -7}, {7, 7}}, rotation = 0)));
  SolarTherm.Logictest_hot logictest_hot annotation(
    Placement(visible = true, transformation(origin = {-48, 76}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
//if T_mea <= from_degC(290) then
//  uMax = 1e-3;
//  else
//  uMax = 680;
//  end if;
  connect(T_mea, LimPID_PB.u_m) annotation(
    Line(points = {{-104, -4}, {-68, -4}, {-68, -46}, {2, -46}, {2, -10}, {2, -10}}, color = {0, 0, 127}));
  connect(T_ref_input.y, LimPID_PB.u_s) annotation(
    Line(points = {{-57, 34}, {-44, 34}, {-44, 2}, {-10, 2}}, color = {0, 0, 127}));
  connect(m_flow_off_input.y, switch.u3) annotation(
    Line(points = {{6, 64}, {18, 64}, {18, 75}, {31, 75}}, color = {0, 0, 127}));
  connect(LimPID_PB.y, switch.u1) annotation(
    Line(points = {{14, 2}, {20, 2}, {20, 87}, {31, 87}}, color = {0, 0, 127}));
  connect(switch.y, m_flow_hot) annotation(
    Line(points = {{47, 81}, {58, 81}, {58, 74}, {80, 74}, {80, 72}}, color = {0, 0, 127}));
  connect(T_mea, logictest_hot.T_mea) annotation(
    Line(points = {{-104, -4}, {-86, -4}, {-86, 76}, {-58, 76}, {-58, 76}}, color = {0, 0, 127}));
  connect(logictest_hot.y, switch.u2) annotation(
    Line(points = {{-38, 76}, {-6, 76}, {-6, 81}, {31, 81}}, color = {255, 0, 255}));
  annotation(
    uses(SolarTherm(version = "0.2"), Modelica(version = "3.2.3")));
end TestPBMasterControl_3_CRI_hot;