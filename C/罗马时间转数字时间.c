#include <stdio.h>
#include <string.h>
int main ()
{
    char roman_numeral[8];									//�����ַ������������ 
    while ( gets( roman_numeral ) != NULL )					//��������� ��= NULL���˳� contr + z�˳����� 
    {
        if ( strcmp( roman_numeral, "I" ) == 0)				//��������ַ�����ÿ������������Աȣ� 
            printf( "��Ӧ������ʱ����: %d\n", 1);			//�����Ӧ�����֣����¶���� 
        else if (  strcmp( roman_numeral, "II" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 2 );
        else if (  strcmp( roman_numeral, "III" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 3 );
        else if (  strcmp( roman_numeral, "IV" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 4 );
        else if (  strcmp( roman_numeral, "V" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 5 );
        else if (  strcmp( roman_numeral, "VI" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 6 );
        else if (  strcmp( roman_numeral, "VII" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 7 );
        else if (  strcmp( roman_numeral, "VIII" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 8 );
        else if (  strcmp( roman_numeral, "IX" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 9 );
        else if (  strcmp( roman_numeral, "X" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 10 );
        else if (  strcmp( roman_numeral, "XI" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 11 );
        else if (  strcmp( roman_numeral, "XII" )== 0 )
            printf( "��Ӧ������ʱ����: %d\n", 12 );
        else 
			printf("������ĵĲ�����ȷ������ʱ�䣡\n");
    }
    return 0;
}
