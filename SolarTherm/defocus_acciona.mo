within SolarTherm;

block defocus_acciona
 Modelica.Blocks.Interfaces.RealInput Recpower annotation(
    Placement(visible = true, transformation(extent = {{-126, 74}, {-86, 114}}, rotation = 0), iconTransformation(origin = {-96, 12}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
    
    parameter Real Rec_max = 700;
//    parameter Real Rec_init = 0;
//     parameter Real level_max = 90;
//    parameter Real level_min = 10;

  Modelica.Blocks.Interfaces.BooleanOutput y
    annotation (Placement(transformation(extent={{98,-10},{118,10}})));

initial equation
//  y= (Recpower<level_max) and (Recpower<level_min);
y = Recpower < Rec_max;

equation
  if Recpower>Rec_max then
    y=false;
   else
   y= true;
//  elsewhen Recpower<level_min then
//    y=false;
  end if;


//initial equation
//  y= (Recpower > Rec_max) and (Recpower < Rec_init)/*(level_ref>level_max) and (level_ref>level_min)*/;
  
//equation

////  when Recpower > Rec_max then
////    y=false;
////  end when;
  
  
//  when (Recpower > Rec_max) then
//    y=false;
//  elsewhen (Recpower < Rec_init) then
//    y=true;
//   end when;
   
end defocus_acciona;