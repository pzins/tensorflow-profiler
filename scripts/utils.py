

DEBUG_SIZE = 40
PRINT_DEBUG_SYMBOL = "="

def debugPrint(st):
    stars = DEBUG_SIZE - len(st)
    left_stars = int(stars / 2)
    right_stars = stars - left_stars
    for i in range(left_stars):
        print(PRINT_DEBUG_SYMBOL, end="")
    print(" ", end="")
    print(st, end="")
    print(" ", end="")
    for i in range(right_stars):
        print(PRINT_DEBUG_SYMBOL, end="")
    print("")
