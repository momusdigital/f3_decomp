// src/f3staging/f3blk_00c00000_od.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

// @f3 0x00c0e1a2 (community match, verified in this file)
extern "C" unsigned int DAT_0106b8a8;
namespace f3m_00c0e1a2 {
namespace f3m_00c0e1a2 {
extern "C" unsigned int __cdecl FUN_00c0f4eb(unsigned int newctrl, unsigned int mask);
extern "C" int __cdecl FUN_00c0ecee(double x);
extern "C" double __cdecl FUN_00c1c7e1(double x);
extern "C" double __cdecl FUN_00c0f3c7(unsigned int op, double arg, unsigned int savedcw);
extern "C" double __cdecl FUN_00c0f41a(int flags, int opcode, double arg, double res, unsigned int savedcw);
extern "C" double __cdecl FUN_00c0e1a2(double x)
{
    unsigned int savedcw;
    double result;
    savedcw = FUN_00c0f4eb(DAT_0106b8a8, 0xffff);
    if ((*((unsigned short*)&x + 3) & 0x7ff0) == 0x7ff0) {
        switch (FUN_00c0ecee(x)) {
        case 1:
        case 2:
            FUN_00c0f4eb(savedcw, 0xffff);
            return x;
        case 3:
            return FUN_00c0f3c7(11, x, savedcw);
        default:
            return FUN_00c0f41a(8, 11, x, x + 1.0, savedcw);
        }
    }
    result = FUN_00c1c7e1(x);
    if (result == x) {
        FUN_00c0f4eb(savedcw, 0xffff);
        return result;
    }
    if (savedcw & 0x20) {
        FUN_00c0f4eb(savedcw, 0xffff);
        return result;
    }
    return FUN_00c0f41a(16, 11, x, result, savedcw);
}
}
}   // namespace f3m_00c0e1a2

// @f3 0x00c1302b (community match, verified in this file)
extern "C" unsigned int DAT_0106bc28;
namespace f3m_00c1302b {
namespace f3m_00c1302b {
extern "C" unsigned int __cdecl FUN_00c0f4eb(unsigned int newctrl, unsigned int mask);
extern "C" int __cdecl FUN_00c0ecee(double x);
extern "C" double __cdecl FUN_00c1c7e1(double x);
extern "C" double __cdecl FUN_00c0f3c7(unsigned int op, double arg, unsigned int savedcw);
extern "C" double __cdecl FUN_00c0f41a(int flags, int opcode, double arg, double res, unsigned int savedcw);
extern "C" double __cdecl FUN_00c1302b(double x)
{
    unsigned int savedcw;
    double result;
    savedcw = FUN_00c0f4eb(DAT_0106bc28, 0xffff);
    if ((*((unsigned short*)&x + 3) & 0x7ff0) == 0x7ff0) {
        switch (FUN_00c0ecee(x)) {
        case 1:
        case 2:
            FUN_00c0f4eb(savedcw, 0xffff);
            return x;
        case 3:
            return FUN_00c0f3c7(12, x, savedcw);
        default:
            return FUN_00c0f41a(8, 12, x, x + 1.0, savedcw);
        }
    }
    result = FUN_00c1c7e1(x);
    if (result == x) {
        FUN_00c0f4eb(savedcw, 0xffff);
        return result;
    }
    if (savedcw & 0x20) {
        FUN_00c0f4eb(savedcw, 0xffff);
        return result;
    }
    return FUN_00c0f41a(16, 12, x, result, savedcw);
}
}
}   // namespace f3m_00c1302b

