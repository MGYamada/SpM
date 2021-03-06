//=============================================================================
/*! _zhematrix+_zssmatrix operator */
inline _zgematrix operator+(const _zhematrix& matA, const _zssmatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat =matA;
  
  for(CPPL_INT c=0; c<matB.vol; c++){
    newmat(matB.indx[c],matB.jndx[c]) += matB.array[c];
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}

//=============================================================================
/*! _zhematrix-_zssmatrix operator */
inline _zgematrix operator-(const _zhematrix& matA, const _zssmatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m || matA.n!=matB.n){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") - (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  zgematrix newmat =matA;
  
  for(CPPL_INT c=0; c<matB.vol; c++){
    newmat(matB.indx[c],matB.jndx[c]) -= matB.array[c];
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}

//=============================================================================
/*! _zhematrix*_zssmatrix operator */
inline _zgematrix operator*(const _zhematrix& matA, const _zssmatrix& matB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") * (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat(matA.n, matB.n);
  newmat.zero();
  
  for(CPPL_INT c=0; c<matB.vol; c++){
    for(CPPL_INT i=0; i<matA.n; i++){
      newmat(i,matB.jndx[c]) += matA(i,matB.indx[c])*matB.array[c];
    }
  }
  
  matA.destroy();
  matB.destroy();
  return _(newmat);
}
