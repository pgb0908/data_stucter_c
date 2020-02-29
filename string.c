#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define BUF_SIZE 20


int main(void)
{
  char buffer[BUF_SIZE];
  
  while(1)
  {
    printf("$ ");
    int len = read_line_with_compression(buffer, BUF_SIZE);
    printf("%s:%d\n", buffer, len);

  }

  return 0;
}


int read_line_with_compression(char str[],int len)
{
  int idx = 0;
  char ch;
  while((ch = getchar()) != '\n')
  {
    //처음에 ' '면 생략 && ' ' 이전에 ' '이면 현재 ' ' 생략
    if(idx < len-1 && (!isspace(ch) || (idx > 0 && !isspace(str[idx-1])) ))
    {
      str[idx] = ch;
      idx++;
    }
  }
  
  //마지막 문자가 공백일 경우
  if(idx > 0 && isspace(str[idx-1])) idx --;
  str[idx] = '\0';

  return idx;
}


