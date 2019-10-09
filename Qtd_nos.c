qtdNos(no* raiz){
  if(raiz == NULL){
    return 0;
  }
  return qtdNos(raiz->esq) + qtdNos(raiz->dir) + 1;
}