// @f3 0x00c0def2 (community match, verified in this file)
#include <math.h>
extern int DAT_0117a214;
extern void* DAT_0117a764;
namespace f3m_00c0def2 {


namespace libm {
typedef int (__cdecl *MathHandler)(_exception*);
MathHandler __cdecl FUN_00c0c00d(void* encoded);
int __cdecl FUN_00c1c7de(_exception* error);
int* __cdecl FUN_00c02a76();

enum ErrorType { Domain = 1, Singularity = 2, Overflow = 3, Underflow = 4 };

enum ErrorTag {
    log_zero = 2,
    log_negative = 3,
    log10_zero = 8,
    log10_negative = 9,
    exp_overflow = 14,
    exp_underflow = 15,
    pow_overflow = 24,
    pow_underflow = 25,
    pow_zero_to_zero = 26,
    pow_zero_to_negative = 27,
    pow_neg_to_non_integer = 28,
    pow_nan_to_zero = 29,
    acos_gt_one = 58,
    asin_gt_one = 61,
    exp10_overflow = 166,
    log_nan = 1000,
    log10_nan = 1001,
    exp_nan = 1002,
    atan_nan = 1003,
    ceil_nan = 1004,
    floor_nan = 1005,
    pow_nan = 1006,
    modf_nan = 1007,
    acos_nan = 1008,
    asin_nan = 1009,
    sin_naninf = 1010,
    cos_naninf = 1011,
    tan_naninf = 1012
};

// pdb: __libm_error_support | _libm_error_.obj | tesv_win, call_dedup, low
void __cdecl FUN_00c0def2(void* arg1, void* arg2, void* retval, ErrorTag input_tag)
{
    _exception exc;
    const unsigned char double_zero[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    MathHandler handler = DAT_0117a214 ? FUN_00c0c00d(DAT_0117a764) : FUN_00c1c7de;
    switch (input_tag) {
    case log_zero:
        exc.type = Singularity;
        exc.name = "log";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case log_negative:
        exc.type = Domain;
        exc.name = "log";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case log10_zero:
        exc.type = Singularity;
        exc.name = "log10";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case log10_negative:
        exc.type = Domain;
        exc.name = "log10";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case exp_overflow:
        exc.type = Overflow;
        exc.name = "exp";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case exp_underflow:
        exc.type = Underflow;
        exc.name = "exp";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        handler(&exc);
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_zero_to_zero:
        *static_cast<double*>(retval) = 1.0;
        break;
    case pow_overflow:
        exc.type = Overflow;
        exc.name = "pow";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_underflow:
        exc.type = Underflow;
        exc.name = "pow";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        handler(&exc);
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_zero_to_negative:
        exc.type = Singularity;
        exc.name = "pow";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_neg_to_non_integer:
        exc.type = Domain;
        exc.name = "pow";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_nan_to_zero:
        exc.type = Domain;
        exc.name = "pow";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case asin_gt_one:
        exc.type = Domain;
        exc.name = "asin";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case acos_gt_one:
        exc.type = Domain;
        exc.name = "acos";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case exp10_overflow:
        exc.type = Overflow;
        exc.name = "exp10";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 34;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case log_nan:
        exc.type = Domain;
        exc.name = "log";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case log10_nan:
        exc.type = Domain;
        exc.name = "log10";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case exp_nan:
        exc.type = Domain;
        exc.name = "exp";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case atan_nan:
        exc.type = Domain;
        exc.name = "atan";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case ceil_nan:
        exc.type = Domain;
        exc.name = "ceil";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case floor_nan:
        exc.type = Domain;
        exc.name = "floor";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case pow_nan:
        exc.type = Domain;
        exc.name = "pow";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case modf_nan:
        exc.type = Domain;
        exc.name = "modf";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case acos_nan:
        exc.type = Domain;
        exc.name = "acos";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case asin_nan:
        exc.type = Domain;
        exc.name = "asin";
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case sin_naninf:
        exc.type = Domain;
        exc.name = "sin";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1) * *reinterpret_cast<const double*>(double_zero);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case cos_naninf:
        exc.type = Domain;
        exc.name = "cos";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1) * *reinterpret_cast<const double*>(double_zero);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    case tan_naninf:
        exc.type = Domain;
        exc.name = "tan";
        *static_cast<double*>(retval) = *static_cast<double*>(arg1) * *reinterpret_cast<const double*>(double_zero);
        exc.arg1 = *static_cast<double*>(arg1);
        exc.arg2 = *static_cast<double*>(arg2);
        exc.retval = *static_cast<double*>(retval);
        if (!handler(&exc))
            *FUN_00c02a76() = 33;
        *static_cast<double*>(retval) = exc.retval;
        break;
    }
}
}

}   // namespace f3m_00c0def2

// @f3 0x00c0b987 (community match, verified in this file)
namespace f3m_00c0b987 {
// pdb: _ms_p5_test_fdiv | _testfdiv_.obj | tesv_win, uconst, low
int __cdecl FUN_00c0b987()
{
    struct Probe { volatile double dividend, divisor; double remainder; };
    Probe values;
    values.divisor = 3145727.0;
    values.dividend = 4195835.0;
    double product = values.dividend / values.divisor * values.divisor;
    static_cast<volatile double&>(values.remainder) = values.dividend - product;
    if (values.remainder > 1.0) return 1;
    return 0;
}
}   // namespace f3m_00c0b987
