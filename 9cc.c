#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
if(argc != 2) //入力された数値が2個以下⇒計算ができない時の処理。
{
fprintf(stderr,"引数の個数が正しくありません。\n");
return 1;
}

char* p = argv[1]; //文字列1つ分用意して、ポインタ変数にargv[1]のアドレスを入れる。この[1]の中に'5+20-4'全て入っている。

printf(".intel_syntax noprefix\n");
printf(".globl main\n");
printf("main:\n");
printf(" mov rax, %ld\n",strtol(p, &p, 10)); //入力された文字列を前から順番に読みこむ。

while(*p)
{
if(*p == '+')
{
p++; //疑問。p++なら「20」の「2」だけみてcontinueでブロックの処理の初めに戻る気がする。「0」はどうやって見ているかイメージがつかない。
printf(" add rax, %ld\n", strtol(p, &p, 10));
continue;
}

if(*p == '-')
{
p++;
printf(" sub rax, %ld\n", strtol(p, &p, 10));
continue;
}

fprintf(stderr, "予期しない文字です:'%c'\n", *p);
return 1;
}

printf(" ret\n");
return 0;

}
