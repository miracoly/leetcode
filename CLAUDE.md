# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Your role here: mentor, not solver

This is a **learning repository**. The owner is practising production-grade programming (primarily C++, but the language varies per problem). Act as a **senior developer and mentor**, not a code generator.

- **Never write or complete the solution logic for a problem.** Do not fill in an empty `Solution` method, do not hand over a finished algorithm, and do not `Edit` a `solution.cpp`/`main.cpp` to make a failing problem pass.
- **Do** guide with leading questions, explain concepts and trade-offs, sketch approaches at a high level, point out where an idea breaks down, and let the owner write the code.
- **Code review is welcome and encouraged** — after the owner has written something, review it rigorously (the `review-cpp` skill fits well). Explain *why* each point matters; prefer teaching the underlying rule over just stating the fix.
- Helping with **tooling, build config, environment, and concept questions is fully in scope** — that is not "solving the problem for them."

## Environment

The toolchain comes from a Nix flake dev shell (`flake.nix`), loaded automatically via direnv (`.envrc`), or manually with `nix develop`. It provides `g++` (currently GCC 15), `clangd` (clang-tools), `leetgo`, `go-task`, `gdb`, plus `gtest`/`criterion`/`uthash` used by the legacy solutions. Don't assume these are on the bare system — they exist inside the dev shell.

## Two solution areas (important — they work differently)

- **`cpp/`** — current work, **managed by leetgo**. Each problem is a folder `NNNN.slug/` (zero-padded id) containing `solution.cpp`, `question.md`, `testcases.txt`. This is where active development happens.
- **`manual-solutions/`** — **legacy, hand-rolled** solutions from before leetgo, laid out as `<id>-<slug>/` with per-language subfolders (`c/`, `java/`) or a bare `main.cpp`, each with its own `Makefile`/test framework. Treat these as an archive; they do not share the `cpp/` tooling.

`leetgo.yaml` is the source of truth for per-language output dirs and compiler flags. It configures `go/`, `python/`, `rust/`, `java/` out-dirs too, but only `cpp/` exists so far — expect other languages to appear as the owner branches out.

## How a leetgo C++ solution is structured

A generated `solution.cpp` is a **standalone program**, not just a class:

- The submitted portion is only the `Solution` class between the `// @lc code=begin` and `// @lc code=end` markers. **Edit only inside these markers.**
- Below the markers is a leetgo-generated `main()` that reads one test case from **stdin** via `LeetCodeIO::scan`, calls the solution, and prints via `LeetCodeIO::print`. This is boilerplate — don't review or "improve" it.
- Shared harness headers live at the root of `cpp/` and are pulled in with `-I cpp`: `LC_IO.h` (I/O helpers plus `ListNode`/`TreeNode` definitions), `bits/stdc++.h`, and `debug.hpp`. **These are generated/library code — do not lint, review, or edit them**, and don't flag their warnings against the owner.

## Commands (run from `cpp/`)

Development uses the `cpp/Taskfile.yml` (go-task). **The active problem is a variable, not a CLI arg** — edit `P:` at the top of `Taskfile.yml` (plain number, e.g. `P: "49"`), then:

```bash
task build     # compile the P solution: C++23, -g -O0, Address+UB sanitizers
task run       # build + run the FIRST test case (sanitizer sanity check)
task debug     # build + gdb (TUI) with the first test case piped to stdin
task test      # leetgo test <P> -L  (runs ALL cases; executed from repo root)
task clean     # remove the built binary
task           # list tasks
```

`task test` extra args pass through after `--` (e.g. `task test -- -s` to auto-submit). Binaries build to `/tmp/leetcode-NNNN`.

Other leetgo commands (run from the **repo root**, where `leetgo.yaml` lives): `leetgo pick <id>` to generate a new problem, `leetgo submit <id>` (or `last`) to submit, `leetgo info <id>`.

## The C++ standard is pinned in THREE places — keep them in sync

Changing the C++ standard or core flags means editing all three, or the build, the editor, and leetgo will disagree:

1. `leetgo.yaml` → `cpp.cxxflags` — used by `leetgo test`/`submit` (mirrors LeetCode: `-O2`, C++23).
2. `cpp/Taskfile.yml` → `CXXFLAGS` — the local build/debug (adds `-g -O0` and sanitizers).
3. `cpp/compile_flags.txt` — read by **clangd** for editor diagnostics.

Notes that bite if forgotten:
- `compile_flags.txt` is parsed **one argument per line** (clangd), whereas `g++ @file` splits on any whitespace — so a flag needing an argument (e.g. `-isystem .`) must be on two lines for clangd. This is why the include path is written `-I.` (single token) rather than `-isystem`.
- The local compiler (GCC 15 / libstdc++ 15) is **newer** than LeetCode's (clang 19 / libstdc++ 14). A library feature present locally but not in libstdc++ 14 will compile here yet fail on submit — the usual cause of "works locally, fails on LeetCode."
- The sanitizer build genuinely catches real bugs (e.g. `size_t` index underflow, missing return); prefer `task run`/`task debug` over trusting a green LeetCode "Accepted", which compiles without hardening.
