#!/bin/bash

root="$( dirname "$( readlink -f "$0" )" )"

echo "root dir: ${root}"

# git submodule update
# cd "${root}/qmk_firmware" || exit
# git checkout master
# git pull
# make git-submodule

declare -A keybs=(
   ["lily58"]="rev1"
   ["preonic"]="rev3"
   ["boardsource"]="technik_o"
   ["crkbd"]="rev1"
   ["massdrop"]="thekey"
)

declare -A keyMapDirs=(
   ["lily58"]=""
   ["preonic"]=""
   ["boardsource"]="technik_o/"
   ["crkbd"]=""
   ["massdrop"]="thekey/"
)

declare -A extension=(
   ["lily58"]="hex"
   ["preonic"]="bin"
   ["boardsource"]="hex"
   ["crkbd"]="hex"
   ["massdrop"]="hex"
)

user="chgeuer"

for vendor in "${!keybs[@]}"; do
   keyboard="${keybs[$vendor]}"
   echo "building ${vendor}:${keyboard}"

   keymapDir="${root}/qmk_firmware/keyboards/${vendor}/${keyMapDirs[$vendor]}keymaps"
   # echo "cd ${keymapDir} && ln -s ${root}/chgeuer_keyboards/${vendor}__${keyboard} ${user}"
   cd "${keymapDir}" || exit
   rm -f "${user}"
   ln --symbolic --verbose "${root}/chgeuer_keyboards/${vendor}__${keyboard}" "${user}"
   # ls -als "${user}"

   cd "${root}/qmk_firmware" || exit
   qmk compile -kb "${vendor}/${keyboard}" -km "${user}"

   cp ".build/${vendor}_${keyboard}_${user}.${extension[$vendor]}" "/mnt/c/Users/${user}/Desktop/"
   cd "${root}" || exit
   rm -f "${user}"
done
