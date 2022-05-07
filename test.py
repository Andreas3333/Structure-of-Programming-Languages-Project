import sys # imported for get_ref_count() use

 # Andreas Schaler
 # Structure of Programming Languages
 # Aditi Singh
 # Spring 2022
 #
 # compile with python version 3.10.4 interpreter
 #
 # -----------------------------------------------
 # This program is ment to deminstrate the use of 
 # garbage collection, pointers and memory allocation,
 # and parameter passing in the python language. Where
 # these mechinisms are supported or not.
 #
 # Explination of python's gc taken from
 # 'https://devguide.python.org/garbage_collector/'
 # all credit given.
 # 1) Garbage Collection is performed by python's
 #    garbage collection algorithm which is a mark and
 #    scan algorithm. Refrence counter tracks the number
 #    of refences an object has to it, when this counter
 #    reaches 0 an object is freed from memory. A mechinism
 #    which is also used in pythons parmeter passing and 
 #    memory manager mechinisms.
 #
 # Explination of python's memory managment taken from
 # 'https://docs.python.org/3/extending/extending.html#reference-counts'
 # all credit given.
 # 2) Memory allocation and deallocation is implicitly
 #    handled by python's memory manager which also makes
 #    use of refrence counts to an object. When an 
 #    objects refrence count becomes 0, the memory
 #    location which the object occupies is released 
 #    from memory by its automatic garbage collection
 #    mechinism. The programer does not have explicit
 #    control over memory stores of his program by means
 #    of known c and c++ memory allocation malloc(), free(),
 #    and new, delete operations. This control is taken
 #    out pf the programers hands and left to the memory
 #    management stratages of the language.
 #
 # 3) Supported parameter passing mechinisms in python
 #    is pass by assignment. Refrences are passed between
 #    refrencing areas of a python program to the objects
 #    location in memory for access and use in operating 
 #     with and on an object.
 #
 #
 #
 #

str = "abcd"      # global variable for use in demonstraitions
print("Gloabl refrence count of str = ", sys.getrefcount(str))
print("------------------------------------------------")

def str_rev(str):
    print("Refrence count of str in called str_rev() method = ", sys.getrefcount(str))
    print(str, id(str), "  --Memory location of passed by value argument, local funtion output.")
    reved_str = str
    print(reved_str, id(reved_str))
    reved_str = str [::-1]
    print(reved_str, id(reved_str))
    print("Refrence count of str in called str_rev() method after use in reversal of char sequences = ", sys.getrefcount(str))
 

def main():
    print("Refrence count of str in called main() = ", sys.getrefcount(str))
    print(str, id(str), "  --Memory location for output from main() calling area, for compairison.")
    str_rev(str)
    
  
    

if __name__ == "__main__":
    print("Inside main() driver function refrence count of str = ", sys.getrefcount(str))
    main()
    print("Refrence count of str = ", sys.getrefcount(str))