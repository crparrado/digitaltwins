import itertools
import csv
import os

# Define the range and step size for the variations
variation_range = [i * 0.1 for i in range(1, 11)]  # 0.1, 0.2, ..., 1.0

# Define the hours to vary (in seconds): 12 PM, 2 PM, 4 PM, 6 PM, and 8 PM
hours_to_vary = [43200, 50400, 57600, 64800, 72000]

# Generate all possible combinations for the 5 hours
combinations = list(itertools.product(variation_range, repeat=5))

# Base vector (excluding the hours to vary, ensure there's no overlap with hours_to_vary)
base_vector = [
    (0, 0.6), (3600, 0.6), (7200, 0.6), (10800, 0.6), (14400, 0.6), 
    (18000, 0.6), (21600, 0.6), (25200, 1), (28800, 1), (32400, 1),
    # Ensure 43200, 50400, 57600, 64800, and 72000 are not in the base_vector
    (75600, 0.6), (79200, 0.6), (82800, 0.6)
]

# Function to create a modified vector
def create_modified_vector(base_vector, variable_hours, values):
    vector = base_vector.copy()
    for hour, value in zip(variable_hours, values):
        vector.append((hour, value))
    vector.sort()  # Sort the vector by hour
    return vector

from solartherm import simulation
from solartherm import postproc
from solartherm import params
from solartherm.optimisation import *
import functools

import colorama
colorama.init()

class acciona:
    def __init__(self, fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo'):
        self.sim = simulation.Simulator(fn)
        print('Compiling model')
        self.sim.compile_model(args=['-d=nonewInst'])
        self.sim.compile_sim(args=['-s'])
        self.sim.load_init()

    def simulate(self):
        self.sim.simulate(start=0, stop='1y', tolerance=1e-4, step='300s', solver='dassl', nls='homotopy')
        self.res = postproc.SimResultElec(self.sim.res_fn)
        self.perf = self.res.calc_perf()
        print('epy  [GWhe ]: {0}'.format(self.perf[0]/1e3))
        print('lcoe [$/MWh]: {0}'.format(self.perf[1]))
        print('capf [  %  ]: {0}'.format(self.perf[2]))
        print('srev [  USD  ]: {0}'.format(self.perf[3]))

    def simulate_with_vector(self, vector):
        # Modify the sch_acciona.motab file with the new vector
        self.modify_dispatch_vector(vector)

        # Run the simulation
        self.simulate()

        # Return the performance metrics
        return self.perf

    def modify_dispatch_vector(self, vector):
        vector_path = '/home/cparrado/.openmodelica/libraries/SolarTherm/Data/Schedules/sch_acciona.motab'
        with open(vector_path, 'w') as file:
            file.write('#1\ndouble daily1(24,2)\n')
            for hour, value in vector:
                print(f'{hour} {value}')  # Debugging output
                file.write(f'{hour} {value}\n')


# Main function to run the simulations with all combinations
def run_simulations():
    model = acciona(fn='/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo')

    results = []
    for combination in combinations:
        try:
            modified_vector = create_modified_vector(base_vector, hours_to_vary, combination)
            performance_metrics = model.simulate_with_vector(modified_vector)
            results.append((combination, performance_metrics))

            # Save results to CSV after each successful simulation
            with open('/home/cparrado/sunaicl-solartherm/tests/results.csv', 'a', newline='') as file:
                writer = csv.writer(file)
                writer.writerow([combination, *performance_metrics])

        except Exception as e:
            print(f"Simulation failed for combination {combination}. Error: {e}")
            # Optionally, log the failed combination to a separate file
            with open('/home/cparrado/sunaicl-solartherm/tests/failed_combinations.csv', 'a', newline='') as file:
                writer = csv.writer(file)
                writer.writerow([combination, str(e)])

    return results

# Call the function to run all simulations
simulation_results = run_simulations()
