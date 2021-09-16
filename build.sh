#!/bin/bash

user="chgeuer"
destination="/mnt/c/Users/${user}/Desktop/"

declare -A keybs=(
   ["lily58"]="rev1"
   ["preonic"]="rev3"
   ["boardsource"]="technik_o"
)

for vendor in "${!keybs[@]}"; do
   keyboard="${keybs[$vendor]}"

   echo "building ${vendor}-${keyboard}"
   
   qmk compile -kb "${vendor}/${keyboard}" -km "${user}"
   cp "${vendor}_${keyboard}_${user}.hex" "${destination}"
done
