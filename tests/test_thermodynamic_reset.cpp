#include <iostream>
#include <cassert>
#include <cmath>
#include "torky/thermodynamic_reset_engine.hpp"

using namespace torky::thermodynamic::reset;

int main() {
    std::cout << "[TEST RUNNER] Verifying torky-thermodynamic-reset..." << std::endl;
    assert(sizeof(TorkyCellDtype) == 9);
    double v0 = ThermodynamicResetEngine::evaluate_v_finite(0.0);
    assert(v0 > 0.0);
    double reset_val = ThermodynamicResetEngine::evaluate_counterdiabatic_reset(300.0, 1.0);
    assert(!std::isnan(reset_val));
    std::cout << ">>> ALL torky-thermodynamic-reset KERNELS PASSED (v24.0.0-GA)!" << std::endl;
    return 0;
}
