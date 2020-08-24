within SolarTherm;

block Logic_OMods

  Modelica.Blocks.Interfaces.RealInput T_mea (final quantity="T_mea",
                                          final unit = "K", displayUnit = "degC", min=0)
    annotation (Placement(transformation(extent={{-120,-20},{-80,20}}),
        iconTransformation(extent={{-120,-20},{-80,20}})));
    parameter Real t_ref = 395+273.15;
    
    //parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
    
initial equation
  y=  T_mea<t_ref;
equation
  when T_mea>t_ref then
    y=false;
  end when;
  
  

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));


end Logic_OMods;