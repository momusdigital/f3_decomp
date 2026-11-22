# Fallout 3 decompilation: guide for contributors and agents

Reconstruct the source of Fallout 3 PC 1.7.0.3 so that Visual C++ 2005 SP1, with each unit's flags, emits the
game's code byte for byte, function by function. Matching bytes prove the source is faithful; they are not the goal.
The goal is source a reader can understand: every function must pass the **reader test** — would a programmer at
Bethesda Game Studios, writing in that codebase's style, have typed this, and can a reader see what it does without
the disassembly? Source that matches through tricks (a **fakematch**) is not a match.

`README.md` covers what the project is, the legal terms, the PR check and how to build. This file is the project
profile: the rules the source is held to, the evidence names come from, and the commands.

## Commands

| verb | command |
|---|---|
| `build` | `python3 tools/build_and_match.py --image <Fallout3.exe> --jobs N [--out results.json]` (every unit, against your own 1.7.0.3 executable) |
| `match <unit>` | `python3 tools/build_and_match.py --image <Fallout3.exe> --only <path text>` |
| `gate` | the PR check against `main` (README, "Running the check yourself"): `compare_builds.py plan`, `shard`, `report`; then `build` |
| `rules` | `f3rules` (see "Rule checker" below): every recipe function's [match] and advisory findings |

Toolchain: cl 14.00.50727.762 (VS2005 SP1), every unit `compiler: vs2005`. On Windows the compiler also runs from an
installed Visual Studio 2005 SP1: point `F3_MSVC_ROOT` at a folder with `VC/` (junction to the installed `VC`) and
`SDK/` (a Windows SDK 6.0/6.0A `Include` and `Lib`), and put `Common7/IDE` on `PATH` (`mspdb80.dll`). The VS2005
PlatformSDK alone is too old: 21 units need `d3d9.h`, the Vista-era `winbase.h` and its `intrin.h`-compatible
`__rdtsc`.

## The two laws

1. **The bytes win.** A change made for style must not change what the compiler emits. When a rule and the bytes
   disagree, keep the bytes and write `// RULE-EXCEPTION: <rule>, <the reason the bytes give>` at the code.
2. **Identical bytes alone are not a match.** A function counts as *matched under the rules* only when its bytes
   match **and** it passes every [match] rule:
   - R1: each type defined once, in a shared header (no local stand-in copies of a real class);
   - R2: each global declared once, as `extern` in a header, defined in its owning unit;
   - R4: typed members, never fixed offsets (`*(int *)((char *)this + 0x24)` is not source);
   - R13: real vtables, from the binary's RTTI and vtables (no `vf41`, `pad`, `dummy` slots);
   - R17: no fake code (`volatile` carriers, dummy locals, steering blocks, `do { } while ( 0 )` outside a macro);
   - R18: no assembly bodies (`__asm`), unless the function is `ORIGINAL-ASM`.

   The full catalogue is the `decomp-code-rules` rule set (R1–R37, Section F lists each fakematch and its human
   form). Naming (R7) is not required for a match: placeholder names are open work.

Progress has two numbers, and both are reported every time: **matched under the rules** (the headline) and **bytes
matched** (every function in `build/units.json`; `main` is byte exact).

## Function status

| status | meaning | how it is recorded |
|---|---|---|
| matched | bytes match, every [match] rule passes | nothing extra |
| `MATCH-PENDING` | bytes match, a [match] rule fails (usually a fakematch) | `MATCH_PENDING.md` lists it with the rules that fail; the source is the best-known state and **is kept** |
| `RULE-EXCEPTION` | bytes match, a *style* rule loses to the bytes | `// RULE-EXCEPTION: <rule>, <reason>` at the code |
| `ORIGINAL-ASM` | the evidence shows the original was assembly (runtime library objects) | `// ORIGINAL-ASM: <evidence>` in the header comment; counted neither way |
| unchecked | a definition in `src/` that no `build/units.json` entry verifies | not Fallout 3 source; see below |

