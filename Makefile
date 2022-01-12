all: main.o has_cycle.o merge_sort.o reverse_list.o \
	two_sum.o merge_sorted_list.o list_stdlib.o string_encryption.o
	cc -g3 -o main_app main.o has_cycle.o merge_sort.o reverse_list.o \
	two_sum.o merge_sorted_list.o list_stdlib.o string_encryption.o
main.o: main.c has_cycle.o two_sum.o merge_sort.o merge_sorted_list.o \
	list_stdlib.o string_encryption.o
	cc -c main.c
has_cycle.o: has_cycle.c has_cycle.h list_stdlib.o
	cc -c has_cycle.c
merge_sort.o: merge_sort.c merge_sort.h list_stdlib.o
	cc -c merge_sort.c
merge_sorted_list.o: merge_sorted_list.c merge_sorted_list.h list_stdlib.o
	cc -c merge_sorted_list.c
reverse_list.o: reverse_list.c reverse_list.h list_stdlib.o
	cc -c reverse_list.c
two_sum.o: two_sum.c two_sum.h
	cc -c two_sum.c
list_stdlib.o: list_stdlib.c list_stdlib.h
	cc -c list_stdlib.c
string_encryption.o: string_encryption.c string_encryption.h
	cc -c string_encryption.c
clean: 
	rm *.o