import numpy as np
from pymoo.core.problem import ElementwiseProblem

from pymoo.algorithms.moo.nsga2 import NSGA2
from pymoo.operators.crossover.sbx import SBX
from pymoo.operators.mutation.pm import PM
from pymoo.operators.sampling.rnd import FloatRandomSampling

from pymoo.termination import get_termination

from pymoo.optimize import minimize

### DEFINE FUNCION OBJETIVO
def simulation_st(arr_dispatch):
    print("el dispatch es:")
    print(arr_dispatch)

    energy = np.random.uniform(50,100,24)
    arr_dispatch = np.array(arr_dispatch)

    res = np.sum(arr_dispatch*energy)

    return res

### DEFINE EL PROBLEMA A OPTIMIZAR
class Optimize_Simulation_ST(ElementwiseProblem):

    def __init__(self):
        super().__init__(n_var=24,
                         n_obj=1,
                         n_ieq_constr=1,
                         xl=np.array([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]),
                         xu=np.array([1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]))

    def _evaluate(self, x, out, *args, **kwargs):
        
        f = -simulation_st(x)
        g = -simulation_st(x)

        out["F"] = [f]
        out["G"] = [g]

problem = Optimize_Simulation_ST()

### DEFINE EL OPTIMIZADOR
algorithm = NSGA2(
    pop_size=40,
    n_offsprings=10,
    sampling=FloatRandomSampling(),
    crossover=SBX(prob=0.9, eta=15),
    mutation=PM(eta=20),
    eliminate_duplicates=True
)

## DEFINE CRITERIO DE TERMINO
termination = get_termination("n_gen", 40)

res = minimize(problem,
               algorithm,
               termination,
               seed=1,
               save_history=True,
               verbose=True)

X = res.X
F = res.F

print(X,F)
