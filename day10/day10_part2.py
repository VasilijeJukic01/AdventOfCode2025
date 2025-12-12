import re
from z3 import *

# WTF IS THIS PROBLEM?! :'((((((


def solve(line):
    match_targets = re.search(r'\{(.*?)\}', line)
    targets = [int(x) for x in match_targets.group(1).split(',') if x.strip()]

    # Parsing buttons
    header = line.split('{')[0]
    raw = re.findall(r'\(([\d,]+)\)', header)

    button_affects = []
    for rb in raw:
        indices = [int(x) for x in rb.split(',') if x.strip()]
        button_affects.append(indices)

    num_btns = len(button_affects)
    num_cnts = len(targets)

    # Z3
    opt = Optimize()

    # Variables for each button -> how many times we press each button
    x = [Int(f'x_{i}') for i in range(num_btns)]

    # Constraints
    for var in x:
        opt.add(var >= 0)

    # For each affect, sum of presses of buttons affecting it must equal the target
    for c in range(num_cnts):
        affecting_buttons = []
        for btn in range(num_btns):
            if c in button_affects[btn]:
                affecting_buttons.append(x[btn])

        # If btns exist for counter -> add sum constraint
        if affecting_buttons:
            opt.add(Sum(affecting_buttons) == targets[c])
        else:
            # If no buttons affect -> must start at 0 or not possible
            if targets[c] != 0:
                return 0

    # Minimization
    total_presses = Sum(x)
    opt.minimize(total_presses)

    if opt.check() == sat:
        model = opt.model()
        return model.eval(total_presses).as_long()
    else:
        return 0


def main():
    total = 0

    for line in sys.stdin:
        line = line.strip()
        if line == "stop":
            break

        total += solve(line)

    print(total)


if __name__ == "__main__":
    main()
