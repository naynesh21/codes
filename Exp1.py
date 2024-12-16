'''
Assignment No. 1 : In a second year computer engineering class, group A students play cricket, group B students play
                   badminton and group C students play football.
                   Write a python program using functions to compute following:
                   a) List of students who play both cricket and badminton.
                   b) List of students who play either cricket or badminton but not both.
                   c) Number of students who play neither cricket nor badminton.
                   d) Number of students who play cricket and football but not badminton.
(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET built-in functions)

# Function to remove duplicate entries
def removeduplicates(d): 
    list1 = [] 
    for i in d: 
        if i not in list1: 
            list1.append(i) 
    return list1

# Function for union of two sets
def Union(cricket, badminton): 
    list3 = cricket.copy()  
    for val in badminton: 
        if val not in list3: 
            list3.append(val) 
    return list3

# Function for difference between two sets
def Difference(cricket, badminton): 
    list3 = [] 
    for val in cricket: 
        if val not in badminton: 
            list3.append(val) 
    return list3

# Function for intersection of two sets
def Intersection(cricket, badminton): 
    list3 = []
    for val in cricket:
        if val in badminton:
            list3.append(val)
    return list3

# Function for symmetric difference of two sets
def SymmetricDiff(cricket, badminton):  
    d1 = Difference(cricket, badminton)
    d2 = Difference(badminton, cricket)
    return Union(d1, d2)

# Menu option functions
def CB(cricket, badminton): 
    list3 = Intersection(cricket, badminton)  
    print("\nList of students who play both cricket and badminton: ", list3) 
    return len(list3)

def eCeB(cricket, badminton): 
    list3 = SymmetricDiff(cricket, badminton) 
    print("\nList of students who play either cricket or badminton but not both: ", list3) 
    return len(list3)

def nCnB(SEcomp, cricket, badminton): 
    list4 = Difference(SEcomp, Union(cricket, badminton)) 
    print("\nList of students who play neither cricket nor badminton: ", list4) 
    return len(list4)

def CFnB(cricket, football, badminton): 
    list3 = Intersection(cricket, football)
    list4 = Difference(list3, badminton)
    print("\nList of students who play cricket and football but not badminton: ", list4) 
    return len(list4)

# Input for students
def input_group(prompt):
    n = int(input(f"Enter number of students {prompt}: "))
    group = [input("Enter student name: ").strip() for _ in range(n)]
    return removeduplicates(group)

# Main program
SEcomp = input_group("in SEcomp")
Cricket = input_group("playing Cricket")
Badminton = input_group("playing Badminton")
Football = input_group("playing Football")

flag = 1
while flag == 1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. Number of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit\n")
    try:
        ch = int(input("Enter your choice (1 to 5): "))
        if ch == 1:
            print("Number of students who play both cricket and badminton: ", CB(Cricket, Badminton))
        elif ch == 2:
            print("Number of students who play either cricket or badminton but not both: ", eCeB(Cricket, Badminton))
        elif ch == 3:
            print("Number of students who play neither cricket nor badminton: ", nCnB(SEcomp, Cricket, Badminton))
        elif ch == 4:
            print("Number of students who play cricket and football but not badminton: ", CFnB(Cricket, Football, Badminton))
        elif ch == 5:
            flag = 0
            print("Thanks for using this program!")
        else:
            print("!! Wrong Choice !! ")
    except ValueError:
        print("Please enter a valid integer choice.")

    if flag:
        a = input("\nDo you want to continue (y/n): ").strip().lower()
        if a != "y":
            flag = 0
            print("Thanks for using this program!")




