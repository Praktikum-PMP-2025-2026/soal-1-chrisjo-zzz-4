/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : 4 - Dynamic Structure
*   Hari dan Tanggal    : Selasa, 5 Mei 2026
*   Nama (NIM)          : Christian Jonathan Hutajulu (13224108)
*   Nama File           : soal1.c
*   Deskripsi           : Dalam sebuah arsip kuno, segel mantra ditulis menggunakan campuran huruf kecil dan simbol 
                          kurung. Huruf-huruf biasa hanyalah isi teks, sedangkan simbol kurung menentukan apakah susunan 
                          segel dianggap sah atau cacat. Peneliti ingin memeriksa validitas segel tersebut secara otomatis. 
                          Tugas Anda adalah menentukan apakah struktur simbol kurung dalam string itu valid ketika huruf
                          huruf diabaikan.
                          Kondisi/Aturan 
                          1. Karakter valid hanya huruf kecil dan ()[]{}  
                          2. Huruf diabaikan  
                          3. Kurung harus berpasangan dan tertutup dalam urutan benar  
                          4. Jika ada karakter penutup yang tidak punya pasangan, string tidak valid
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int Valid(char *s) {
    int len = strlen(s);
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];
        if (current >= 'a' && current <= 'z') {
            continue;
        }
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        }
        else if (current == ')' || current == ']' || current == '}') {
            if (top == -1) {
                free(stack);
                return 0;
            }
            char lastOpen = stack[top--];
            if ((current == ')' && lastOpen != '(') ||
                (current == ']' && lastOpen != '[') ||
                (current == '}' && lastOpen != '{')) {
                free(stack);
                return 0; 
            }
        }
    }

    int result = (top == -1);
    free(stack);
    return result;
}

int main() {
    char input[MAX];
    scanf("%s", input);
    printf(Valid(input) ? "VALID" : "INVALID");
    return 0;
}
