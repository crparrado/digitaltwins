model dispatch_factor


  parameter String file "File where dispatch schedule is stored";
  parameter Integer tz_offset "The timezone to adjust -time- variable";
  
  Real hour_of_day;
  Real disp_fac;
  
  Real disp_sch[24];  // deberia ser un vector de largo 24 (planificacion horaria de despacho para un dia)
                      // tambien deberia sacarlo de un archivo (?)
  
  // agrega aqui la parte donde lee una tabla desde archivo
  
  // agrega aqui la parte para leer la table desde archivo
  
equation
  
  hour_of_day = mod(div(time,3600),24 );
    
algorithm
  for ii in 1:24 loop
    if ((hour_of_day >= (ii-1)) and (hour_of_day < (ii))) then
      disp_fac := disp_sch[ii-1]; 
    end if;
  end for;
  
end dispatch_factor;