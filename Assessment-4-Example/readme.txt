===================================
CS 162 Computer Science II
Assessment 4 (Linked Lists II)
===================================

-----------------------------------
Academic Integrity
-----------------------------------

You may NOT, under any circumstances, begin an assessment by looking for
completed code on StackOverflow or Chegg or any such website, which you can
claim as your own. Please check out the Student Code of Conduct at PCC.

This assessment is individual work only. You must not discuss this assessment
with any person other than your instructor. You may use course material for
reference but you must not use any other (non-course) material during this
assessment.

I may ask you to explain your assessment verbally. If you cannot
satisfactorily explain what your code does, and answer questions about why you
wrote it in a particular way, then you should expect a zero.

This assessment focuses on the implementation of Linked Lists Part II.

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
you will be looking at and editing in order to complete the tasks.

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

You will find this code is quite similar with the code in previous
assessments. Here are some key differences:

1) The implementation for the ItemList class is changed from dynamically
allocated array to a linear linked list (or singular linked list).

2) A struct Node is added to the private section of the ItemList class. This
prevents the code outside of the ItemList class from accessing the Node, but
it provides direct access to the member functions in the class.

3) Three private helper functions are added: destroy, copy and append. They
are used by the public functions of the class.

4) You should get yourself familiar with two traversal schemes:

  a) One pointer traverse, e.g. use curr only. Usually, we use this scheme
  when we only visit the list

  b) Two pointers traverse, e.g use prev and curr. Usually, we use this scheme
  when we need to modify the list. It’s much more convenient when you have a
  pointer to the previous node when you are trying to insert/remove.

-----------------------------------
Tasks
-----------------------------------

For this test, you will need to complete the following tasks.

1) Create a public member function getItem() for class ItemList. The function
should copy the item at position “index” into anItem and return true if the
index is within the range of the list. It should return false if there are no
matching items. The method prototype should be:
 
  bool getItem(int index, InventoryItem& anItem);

Step 1) Add the member function prototype inside class ItemList in itemList.h.

Step 2) Put the member function implementation in itemList.cpp

Step 3) Add code to main.cpp to exercise the new method. You should read in
the index from the user. Remember to prompt the user. If the retrieval is
successful, you should print the found item. Please label your output
clearly. If the retrieval failed, you still need to let the user know there is
no item at that position.

2) Create a public member function removeItem() for class ItemList. The
function should remove the item with itemName from the list. It returns false
if there is no item with the matching name. The method prototype should be:
 
    bool removeItem(const char* itemName);

Step 1) Add the member function prototype inside class ItemList in itemList.h.

Step 2) Put the member function implementation in itemList.cpp

Step 3) Add code to main.cpp to invoke the new method. You should prompt the
user to enter the name that needs to be removed. Be sure to cover the case
where the name to be removed isn't in the list. Label your output clearly.

Use the provided makefile to compile your code:

To compile: make
To run: ./main
To check memory leaks: valgrind –leak-check=full ./main
To clean up: make clean

-----------------------------------
Sample Run
-----------------------------------

After you write your functions your Sample Run could look like this:

Sample Run 
Current Inventory:
apple     0.99    Sun 2022-03-20
banana  0.69    Wed 2021-04-28
cookie    0.50    Sun 2023-02-12
donut     1.00    Thu 2021-10-28
egg         3.88    Sun 2022-01-30
fish         5.88    Mon 2021-02-15
milk        2.99    Tue 2021-03-02
yogurt    6.38    Sun 2021-06-13

Enter the index to find the item (0 to 8): 4

Item found!
egg         3.88    Sun 2022-01-30

Enter name of the item to remove: milk

Item removed! Updated list below:

apple     0.99    Sun 2022-03-20
banana  0.69    Wed 2021-04-28
cookie    0.50    Sun 2023-02-12
rice         2.39    Thu 2022-05-12
donut     1.00    Thu 2021-10-28
egg         3.88    Sun 2022-01-30
fish         5.88    Mon 2021-02-15
yogurt    6.38    Sun 2021-06-13

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

