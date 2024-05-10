# patterns=(
#     ".DS_Store"
#     "tempCodeRunnerFile"
#     "a.out"
#     "*.dSYM"
#     "*.gch"
#     "*.obj"
#     "*.o"
#     "*.d"
#     "tempCodeRunnerFile*"
# )


# find . \( -name "${patterns[0]}" $(printf -- '-o -name "%s" ' "${patterns[@]:1}") \) -exec rm {} +





# find . \( -name ".DS_Store" -o -name "tempCodeRunnerFile" -o -name "a.out" -o -name "*.dSYM" -o -name "*.gch" -o -name "*.obj" -o -name "*.o" -o -name "*.d" -o -name "*tempCodeRunnerFile" \) -exec rm {} \;
# find . \( -name ".DS_Store" -o -name "tempCodeRunnerFile" -o -name "a.out" -o -name "*.dSYM" -o -name "*.gch" -o -name "*.obj" -o -name "*.o" -o -name "*.d" -o -name "*tempCodeRunnerFile" \) -delete

#!/bin/bash

# Define an array of filenames
patterns=(
    ".DS_Store"
    "tempCodeRunnerFile"
    "a.out"
    "*.dSYM"
    "*.gch"
    "*.obj"
    "*.o"
    "*.d"
    "*tempCodeRunnerFile*"
)

# Construct the find command
find_command="find . \( "
for pattern in "${patterns[@]}"; do
    find_command+=" -name '$pattern' -o"
done
find_command=${find_command% -o}  # Remove the last '-o'
find_command+=" \) -delete"

# Execute the find command
eval "$find_command"
