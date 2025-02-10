# Based on code by ivolol from twitch

import sys, os
from subprocess import run, PIPE, STDOUT
from pathlib import Path

this_dir = os.path.dirname(os.path.realpath(__file__))
prev_dir = this_dir[:this_dir.rfind("/")]

CASES_FILE = f"{this_dir}/cases.txt"
PROGRAM = f"{prev_dir}/readability"

# full example usage: python check_outputs.py ./credit inputs.txt
# ./credit should be an executable file
# inputs.txt should be a set of inputs -> outputs, separated by a tab character (\t)

# use cmd line arguments, if some are provided
if len(sys.argv) > 1:
    test_prog = sys.argv[1]
else:
    test_prog = PROGRAM

if len(sys.argv) > 2:
    test_file = Path(sys.argv[2])
else:
    test_file = Path(CASES_FILE)

# check that our cases file exists, and read it into TEST_CASES if so
if test_file.is_file():
    with open(test_file) as f:
        TEST_CASES = [line[:-1].split("\t") for line in f]
else:
    sys.exit(f"Error, {test_file} not found")


# check that our executable is readable and also executable
if not (Path(test_prog).is_file() and os.access(test_prog, os.X_OK)):
    sys.exit(f"Error, {test_prog} not an executable file")


cases, passes, fails = 0, 0, 0
for input_text, output_text in TEST_CASES:
    cases += 1
    output = run(test_prog, input=input_text, stdout=PIPE, stderr=STDOUT, text=True)
    if output.stdout.strip() != output_text.strip():
        input_plain = input_text.strip()
        expected_plain = output_text.strip()
        output_plain = output.stdout.strip().replace("Text: ", "")
        print(f"Error \nInput: '{input_plain}' \n\nActual:   '{output_plain}' \nExpected: '{expected_plain}'\n\n")
        fails += 1
    else:
        passes += 1

print(" ---")
print(f"Cases: {cases} | Passes: {passes} | Fails: {fails}")
