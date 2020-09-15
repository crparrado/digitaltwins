within SolarTherm;

model Logic_PB_Acciona_3
  //power block startup+ time of standby
  // Inputs y Outputs
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(transformation(extent = {{-128, -20}, {-88, 20}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{90, -20}, {130, 20}}, rotation = 0), iconTransformation(extent = {{90, 12}, {130, 52}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0), iconTransformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{92, -70}, {132, -30}}, rotation = 0), iconTransformation(extent = {{90, -102}, {130, -62}}, rotation = 0)));
  
 
//  Modelica.Blocks.Interfaces.BooleanOutput switch annotation (Placement(
//    visible = true, transformation(origin = {112, 42}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {110, 80}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
//   Modelica.Blocks.Interfaces.BooleanOutput switch2 annotation (Placement(
//    visible = true, transformation(origin = {110, 82}, extent = {{-20, -20}, {20, 20}}, rotation = 0), iconTransformation(origin = {110, -20}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  
  //////
  // Universal parameters
  parameter Modelica.SIunits.Time t_start = 0.5 * 3600;
  parameter Modelica.SIunits.Time t_standby = 2 * 3600;
  parameter Real m_flow_max;
  parameter Real m_flow_startup;
  parameter Real m_flow_standby;
  parameter Real level_on_hot = 10;
  parameter Real level_off_hot = 5;
  parameter Real level_on_cold = 20;
  parameter Real level_off_cold = 15;
  parameter Real level_hot_min = 10;
  parameter Real level_cold_max = 70;
 
  Integer blk_state(min = 1, max = 5) "Power block state";


 // SI.Time t_blk_w_now "Time of power block current warm-up event";
//  SI.Time t_blk_w_next "Time of power block next warm-up event";
//  SI.Time t_blk_c_now "Time of power block current cool-down event";
//  SI.Time t_blk_c_next "Time of power block next cool-down event";
//  SI.Time t_blk_synchro;

  Boolean on_charge;
  Boolean on_discharge_hot;
  Boolean on_discharge_cold;
  Boolean cond_ramp_down;
  Boolean cond_ramp_up;
  Boolean cond_full_load;
  discrete Modelica.SIunits.Time t_ramp_on;
  discrete Modelica.SIunits.Time t_off;
  discrete Modelica.SIunits.Time t_on;
  discrete Modelica.SIunits.Time t_ramp_down;
  
  
  //Boolean on_charge_cold;
  //Boolean on_discharge_cold;
  
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(visible = true, transformation(origin = {0, 104}, extent = {{-20, -20}, {20, 20}}, rotation = -90), iconTransformation(extent = {{28, 76}, {68, 116}}, rotation = -90)));
  //  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
  //    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = -90, origin = {0, 104})));
  
initial equation

  blk_state = 1;
 
  pre(t_ramp_on) = 0;
  pre(t_off) = 0;
  pre(t_on) = 0;
  pre(t_ramp_down) = 0;
  on_discharge_hot= (level_hot>level_on_hot) and (level_hot>level_off_hot);
  on_discharge_cold= (level_cold>level_on_cold) and (level_cold>level_off_cold);
  cond_ramp_down= (level_hot<level_on_hot) and (level_hot<level_off_hot);
  cond_ramp_up= (level_hot>level_on_hot) and (level_hot>level_off_hot);
  cond_full_load= (level_hot>level_on_hot) and (level_hot>level_off_hot);
algorithm

// On Discharge Hot Tank
    when level_hot>level_on_hot then
      on_discharge_hot := true;
    elsewhen level_hot<level_off_hot then
      on_discharge_hot := false;
    end when;
 
// On Discharge Cold Tank  
    when level_cold>level_on_cold then
      on_discharge_cold := true;
    elsewhen level_cold<level_off_cold then
      on_discharge_cold := false;
    end when;
    
// Counting the on time when is charge or discharge   
    when on_charge or on_discharge_hot then
      t_on := time;
    end when;
    
// Counting the off time when is charge or discharge   
    when not (on_charge or on_discharge_hot) then
      t_off := time;
    end when;
//Counting ramping up on    
    when cond_ramp_up then
      t_ramp_on := time;
    end when;
 
 //Counting ramping down    
    when cond_ramp_down then
      t_ramp_down := time;
    end when;
    
// Condition Ramp Down
    //when level_hot < level_on_hot then
    when level_hot < level_off_hot then //we mush shut down PB because hot tank is almost empty
      cond_ramp_down:= true;
    elsewhen level_hot > level_on_hot then //elsewhen level_hot > level_off_hot then
      cond_ramp_down := false;
    end when;
 
 // Condition Ramp Up and full load
    when level_hot > level_on_hot then
      cond_ramp_up := true;
      cond_full_load := true;
    elsewhen level_hot < level_off_hot then
      cond_ramp_up := false;
      cond_full_load := false;
    end when; 
    
    
    //*time - t_blk_w_now > 392 * 60*/
//Power Block
    when blk_state == 1 and (time>t_start) then // Off
      blk_state := 2;
    elsewhen blk_state == 2 and (time-t_on)>t_standby then //Filling
      blk_state := 3;
    elsewhen blk_state == 3 and cond_ramp_up then // Standby
      blk_state := 4;
    //elsewhen blk_state == 4 and cond_full_load then // Full load - Operation
    elsewhen blk_state == 4 and (time > t_ramp_on + 879.2) then // Full load - Operation
      blk_state := 5;
    elsewhen blk_state == 5 and cond_ramp_down then // Ramp down
      blk_state := 6;
    //elsewhen blk_state == 6 and cond_ramp_up then // Back to standby 
    elsewhen blk_state == 6 and (time > t_ramp_down + 1800.0) then // Back to standby 
      blk_state := 3; // Back to standby
  end when;
 
    
equation
 on_charge=m_flow_in>0;
//Nuevo Control

  if blk_state==4 then
    m_flow_hot = 0.77*(time - t_ramp_on); //0.077*dt=677, dt=8792.2 0.77
	m_flow_cold = 0;
	
  elseif blk_state==3 then
    m_flow_hot = 0;
	m_flow_cold = 185;

  elseif blk_state==2 then
    m_flow_hot = 0;
	//m_flow_cold = 0.64236*(time - t_ramp_on)-1156.25;
	m_flow_cold = min(0.64236*(time - t_ramp_on)-1156.25,185.0);
	
	
	
  elseif blk_state==5 then
    m_flow_hot = 677;
	m_flow_cold = 0;
	
  elseif blk_state==6 then
//    m_flow_hot = -0.77*(t_ramp_down-time);
    m_flow_hot = 0;
	m_flow_cold = 100;

  else
    m_flow_hot = 0;
	m_flow_cold = 0;
    
  end if;  

//////

  annotation(
    Icon(coordinateSystem(preserveAspectRatio = false)),
    Diagram(coordinateSystem(preserveAspectRatio = false)),
    uses(Modelica(version = "3.2.2")));

end Logic_PB_Acciona_3;