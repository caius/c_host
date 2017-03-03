#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "plugin.h"

typedef void (*lib_func)();

int main (int argc, char const *argv[])
{
  void *plugin_handle = NULL;
  lib_func hurrow = NULL;

  char *lib_path = argv[1];

  printf("Oh hai\n");
  printf("Loading %s\n", lib_path);

  plugin_handle = dlopen(lib_path, RTLD_NOW);
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
