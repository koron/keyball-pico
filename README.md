# Keyball series firmware for RP2040

To build all:

```console
$ make
```

## Prerequirements

* pico-sdk 1.4.0 or above
* cmake
* diykb library in github.com/koron/yuiop60pi

## Configurables

*   `DIYKB_PATH` env - path to local copy of <https://github.com/koron/yuiop60pi/tree/main/diykb>.
    Default is `../yuiop60pi/diykb`
* `PICO_BOARD` env - a board which have ProMicro like footprint.
    Default is `sparkfun_promicro`
