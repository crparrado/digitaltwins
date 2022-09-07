within SolarTherm.Models.Control;
model NewStartUpLogic5
  Modelica.Blocks.Interfaces.RealInput level
    annotation (Placement(transformation(extent={{-128,-20},{-88,20}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow
    annotation (Placement(transformation(extent={{90,-20},{130,20}})));

  parameter Modelica.SIunits.Time t_start=0.5*3600;
  parameter Modelica.SIunits.Time t_standby=2*3600;
  parameter Real m_flow_max;
  parameter Real m_flow_startup;
  parameter Real m_flow_standby;
  parameter Real level_on=20;
  parameter Real level_off=5;
//  Boolean standby;
//  Boolean startup(start=false, fixed=true);
  Boolean on_charge;
  Boolean on_discharge;
  Integer blk_state(min=1, max=5) "Power block state";

   discrete Modelica.SIunits.Time t_off;
   discrete Modelica.SIunits.Time t_on;
public
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation (Placement(
    transformation(
      extent={{-20,-20},{20,20}},
      rotation=-90,
      origin={0,104})));

  Modelica.Blocks.Interfaces.BooleanOutput switch annotation (Placement(
    transformation(
      extent={{-20,-20},{20,20}},
      rotation=0,
      origin={110,50})));

initial equation
   pre(t_off) = 0;
   pre(t_on) = 0;
   on_discharge= (level>level_on) and (level>level_off);
   blk_state = 1;

algorithm
    when level>level_on then
      on_discharge := true;
    elsewhen level<level_off then
      on_discharge := false;
    end when;

    when on_charge or on_discharge then
      t_on := time;
    end when;

    when not (on_charge or on_discharge) then
      t_off := time;
    end when;

    when blk_state == 1 and (time>t_start) then
		blk_state := 2; // preheating ends, switching to filling with cold salt
	elsewhen blk_state == 2 and (time-t_on)>t_start then
		blk_state := 3; // shell is full, switching to standby (steady-state cold salt flow)
	elsewhen blk_state == 3 and level>level_on then
		blk_state := 4; // able to discharge, switching to PID control
	elsewhen blk_state == 4 and level<level_off then
		blk_state := 3; // stop discharging, switching to standby (steady-state cold salt flow)
	elsewhen blk_state == 3 and level<0.5*level_off then
		blk_state := 5; // start draining
	elsewhen blk_state == 5 and level<0.1*level_off then
		blk_state := 1; // back to preheating
	end when;

equation
   on_charge=m_flow_in>0;

  if blk_state==4 then
    switch=true;
  else
    switch=false;
  end if;  

  if blk_state==2 or blk_state==5 then
    m_flow=m_flow_startup;
  elseif blk_state==3 then
    m_flow=m_flow_standby;
  else
    m_flow=0;
  end if;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    uses(Modelica(version="3.2.2")));
end NewStartUpLogic5;
