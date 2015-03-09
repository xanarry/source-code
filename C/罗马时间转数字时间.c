#include <stdio.h>
#include <string.h>
int main ()
{
    char roman_numeral[8];									//定义字符数组接收输入 
    while ( gets( roman_numeral ) != NULL )					//如果不输入 ！= NULL则不退出 contr + z退出输入 
    {
        if ( strcmp( roman_numeral, "I" ) == 0)				//将输入的字符串与每个罗马数组最对比， 
            printf( "对应的数字时间是: %d\n", 1);			//输出对应的数字，以下都如此 
        else if (  strcmp( roman_numeral, "II" )== 0 )
            printf( "对应的数字时间是: %d\n", 2 );
        else if (  strcmp( roman_numeral, "III" )== 0 )
            printf( "对应的数字时间是: %d\n", 3 );
        else if (  strcmp( roman_numeral, "IV" )== 0 )
            printf( "对应的数字时间是: %d\n", 4 );
        else if (  strcmp( roman_numeral, "V" )== 0 )
            printf( "对应的数字时间是: %d\n", 5 );
        else if (  strcmp( roman_numeral, "VI" )== 0 )
            printf( "对应的数字时间是: %d\n", 6 );
        else if (  strcmp( roman_numeral, "VII" )== 0 )
            printf( "对应的数字时间是: %d\n", 7 );
        else if (  strcmp( roman_numeral, "VIII" )== 0 )
            printf( "对应的数字时间是: %d\n", 8 );
        else if (  strcmp( roman_numeral, "IX" )== 0 )
            printf( "对应的数字时间是: %d\n", 9 );
        else if (  strcmp( roman_numeral, "X" )== 0 )
            printf( "对应的数字时间是: %d\n", 10 );
        else if (  strcmp( roman_numeral, "XI" )== 0 )
            printf( "对应的数字时间是: %d\n", 11 );
        else if (  strcmp( roman_numeral, "XII" )== 0 )
            printf( "对应的数字时间是: %d\n", 12 );
        else 
			printf("您输入的的不是正确的罗马时间！\n");
    }
    return 0;
}
