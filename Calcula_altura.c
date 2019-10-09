calculaAlt(no* raiz){
  if(raiz == NULL){
    return 0;
  }
  return max(calculaAlt(raiz->esq), calculaAlt(raiz->dir)) +1;
}
