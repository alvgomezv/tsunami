#include <stdio.h>
#include <windows.h>

int main () 
{
    __asm
    {
        //LoadLibrary("msvcrt.dll");
        push ebp //save the previous base pointer 
        mov ebp,esp // establish a new base pointer into the function (creates a new stack for out variables)
        xor edi,edi //set edi to '0'to clear it's value
        push edi // pushes edi into the stack
        sub esp,0x0C // allocate twelve bytes of space onto the stack (10 letters)
        mov byte ptr [ebp-0x0B], 0x6D // letter 'm'
        mov byte ptr [ebp-0x0A], 0x73 // letter 's'
        mov byte ptr [ebp-0x09], 0x76 // letter 'v'
        mov byte ptr [ebp-0x08], 0x63 // letter 'c'
        mov byte ptr [ebp-0x07], 0x72 // letter 'r'
        mov byte ptr [ebp-0x06], 0x74 // letter 't'
        mov byte ptr [ebp-0x05], 0x2E // letter '.'
        mov byte ptr [ebp-0x04], 0x64 // letter 'd'
        mov byte ptr [ebp-0x03], 0x6C // letter 'l'
        mov byte ptr [ebp-0x02], 0x6C // letter 'l'
        lea eax, [ebp-0x0B] // loads the address of the string (points to 'm'), into eax
        push eax // pushes the string into the stack, prepares it to be called
        mov ebx, 0x7c801d7b // addres of the function 'LoadLibrary' of 'kernel32.dll'
        call ebx // 'LoadLibrary' is called executing 'msvcrt.dll'
        
        //system("calc.exe");
        push ebp //save the previous base pointer 
        mov ebp,esp // establish a new base pointer into the function (creates a new stack for out variables)
        xor edi,edi //set edi to '0'to clear it's value
        push edi // pushes edi into the stack
        sub esp,0x08 // allocate eight bytes of space onto the stack (8 letters)
        mov byte ptr [ebp-0x09], 0x63 // letter 'c'
        mov byte ptr [ebp-0x08], 0x61 // letter 'a'
        mov byte ptr [ebp-0x07], 0x6C // letter 'l'
        mov byte ptr [ebp-0x06], 0x63 // letter 'c'
        mov byte ptr [ebp-0x05], 0x2E // letter '.'
        mov byte ptr [ebp-0x04], 0x65 // letter 'e'
        mov byte ptr [ebp-0x03], 0x78 // letter 'x'
        mov byte ptr [ebp-0x02], 0x65 // letter 'e'
        lea eax, [ebp-0x09] // loads the address of the string (points to 'c'), into eax
        push eax // pushes the string into the stack, prepares it to be called
        mov ebx, 0x77bf8044 // addres of the function 'system' of lib 'msvcrt.dll'
        call ebx // 'system' is called executing 'calc.exe'
    }
}
