within SolarTherm;

block Logictest

  Modelica.Blocks.Interfaces.RealInput T_mea (final quantity="T_mea",
                                          final unit = "K", displayUnit = "degC", min=0)
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}}),
        iconTransformation(extent={{-120,-20},{-80,20}})));
    parameter Real t_max = 290+273.15;
    parameter Modelica.SIunits.Time t_start=0.5*3600;
    parameter Modelica.SIunits.Time t_standby=2*30;
    Boolean startup(start=false, fixed=true);
    discrete Modelica.SIunits.Time t_off;
    discrete Modelica.SIunits.Time t_on;
    Boolean standby;
    //parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
initial equation
  y=  T_mea<t_max;
equation
  when T_mea>t_max then
    y=false;
  end when;
  
  //Start time
   when y then
     t_on = time;  //t_on=time if on_charge or on_discharge or on_discharge_tk2 becomes true
   end when;

   //Stop time
   when not y then //t_off=time if on_charge or on_discharge or on_discharge_tk2 becomes false
     t_off = time;
   end when;

   //Power block starting up
   when t_on-(t_off+t_standby)>0 then //startup=true if t_on>(t_off+t_standby) becomes true
     startup=true;
   elsewhen (time-t_on)>t_start then //startup=flase if (time-t_on)>t_start becomes true
     startup=false;
   end when;

   standby = (time-t_off)<t_standby; //standby=true if (time-t_off)<t_standby at current time step

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));


end Logictest;