if __name__ == "__main__":
    
    initial = 0
    increment = 10
    maximum = 100
    for count in range(1, 10):

        increment = increment/10
        maximum = maximum/10

        i = initial
        while i < maximum:
            i = i + increment
        
        print(count, i)
