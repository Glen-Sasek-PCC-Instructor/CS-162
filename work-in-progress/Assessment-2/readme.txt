===================================
CS 162 Computer Science II
Assessment 2 (Dynamic Memory)
===================================

-----------------------------------
Academic Integrity
-----------------------------------

You may NOT, under any circumstances, begin an assessment by looking for
completed code on StackOverflow or Chegg or any such website, which you can
claim as your own. Please check out the Student Code of Conduct at PCC.  This
assessment is individual work only. You must not discuss this assessment with
any person other than your instructor. You may use course material for
reference but you must not use any other (non-course) material during this
assessment. I may ask you to explain your assessment verbally. If you cannot
satisfactorily explain what your code does, and answer questions about why you
wrote it in a particular way, then you should expect a zero.

This is the ACTUAL Assessment. This assessment focuses on the implementation
of dynamic memory in class members.

This is a timed assessment, individual work only. Please do not discuss this
assessment with any person other than the instructor.    

Please be sure to submit something before the deadline! Late submissions are
not accepted and will receive a zero score. Submitting something, even if it
does not work as well as you would like, is always better than not submitting
anything and receiving a zero score!

-----------------------------------
Overview
-----------------------------------

This assessment comes with several files containing code. These are the files
you will be looking and editing to complete the tasks.

Use the provided makefile to compile your code:

To compile: make
To run: ./main
To clean up: make clean

Your output should look like this:

Current Inventory:
apple     0.99    Sun 2022-03-20
banana  0.69    Wed 2021-04-28
cookie    0.50    Sun 2023-02-12
donut     1.00    Thu 2021-10-28
egg         3.88    Sun 2022-01-30
fish         5.88    Mon 2021-02-15
milk        2.99    Tue 2021-03-02
yogurt    6.38    Sun 2021-06-13

Now go through the provided files so you understand what is in there and then
start working on the Tasks outlined below.

You can modify the provided source files, header files and makefile as
needed. The file items.txt contains a set of sample data which is used by the
program to populate the inventory. You are not allowed to use <string>,
<vector> or any other header files in STL.

Check out the Sample Runs at the end of this section

You will find topic2’s code is quite similar with the code in topic1. Here are
some key differences:

1) I created a module for the Date object using the date.h and date.cpp
files. You only need to refer to the public interface of date.h about how to
use the Date type. You should not need to worry about the implementation
details in date.cpp. With that said, you are more than welcome to check it out
and get yourself acquainted with <ctime> library.

2) I modified item.h and item.cpp to add "expiration date" attribute to the
InventoryItem class. Other code requires little modification since the code is
more modular.

3) I used dynamically allocated cstring for the “item name” attribute. The item
name in each InventoryItem object is going to be just big enough. For example:
"apple" will have 6 chars allocated and "pear" will have 5 chars instead.

4) I changed the array inside the ItemList class to a dynamically allocated
array. It can grow when needed. The private expandArray() function is used to
grow the array. The code that adds new items to the list will check logical
size against the current physical capacity. If the array is full, it will
invoke expandArray() to allocate a bigger array for the list.

5) I added copy constructor, move constructor and destructor for both Item and
ItemList classes since they have dynamically allocated data members in
them. We haven't discussed move constructors before. You can ignore it.

-----------------------------------
Tasks
-----------------------------------

For this test, you will need to complete the following tasks.

1) Create isLessThan() for class InventoryItem. It should compare the passed
in item with the invoking item by expiration date. The method prototype
should be:

    bool isLessThan (const InventoryItem& anItem);

Step 1) Add the prototype to item.h.

Step 2) Put the function implementation in the item.cpp file.

Step 3) Add code to main.cpp to test the isLessThan() method on an item.

For your code that tests this, you need to read in the items to be compared
from the user. When reading in from the user, you can read in individual
attributes and invoke the set methods in InventoryItem class.

Hint: operator < is already defined for Date ADT, so you can compare two dates
by: date1 < date2

The sample invocation code could look like (but it not limited to this):

    InventoryItem item1, item2;
    //set up item1, item2

    // ..

    if(item1.isLessThan(item2)) 
    {
      cout << “item1 < item2” << endl;
    }
    else
    {
      cout << “item1 >= item2” << endl;
    }

2) Create a public member function getPrices() for class ItemList to return
the item prices in the list. The prices should be returned through a
dynamically allocated array "prices" and the method should return the number
of prices in the list. The method prototype should be:

    int getPrices(float*& prices) const;

Your method will allocate the new array. This should only be enough memory to
hold the prices. For example, if there are 10 items in the list, you should
allocate an array of 10 prices. Check out all the given functions in this
class to help you with this task. Each element in the array is a float value.

Step 1) Add the member function prototype inside class ItemList in itemList.h.

Step 2) Put the member function implementation in itemList.cpp.

Step 3) Create code in main.cpp to invoke and test the method. You need to
        display the retrieved prices. Please label your output clearly.

Hint 1: Check out zyBooks Section 19.6 and Section 19.7

Hint 2: Remember to allocate the array before you try to populate it and also
        remember to deallocate the array after you are done using it. If you
        forget to allocate the array, your code will crash. If you forget to
        deallocate the array, you will get memory leaks. Many people hate C++
        for these two frequently encountered enemies: segmentation fault and
        memory leaks.

Use the provided makefile to compile your code:

To compile: make
To run: ./main
To check memory leaks: valgrind –leak-check=full ./main
To clean up: make clean

-----------------------------------
Sample Run
-----------------------------------

After you write your functions your Sample Run could look like this:

Current Inventory:
apple     0.99    Sun 2022-03-20
banana  0.69    Wed 2021-04-28
cookie    0.50    Sun 2023-02-12
donut     1.00    Thu 2021-10-28
egg         3.88    Sun 2022-01-30
fish         5.88    Mon 2021-02-15
milk        2.99    Tue 2021-03-02
yogurt    6.38    Sun 2021-06-13

Enter name of item1: Rice
Enter price of item1: 2.39
Enter expiry date of item1: 2022/05/12

Enter name of item2: Pasta
Enter price of item2: 5.99
Enter expiry date of item2: 2024/08/23

Calling isLessThan:
item1 < item2

There are 8 items in your list.
The item prices in your list are:
0.99
0.69 
0.50
1.00
3.88
5.88
2.99
6.38


-----------------------------------
Testing and Output on the Linux server
-----------------------------------

Record 3 runs of your test by following the instructions below.

If you don't remember how to use the script command you can watch this video:

https://youtu.be/sUjzx7I3VoE

1) Type “script output.txt” on the command line and it will start recording
your session in a file called “output.txt.”

2) Run your program as usual and test it with some sample input. Do this 3
times with different inputs.

3) Type “exit” to stop recording.

4) The file should contain three runs of your test. Open output.txt and make
sure it has the three runs of your test.

-----------------------------------
Submission
-----------------------------------

1) Create a single file (tar or zip) that contains all the cpp and h files.

2) Transfer the file generated in step 1 and output.txt from the PCC Linux
server and upload to the D2L assignment. For more information on transferring
files, please review Chapter 2 in the PCC Linux and vim Manual and watch the
Linux Tutorial Videos in the D2L shell.

3) Do your own work. Consult the syllabus for more information about academic
integrity.

