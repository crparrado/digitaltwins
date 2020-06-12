model state_control_rec_tower

// variable Limits
parameter Real SUN_ELEV_LIMIT_MAX = 45;
parameter Real SUN_ELEV_LIMIT_MIN = -25;
parameter Real REC_POW_MIN = 140;

parameter Real HOT_SET_POINT = 565;
parameter Real COLD_SET_POINT = 288;

parameter Real INITIAL_TRACE_T;
parameter Real INITIAL_U_BYPASS;

parameter Real HhMAX;
parameter Real HcMIN;

parameter Real DIF_REC_CTANK_LIMIT = 50;

parameter Integer INITIAL_STATE = 1;
  
parameter Real INITIAL_PUMP_T = 0;
parameter Real INITIAL_AIMING = 0;
parameter Real TRACE_T = 0.05;
parameter Real INITITAL_U_BYPASS = 0;

parameter Real INITIAL_REGULA = 1;

// Variables de Control
Real pump_t;
Real aiming;
Real trace_t;
Real u_bypass;
Real air;

Real regula;

Real T_setpoint;

Integer permisive_trace;

// Modo de operacion
Integer MODE_SF; 
Modelica.Blocks.Interfaces.IntegerOutput MODE_SF annotation(Placement(visible = true, transformation(extent = {{80, 10}, {120, -10}}, rotation = 0), iconTransformation(extent = {{80, 10}, {120, -10}}, rotation = 0)));

// Variables Fisicas

Modelica.Blocks.Interfaces.RealInput Sun_elev annotation(
    Placement(visible = true, transformation(origin = {20, 100},extent = {{-20, 10}, {20, -10}}, rotation = -90), iconTransformation(origin = {20, 100},extent = {{-20, 10}, {20, -10}}, rotation = -90)));
Modelica.Blocks.Interfaces.RealInput Recpow annotation(
    Placement(visible = true, transformation(extent = {{-120, 90}, {-80, 70}}, rotation = 0), iconTransformation(extent = {{-120, 90}, {-80, 70}}, rotation = 0)));
Modelica.Blocks.Interfaces.RealInput Hh annotation(
    Placement(visible = true, transformation(extent = {{-120, 60}, {-80, 40}}, rotation = 0), iconTransformation(extent = {{-120, 60}, {-80, 40}}, rotation = 0)));
Modelica.Blocks.Interfaces.RealInput Hc annotation(
    Placement(visible = true, transformation(extent = {{-120, 30}, {-80, 10}}, rotation = 0), iconTransformation(extent = {{-120, 30}, {-80, 10}}, rotation = 0)));

Modelica.Blocks.Interfaces.RealInput Tcold annotation(
    Placement(visible = true, transformation(extent = {{-120, 0}, {-80, -20}}, rotation = 0), iconTransformation(extent = {{-120, 0}, {-80, -20}}, rotation = 0)));

Modelica.Blocks.Interfaces.RealInput SGSpow annotation(
    Placement(visible = true, transformation(extent = {{-120, -30}, {-80, -50}}, rotation = 0), iconTransformation(extent = {{-120, -30}, {-80, -50}}, rotation = 0)));

Modelica.Blocks.Interfaces.RealInput Dif_Rec_CTank annotation(
    Placement(visible = true, transformation(extent = {{-120, -58}, {-80, -78}}, rotation = 0), iconTransformation(extent = {{-120, -58}, {-80, -78}}, rotation = 0)));

Modelica.Blocks.Interfaces.RealInput TIME annotation(
    Placement(visible = true, transformation(origin = {-20, 100},extent = {{-20, 10}, {20, -10}}, rotation = -90), iconTransformation(origin = {-20, 100},extent = {{-20, 10}, {20, -10}}, rotation = -90)));

// define estado inicial (?)

// define estado inicial (?)

initial equation

  MODE_SF = INITIAL_STATE;
  
  pump_t = INITIAL_PUMP_T;
  aiming = INITIAL_AIMING;
  trace_t = INITIAL_TRACE_T;
  u_bypass = INITIAL_U_BYPASS;
  
equation

  regula = INITIAL_REGULA;  // ecuacion para regular el flujo de la bomba

