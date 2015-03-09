#include <stdio.h>
int main()
{
	float x,y;
	scanf("%f%f",&x,&y);
	if(x > 0 && y > 0 ) printf("First Quadrant");
	if(x > 0 && y < 0 ) printf("Fourth Quadrant");
	if(x < 0 && y < 0 ) printf("Third Quadrant");
	if(x < 0 && y > 0 ) printf("Second Quadrant");
}
