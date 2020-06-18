within SolarTherm;

block Logictest_hot

  Modelica.Blocks.Interfaces.RealInput T_mea
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}}),
        iconTransformation(extent={{-120,-20},{-80,20}})));
    parameter SI.Temperature t_max = from_degC(290);
    
    //parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
initial equation
  //y=  T_mea>t_max;
equation
  when T_mea>t_max then
    y=true;
//  elsewhen T_mea>t_max then
//    y=true;
  end when;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));


end Logictest_hot;