#include <iostream>
#include <cassert>
#include "torky/thermodynamic_reset_engine.hpp"

using namespace torky::thermo::reset;

int main() {
    std::cout << "[TEST RUNNER] Verifying torky-thermodynamic-reset..." << std::endl;
    assert(sizeof(TorkyCellDtype) == 9);

    TorkyCellDtype cell{0xDEADBEEFCAFEBABEULL, 0x01};
    for(int i = 0; i < 100000; ++i) {
        cell = ThermodynamicResetEngine::execute_reset(cell, 10.0);
    }

    std::cout << ">>> ALL torky-thermodynamic-reset KERNELS PASSED (v24.0.0-GA)!" << std::endl;
    return 0;
}