**No unmatching through the recipe.** The PR check requires every function's address and size to stay in
`build/units.json`, so a fakematch is never removed from the recipe: it is kept, compiled and checked, and recorded
as `MATCH-PENDING` until a lane replaces its source with the real form at the same bytes.

**Unchecked definitions.** Much of the tree was started from another game's decompilation: whole files were copied
and edited until the functions the recipe lists matched, and the other definitions stayed. A definition that no
recipe entry checks is not evidence of anything about Fallout 3. It may not carry a `// @f3` tag, a Fallout 3 name
derived from it, or be cited as a source. Remove such definitions when nothing checked depends on them (the gate
proves it), or move them out when a later lane matches them.

## Evidence for names, and how far each source is trusted

| source | what it gives | trust |
|---|---|---|
| Fallout 3's own executable | RTTI class names and vtables, strings that name a function or setting, imports | proves what it names |
| Fallout: New Vegas Xbox 360 PDBs (retail and debug builds of 2010-07-21, 2010-08-22, 2010-11-10) | function, parameter, local, field, global and class names; object files and source paths | names are original; the **link** from a Fallout 3 function to an Xbox 360 function carries the confidence |
| The Elder Scrolls V: Skyrim PC map (2013) | decorated names (so signatures) of every public function | as above; x86, so exact-code links are possible |
| Fallout 4 PC PDB (2019) | class and member names, layouts of the later engine | corroboration of spellings only |
| `fnv_decomp` (the New Vegas decompilation) | | **not evidence**: under audit. Its names, its mapping data and the `// @fnv` tags in this tree prove nothing about Fallout 3 |
| existing names in this tree | | open to review; a name without a provenance marker is a claim, not evidence |

A link from a Fallout 3 function to a named reference function is made by evidence that does not depend on names:
unique strings, RTTI class and vtable slot, exact normalised code (x86 references), call-graph position, object-file
order. Tiers are **measured**: the same linker is run between two references that are both named (Skyrim and the
Xbox 360 build), and a method's tier is the precision it reached there (high ≥ 99%, medium ≥ 90%, low below). Only
high-tier links rename; medium and low links appear as comments, labelled with their tier.

