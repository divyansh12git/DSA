def find_final_value(M, N):
    if M < N:
        print(M)
    else:
        while M >= N:
            M -= N
        print(M)

# Taking input from the user
M = int(input("Enter the value of M: "))
N = int(input("Enter the value of N: "))

find_final_value(M, N)