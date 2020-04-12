within SolarTherm.Models.Control;
block NewLevel2Logic

  parameter Real level_max = 90;
  parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.RealInput level_ref_tk2
    annotation (Placement(visible = true,transformation(origin = {-120, 0}, extent={{0,0},{40,40}}, rotation = 0), iconTransformation(origin = {-120, 20}, extent={{0,0},{40,40}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealInput level_ref_tk1
    annotation (Placement(visible = true,transformation(origin = {-120, -40}, extent={{0,0},{40,40}}, rotation = 0), iconTransformation(origin = {-120, -60}, extent={{0,0},{40,40}}, rotation = 0)));

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));
initial equation
  y= (level_ref>level_max) and
                             (level_ref>level_min);

equation
  when level_ref>level_max then
    y=true;
  elsewhen level_ref<level_min then
    y=false;
  end when;

  annotation (Icon(coordinateSystem(preserveAspectRatio=false)), Diagram(
        coordinateSystem(preserveAspectRatio=false)));
end NewLevel2Logic;
