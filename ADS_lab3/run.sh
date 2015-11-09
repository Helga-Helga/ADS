cat strings.txt | while read string
do
	>array_out.txt
	>list_out.txt
	./lab3 array "$string" >> array_out.txt
	./lab3 list "$string" >> list_out.txt
done
diff -u array_out.txt list_out.txt
