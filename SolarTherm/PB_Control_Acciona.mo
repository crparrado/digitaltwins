within SolarTherm;

model PB_Control_Acciona//SI.MassFlowRate m_flow_sgp;

  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
  parameter String refi_table = "outputs";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(visible = true, transformation(extent = {{-134, -112}, {-94, -72}}, rotation = 0), iconTransformation(extent = {{-132, -112}, {-92, -72}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-132, -22}, {-92, 18}}, rotation = 0), iconTransformation(extent = {{-132, -22}, {-92, 18}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -40}, {132, 0}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 8}, {132, 48}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -95}, {132, -55}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{92, 68}, {132, 108}}, rotation = 0), iconTransformation(extent = {{92, 58}, {132, 98}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T(final quantity = "ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(visible = true, transformation(origin = {-112, -60}, extent = {{20, -20}, {-20, 20}}, rotation = 180), iconTransformation(origin = {-113, 41}, extent = {{19, -19}, {-19, 19}}, rotation = 180)));
  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, -55}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealInput level_hot_tk2 annotation(
  //    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  //  Modelica.Blocks.Interaction.Show.RealValue realValue annotation(
  //    Placement(transformation(extent = {{-68, -8}, {-28, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  SolarTherm.Models.Control.Level2Logic defocus_logic(y(start = false), level_max = L_df_on, level_min = L_df_off) annotation(
    Placement(visible = true, transformation(origin = {-3.55271e-15, -71}, extent = {{-17, -10}, {17, 10}}, rotation = -90)));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(visible = true, transformation(origin = {-112, -32}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {-112, -48}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  SolarTherm.Logic_PB_Acciona logic_PB_Acciona annotation(
    Placement(visible = true, transformation(origin = {-2, -15}, extent = {{-16, -19}, {16, 19}}, rotation = 0)));
  Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);
  Modelica.Blocks.Interfaces.RealInput P_SP annotation(
    Placement(visible = true, transformation(extent = {{-132, 4}, {-92, 44}}, rotation = 0), iconTransformation(extent = {{-132, 62}, {-92, 102}}, rotation = 0)));
  equation
  connect(defocus_logic.level_ref, level_hot) annotation(
    Line(points = {{0, -54}, {0, -40}, {-52, -40}, {-52, -92}, {-114, -92}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{0, -89}, {0, -114}}, color = {255, 0, 255}));
  connect(m_pump_2.y, m_pump2) annotation(
    Line(points = {{61, -55}, {92, -55}}, color = {0, 0, 127}));
  connect(m_tank_2.y, m_tank2) annotation(
    Line(points = {{61, 52}, {92, 52}}, color = {0, 0, 127}));
//  connect(level_hot_tk2, realValue.number)
// P_SGS = ref_table.y[10];
//    annotation (Line(points={{-88,2},{-80,2},{-80,7},{-74,7}}, color={0,0,127}));
//  extends SolarTherm.Icons.Control;
//  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
//  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
//  parameter Real L_on = 10 "Level of start discharge";
//  parameter Real L_off = 5 "Level of stop discharge";
//  parameter Real L_df_on = 80 "Level of start defocus";
//  parameter Real L_df_off = 70 "Level of stop defocus";
//  parameter SI.SpecificEnergy k_loss = 0.55e3 "Hot tank parasitic power coefficient";
//  parameter Real dispatch_factor = 1 "Operation strategy dispatch factor";
//  SI.Power W_loss;
//  Boolean on_discharge_tk1;
//  Boolean on_discharge_tk2;
//  Boolean charge_tnk1;
//  Boolean charge_tnk2;
//  // Level measurement
//  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
//    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
//  Modelica.Blocks.Interfaces.RealInput level_hot2 annotation(
//    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
//  // Flow measurement
//  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
//    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
//  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
//    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));
//  Modelica.Blocks.Interfaces.RealOutput m_flow2 annotation(
//    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));
//  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
//    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -20}, {132, 20}}, rotation = 0)));
//  Modelica.Blocks.Interfaces.RealOutput m_flow_charge_tk2 annotation(
//    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -75}, {132, -35}}, rotation = 0)));
//algorithm
//   when level_hot>L_on and level_hot2>L_on and level_hot>level_hot2 then
//      on_discharge_tk1 := true;
//      on_discharge_tk2 := false;
//   elsewhen level_hot>L_on and level_hot2>L_on and level_hot2>level_hot then
//      on_discharge_tk1 := false;
//      on_discharge_tk2 := true;
//   elsewhen level_hot>L_on and level_hot2<L_off then
//     on_discharge_tk1 := true;
//     on_discharge_tk2 := false;
//   elsewhen level_hot<L_off and level_hot2>L_on then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := true;
//   elsewhen level_hot<L_off and level_hot2<L_off then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := false;
//   end when;
//  when level_hot < L_df_on and level_hot2 < L_df_on and level_hot >= level_hot2 then // si ambos estan habiles para ser cargados, cargue el mas lleno
//        charge_tnk1:=true;
//        charge_tnk2:=false;
//  elsewhen level_hot < L_df_on and level_hot2 < L_df_on and level_hot < level_hot2 then
//        charge_tnk1:=false;
//        charge_tnk2:=true; // sino, cargue el que este bajo los niveles  permitidos
//  elsewhen (level_hot >= L_df_on) and (level_hot2 < L_df_on) then
//    charge_tnk1:=false; // Si el tk1 esta lleno, llene el tk2 si se puede
//    charge_tnk2:=true;
//  elsewhen (level_hot < L_df_on) and (level_hot2 >= L_df_on) then
//    charge_tnk1:=true;  // Si el tk2 esta lleno, llene el tk1 si se puede
//    charge_tnk2:=false;
//  elsewhen (level_hot >= L_df_on) and (level_hot2 >= L_df_on) then
//    charge_tnk1:=true;
//    charge_tnk2:=false;
//    defocus := true;
//  end when;
//equation
//  W_loss = (abs(m_flow_in - m_flow) + m_flow) * k_loss;
////  if on_discharge_tk1 then
////    m_flow = dispatch_factor*m_flow_on;
////    m_flow2 = 0;
////  elseif on_discharge_tk2 then
////    m_flow2 = dispatch_factor*m_flow_on;
////    m_flow = 0;
////  end if;
////  if charge_tnk1 then
////    m_flow_charge_tk2 = 0;
////  elseif charge_tnk2 then
////    m_flow_charge_tk2 = m_flow_in;
////  end if;
//  annotation(
//    Documentation(revisions = "<html>
//<ul>
//<li>Alberto de la Calle:<br>Released first version. </li>
//</ul>
//</html>"));
  connect(level_cold, logic_PB_Acciona.level_cold) annotation(
    Line(points = {{-112, -2}, {-52, -2}, {-52, -25}, {-19, -25}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.level_hot, level_hot) annotation(
    Line(points = {{-19, -15}, {-62, -15}, {-62, -92}, {-114, -92}}, color = {0, 0, 127}));
  connect(T, logic_PB_Acciona.t_sgs) annotation(
    Line(points = {{-112, -60}, {-68, -60}, {-68, -5}, {-19, -5}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.m_flow_cold, m_flow_cold) annotation(
    Line(points = {{16, -24.5}, {32, -24.5}, {32, 88}, {112, 88}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.m_flow_hot, m_flow_hot) annotation(
    Line(points = {{16, -15}, {50, -15}, {50, 0}, {112, 0}}, color = {0, 0, 127}));
  connect(P_SP, logic_PB_Acciona.P_SP) annotation(
    Line(points = {{-112, 24}, {-8, 24}, {-8, 4}}, color = {0, 0, 127}));
  connect(m_flow_in, logic_PB_Acciona.m_flow_in) annotation(
    Line(points = {{-112, -32}, {-80, -32}, {-80, 26}, {6, 26}, {6, 6}, {6, 6}, {6, 4}}, color = {0, 0, 127}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end PB_Control_Acciona;