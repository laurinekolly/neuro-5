#include <tclap/CmdLine.h>
#include "UserArguments.hpp"

UserArguments::UserArguments(int argc, char** argv) {
    parse(argc, argv);
}

void UserArguments::parse(int argc, char** argv)
{
    try
    {
        TCLAP::CmdLine cmd("Simulation of neurons network");
        TCLAP::ValueArg<Physics::Time> time_of_simulation_arg("t", "time","total simulation time", false, 1000, "double", cmd);
        TCLAP::ValueArg<unsigned int> number_neurons_arg("n", "neurons", "total number of neurons to consider for the simulation", false, 12500, "int", cmd);
        TCLAP::ValueArg<double> gamma_arg("g", "gamma", "proportion of inhibitory over excitatory neurons", false, 0.25, "double", cmd);
        TCLAP::ValueArg<double> epsilon_arg("e", "epsilon", "connections density", false, 0.1, "double", cmd);
        TCLAP::ValueArg<double> external_factor_arg("f", "factor", "external factor", false, 1, "double", cmd);
        TCLAP::ValueArg<Physics::Time> time_step_arg("d", "dt", "time step of the simulation", false, 2, "Time", cmd);
        cmd.parse(argc, argv);

        time_of_simulation = time_of_simulation_arg.getValue();
        number_neurons = number_neurons_arg.getValue();
        gamma = gamma_arg.getValue();
        epsilon = epsilon_arg.getValue();
        external_factor = external_factor_arg.getValue();
        time_step = time_step_arg.getValue();
    }
    catch (TCLAP::ArgException& e)
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }
}

UserArguments::~UserArguments(){}

double UserArguments::get_epsilon()
{
    return epsilon;
}

double UserArguments::get_external_factor()
{
    return external_factor;
}

double UserArguments::get_gamma()
{
    return gamma;
}

Physics::Time UserArguments::get_time_of_simulation()
{
    return time_of_simulation;
}

unsigned int UserArguments::get_number_neurons()
{
    return number_neurons;
}

Physics::Time UserArguments::get_time_step()
{
    return time_step;
}