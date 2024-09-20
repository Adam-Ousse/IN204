#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
struct fs_header{
  u_int64_t rom1fs;
  u_int32_t full_size;
  u_int32_t check_sum;
  u_int8_t content[];

};
void decode(struct fs_header *p, size_t size){


  
}

u_int32_t read32(char ptr[4]) {
  return ((u_int32_t)ptr[0] << 24) | ((u_int32_t)ptr[1] << 16) | 
           ((u_int32_t)ptr[2] << 8) | (u_int32_t)ptr[3];
}

long ceil_16(long x) {
  
}
int main(void){
  int fd = open("fs.romfs",O_RDONLY);
  struct fs_header fs;
  
  assert(fd != -1);
  off_t fsize;
  fsize = lseek(fd,0,SEEK_END);
  printf("size is %ld\n", fsize);
  
  char *addr =mmap(addr, fsize, PROT_READ, MAP_SHARED, fd, 0);
  assert(addr != MAP_FAILED);


  char rom1fs[8];
  strncpy(rom1fs, addr, 8);
  fs.rom1fs = rom1fs;

  printf("%s \n",rom1fs);
  char full_size[4];
  
  strncpy(full_size, addr+8, 4);
  fs.full_size = full_size;
  printf("%u \n",read32(full_size));
  assert(read32(full_size) >= fsize);
  // for(int i=0;i<1000;i++){
  //   printf("%c",addr[i]);
  //   if(i+1%4==0){
  //     printf("\n");
  //   }
  // }
  //Question 3
  // char rom1fs[8];
  // strncpy(rom1fs,addr,addr+8);
  // printf("%s \n",rom1fs);
  // for (int i=0;i<8;i++){
  
  //   printf("%c",addr[i]);
  // }printf("\n");
  // decode(addr, fsize);
  printf("lol\n");
  return 0;
}
