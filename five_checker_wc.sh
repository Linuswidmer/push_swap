#!/bin/bash

numbers=(1 2 3 4 5)

for ((i=0; i<${#numbers[@]}; i++)); do
  for ((j=0; j<${#numbers[@]}; j++)); do
    for ((k=0; k<${#numbers[@]}; k++)); do
      for ((l=0; l<${#numbers[@]}; l++)); do
        for ((m=0; m<${#numbers[@]}; m++)); do
            ./push_swap "${numbers[i]} ${numbers[j]} ${numbers[k]} ${numbers[l]} ${numbers[m]}" | grep -v "Error" | wc -l | grep -v "0"
        done
      done
    done
  done
done
