divisor(int* vet, n){
  int maior = 0;
  for(int i=0; i<n; i++){
    if(vet[i] > maior)
      maior = vet[i];
  }
  return maior/n;
}
