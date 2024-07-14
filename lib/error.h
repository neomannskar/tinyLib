#ifndef TINYLIB_ERROR_H_
#define TINYLIB_ERROR_H_

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define ANSI_RESET "\x1b[0m"
#define ANSI_REGULAR "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_REVERSE "\x1b[7m"
#define ANSI_BOLD_OFF "\x1b[21m"
#define ANSI_UNDERLINE_OFF "\x1b[24m"
#define ANSI_REVERSE_OFF "\x1b[27m"

#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_BRIGHT_BLACK "\x1b[90m"
#define ANSI_COLOR_BRIGHT_RED "\x1b[91m"
#define ANSI_COLOR_BRIGHT_GREEN "\x1b[92m"
#define ANSI_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN "\x1b[96m"
#define ANSI_COLOR_BRIGHT_WHITE "\x1b[97m"

enum Err {
  UNKNOWN = -1,
  TINYLIB_SUCCESS,
  TINYLIB_FAILURE,
  TINYLIB_WARNING
};

enum Err tl_warning(const char *msg, const char *err) {
  fputs(ANSI_BOLD ANSI_COLOR_BRIGHT_MAGENTA "Warning" ANSI_REGULAR ANSI_COLOR_WHITE " : ", stdout); 
  fputs(ANSI_REGULAR, stdout);
  fputs(err, stdout);
  fputs(ANSI_REGULAR ANSI_COLOR_WHITE "\n        | " ANSI_RESET, stdout);
  
  size_t length = strlen(msg);
  for (size_t i = 0; i < length; ++i) {
    if (!isalnum(msg[i]) && !isspace(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
      putchar(msg[i]);
      if (msg[i] == '(') {
        while (msg[++i] != ')') {
          if (isalnum(msg[i])) {
            fputs(ANSI_REGULAR ANSI_COLOR_CYAN, stdout);
          } else {
            fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
          }
          putchar(msg[i]);
        } --i;
      }
    } else if (isalpha(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_GREEN, stdout);
      putchar(msg[i]);
    }
  }

  puts(ANSI_REGULAR);
  return TINYLIB_WARNING;
}

enum Err tl_error(const char *msg, const char *err) {
  fputs(ANSI_BOLD ANSI_COLOR_RED "Error " ANSI_REGULAR ANSI_COLOR_WHITE "  : ", stdout); 
  fputs(ANSI_REGULAR, stdout);
  fputs(err, stdout);
  fputs(ANSI_REGULAR ANSI_COLOR_WHITE "\n        | " ANSI_RESET, stdout);
  
  size_t length = strlen(msg);
  for (size_t i = 0; i < length; ++i) {
    if (!isalnum(msg[i]) && !isspace(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
      putchar(msg[i]);
      if (msg[i] == '(') {
        while (msg[++i] != ')') {
          if (isalnum(msg[i])) {
            fputs(ANSI_REGULAR ANSI_COLOR_CYAN, stdout);
          } else {
            fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
          }
          putchar(msg[i]);
        } --i;
      }
    } else if (isalpha(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_GREEN, stdout);
      putchar(msg[i]);
    }
  }

  puts(ANSI_REGULAR);
  return TINYLIB_FAILURE;
}

enum Err tl_assert(long long expr, const char *msg, const char *err) {
  if (expr)
    return TINYLIB_SUCCESS;
  
  fputs(ANSI_BOLD ANSI_COLOR_RED "Assert" ANSI_REGULAR ANSI_COLOR_WHITE "  : ", stdout);
  puts(err);
  fputs(ANSI_REGULAR ANSI_COLOR_WHITE "        | " ANSI_RESET, stdout);

  size_t length = strlen(msg);
  for (size_t i = 0; i < length; ++i) {
    if (!isalnum(msg[i]) && !isspace(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
      putchar(msg[i]);
      if (msg[i] == '(') {
        while (msg[++i] != ')') {
          if (isalnum(msg[i])) {
            fputs(ANSI_REGULAR ANSI_COLOR_CYAN, stdout);
          } else {
            fputs(ANSI_BOLD ANSI_COLOR_BLACK, stdout);
          }
          putchar(msg[i]);
        } --i;
      }
    } else if (isalpha(msg[i])) {
      fputs(ANSI_BOLD ANSI_COLOR_GREEN, stdout);
      putchar(msg[i]);
    }
  }
  fputs(ANSI_REGULAR ANSI_COLOR_RED "\n        ! " ANSI_REGULAR, stdout);
  assert(expr);
  return TINYLIB_FAILURE;
}

#endif // TINYLIB_ERROR_H_
