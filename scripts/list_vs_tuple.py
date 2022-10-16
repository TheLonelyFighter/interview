"""module which shows the difference between list and tuple"""
import sys

#python list can contain heterogenous data types (what a heresy) and can be changed
shopping_list = ["milk", "pasta", "eggs", "spam", "bread", "rice", "1", 2, 3.14, True, False, None]
shopping_tuple = ("milk", "pasta", "eggs", "spam", "bread", "rice", "1", 2, 3.14, True, False, None)

for i in shopping_list:
    print(type(i), i)

# printing the list will simply print the class type without the elements
print(list)

# printing the tuple will print the elements
print(shopping_tuple)

# lists are muttable, you CAN change/add/remove elements
shopping_list[0] = "cream"
shopping_list.append("chocolate")
shopping_list.remove("spam")

# tuples are immutable, you CANNOT change/add/remove elements
#shopping_tuple[0] = "cream" # will throw an error

# tuples are more memory efficient than lists
print("List memory size: ", sys.getsizeof(shopping_list), " bytes")
print("Tuple memory ize: ", sys.getsizeof(shopping_tuple), " bytes")

# tuples are faster to access than lists because they are immutable

#Conlusion: Use tuples when you have a fixed set of data and you don't want to change it
#           Use lists when you have a variable set of data and you want to change it
