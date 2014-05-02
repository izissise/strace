#!/bin/bash

INFILE="/usr/include/asm/unistd_64.h"

while read CALL
do
NAME="$(echo $CALL | cut -d' ' -f1)"
NUMBER="$(echo $CALL | cut -d' ' -f2)"
PROTO=$(man "$NAME" | cat | grep " $NAME(.*);$" | head -n 1)

PROTO=$(echo "$PROTO" | sed "s/$NAME//" | tr -d "(;" | tr ")" "," | sed 's/\[2\]//' \
  | sed 's/[a-z]*,//g' | sed 's/ \*/\*/' | sed 's/  / /g' | sed 's/^  //g')
echo "$PROTO"
# echo $NAME $NUMBER "$PROTO"
done < <(cat $INFILE | sed 's/.*__NR_//' | grep -Ev '(#endif|#define|#ifndef|^$)')