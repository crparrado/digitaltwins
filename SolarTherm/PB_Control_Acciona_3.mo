within SolarTherm;

model PB_Control_Acciona_3
  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
  parameter String refi_table = "outputs";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real m_flow_max = 674.1 "Maximum flow to the power block";
  parameter Real m_flow_min = 0 "Minimum flow to the power block";
  parameter Real y_start = 300 "Initial value of output";
  parameter Real Ti = 1 "Integer constant";
  parameter Real Kp = -10 "Proportional constant";
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(visible = true, transformation(extent = {{-134, -112}, {-94, -72}}, rotation = 0), iconTransformation(extent = {{-128, -94}, {-88, -54}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-132, -22}, {-92, 18}}, rotation = 0), iconTransformation(extent = {{-128, 12}, {-88, 52}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -40}, {132, 0}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 8}, {132, 48}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{94, -57}, {134, -17}}, rotation = 0), iconTransformation(extent = {{92, -95}, {132, -55}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{92, -112}, {132, -72}}, rotation = 0), iconTransformation(extent = {{92, 58}, {132, 98}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T(final quantity = "ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(visible = true, transformation(origin = {-112, -60}, extent = {{20, -20}, {-20, 20}}, rotation = 180), iconTransformation(origin = {-109, 81}, extent = {{19, -19}, {-19, 19}}, rotation = 180)));
  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {63, 71}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {75, -38}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  parameter SI.Temperature T_ref = from_degC(570) "Setpoint of temperature";
  parameter SI.Temperature T_ref_cold = from_degC(290) "Setpoint of temperature";
  //  Modelica.Blocks.Interfaces.RealInput level_hot_tk2 annotation(
  //    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  //  Modelica.Blocks.Interaction.Show.RealValue realValue annotation(
  //    Placement(transformation(extent = {{-68, -8}, {-28, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  SolarTherm.Models.Control.Level2Logic defocus_logic(y(start = false), level_max = L_df_on, level_min = L_df_off) annotation(
    Placement(visible = true, transformation(origin = {-41, -70}, extent = {{-10, -5}, {10, 5}}, rotation = -90)));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(visible = true, transformation(origin = {-40, -110}, extent = {{20, -20}, {-20, 20}}, rotation = 90), iconTransformation(origin = {-40, -110}, extent = {{20, -20}, {-20, 20}}, rotation = 90)));
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(visible = true, transformation(origin = {-112, -32}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-108, -20}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);
  //  Modelica.Blocks.Interfaces.RealInput P_SP annotation(
  //    Placement(visible = true, transformation(extent = {{-132, 4}, {-92, 44}}, rotation = 0), iconTransformation(extent = {{-132, 4}, {-92, 44}}, rotation = 0)));
  //SI.MassFlowRate m_flow_sgp;
  SolarTherm.Logic_PB_Acciona_3 logic_PB_Acciona_3 annotation(
    Placement(visible = true, transformation(origin = {-6, 24}, extent = {{-28, -28}, {28, 28}}, rotation = 0)));
equation
  connect(defocus_logic.level_ref, level_hot) annotation(
    Line(points = {{-41, -60}, {-41, -40}, {-52, -40}, {-52, -92}, {-114, -92}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{-41, -81}, {-41, -103.5}, {-40, -103.5}, {-40, -110}}, color = {255, 0, 255}));
//  connect(T, logic_PB_Acciona_2.t_sgs) annotation(
//    Line(points = {{-112, -60}, {-78, -60}, {-78, 4}, {-20, 4}, {-20, 1}, {-19, 1}}, color = {0, 0, 127}));
//  connect(P_SP, logic_PB_Acciona_2.P_SP) annotation(
//    Line(points = {{-112, 24}, {-8, 24}, {-8, 8}}, color = {0, 0, 127}));
  connect(m_tank_2.y, m_tank2) annotation(
    Line(points = {{86, -38}, {114, -38}, {114, -36}}, color = {0, 0, 127}));
  connect(m_pump_2.y, m_pump2) annotation(
    Line(points = {{74, 72}, {84, 72}, {84, 50}, {112, 50}, {112, 52}}, color = {0, 0, 127}));
  connect(m_flow_in, logic_PB_Acciona_3.m_flow_in) annotation(
    Line(points = {{-112, -32}, {-68, -32}, {-68, 80}, {8, 80}, {8, 50}, {8, 50}}, color = {0, 0, 127}));
  connect(level_cold, logic_PB_Acciona_3.level_cold) annotation(
    Line(points = {{-112, -2}, {-56, -2}, {-56, 10}, {-36, 10}, {-36, 10}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona_3.m_flow_cold, m_flow_cold) annotation(
    Line(points = {{24, 2}, {56, 2}, {56, -92}, {112, -92}, {112, -92}}, color = {0, 0, 127}));
  connect(level_hot, logic_PB_Acciona_3.level_hot) annotation(
    Line(points = {{-114, -92}, {-60, -92}, {-60, 26}, {-36, 26}, {-36, 24}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona_3.m_flow_hot, m_flow_hot) annotation(
    Line(points = {{24, 32}, {68, 32}, {68, 0}, {112, 0}, {112, 0}}, color = {0, 0, 127}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end PB_Control_Acciona_3;