algorithm
  
  if MODE_SF == 1 then // INITIAL STATE
    //pump_t = 0;
    //aiming = 0;
    //trace_t = 0.05;
    //u_bypass = 0;
    //air = 0;
    if ( ((Sun_elev < SUN_ELEV_LIMIT_MAX) and (Sun_elev > SUN_ELEV_LIMIT_MIN) or (Recpow >= REC_POW_MIN))
        and ( (Hh < 0.98*HhMAX)  and (Hc > 1.1*HcMIN) ) ) then
      MODE_SF := 2;
    end if;  
  end if;
  
  if MODE_SF == 2 then // encience tracing (?)
     trace_t := 1;
     if permisive_trace == 1 then
        MODE_SF := 3;   
     end if;
  end if;

  if MODE_SF == 3 then // preheating
    trace_t := 0.25;
    if Recpow >= REC_POW_MIN then
      trace_t := 0.05;
      MODE_SF := 4;
    elseif ( (Sun_elev>SUN_ELEV_LIMIT_MAX) and (Recpow<REC_POW_MIN) ) then
      MODE_SF := 1;
      pump_t := 0;
      aiming := 0;
      trace_t := 0.05;
      u_bypass := 0;
      air := 0;
    end if;
  end if;

  if MODE_SF == 4 then // mas preheating
    pump_t := 0.5;
    air := 1;
    if TIME > 5*60 then // mas de 5 minutos
        MODE_SF := 5;
        TIME := 0;
        air := 0.05;
    end if;
  end if;

  if MODE_SF == 5 then // mas preheating
    pump_t := 1;
    u_bypass := 1;
    T_setpoint := min(1,TIME/4)*(HOT_SET_POINT-Tcold) + HOT_SET_POINT;
    pump_t := regula;
    aiming := min(1,TIME/4);
    if TIME > 5*60 then /// mas de 5 minutos
        TIME := 0;
        air := 0.05;
        MODE_SF := 6;
    end if;
  end if;

  if MODE_SF == 6 then
    pump_t := regula;
    if ( (Hh >= 0.98*HhMAX) or (Hc <= HcMIN) ) then
      MODE_SF := 7;
    elseif Recpow < 140 then
      MODE_SF := 8;
      TIME := 0;
    end if;
  end if;

  if MODE_SF == 7 then
    aiming := min(1,SGSpow/Recpow);
    pump_t := regula;
    if ( (Recpow < 140) and (Hh >= 1.1*HhMAX) and (Hc >= 0.8*HcMIN) ) then
      MODE_SF := 9;
    elseif ( (Hh < 0.95*HhMAX) and (Hc > 1.5*HcMIN) ) then
      MODE_SF := 6;
    end if;  
  end if;

  if MODE_SF == 8 then
    pump_t := regula;
    if (Recpow >= 140) then
      MODE_SF := 6;
    elseif ( (Hh >= 0.98*HhMAX) or (Hc <= 1.1*HcMIN) ) then
      MODE_SF := 9;
    elseif ( (TIME > 600) and (Recpow < REC_POW_MIN) ) then
      MODE_SF := 10;
      TIME := 0;

    end if;
  end if;

  if MODE_SF == 9 then
    pump_t := regula;
    aiming := min(1,SGSpow/Recpow);
    if ( (Hh<0.95*HhMAX) and (Hc>1.5*HcMIN) ) then
      MODE_SF := 8;
    elseif ( (Recpow >= REC_POW_MIN) and (Hh < 1.1*HhMAX) and (Hc > 0.8*HcMIN) ) then
      MODE_SF := 7;
      aiming := min(1,SGSpow/Recpow);
      pump_t := regula;
    elseif ( ((Hh >= 1.1*HhMAX) or (Hc <= 0.8*HcMIN)) or
            ((TIME > 600) and (Recpow < REC_POW_MIN)) ) then
      MODE_SF := 10;
      TIME := 0;
    end if;
  end if;

  if MODE_SF == 10 then
    T_setpoint := -TIME/19*(HOT_SET_POINT-Tcold)+565;
    pump_t := regula;
    if Dif_Rec_CTank <= DIF_REC_CTANK_LIMIT then
      MODE_SF := 1;
      T_setpoint := COLD_SET_POINT;

      pump_t := 0;
      aiming := 0;
      trace_t := 0.05;
      u_bypass := 0;
      air := 0;
    end if;
  end if; 

annotation(
    Icon(graphics = {Text(origin = {-44, 47}, extent = {{-28, 21}, {28, -21}}, textString = "SF"), Text(origin = {-44, 18}, extent = {{-26, 32}, {26, -32}}, textString = "REC"), Text(origin = {36, 34}, extent = {{-50, 30}, {50, -30}}, textString = "STATE"), Text(origin = {1, -48}, extent = {{-73, 36}, {73, -36}}, textString = "CONTROL")}));
end state_control_rec_tower;