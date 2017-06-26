//=============================================================================
/*! _zcovector+zcovector operator */
inline _zcovector operator+(const _zcovector& vecA, const zcovector& vecB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(vecA.l!=vecB.l){
    ERROR_REPORT;
    std::cerr << "These two vectors can not make a sumation." << std::endl
              << "Your input was (" << vecA.l << ") + (" << vecB.l << ")." << std::endl;
    exit(1);
  }
  
#endif//CPPL_DEBUG
  
  for(CPPL_INT i=0; i<vecA.l; i++){
    vecA.array[i] += vecB.array[i];
  }
  
  return vecA;
}

//=============================================================================
/*! zcovector-zcovector operator */
inline _zcovector operator-(const _zcovector& vecA, const zcovector& vecB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(vecA.l!=vecB.l){
    ERROR_REPORT;
    std::cerr << "These two vectors can not make a subtraction." << std::endl
              << "Your input was (" << vecA.l << ") - (" << vecB.l << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(CPPL_INT i=0; i<vecA.l; i++){
    vecA.array[i] -= vecB.array[i];
  }
  
  return vecA;
}

//=============================================================================
/*! zcovector^T*zcovector operator (inner product) */
inline comple operator%(const _zcovector& vecA, const zcovector& vecB)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(vecA.l!=vecB.l){
    ERROR_REPORT;
    std::cerr << "These two vectors can not make a dot product." << std::endl
              << "Your input was (" << vecA.l << ") % (" << vecB.l << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  CPPL_INT inc =1;
  comple val =zdotu_( &vecA.l, vecA.array, &inc, vecB.array, &inc );
  
  vecA.destroy();
  return val;
}
