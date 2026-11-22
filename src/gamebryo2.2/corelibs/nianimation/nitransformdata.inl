struct NiQuaternionConjugateValue
{
    float w, x, y, z;
};

// Quaternion conjugation inferred from the PC instructions.
// @fnv 0x00a6dc00
// pdb: NiQuaternion::UnitInverse | NiQuaternion.obj | fnv360_0822_retail, objrun_prop, medium
// pdb params: p
NiQuaternionConjugateValue __cdecl NiQuaternionConjugate(const NiQuaternionConjugateValue& value)
{
    NiQuaternionConjugateValue result;
    result.w = value.w;
    result.x = -value.x;
    result.y = -value.y;
    result.z = -value.z;
    return result;
}
