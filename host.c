#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "plugin.h"

typedef void (*lib_func)();

int main (int argc, char const *argv[])
{
  void *plugin_handle = NULL;
  lib_func hurrow = NULL;

  printf("Oh hai\n");

  plugin_handle = dlopen("./plugin.so", RTLD_NOW);
  if (!plugin_handle) {
      fprintf(stderr, "Error during dlopen(): %s\n", dlerror());
      exit(1);
  }

  hurrow = dlsym(plugin_handle, "hurrow");
  if (hurrow == NULL) {
    fprintf(stderr, "Error during dlsym(): %s\n", dlerror());
    return 1;
  }

  hurrow();

  return 0;
}
