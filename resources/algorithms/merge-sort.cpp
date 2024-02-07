template <typename T>
void merge(vector<T> &arr, int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;

  vector<T> L(n1), R(n2);
  for (int i=0; i < n1; i++) 
    L[i] = arr[l+1];
  for (int i=0; i < n2; i++) 
    R[i] = arr[mid + 1 + i];

  int i=0, j=0, k = l;
  while ( i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  for (;i < n1; i++, k++)
    arr[k] = L[i];
  for (;j < n2; j++, k++)
    arr[k] = R[j];
}

template <typename T>
void merge_sort (vector<T> & arr, int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}
