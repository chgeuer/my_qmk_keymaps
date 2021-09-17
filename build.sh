#!/bin/bash

root="$( dirname "$( readlink -f "$0" )" )"

# git submodule update
# cd "${root}/qmk_firmware" || exit
# make git-submodule

declare -A keybs=(
   ["lily58"]="rev1"
   ["preonic"]="rev3"
   ["boardsource"]="technik_o"
)

declare -A keyMapDirs=(
   ["lily58"]=""
   ["preonic"]=""
   ["boardsource"]="technik_o/"
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
   cp ".build/${vendor}_${keyboard}_${user}.hex" "/mnt/c/Users/${user}/Desktop/"
   cd "${root}" || exit
   rm -f "${user}"
done
