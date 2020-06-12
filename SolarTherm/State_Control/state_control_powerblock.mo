model state_control_powerblock

// variable Limits
parameter Integer INITIAL_STATE = 1;
parameter Real INITIAL_PUMP_PBC = 0;
parameter Real INITIAL_PUMP_PBH = 0;
parameter Real INITIAL_TRACE_SGS = 0;
parameter Real INITIAL_ON_OFF = 0;

parameter Real HOT_SET_POINT = 565;
parameter Real COLD_SET_POINT = 288;

parameter Real POW_SP_MIN = 10000000; // 10 MegaWatts

parameter Real HhMIN;
parameter Real HcMAX;

parameter Real time_sinchro;
parameter Real stup_T;

// Variables Fisicas
Modelica.Blocks.Interfaces.RealInput Hh annotation(
    Placement(transformation(extent = {{-120, 90}, {-80, 70}})));
Modelica.Blocks.Interfaces.RealInput Hc annotation(Placement(transformation(extent = {{-120, 50}, {-80, 30}})));

Modelica.Blocks.Interfaces.RealInput Pow_SP annotation(Placement(transformation(extent = {{-120, 10}, {-80, -10}})));

Modelica.Blocks.Interfaces.RealInput SGS_T annotation(Placement(transformation(extent = {{-120, -30}, {-80, -50}})));

Modelica.Blocks.Interfaces.RealInput TIME annotation(
    Placement(transformation(extent = {{-120, -70}, {-80, -90}})));

// Modo de operacion
// Integer MODE_PB;
Modelica.Blocks.Interfaces.IntegerOutput MODE_PB annotation(Placement(visible = true, transformation(extent = {{80, 10}, {120, -10}}, rotation = 0), iconTransformation(extent = {{80, 10}, {120, -10}}, rotation = 0)));
//Integer MODE_PB;

// Variables de Control
Real pump_pbc;
Real pump_pbh;
Real ramp_pbc;
Real ramp_pbh;

Real trace_SGS;
Real ALS_stup;
Real on_off;
Real ramp_SGS;
Real sinchro;
Real ST_rampup;
Real ST_startup;

Real PID_pbh;
Real PID_pbc;

initial equation

    MODE_PB = INITIAL_STATE; // MODO NADA
    pump_pbc = INITIAL_PUMP_PBC;
    pump_pbh = INITIAL_PUMP_PBH;
    trace_SGS = INITIAL_TRACE_SGS;
    on_off = INITIAL_ON_OFF;

equation

algorithm

    if MODE_PB == 1 then
        MODE_PB := 2;
        pump_pbc := 1;
        trace_SGS := 1;
        TIME := 0;
    end if;

    if MODE_PB == 2 then
        if TIME > 392*60 then
            MODE_PB := 3;
            pump_pbc := 1;
            trace_SGS := 0.1;
            ALS_stup := 0;
            on_off := 0;
            pump_pbc := 0;
        end if;
    end if;

    if MODE_PB == 3 then
        if ( (Hh > 1.5*HhMIN) and (Hc < HcMAX) and (Pow_SP >= POW_SP_MIN) ) then
            MODE_PB := 4;
            trace_SGS := 0;
            TIME := 0;
            ST_startup := 1;
        end if;
    end if;

    if MODE_PB == 4 then
        pump_pbc := ramp_SGS;
        pump_pbh := 0.1;
        if (SGS_T >= stup_T) then
            MODE_PB := 5;
            TIME := 0;
            sinchro := 1;
        end if;
    end if;

    if MODE_PB == 5 then
        if TIME > time_sinchro then
            MODE_PB := 6;
            TIME := 0;
            sinchro := 0;
            on_off := 1;
        elseif ((Hh>=HhMIN) or (Pow_SP<POW_SP_MIN)) then
            MODE_PB := 3;
            pump_pbc := 1;
            pump_pbh := 0;
            SGS_T := 0;
            ALS_stup := 0;
            on_off := 0;
        else
            MODE_PB := 5;
        end if;
    end if;

    if MODE_PB == 6 then
        pump_pbc := ramp_pbc;
        pump_pbh := ramp_pbh;
        if TIME > ST_rampup then
            MODE_PB := 7;
            ST_startup := 0;
            ALS_stup := 0;
        elseif ((Hh <= HhMIN) or (Pow_SP <= POW_SP_MIN)) then
            MODE_PB := 3;
            pump_pbc := 1;
            pump_pbh := 0;
            on_off := 0;
            ALS_stup := 0;
            trace_SGS := 0.1;
        end if;
    end if;

    if MODE_PB == 7 then
        pump_pbh := PID_pbh;
        pump_pbc := PID_pbc;
        if ((Hh<=HhMIN) or (Hc >=HcMAX) or (Pow_SP < POW_SP_MIN)) then
            MODE_PB := 3;
            pump_pbc := 1;
            pump_pbh := 0;
            on_off := 0;
            ALS_stup := 0;
            trace_SGS := 0.1;
        end if;
    end if;


annotation(
    uses(Modelica(version = "3.2.2")),
    Icon(graphics = {Text(origin = {2, 41}, extent = {{-74, 27}, {74, -27}}, textString = "PB STATE"), Text(origin = {3, -24}, extent = {{-75, 36}, {75, -36}}, textString = "CONTROL")}));
end state_control_powerblock;