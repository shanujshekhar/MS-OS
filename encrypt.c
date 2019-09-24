
#include <stdio.h>
#include <malloc.h>

char * encrpyt(char str[], int key)
{
    int i;
    char * en = (char *) malloc(sizeof(char) * 100);
    for(i=0 ; str[i]!='\0' ; i++)
    {
        if( str[i] >= 'a' && str[i] <= 'z' )
        {
            if( str[i] + key > 'z' )
                en[i] = str[i] + key - 'z' + 'a' - 1 ;
            else
                en[i] = str[i] + key;
        }
        else
        {
            if( str[i] + key > 'Z' )
                en[i] = str[i] + key - 'Z' + 'A' - 1 ;
            else
                en[i] = str[i] + key;
        }
    }
    en[i] = '\0';
    return en;   
}

int main()
{

    char str[100] = "";
    int key;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("Enter the key: ");
    scanf("%d",&key);
    if( key<1 && key>5 )
    {    
        printf("Key Out of Bound!!");
        return 0;
    }
    printf("Encrypted String: ");
    printf("%s",encrpyt(str,key));
    return 0;
}
