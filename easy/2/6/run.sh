#!/bin/bash

result="success"

while read input; do
  read output1
  read output2
  
  while read line1; do
    read line2

    if [ "$line1" = "$output1" ] && [ "$line2" = "$output2" ]; then
      echo "Test success: $input"
    else
      result="failure"
    fi

  done < <(./main < <(echo $input))
  
done < "$1"

