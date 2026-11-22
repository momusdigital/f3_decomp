//
// Gamebryo engine system support.
//
// The MSVC runtime supplies the case-insensitive string comparison;
// the engine exposes it under its own name so shared game code does
// not depend directly on the CRT spelling.

extern "C" int _stricmp(const char* s1, const char* s2);

// @fnv 0x00aa1360
// pdb: NiStricmp | NiSystem.obj | fnv360_0822_retail, call_seq, high
// pdb params: s1, s2
int NiStricmp(const char* a, const char* b)
{
    return _stricmp(a, b);
}

extern "C" void FUN_00ec7ec0(void);

// @fnv 0x00aa1370
// pdb: ActorMover::SetGoal | ActorMover.obj | fnv360_0822_retail, call_seq, medium
// pdb params: apRequest
void FUN_00aa1370()
{
    FUN_00ec7ec0();
}
