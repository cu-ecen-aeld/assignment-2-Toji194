#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Error: Two arguments required"
    exit 1
fi

writefile="$1"
writestr="$2"

mkdir -p "$(dirname "$writefile")" || {
    echo "Error: Could not create directory"
    exit 1
}

echo "$writestr" > "$writefile" || {
    echo "Error: Could not write file"
    exit 1
}

exit 0
