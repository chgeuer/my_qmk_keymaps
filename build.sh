#!/bin/bash

cd ./qmk_firmware || exit
make git-submodule
cd ..

user="chgeuer"
destination="/mnt/c/Users/${user}/Desktop/"

# ln -s -f "$(pwd)/chgeuer_keyboards/lily58__rev1"           ./qmk_firmware/keyboards/lily58/keymaps/chgeuer
# ln -s -f "$(pwd)/chgeuer_keyboards/preonic__rev3"          ./qmk_firmware/keyboards/preonic/keymaps/chgeuer
# ln -s -f "$(pwd)/chgeuer_keyboards/boardsource__technik_o" ./qmk_firmware/keyboards/boardsource/technik_o/keymaps/chgeuer

declare -A keybs=(
   ["lily58"]="rev1"
   ["preonic"]="rev3"
   ["boardsource"]="technik_o"
)

declare -A keyMapDir=(
   ["lily58"]="./qmk_firmware/keyboards/lily58/keymaps/chgeuer"
   ["preonic"]="./qmk_firmware/keyboards/preonic/keymaps/chgeuer"
   ["boardsource"]="./qmk_firmware/keyboards/boardsource/technik_o/keymaps/chgeuer"
)

for vendor in "${!keybs[@]}"; do
   keyboard="${keybs[$vendor]}"
   folder="${keyMapDir[$vendor]}"

   echo "building ${vendor}-${keyboard}"
   
   rm "${folder}"
   ln -s -f "$(pwd)/chgeuer_keyboards/${vendor}__${keyboard}" "${folder}"
   cd ./qmk_firmware || exit

   qmk compile -kb "${vendor}/${keyboard}" -km "${user}"
   cp ".build/${vendor}_${keyboard}_${user}.hex" "${destination}"
   cd ..
   rm "${folder}"
done
