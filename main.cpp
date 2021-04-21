#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread1(void* args)
{
  while (!(*(bool*)args))
  {
    std::cout << "1\n";
    sleep(1);
  }
  return nullptr;
}

void* thread2(void* args)
{
  while (!(*(bool*)args))
  {
    std::cout << "2\n";
    sleep(1);
  }
  return nullptr;
}

int main() 
{
  pthread_t t1, t2;
  bool flag1 = false;
  bool flag2 = false;
  bool* flag_1 = &flag1;
  bool* flag_2 = &flag2;
  pthread_create(&t1, NULL, &thread1, flag_1);
  pthread_create(&t2, NULL, &thread2, flag_2);
  getchar();
  flag1 = true;
  flag2 = true;
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  return 0;
}