#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

#include <Rinternals.h>

extern SEXP  lcs(SEXP, SEXP , SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"lcs",      (DL_FUNC) &lcs,      3},
    {NULL,        NULL,               0}
};

void R_init_qualV(DllInfo *dll) {
  // register entry points
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  
  // the following two lines protect against accidentially finding entry points
  R_useDynamicSymbols(dll, FALSE);  // disable dynamic searching
  R_forceSymbols(dll, TRUE);        // entry points as R objects, not as strings
} 
