//=============================================================================
/*! nullify all the matrix data */
inline void _dgbmatrix::nullify() const
{CPPL_VERBOSE_REPORT;
  m=0;
  n=0;
  kl=0;
  ku=0;
  array=NULL;
  darray=NULL;
}

//=============================================================================
/*! destroy all the matrix data */
inline void _dgbmatrix::destroy() const
{CPPL_VERBOSE_REPORT;
  delete [] array;
  delete [] darray;
  array=NULL;
  darray=NULL;
}
