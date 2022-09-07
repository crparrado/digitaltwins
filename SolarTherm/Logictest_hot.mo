within SolarTherm;

block Logictest_hot
<<<<<<< HEAD
 Modelica.Blocks.Interfaces.RealInput T_mea(final quantity = "T_mea", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(transformation(extent = {{-120, -20}, {-80, 20}}), iconTransformation(extent = {{-120, -20}, {-80, 20}})));
  parameter Real t_min = 280 + 273.15;
  parameter Real t_set = 395 + 273.15;
  SI.Temperature t_refi;
  discrete Modelica.SIunits.Time t_on;
  Modelica.Blocks.Interfaces.RealOutput t_ref(final quantity = "ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(visible = true, transformation(origin = {4, -108}, extent = {{-14, -14}, {14, 14}}, rotation = -90), iconTransformation(origin = {30, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //parameter Real level_min = 10;
  Modelica.Blocks.Interfaces.BooleanOutput y annotation(
    Placement(transformation(extent = {{98, -10}, {118, 10}})));
initial equation
//y=  T_mea<t_min;
equation
  when T_mea > t_min then
    y = true;
//  elsewhen T_mea>t_max then
//    y=true;
  end when;
  when T_mea > t_set then
=======

  Modelica.Blocks.Interfaces.RealInput T_mea (final quantity="T_mea",
                                          final unit = "K", displayUnit = "degC", min=0)
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}}),
        iconTransformation(extent={{-120,-20},{-80,20}})));
    parameter Real t_min = 280+273.15;
    parameter Real t_set = 395 + 273.15;
    
    SI.Temperature t_refi;
    discrete Modelica.SIunits.Time t_on;
    
      Modelica.Blocks.Interfaces.RealOutput t_ref(final quantity="ThermodynamicTemperature",
                                          final unit = "K", displayUnit = "degC", min=0) annotation (Placement(visible = true,transformation(
        
        origin={4, -108},extent={{-14, -14}, {14, 14}},
        rotation=-90), iconTransformation(
        
        origin={30,0},extent={{-10,-10},{10,10}},
        rotation=0)));

    //parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
initial equation
  //y=  T_mea<t_min;
equation
  when T_mea>t_min then
    y=true;
//  elsewhen T_mea>t_max then
//    y=true;
  end when;
  
   when T_mea>t_set then
>>>>>>> 748c3e56847c66b4b9a7fecbbe3b40e1279fad40
    t_on = time;
//  elsewhen T_mea>t_max then
//    y=true;
  end when;
<<<<<<< HEAD
  if T_mea > t_set and time - t_on > 35 * 60 then
    t_refi = from_degC(565);
  else
    t_refi = from_degC(400);
  end if;
  t_ref = t_refi;
  annotation(
    Icon(coordinateSystem(preserveAspectRatio = false)),
    Diagram(coordinateSystem(preserveAspectRatio = false)));
=======

if T_mea > t_set and (time-t_on)>35*60 then
  t_refi = from_degC(565);
 else 
t_refi = from_degC(400);
end if;

t_ref = t_refi;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));

>>>>>>> 748c3e56847c66b4b9a7fecbbe3b40e1279fad40

end Logictest_hot;