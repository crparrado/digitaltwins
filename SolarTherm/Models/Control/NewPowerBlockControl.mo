within SolarTherm.Models.Control;

model NewPowerBlockControl
  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 10 "Level of start discharge";
  parameter Real L_off = 5 "Level of stop discharge";
  parameter Real L_df_on = 80 "Level of start defocus";
  parameter Real L_df_off = 70 "Level of stop defocus";
  parameter SI.SpecificEnergy k_loss = 0.55e3 "Hot tank parasitic power coefficient";
  parameter Real dispatch_factor = 1 "Operation strategy dispatch factor";
  SI.Power W_loss;

  Boolean on_discharge_tk1;
  Boolean on_discharge_tk2;
  Boolean charge_tnk1;
  Boolean charge_tnk2;  
  
  // Level measurement
  Modelica.Blocks.Interfaces.RealInput L_mea annotation(
    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
  Modelica.Blocks.Interfaces.RealInput L_mea2 annotation(
    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));

  // Flow measurement
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));

  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));

  Modelica.Blocks.Interfaces.RealOutput m_flow2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -20}, {132, 20}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput m_flow_charge_tk2 annotation(
    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -75}, {132, -35}}, rotation = 0)));

algorithm

   when L_mea>L_on and L_mea2>L_on and L_mea>L_mea2 then
      on_discharge_tk1 := true;
      on_discharge_tk2 := false;
   elsewhen L_mea>L_on and L_mea2>L_on and L_mea2>L_mea then
      on_discharge_tk1 := false;
      on_discharge_tk2 := true;
   elsewhen L_mea>L_on and L_mea2<L_off then
     on_discharge_tk1 := true;
     on_discharge_tk2 := false;
   elsewhen L_mea<L_off and L_mea2>L_on then
     on_discharge_tk1 := false;
     on_discharge_tk2 := true;
   elsewhen L_mea<L_off and L_mea2<L_off then
     on_discharge_tk1 := false;
     on_discharge_tk2 := false;
   end when;

  when L_mea < L_df_on and L_mea2 < L_df_on and L_mea >= L_mea2 then // si ambos estan habiles para ser cargados, cargue el mas lleno
        charge_tnk1:=true;
        charge_tnk2:=false;
  elsewhen L_mea < L_df_on and L_mea2 < L_df_on and L_mea < L_mea2 then
        charge_tnk1:=false;
        charge_tnk2:=true; // sino, cargue el que este bajo los niveles  permitidos
  elsewhen (L_mea >= L_df_on) and (L_mea2 < L_df_on) then 
    charge_tnk1:=false; // Si el tk1 esta lleno, llene el tk2 si se puede
    charge_tnk2:=true;  
  elsewhen (L_mea < L_df_on) and (L_mea2 >= L_df_on) then
    charge_tnk1:=true;  // Si el tk2 esta lleno, llene el tk1 si se puede
    charge_tnk2:=false;
  elsewhen (L_mea >= L_df_on) and (L_mea2 >= L_df_on) then
    charge_tnk1:=true;
    charge_tnk2:=false;
    defocus := true;
  end when;
 
equation

  W_loss = (abs(m_flow_in - m_flow) + m_flow) * k_loss;

  if on_discharge_tk1 then
    m_flow = dispatch_factor*m_flow_on;
    m_flow2 = 0;
  elseif on_discharge_tk2 then
    m_flow2 = dispatch_factor*m_flow_on;
    m_flow = 0;
  end if;

  if charge_tnk1 then
    m_flow_charge_tk2 = 0;
  elseif charge_tnk2 then
    m_flow_charge_tk2 = m_flow_in;
  end if;

  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end NewPowerBlockControl;
