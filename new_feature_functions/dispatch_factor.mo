model dispatch_factor

  parameter String file "File where dispatch schedule is stored";
  parameter Integer tz_offset "The timezone to adjust -time- variable";
  
  Real hour_of_day;
  Real disp_fac;
  
  Real disp_sch[24];  // deberia ser un vector de largo 24 (planificacion horaria de despacho para un dia)
                      // tambien deberia sacarlo de un archivo (?) o usar un parametro (?)
  
                      // que el input sea una matriz (??)
                      // disp_sch = [[hora0,factor0],[hora1,factor1],...,[horaN,factorN]]] (??)
  
equation
  
  hour_of_day = mod(div(time,3600),24 );
    
algorithm 
  // loop hecho para una programacion a intervalos de una hora, para un día
  // hacer que disp_sch sea la matriz "disp_sch" de  los comentarios de arriba y modificar el loop  (??)
  for ii in 1:24 loop
    if ((hour_of_day >= (ii-1)) and (hour_of_day < (ii))) then
      disp_fac := disp_sch[ii-1]; 
    end if;
  end for;
  
end dispatch_factor;