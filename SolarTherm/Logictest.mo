within SolarTherm;

block Logictest

  Modelica.Blocks.Interfaces.RealInput T_mea (final quantity="T_mea",
                                          final unit = "K", displayUnit = "degC", min=0)
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}}),
        iconTransformation(extent={{-120,-20},{-80,20}})));
    parameter Real t_max = 290+273.15;
    
    //parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
initial equation
  y=  T_mea<t_max;
equation
  when T_mea>t_max then
    y=false;
//  elsewhen T_mea>t_max then
//    y=true;
  end when;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));


end Logictest;