#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_chain(info_t *info, char *buf, size_t *p) {
  if (info->cmd_buf_type == CMD_CHAIN) {
    return 1;
  } else {
    return 0;
  }
}

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len) {
  if (is_chain(info, buf, p)) {
    node = node_starts_with(info->alias, info->argv[0], '=');
    if (node != NULL) {
      free(info->argv[0]);
      info->argv[0] = node->value;
    }
  }
}

int replace_alias(info_t *info) {
  char *alias = info->alias;
  char *value = info->argv[0];
  char *new_alias = malloc(strlen(alias) + strlen(value) + 1);
  if (new_alias == NULL) {
    return -1;
  }
  strcpy(new_alias, alias);
  strcat(new_alias, "=");
  strcat(new_alias, value);
  free(info->alias);
  info->alias = new_alias;
  return 0;
}

int main() {
  info_t *info = malloc(sizeof(info_t));
  if (info == NULL) {
    return -1;
  }

  info->cmd_buf_type = CMD_AND;
  info->status = 1;
  info->argv[0] = "foo";
  info->argv[1] = "bar";

  check_chain(info, NULL, NULL, 0, 0);

  if (replace_alias(info) == -1) {
    return -1;
  }

  printf("info->alias: %s\n", info->alias);

  free(info);

  return 0;
}
