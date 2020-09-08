within SolarTherm;

model Logic_PB_Acciona_2
  //power block startup+ time of standby
  // Inputs y Outputs
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(transformation(extent = {{-128, -20}, {-88, 20}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{90, -20}, {130, 20}}, rotation = 0), iconTransformation(extent = {{90, 12}, {130, 52}}, rotation = 0)));
//  parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
//  parameter String refi_table = "outputs";
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0), iconTransformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{92, -70}, {132, -30}}, rotation = 0), iconTransformation(extent = {{90, -102}, {130, -62}}, rotation = 0)));
  
 
  Modelica.Blocks.Interfaces.BooleanOutput switch annotation (Placement(
    visible = true, transformation(origin = {112, 42}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {110, 80}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
   Modelica.Blocks.Interfaces.BooleanOutput switch2 annotation (Placement(
    visible = true, transformation(origin = {110, 82}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {110, -20}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  
  //////
  // Universal parameters
  parameter Modelica.SIunits.Time t_start = 0.5 * 3600;
  parameter Modelica.SIunits.Time t_standby = 2 * 3600;
  parameter Real m_flow_max;
  parameter Real m_flow_startup;
  parameter Real m_flow_standby;
  parameter Real level_on = 20;
  parameter Real level_off = 5;
  parameter Real level_hot_min = 10;
  parameter Real level_cold_max = 70;
 
  Integer blk_state(min = 1, max = 5) "Power block state";


 // SI.Time t_blk_w_now "Time of power block current warm-up event";
//  SI.Time t_blk_w_next "Time of power block next warm-up event";
//  SI.Time t_blk_c_now "Time of power block current cool-down event";
//  SI.Time t_blk_c_next "Time of power block next cool-down event";
//  SI.Time t_blk_synchro;
  Boolean on_charge;
  Boolean on_discharge;
  discrete Modelica.SIunits.Time t_off;
  discrete Modelica.SIunits.Time t_on;
  //Boolean on_charge_cold;
  //Boolean on_discharge_cold;
  
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(visible = true, transformation(origin = {0, 104}, extent = {{-20, -20}, {20, 20}}, rotation = -90), iconTransformation(extent = {{28, 76}, {68, 116}}, rotation = -90)));
  //  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
  //    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = -90, origin = {0, 104})));
//  Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);
  
initial equation

  blk_state = 1;
  //t_blk_w_now = 0;
//  t_blk_w_next = 0;
//  t_blk_c_now = 0;
//  t_blk_c_next = 0;
//  t_blk_synchro = 0;
  pre(t_off) = 0;
  pre(t_on) = 0;
  on_discharge= (level_hot>level_on) and (level_hot>level_off);
  
algorithm

//  when blk_state == 2 then
//    t_blk_w_now := time;
//    //t_blk_w_next := time + t_blk_on_delay;
//  end when;
  
    when level_hot>level_on then
      on_discharge := true;
    elsewhen level_hot<level_off then
      on_discharge := false;
    end when;
    
    when on_charge or on_discharge then
      t_on := time;
    end when;

    when not (on_charge or on_discharge) then
      t_off := time;
    end when;
    
//Power Block
  when blk_state == 1 and (time>t_start) then
    blk_state := 2;
  elsewhen blk_state == 2 and (time-t_on)>t_start/*time - t_blk_w_now > 392 * 60*/ then
    blk_state := 3;
  elsewhen blk_state == 3 and level_hot > level_on /*and level_cold < level_cold_max and P_SP >= 10*/ then
    blk_state := 4;
  elsewhen blk_state == 4 and level_hot<level_off then
    blk_state := 3;
    elsewhen blk_state == 3 and level_hot<0.5*level_off then
		blk_state := 5; // start draining
  elsewhen blk_state == 5 and level_hot<0.1*level_off then
    blk_state := 1;
  end when;
  
equation
 on_charge=m_flow_in>0;
//Nuevo Control

 if blk_state==4 then
    switch=true;
    switch2=false;
  else
    switch=false;
    switch2=true;
    
  end if;  

  if blk_state==2 or blk_state==5 then
    m_flow_hot=m_flow_startup;
    m_flow_cold = 185;
  elseif blk_state==3 then
    m_flow_hot=m_flow_standby;
    m_flow_cold = 100;
  else
    m_flow_hot=0;
    m_flow_cold = 0;
  end if;

//////

  annotation(
    Icon(coordinateSystem(preserveAspectRatio = false)),
    Diagram(coordinateSystem(preserveAspectRatio = false)),
    uses(Modelica(version = "3.2.2")));

end Logic_PB_Acciona_2;