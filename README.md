# my_qmk_keymaps

This repo builds firmware for my keyboards.

Check install instructions: https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/getting_started_build_tools.md



```shell
#!/bin/bash

sudo apt-get update

sudo apt-get install gcc unzip wget zip gcc-avr binutils-avr avr-libc dfu-programmer dfu-util gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi

python3 -m pip install qmk

git clone --recurse-submodules --remote-submodules git@github.com:chgeuer/my_qmk_keymaps.git
```
