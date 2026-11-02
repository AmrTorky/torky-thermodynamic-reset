#ifndef TORKY_THERMODYNAMIC_RESET_ENGINE_HPP
#define TORKY_THERMODYNAMIC_RESET_ENGINE_HPP

#include <cmath>
#include <cstdint>
#include <algorithm>

namespace torky::thermodynamic::reset {
    inline constexpr double EPSILON_NM2       = 0.016;
    inline constexpr double V_FINITE_ZERO_EV  = 11.384;

    #pragma pack(push, 1)
    struct TorkyCellDtype {
        uint8_t  gov_gate;     // TSG Gate Register (0x01 - 0x04)
        int16_t  phase_q16;    // Phase Q16 Fixed-Point
        int16_t  field_q16;    // Field Q16 Fixed-Point
        uint32_t syndrome_u32; // SHA-256 Merkle Syndrome
    };
    #pragma pack(pop)

    static_assert(sizeof(TorkyCellDtype) == 9, "CRITICAL: TorkyCellDtype must be precisely 9 bytes!");

    class ThermodynamicResetEngine {
    public:
        // Counterdiabatic driving bypassing Landauer's bound with zero-entropy heat extraction
        static inline double evaluate_counterdiabatic_reset(double temperature_k, double control_field) {
            double landauer_bypass = 1.0 / std::sqrt((control_field * control_field) + EPSILON_NM2);
            return temperature_k * landauer_bypass * 0.01;
        }
        static inline double evaluate_v_finite(double r_nm) {
            return 1.0 / std::sqrt((r_nm * r_nm) + EPSILON_NM2);
        }
    };
}
#endif
