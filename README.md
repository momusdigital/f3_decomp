# Fallout 3 decompilation

The decompilation of Fallout 3 for PC (version 1.7.0.3): C++ source code rebuilt function by function from the game's
executable. Built with the compiler the game was built with, Visual C++ 2005 SP1, every function listed in
`build/units.json` compiles to the same bytes as the original.

The project was run on [f3decomp.com](https://f3decomp.com), as the successor of the Fallout: New Vegas
decompilation (`fnv_decomp`, coordinated on [fnvdecomp.com](https://fnvdecomp.com)).

- **What it is for.** The modding community has kept working on Fallout 3 for more than fifteen years. This
  repository is meant for that community: for research, modding and game preservation.
- **Not a way around buying the game.** It is not meant to replace owning the game and must not be used to play or
  share it without a copy of your own.
- **Source code only.** It contains no game files, no assets, no executables and nothing you can play, and nothing
  of the game is distributed here.
- **You need the game.** To use any of this you need your own copy of Fallout 3 for PC, version 1.7.0.3 (see
  [What you need](#what-you-need)).
- **Public domain (CC0).** The contributors' own work here is dedicated to the public domain under CC0 1.0: use it as
  you see fit. That covers only what the contributors wrote, never the game itself; see [Legal](#legal).
- **Trademarks** belong to their holders, listed under [Legal](#legal). This project is not affiliated with or
  endorsed by any of them.

## Contributing

Pull requests are welcome from anyone. Most of what is left is readability: many functions still have placeholder
names (`FUN_00xxxxxx`), vague names or no comment, and many sit in provisional files named after their address
(`src/f3staging/`, `src/f3twins/`) rather than in the source file they came from. All of that can be improved without
changing a single byte of the output. By opening a pull request you dedicate your contribution to the public domain
under CC0 1.0, like the rest of the contributors' work here (see [Legal](#legal)).

### The automatic check

Every pull request gets an automatic check, called `match`. It runs on GitHub's machines, involves no part of the
game, and has to pass before a pull request can be merged:

1. It finds the translation units your change can affect: the files you changed, every unit that includes them, and
   every unit whose entry in `build/units.json` changed.
2. It builds each of those units twice, from `main` and with your change, with Visual C++ 2005 SP1.
3. Every function has to come out identical, at its original address: the same code bytes, and every call and data
   reference resolving to the same original address through `build/units.json`. A function that moved to another
   unit is compared with what it compiled to in its old unit. `main` matches the game byte for byte, so a change that
   passes still does.

What to expect:

- **Passes:** renaming functions, parameters, variables, types and fields; adding or improving comments;
  reformatting; restructuring headers and types; moving functions between units (see "Changing the build recipe"). A
  change only to comments, spacing or blank lines passes without a build.
- **Fails:** anything that changes what a function compiles to. The check lists the functions that differ by
  address; see what differs with your own copy of the game:
  `python3 tools/build_and_match.py --image <your Fallout3.exe> --only <unit>`.
- **Needs a maintainer:** changes outside `src/`, `include/`, `build/units.json` and Markdown files (the tools, the
  workflow), and changes to `build/units.json` beyond what "Changing the build recipe" allows. The check fails on
  these and nobody can merge them, so open an issue instead. Changes to the tools, the workflow and `LICENSE` are made
  by the repository owner; tool changes are verified against the game.

### Review and merging

A pull request is merged when the check passes and two reviewers have approved it:

- Nobody can skip the check, the repository owner included.
- Two approvals are needed. An approval is dropped when new commits arrive, and the last push has to be approved by
  someone other than the person who made it.
- The pull request has to be up to date with `main`. If `main` moves first, use "Update branch" and the check runs
  again on the combined code.

After every change to `main`, the whole of `main` is also built against the game's executable on the project's own
machine. That build proves `main` still matches the game byte for byte, not only that it compiles the same as
before.

### Renaming a function

`build/units.json` lists every function by its original address and its decorated (mangled) name. When you rename a
function, put its new decorated name at the same address, in every unit that lists it; otherwise the check reports
the old name as unbound. Adding a declaration or a string literal can renumber the compiler's string labels
(`$SG...`) that `build/units.json` names; the check says so when that is the cause.

A unit may also bind a name to an address it refers to, for example a global or a vtable that the code used to write
as a number: the check builds the unit again and the bytes at every function's address have to stay the same.

### Changing the build recipe

Besides names, a pull request may change how `build/units.json` builds the functions, because the check builds both
sides and compares every function at its address:

- add, remove or reorder units, and move functions from one unit to another;
- change a unit's compiler options, using only the options `main` already uses (listed in `FLAGS` in
  `tools/compare_builds.py`); every unit uses the one compiler, `vs2005`;
- a new unit's source is a `.c` or `.cpp` file in `src/`.

What has to stay: every function's address and size, each unit's `literal_symbols`, and `totals` (apart from `units`,
which is the number of units). A unit lists each address once, and a function's `fold_aliases` must compile to
exactly the same code as the function. A unit is identified by its source; when two units build the same source, by
their order among those. The tree may only hold regular files (no symlinks).

### Never include any part of the game

No executable, no bytes copied from it, no object files built from this code, no game data. A pull request that
contains any of it is closed.

### Running the check yourself

With the compiler set up (see "What you need"), commit your change, then compare it with `main`:

    git fetch origin
    git worktree add --detach ../f3-main origin/main      # main, to compare against
    git worktree add --detach ../f3-scratch HEAD          # a scratch checkout the check builds in
    python3 tools/compare_builds.py plan ../f3-main . --out ../plan.json --max-shards 1
    python3 tools/compare_builds.py shard ../f3-scratch "$(git rev-parse origin/main)" "$(git rev-parse HEAD)" \
        --plan ../plan.json --shard 0 --out ../result.json
    python3 tools/compare_builds.py report --plan ../plan.json ../result.json

When `plan` reports no units to build, skip `shard` and run `report` without `../result.json`.

## Status

- Functions in scope: 63,681 of 63,682 match byte for byte.
- Bytes in scope: 9,107,120 of 9,137,108.
- Matched under the rules: 17,041 of those 63,681 functions (2,457,227 bytes). A function counts here when its
  bytes match *and* its source passes every [match] rule in `AGENTS.md`: one definition per type and global, typed
  members instead of offset casts, real vtables, no fake code, no assembly bodies. The other 46,194 still match
  byte for byte; `MATCH_PENDING.md` lists each with the rules it fails, and most of it is open work for anyone.

"In scope" leaves out code the compiler and linker generate on their own (runtime stubs, thunks, padding, exception
unwinding code), the parts of the Visual C++ 2005 runtime that were written in assembly (the build links the real
runtime), runtime library functions identified as such, and the few places where the downgraded Steam executable
carries the downgrade patcher's own code (`build/image_check.json`, `patcher_sites`).

## What this is, and what it is not

- It is a reference: readable C++ that shows how the game works, and that reproduces the original machine code.
- It is not a port, a source port or a replacement executable. Building it gives you object files to compare, not a
  game.
- It does not contain, and will not accept, tools or instructions for getting around the game's copy protection.
- It does not contain any part of the game's executable or data files. Addresses, function sizes and a few SHA-256
  fingerprints are the only facts about the executable in this repository.

## Where the code came from

Fallout 3 and New Vegas share most of their engine. Much of this code started from the matching functions of the New
Vegas decompilation and was changed until it compiled to Fallout 3's bytes; the rest was written by the community on
f3decomp.com, function by function, and checked by the same comparison this repository runs.

## What you need

1. **The game.** A legally owned copy of Fallout 3 for PC.
2. **Version 1.7.0.3 of its executable, from your own copy.** Two copies work:
   - the GOG release (`Fallout3.exe`, 1.7.0.3);
   - the Steam release, which installs 1.7.0.4, downgraded to 1.7.0.3 with the Fallout Anniversary Patcher the
     modding community uses (Nexus Mods, Fallout 3 mod 24913).

   Their game code differs only where the patcher puts its own (`build/image_check.json` lists the places); none of those
   functions is part of the decompilation, so both copies give the same result. This repository does not supply the
   executable, any part of it, or any way to produce it. Never share yours.
3. **Python 3.10 or newer.**
4. **Visual C++ 2005 SP1** (cl 14.00.50727.762), from Microsoft's free "Windows SDK for Windows Vista Update (February
   2007)" DVD image (none of it is included here). `tools/get_vs2005.py` unpacks the compiler and the SDK headers and
   libraries from that image into one folder, on Windows, Linux or macOS, without installing anything:

       python3 tools/get_vs2005.py 6.1.6000.16384.10.WindowsSDK_Vista_Feb2007Update_rtm.DVD.Rel.iso /path/to/vs2005

   On Linux and macOS the compiler runs under Wine.

## Build and compare

    export F3_MSVC_ROOT=/path/to/vs2005           # folder with VC/ and SDK/
    export F3_MSVC_PREFIX=/path/to/wineprefix     # not needed on Windows

    python3 tools/build_and_match.py --image /path/to/your/Fallout3.exe

The image is checked first against a few fingerprints; nothing runs on any other file. Every unit is then compiled
and every function compared, relocations included. The result is a count of matching functions and bytes, and a list
of anything that does not match. `--only <text>` builds the units whose path contains the text, `--jobs N` sets how
many compile at once, and `--out results.json` writes the per-unit results (addresses and counts only, never bytes of
your executable).

A full run compiles 2,139 units; expect it to take a while.

## Layout

| Path | What it holds |
|---|---|
| `src/` | The game's code and the libraries linked into it, as C++ translation units. `src/f3staging/` and `src/f3twins/` hold functions not yet moved to the file they came from, grouped by address. |
| `include/` | Shared headers. |
| `build/units.json` | The build recipe: for each unit its source, compiler, flags and the functions it must reproduce. |
| `build/image_check.json` | SHA-256 fingerprints of a few functions and of the two usable executables, and the patcher's places. |
| `build/function_index.json` | The address of every function entry in the executable (no sizes, no bytes): the comparison reads a function's extent from your executable up to the next entry. |
| `tools/` | The compiler wrapper, `get_vs2005.py`, the COFF/PE comparison, `build_and_match.py` and `compare_builds.py` (the pull request check, see [Contributing](#contributing)). |
| `.github/` | The automatic check on pull requests. |

Some units appear in more than one variant (for example `*_o2_variant.cpp`): the original was built with different
optimisation settings in different places, and each variant reproduces the functions built with its settings.

## Credits

This was a community effort, coordinated on [f3decomp.com](https://f3decomp.com). Contributors who chose to be named
are listed in `CREDITS.md` and as co-authors of the first commit.

## Legal

Fallout, Fallout 3, Bethesda, Bethesda Softworks, Bethesda Game Studios and ZeniMax are trademarks or registered
trademarks of ZeniMax Media Inc., a Microsoft company, in the U.S. and/or other countries. The game was developed by
Bethesda Game Studios and published by Bethesda Softworks. Steam is a trademark of Valve Corporation; GOG is a
trademark of GOG sp. z o.o. The libraries linked into the game belong to their owners: Gamebryo (Gamebase Co., Ltd.),
Havok (Microsoft), SpeedTree (Interactive Data Visualization, Inc., part of Unity) and FaceGen (Singular Inversions
Inc.). All other trademarks belong to their respective holders. This project is not affiliated with or endorsed by
any of them.

The game also links zlib 1.2.1 (Jean-loup Gailly and Mark Adler), which is under the zlib licence, not CC0. Its code
was matched into the units under `src/f3staging/` like the rest of the game, and its licence notice stays in those files
as the licence requires.

### Licence: CC0 1.0

The contributors dedicate their own work in this repository to the public domain under CC0 1.0 Universal: the
reconstructed source as they wrote it, the names, comments and documentation, the build recipe and the tools. The full
text is in `LICENSE`. Anyone may copy, change and use that work for any purpose, without asking and without credit.
Contributions are accepted on the same terms: by opening a pull request you dedicate your contribution under CC0 1.0.

CC0 covers only what the contributors could give. It grants no rights in Fallout 3, its code, its data or its assets,
in the libraries linked into it, or in any trademark: those stay with their owners.

### Purpose

This project exists for research, modding and the preservation of the game. It is not a way around buying it: it
contains nothing playable, nothing here works without the game, and it must not be used to play or share the game
without a copy of your own. You need your own legally obtained copy of the game, and you are responsible for following
its licence terms and the law where you live.

### Takedown requests

If you hold rights in this material and want something changed or removed, write to contact@f3decomp.com. We will
respond promptly and comply. We will not contest a takedown request from a rights holder.
