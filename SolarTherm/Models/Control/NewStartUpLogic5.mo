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

  //New variables
  Boolean on_discharge_tk2;
  Modelica.Blocks.Interfaces.RealInput level_tk2;
  Modelica.Blocks.Interfaces.RealOutput m_flow_tk2;
  Modelica.Blocks.Interfaces.RealOutput m_flow_pump2;

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

  on_discharge = (level>level_on) and (level>level_off); //on_discharge=true if level is greather than both trigger levels
  on_discharge_tk2 = (level_tk2>level_on) and (level_tk2>level_off); //on_discharge_tk2=true if level is greather than both trigger levels

equation

   //Tanks charging
   on_charge = m_flow_in>0; //on_charge=true if there is flow comming from the receiver to the tanks at current time step

   //Tank 1 able for discharging
   when level>level_on then //on_discharge=true if level>level_on becomes true
     on_discharge = true;
   elsewhen level<level_off then //on_discharge=false if level<level_off becomes true
     on_discharge = false;
   end when;
   
   //Tank 2 able for discharging
   when level_tk2>level_on then
      on_discharge_tk2 = true;  //on_discharge_tk2=true if level>level_on becomes true
   elsewhen level_tk2<level_off then
      on_discharge_tk2 = false;  //on_discharge_tk2=false if level<level_off becomes true
   end when;

   //Start time
   when on_charge or on_discharge or on_discharge_tk2 then
     t_on = time;  //t_on=time if on_charge or on_discharge or on_discharge_tk2 becomes true
   end when;

   //Stop time
   when not (on_charge or on_discharge or on_discharge_tk2) then //t_off=time if on_charge or on_discharge or on_discharge_tk2 becomes false
     t_off = time;
   end when;

   //Power block starting up
   when t_on-(t_off+t_standby)>0 then //startup=true if t_on>(t_off+t_standby) becomes true
     startup=true;
   elsewhen (time-t_on)>t_start then //startup=flase if (time-t_on)>t_start becomes true
     startup=false;
   end when;

   standby = (time-t_off)<t_standby; //standby=true if (time-t_off)<t_standby at current time step

  if on_charge or on_discharge or on_discharge_tk2 then // Tanks are charging or discharging
    if startup then
      m_flow=m_flow_startup; //If power block is starting up
      m_flow_tk2=1e-3;
      m_flow_pump2=1e-3;
    else
      if on_discharge then   //Tank1 discharging. Tank2 on hold.
        m_flow=m_flow_max;   //Power block running at maximum capacity
        m_flow_tk2=1e-3;
        m_flow_pump2=1e-3;
      elseif on_discharge_tk2 then   //Tank2 discharging. Tank1 on hold.
        m_flow=1e-3;
        m_flow_tk2=m_flow_max;
        m_flow_pump2=m_flow_in;
      else
        m_flow=min(m_flow_in,m_flow_max);  //Tanks at minimum level
        m_flow_tk2=1e-3;
        m_flow_pump2=1e-3;
      end if;
    end if;
  else
    if standby then
      m_flow=m_flow_standby; //Standby operation
      m_flow_tk2=1e-3;
      m_flow_pump2=1e-3;
    else
      m_flow=0;  
      m_flow_tk2=1e-3;
      m_flow_pump2=1e-3;
    end if;
  end if;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)),
    uses(Modelica(version="3.2.2")));
end NewStartUpLogic5;
//initial equation
//   pre(t_off) = 0;
//   pre(t_on) = 0;
//initial equation
//  on_discharge_tk1 = (level>level_on) and (level>level_off);
//  on_discharge_tk2 = (level2>level_on) and (level2>level_off);
//algorithm

//   when level1>level_on and level2>level_on then
//    when level1>level2 then
//      on_discharge_tk1 := true;
//      on_discharge_tk2 := false;
//    elsewhen level2>level1 then
//      on_discharge_tk1 := false;
//      on_discharge_tk2 := true;
//    end when;
//   elsewhen level1>level_on and level2<level_off then
//     on_discharge_tk1 := true;
//     on_discharge_tk2 := false;
//   elsewhen level1<level_off and level2>level_on then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := true;
//   elsewhen level1<level_off and level2<level_off then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := false;
//   end when;
   

//equation
       
//  on_charge = m_flow_in > 0;

//   when on_charge or on_discharge_tk1 or on_discharge_tk2 then
//     t_on = time;
//   end when;
//   when not (on_charge or on_discharge or on_discharge_tk2) then
//     t_off = time;
//   end when;

//   when t_on-(t_off+t_standby)>0 then
//     startup=true;
//   elsewhen (time-t_on)>t_start then
//     startup=false;
//   end when;
//   standby = (time-t_off) < t_standby;

//  if on_charge or on_discharge_tk1 or on_discharge_tk2 then
//    if startup then
//      if on_discharge_tk1 then
//        m_flow = m_flow_startup;
//        m_flow2 = 0;
//      elseif on_discharge_tk2 then
//        m_flow = 0;
//        m_flow2 = m_flow_startup;
//      else
//        m_flow = min(m_flow_in,m_flow_max); //TODO: Revisar cuando falla esta regla
//      end if;
//    else
//      if on_discharge_tk1 then
//        m_flow = m_flow_max;
//        m_flow2 = 0;
//      elseif on_discharge_tk2 then
//        m_flow = 0;
//        m_flow2 = m_flow_max;
//      else
//        m_flow=min(m_flow_in,m_flow_max); //TODO: Revisar cuando falla esta regla
//      end if;
//    end if;
//  else
//    if standby then
//      m_flow=m_flow_standby;
//    else
//      m_flow=0;
//    end if;
//  end if;

//  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
//        coordinateSystem(preserveAspectRatio=false)),
//    uses(Modelica(version="3.2.2")));
