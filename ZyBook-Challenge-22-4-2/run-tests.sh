#! /bin/bash

g++ main.cpp
	
for n in {1..4}; 
do 
	t=test-${n}.txt;  
	echo -e "\n\nINPUT:"; 
	cat $t; 
	echo -e "YOUR OUTPUT:"; 
	./a.out < $t; 
done 

rm ./a.out


