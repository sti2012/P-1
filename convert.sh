#!/bin/bash
FROM=iso-8859-1
TO=UTF-8
ICONV="iconv -f $FROM -t $TO"
# Convierte el archivo tiempo.xml de codificacion ISO-8859-1 a UTF-8
find ./tiempo.xml -type f -name "*" | while read fn; do
cp ${fn} ${fn}.bak
$ICONV < ${fn}.bak > ${fn}
rm ${fn}.bak
done
# Es necesario dar al archivo permisos de ejecucion. chmod 777 convert.sh