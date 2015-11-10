>array_out.txt
>list_out.txt
cat strings.txt | while read string
do
	echo "Processing '$string'"
	./lab3 array "$string" >> array_out.txt
	./lab3 list "$string" >> list_out.txt
done
diff -u array_out.txt list_out.txt
