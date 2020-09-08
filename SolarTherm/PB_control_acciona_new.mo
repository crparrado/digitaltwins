within SolarTherm;

model PB_control_acciona_new
  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real m_flow_max = 1000 "Maximum flow to the power block";
  parameter Real m_flow_min = 0 "Minimum flow to the power block";
  parameter Real y_start = 300 "Initial value of output";
  parameter Real Ti = 1 "Integer constant";
  parameter Real Kp = -10 "Proportional constant";
  parameter SI.Temperature T_ref = from_degC(570) "Setpoint of temperature";
  Modelica.Blocks.Interfaces.RealInput L_mea annotation(
    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{92, -20}, {132, 20}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{98, -64}, {138, -24}}, rotation = 0), iconTransformation(extent = {{98, -64}, {138, -24}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
  //    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0),
  //    iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{92, -109}, {132, -69}}, rotation = 0), iconTransformation(extent = {{92, -109}, {132, -69}}, rotation = 0)));
//  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
//    Placement(visible = false, transformation(origin = {51, -55}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
//  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
//    Placement(visible = false, transformation(origin = {51, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
  SolarTherm.Models.Control.Level2Logic defocus_logic(y(start = false), level_max = L_df_on, level_min = L_df_off) annotation(
    Placement(transformation(extent = {{-17, -10}, {17, 10}}, rotation = -90, origin = {0, -51})));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));
  SolarTherm.Models.Control.PID_AW_reset3 PID(Tt = 1, uMax = m_flow_max, uMin = m_flow_min, initType = Modelica.Blocks.Types.InitPID.InitialOutput, y_start = y_start, Ti = Ti, Kp = Kp) annotation(
    Placement(visible = true, transformation(origin = {30, 80}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(origin = {-108, 80}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput L_cold annotation(
    Placement(visible = true, transformation(origin = {-108, 15}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealInput L_hot_2 annotation(
  //    Placement(visible = true, transformation(origin = {-108, -15}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  Modelica.Blocks.Math.Feedback feedback annotation(
    Placement(visible = true, transformation(origin = {-40, 80}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(origin = {-70, 60}, extent = {{-10, -10}, {10, 10}})));
  Modelica.Blocks.Sources.BooleanExpression ireset annotation(
    Placement(visible = true, transformation(origin = {-10, 72}, extent = {{-10, 10}, {10, -10}}, rotation = 0)));
  Modelica.Blocks.Logical.Switch switch annotation(
    Placement(visible = true, transformation(origin = {66, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.level2_logic_acciona logic(level_off = L_off, level_on = L_on, m_flow_max = m_flow_on, m_flow_standby = 0, m_flow_startup = m_flow_on / 2) annotation(
    Placement(visible = true, transformation(origin = {-2, 4}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Logical.Switch switch1 annotation(
    Placement(visible = true, transformation(origin = {70, -42}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Logical.Not not1 annotation(
    Placement(visible = true, transformation(origin = {32, -36}, extent = {{6, -6}, {-6, 6}}, rotation = 180)));
  Modelica.Blocks.Sources.RealExpression m_flow_off_input(y = 0) annotation(
    Placement(visible = true, transformation(extent = {{16, -84}, {42, -60}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression realExpression1(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {63, -92}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(defocus_logic.level_ref, L_mea) annotation(
    Line(points = {{0, -34}, {0, -34}, {0, -20}, {-38, -20}, {-38, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{0, -69.36}, {0, -69.36}, {0, -82}, {0, -82}, {0, -114}}, color = {255, 0, 255}));
//  connect(m_pump_2.y, m_pump2);
//  connect(m_tank_2.y, m_tank2) annotation(
//    Line);
  
  connect(T_mea, feedback.u1) annotation(
    Line(points = {{-108, 80}, {-50, 80}, {-50, 80}, {-48, 80}}, color = {0, 0, 127}));
  connect(T_ref_input.y, feedback.u2) annotation(
    Line(points = {{-58, 60}, {-40, 60}, {-40, 72}, {-40, 72}}, color = {0, 0, 127}));
  connect(feedback.y, PID.u) annotation(
    Line(points = {{-30, 80}, {18, 80}}, color = {0, 0, 127}));
  connect(ireset.y, PID.reset) annotation(
    Line(points = {{1, 72}, {17, 72}}, color = {255, 0, 255}));
  connect(PID.y, switch.u1) annotation(
    Line(points = {{40, 80}, {47, 80}, {47, 8}, {54, 8}}, color = {0, 0, 127}));
  connect(switch.y, m_flow) annotation(
    Line(points = {{78, 0}, {94, 0}, {94, 0}, {112, 0}}, color = {0, 0, 127}));
  connect(m_flow_in, logic.m_flow_in) annotation(
    Line(points = {{-108, 50}, {-2, 50}, {-2, 14}}, color = {0, 0, 127}));
  connect(logic.m_flow, switch.u3) annotation(
    Line(points = {{9, 4}, {22, 4}, {22, -8}, {54, -8}}, color = {0, 0, 127}));
  connect(logic.switch, switch.u2) annotation(
    Line(points = {{10, 10}, {32, 10}, {32, 0}, {54, 0}, {54, 0}}, color = {255, 0, 255}));
  connect(switch1.y, m_flow_cold) annotation(
    Line(points = {{82, -42}, {102, -42}, {102, -44}, {118, -44}}, color = {0, 0, 127}));
  connect(logic.switch, not1.u) annotation(
    Line(points = {{10, 10}, {18, 10}, {18, -36}, {24, -36}, {24, -36}}, color = {255, 0, 255}));
  connect(not1.y, switch1.u2) annotation(
    Line(points = {{38, -36}, {46, -36}, {46, -42}, {58, -42}, {58, -42}}, color = {255, 0, 255}));
  connect(logic.m_flow_cold, switch1.u1) annotation(
    Line(points = {{10, -2}, {16, -2}, {16, -26}, {46, -26}, {46, -34}, {58, -34}, {58, -34}}, color = {0, 0, 127}));
  connect(m_flow_off_input.y, switch1.u3) annotation(
    Line(points = {{44, -72}, {52, -72}, {52, -50}, {58, -50}, {58, -50}}, color = {0, 0, 127}));
//  connect(realExpression.y, m_pump2) annotation(
//    Line(points = {{72, 50}, {98, 50}, {98, 52}, {112, 52}}, color = {0, 0, 127}));
  
  connect(realExpression1.y, m_tank2) annotation(
    Line(points = {{74, -92}, {96, -92}, {96, -88}, {112, -88}}, color = {0, 0, 127}));
  connect(L_cold, logic.level_cold) annotation(
    Line(points = {{-108, 16}, {-50, 16}, {-50, 2}, {-12, 2}, {-12, 2}}, color = {0, 0, 127}));
  connect(L_mea, logic.level) annotation(
    Line(points = {{-108, -50}, {-62, -50}, {-62, 10}, {-12, 10}, {-12, 10}}, color = {0, 0, 127}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end PB_control_acciona_new;