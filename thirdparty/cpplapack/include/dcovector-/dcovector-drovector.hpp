//=============================================================================
/*! dcovector*drovector operator */
inline _dgematrix operator*(const dcovector& covec, const drovector& rovec)
{CPPL_VERBOSE_REPORT;
  dgematrix newmat(covec.l, rovec.l);
  for(CPPL_INT i=0; i<newmat.m; i++){ for(CPPL_INT j=0; j<newmat.n; j++){
    newmat(i,j) =covec(i)*rovec(j);
  }}
  
  return _(newmat);
}
