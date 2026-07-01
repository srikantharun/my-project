# Overview

## Content

This repository contains a `C++` based project template that leverages [vcpkg](https://github.com/microsoft/vcpkg) and [CMake](https://www.cmake.org)'s [CMakePresets.json](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) to build and test `C++` source code.

Supports `Linux`/`macOS`/`Windows` on `x64` and `arm64` platforms.

`vcpkg` is driven to use its [binary caching](https://learn.microsoft.com/en-us/vcpkg/users/binarycaching) feature storing the content in the GitHub Action cache, hence speeding up workflows by reusing previously built packages.

## Key features:

- `CMakePresets.json` allows to run the same build either _locally on your IDE_ and on _GitHub runners_.
- `vcpkg` greatly helps in pulling and building the needed dependencies (e.g. libraries) which are cached for reuse on GitHub Action cache.

## GitHub Action workflows

The repository provides also two GitHub workflows to build the project on [GitHub runners](https://github.com/actions/runner). Both builds and tests the project using `vcpkg` and `CMake`, the only key difference is their implementation:

- [hosted-pure-workflow.yml](.github/workflows/hosted-pure-workflow.yml): it is a **pure** workflow which does not use unneeded GitHub Actions that cannot run locally on your development machine. On the other hand it is directly using the `CMake`, `Ninja`, `vcpkg` and the `C++ build` tools.
- [hosted-ninja-vcpkg_submod.yml](.github/workflows/hosted-ninja-vcpkg_submod.yml): it is a concise workflow based on the custom GitHub Actions [get-cmake](https://github.com/lukka/get-cmake), [run-vcpkg](https://github.com/lukka/run-vcpkg) and [run-cmake](https://github.com/lukka/run-cmake) which simplify and shorten the workflow verbosity while adding some goodies like vcpkg binary caching stored on GH's cache and inline error annotations.

## Rationale

The main idea of this `C++` project template is to show how to obtain a _perfectly reproducible_ software development process that can be run anywhere without any difference and no surprises, either locally using your preferred tools/IDE, either remotely on build agents typically used for continuous integration.

Unfortunately one of the engineers did a few mistakes and it is up to us to try and fix them.

# Your Goal

## Phase 1:

Feel free, not necessarily in this order to:

- examine the repository;
- try to run it and find the parts that are not working
- find what might not be working in the tests

## Phase 2:

- how would you containerise this with Docker?
- what would your GitHub Actions workflow stages be?
- how would you cache CMake/vcpkg dependencies?
- how would you publish a versioned artifact?
- what secrets/signing risks would you watch for?
- what would your `DockerFile` roughly do?

# Rules of engagement

You are allowed to:

- ask plenty of questions to the interviewer;
- Google for syntax;
- read documentation;
- use AI to fix sub-problems (just don't copy and paste and tell it to do all your work!)

Other rules and tips:

- timebox your work wisel: assume you will work on it only with 30–40 minutes of analysis, discussion and coding, then discussion;
- full completion is not required;
- assume that you will have to explain what you found, what you fixed, and what you would do next to your team mates;
- ideal success criteria (if you had enough time to complete everything): build runs, tests are discovered/executed, CI issue identified, reasoning is clear;
- do not over-focus on vcpkg or other libraries: their knowledge is not the main assessment.
