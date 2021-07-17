# TMetaDump

**TMetaDump** is a homebrew application for the Nintendo Switch which dumps the metadata of all installed titles.

## Usage

Download the latest .nro and launch it through the homebrew menu. Wait until the dump is completed (progress is displayed on screen).

## Compiling

Clone the repository to your already setup Switch homebrew development environment, and run:

```bash
git submodule update --init
make -j$(nproc)
```
