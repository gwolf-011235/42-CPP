#!/bin/bash

# Check if two filenames are provided as arguments
if [ $# -ne 2 ]; then
  echo "Usage: $0 <input_log_filename> <output_log_filename>"
  exit 1
fi

# Store the input and output filenames
input_file="$1"
output_file="$2"

# Use sed to remove the timestamp and save the modified content to the output file
sed 's/\[[0-9]\{8\}_[0-9]\{6\}\] //' "$input_file" > "$output_file"

echo "Timestamps removed. Modified log saved as $output_file"
