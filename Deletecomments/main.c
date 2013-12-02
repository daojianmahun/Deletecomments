//
//  main.c
//  Deletecomments
//
//  Created by Paulina Rubio Tarriba on 12/2/13.
//  Copyright (c) 2013 Paulina Rubio Tarriba. All rights reserved.
//

#include <stdio.h>

static void process(FILE *f)
{
    int c;
    while ( (c=getc(f)) != EOF )
    {
        if (c=='\'' || c=='"')
        {
            int q=c;
            do
            {
                putchar(c);
                if (c=='\\') putchar(getc(f));
                c=getc(f);
            } while (c!=q);
            putchar(c);
        }
        else if (c=='/')
        {
            c=getc(f);
            if (c!='*')
            {
                putchar('/');
                ungetc(c,f);
            }
            else
            {
                int p;
                putchar(' ');
                do
                {
                    p=c;
                    c=getc(f);
                } while (c!='/' || p!='*');
            }
        }
        else
        {
            putchar(c);
        }
    }
}

int main(int argc, char *argv[])
{
    process(stdin);
    return 0;
}

