import sys

SIZE = 50000

def main():

    expected_checksum = 41667916675000
    
    # Initialize lists
    A = [i for i in range(SIZE)]
    B = [SIZE - i for i in range(SIZE)]
    C = [0] * SIZE

    # Perform the main computation
    for i in range(SIZE):
        temp_sum = 0
        for j in range(A[i] + 1):
            temp_sum += B[j]
        C[i] = temp_sum

    # Calculate checksum and verify the result
    computed_checksum = sum(C)

    print(f"Computed checksum: {computed_checksum}")

    # Print error message and exit if checksum does not match
    if computed_checksum != expected_checksum:
        print("Error: Checksum does not match the expected value!")
        sys.exit(1)
    
    sys.exit(0)

# execute main function
if __name__ == "__main__":
    main()