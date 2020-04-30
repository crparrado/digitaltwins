model dispatch_factor

  parameter Integer tz_offset = 0 "The timezone to adjust -time- variable";
  
  Real hour_of_day;
  Integer hour_to_ask;
  
  Modelica.Blocks.Interfaces.RealInput disp_sch[24] = {0.4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0.8} annotation(
    Placement(visible = true, transformation(origin = {-90, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));  // deberia ser un vector de largo 24 (planificacion horaria de despacho para un dia)

  Modelica.Blocks.Interfaces.RealOutput out_disp_fac annotation(
    Placement(visible = true, transformation(origin = {90, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {90, 0},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  
  hour_of_day = mod(div(time,3600),24);
    
algorithm 
  // loop hecho para una programacion a intervalos de una hora, para un día
  // hacer que disp_sch sea la matriz "disp_sch" de  los comentarios de arriba y modificar el loop  (??)
  for ii in 1:24 loop
    hour_to_ask := ii - 1;  
    if (hour_of_day == hour_to_ask) then
      out_disp_fac := disp_sch[ii]; 
    end if;
  end for;

end dispatch_factor;