Promotion by agreement counts only between **independent** chains, and only at the precision measured for that
pair of methods: the direct link to the Xbox 360 build, the link to Skyrim, and the bridge through New Vegas PC (an
x86 build of the same engine) are independent of each other; the several Xbox 360 builds are not (they share
code, so one method makes the same mistake on each). A link loses its tier when a string the Fallout 3 function
itself uses names a different class (`"Actor::..."`), unless the string belongs to a linked caller or callee.
Library prototypes (other games' PC builds with symbols, sharing Gamebryo or Havok code) name only functions of that
library, only by exact normalised code of 32 bytes or more that is unique on both sides, and only where that rule
measured ≥ 99% against the Xbox 360 names of the same library.

Provenance markers:

```cpp
// @f3 0x<address>
// pdb: <Class>::<Method> | <Class>.obj | <reference build>, <link method>, <tier>
<return type> <Class>::<Method>(<parameters>)
```

- `// pdb: <qualified name> | <object> | <build>, <link method>, <tier>` above a function that a reference links.
- `// src: <SOURCE> <address or +offset> (old: <previous name>)` at the end of a renamed global, field or type
  declaration, so each rename can be found and reversed.
- `SOURCE` is one of `F3_EXE` (the executable's own RTTI or strings), `FNV360_PDB`, `TESV_MAP`, `FO4_PDB`.
- A name we invent is marked `// name: invented` and never presented as original.

## Project profile

**Dialect (R22).** Visual C++ 2005: C++98 with Microsoft extensions (`__thiscall`/`__fastcall`/`__stdcall`,
`__declspec`, `__forceinline`, `__int64`); no C++11. C units are C89 as cl compiles them. Templates and EH as VC8
implements them.

**Naming (R7, R8, R28, R29), per code family, measured from the reference PDBs** (counts are symbol records in the
New Vegas Xbox 360 retail PDB, `F4` the Fallout 4 PDB):

| entity | Bethesda game and engine (`fallout/`, `fallout_shared/`, `bs*/`) | Gamebryo 2.2 (`gamebryo2.2/`, `Ni*`) | Havok (`havok/`, `hk*`) |
|---|---|---|---|
| class | PascalCase with module prefix: `TESObjectREFR`, `BGSSaveLoadManager`, `BSShaderProperty`, `bhkCollisionObject` | `Ni` + PascalCase: `NiNode`, `NiTexturingProperty` | `hk` + layer letter: `hkpWorld`, `hkaSkeleton` |
| function, method | PascalCase (99.5%): `LoadGame`, `GetActorBase`; private container helpers `_Allocate` | PascalCase (99.1%): `GetRTTI`, `LoadBinary` | camelCase (88%): `addEntity`, `calcContentStatistics` |
| parameter | `a` + type tag + Pascal (95.2%): `apActor`, `aiCount`, `abFlag`, `afValue`, `arName`, `auiFlags`, `aeType`, `aspModel` | type tag + Pascal (72%): `pkNode`, `kName`, `uiIndex`, `fTime` | lower/camel (96%): `body`, `numShapes` |
| data member | type tag + Pascal, **no `m_`** (77%): `pTiles`, `fScale`, `iFlags`, `spModel`, `eState`, `cFlags` | `m_` + tag (83%): `m_pkNext`, `m_uiCount`, `m_kName` | `m_` + camelCase (96%): `m_data`, `m_numShapes` |
| static member | tag + Pascal: `pInstance`, `pMe`; `ms_RTTI` | `ms_` + tag (76%): `ms_spDefault`, `ms_bInitialized` | `s_` + camel: `s_instance` |
| global | game settings named by their INI key: `fRumbleShakeRadiusMult`, `sLevelUp`; otherwise tag + Pascal; `g_` is rare (3%) | `g_` rare | |
| local | tag glued to a lower-case word: `pactor`, `iformID`, `spmesh` (lower 4,666 vs capitalised 903) | tag + Pascal: `kPos`, `pkClone` | camel/lower |
| enum, enumerator | UPPER_SNAKE type and values with a short prefix (86%): `TES_MODEL_FLAGS`, `MF_HAS_FACEGEN_DATA` | UPPER_SNAKE (92%) | `HK_` UPPER_SNAKE |
| tags | `p` pointer, `sp` smart pointer, `i`/`ui`/`us`/`c` integers by width, `f` float, `b` bool, `e` enum, `r` reference, `s` string, `k` object | `pk` pointer to class, `k` object | |

zlib keeps its own K&R C names. A recorded name keeps its recorded spelling, case and misspellings. When the
reference puts a method on a class that this tree models with a stand-in, the name becomes `Class_Method` on the
stand-in until the real class exists here; the comment carries the original qualified name.

**Placeholders (R7)**, reported as open naming work: `FUN_<hex>`, `DAT_<hex>`, `LAB_`, `sub_`, `unk<hex>`, `unk_`,
`local_`, `param_<n>`, `field_0x`, `iVar<n>`/`uVar<n>`/`fVar<n>`, `__Dummy_<hex>`, `<name>_shell`, `FnvCpu_*`,
stand-ins suffixed with an address (`ColObj_c65f40`), and any whole-word hex run of six to eight characters that
contains a digit. A placeholder that embeds a *New Vegas* address (`FUN_00be0b90` at Fallout 3 address `0x004c0130`)
is still a placeholder; its address is not a link.

**Layout (R12, R15, R32).** Bethesda's own layout, recorded by the Xbox 360 PDBs: the tree is
`Code/<Module>/<Subsystem>/<Class>.cpp` (`Code/Fallout/AI/TrespassPackage.cpp`,
`Code/Fallout Shared/Pathfinding/NavMeshObstacleManager.cpp`, `Code/Gamebryo2.2/CoreLibs/NiAnimation/...`), one class
per file, the object name equal to the file name (99.4%). This tree keeps the same paths in lower case under `src/`
(`src/fallout/ai/`, `src/fallout_shared/pathfinding/`, `src/gamebryo2.2/corelibs/nianimation/`). A function moves
out of `src/f3staging/`, `src/f3twins/`, `src/staging/` and `src/unmapped/` into the file its reference object names,
in the object's function order. The PDBs record source paths in lower case only; the file name's case comes from the
object path (`BGSRagdoll.obj` → `bgsragdoll.cpp` here, as the tree already writes it).

**Formatting (R23).** No surviving Bethesda source shows its brace or indent style, so formatting is not changed in
bulk. Keep each file's existing style. Formatting-only changes go in their own commits and are gated like code.

**Line information.** The retail executable records no source lines. `__LINE__` is used only to name static-assert
typedefs (`FNV_STATIC_ASSERT`), so layout is free except where it adds a `__LINE__` use; the PR check rebuilds
such changes in full.

**Rules this project tightens or relaxes.** None yet. A change is the maintainers' ruling, recorded here with the
reason, with the checker changed in the same commit. How the checker reads two rules:
- R1 fires where a unit actually sees two definitions of one type: a local copy under `src/` of a type that is also
  defined elsewhere, or two different bodies. Using the one shared `include/` definition is the goal, not a finding.
- R18: Havok's `hkMonitorStream::TimerCommand::setTime` is an original inline-asm helper (`rdtsc` stored to a
  local and reloaded, as Battlefield 3's PDB-named out-of-line copy shows; `__rdtsc()` compiles differently). It
  carries the `RULE-EXCEPTION: R18` in `include/havok/hkMonitorStream.h`; code that times a block uses the
  `HK_TIMER_*` macros, not its own copy of the helper (a few snippets in `src/f3staging/` still carry a local
  copy with the same exception until they move onto the shared header).

## Things that are easy to get wrong here

- **Header names are case-insensitive.** A unit's local header named like a shared one (`niobject.h` next to
  `include/NiObject.h`) wins the `#include` and silently replaces the shared class. A local header never shares a
  name with a header in `include/`.
- **Xbox 360 platform objects do not place PC code.** A link to `BSFile_Xenon.obj`, `NiXenonRenderer.obj` or
  `MoviePlayer_Xenon.obj` names the cross-platform method; the PC implementation lived in another file (the PC
  renderer is `NiDX9Renderer`, which the Xbox 360 PDBs do not contain).
- **Fragile functions.** 0x008e69e0 (`src/fallout/ai/actor_o2_variant.cpp`) changes register allocation with the
  number of declarations ahead of it in the unit; re-check it after any edit to `Actor.h` or the headers it
  includes. It cannot move to its own unit while it lists EH tails there.
- **Literal text is part of the source.** The recipe binds a string by address, so the PR check does not compare
  its text; write the game's own string (`"TtSimulate"`, not a remembered `"TtPhysics"`).
- **Compiler flags are evidence too.** A unit whose constructors have no EH frames in the game builds with
  `/EHs-c-` once the real classes (with destructors) are in place; a flag change uses only flags `main` already
  uses, and every function of the unit must still match.

## Rule checker

`f3rules` lives on the `campaign-tools` branch of the fork that introduced this file (C, built with any recent MSVC;
the PR check accepts no tools, so it is kept out of `main`). It compiles each unit with `/Z7` only to find each recipe
function's source lines, then reports per function its [match] findings (R1, R2, R4, R13, R17, R18), advisory
findings (R7 placeholders, R33 missing header comment, R37 `#if 0`), and every unchecked definition.
`MATCH_PENDING.md` is generated from its output.

## Tooling preference

Write campaign tools in C (C++ only where an API such as DIA requires it). Avoid Python for new tools. The repository's
own `tools/*.py` belong to the maintainers and stay as they are.

## Working rules

- Commit focused changes; never mix formatting with code changes; gate every batch (`compare_builds.py` against
  `main`, then a full `build` against the game).
- A fix that breaks a match is reverted or reshaped, never kept.
- Never write a confident-sounding invented name; when the purpose is unknown, keep the placeholder.
- Never commit any part of the game: no executable bytes, no symbol files, no dumps of them.
