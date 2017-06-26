//=============================================================================
/*! _dgbmatrix+_dgematrix operator */
inline _dgematrix operator+(const _dgbmatrix& matA, const _dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.m!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(CPPL_INT i=0; i<matA.m; i++){
    const CPPL_INT jmax =std::min(matA.n,i+matA.ku+1);
    for(CPPL_INT j=std::max(CPPL_INT(0),i-matA.kl); j<jmax; j++){
      matB(i,j) += matA(i,j);
    }
  }
  
  matA.destroy();
  return matB;
}

//=============================================================================
/*! _dgbmatrix-_dgematrix operator */
inline _dgematrix operator-(const _dgbmatrix& matA, const _dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.m!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(CPPL_INT i=0; i<matA.m; i++){
    const CPPL_INT jmax =std::min(matA.n,i+matA.ku+1);
    for(CPPL_INT j=std::max(CPPL_INT(0),i-matA.kl); j<jmax; j++){
      matB(i,j) = matA(i,j)-matB(i,j);
    }
  }
  
  matA.destroy();
  return matB;
}

//=============================================================================
/*! _dgbmatrix*_dgematrix operator */
inline _dgematrix operator*(const _dgbmatrix& matA, const _dgematrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.m << "x" << matA.n << ") * (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat( matA.m, matB.n );
  newmat.zero();
  
  for(CPPL_INT i=0; i<newmat.m; i++){
    for(CPPL_INT j=0; j<newmat.n; j++){
      const CPPL_INT kmax =std::min(matA.n,i+matA.ku+1);
      for(CPPL_INT k=std::max(CPPL_INT(0),i-matA.kl); k<kmax; k++){
        newmat(i,j) += matA(i,k)*matB(k,j);
      }
    }
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
