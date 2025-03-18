#include <stdio.h>
#include "SET.cpp"

int main() {
	
	int data1[] = { 1, 2, 3, 4, 5 };
	int data2[] = { 9, 8, 7, 6, 5, 4 };
	
	Set s1;
	Set s2;

	s1.update(data1, sizeof(data1)/sizeof(int));
	s2.update(data2, sizeof(data2)/sizeof(int));

	printf("Set-1:\n");
	s1.display();		
	printf("Set-2:\n");
	s2.display();
	
	Set s3 = s1.Union(s2);
	printf("Set-3:\n");
	s3.display();		
	
	Set s4 = s1.Intersection(s2);
	printf("Set-4:\n");
	s4.display();	
	
	
	return 0;
}
