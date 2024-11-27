#include <stdio.h>
#include <string.h>

void main() 
{ 
    char m[30], g[20], tm[20]; 
    int ml, gl, i, j, f; 

    printf("\nEnter message: "); 
    gets(m); 
    ml = strlen(m); 
    printf("\nMessage length: %d", ml); 

    printf("\nEnter generator or divisor: "); 
    gets(g); 
    gl = strlen(g); 
    printf("\nGenerator message length: %d", gl); 

    for (i = 0; i < gl - 1; i++) 
        m[ml + i] = '0'; 
    m[ml + i] = '\0'; 
    printf("\nAfter padding, message is: %s", m); 

    for (i = 0; i < gl; i++) 
        tm[i] = m[i]; 

    for (i = 0; i < ml; i++) 
    { 
        if (tm[0] == '1') 
        { 
            for (j = 0; j < gl; j++) 
            { 
                if (tm[j] == g[j]) 
                    tm[j] = '0'; 
                else 
                    tm[j] = '1'; 
            } 
        } 

        for (j = 0; j < gl - 1; j++) 
            tm[j] = tm[j + 1]; 
        tm[gl - 1] = m[i + gl]; 
    } 

    tm[gl - 1] = '\0'; 
    printf("\nRemainder is: %s", tm); 

    for (i = 0; i < gl - 1; i++) 
        m[ml + i] = tm[i]; 
    m[ml + i] = '\0'; 
    printf("\nAfter adding remainder, message is: %s", m); 

    // **************************************************** 

    printf("\nEnter the received message: "); 
    gets(m); 

    for (i = 0; i < gl; i++) 
        tm[i] = m[i]; 

    for (i = 0; i < ml; i++) 
    { 
        if (tm[0] == '1') 
        { 
            for (j = 0; j < gl; j++) 
            { 
                if (tm[j] == g[j]) 
                    tm[j] = '0'; 
                else 
                    tm[j] = '1'; 
            } 
        } 

        for (j = 0; j < gl - 1; j++) 
            tm[j] = tm[j + 1]; 
        tm[gl - 1] = m[i + gl]; 
    } 

    tm[gl - 1] = '\0'; 
    printf("\nRemainder is: %s", tm); 

    for (i = 0, f = 0; i < gl - 1; i++) 
    { 
        if (tm[i] != '0') 
        { 
            f = 1; 
            break; 
        } 
    } 

    if (f == 0) 
        printf("\nNo error in received message"); 
    else 
        printf("\nError in received message"); 

}
