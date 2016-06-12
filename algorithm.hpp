
namespace myalgorithm{
  //Swap tow value
  template <typename T>
  void Swap(T &a, T &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  //start
  //bubble sort
  template <typename T>
  void bubbleSort(T data[], int n) {
    for (int i = 0; i < n; i++) {
      for(int j = 1; j < n - i; j++) {
	if(data[j-1] > data[j])
	  Swap(data[j-1], data[j]);
      }
    }
  }
  //end

  //start
  //insertionSort
  template <typename T>
  void insertionSort(T data[], int len) {
    for(int i = 0; i < len; i++) {
      for(int j = i+1; j < len; j++) {
	if(data[i] > data[j]) {
	  T temp = data[j];  //the temperary small element
	  for(int z = j; z > i; z--) {   //shift elements
	    data[z] = data[z-1];
	  }
	  data[i] = temp; //insert the small element to the j-1 position
	}
      }
    }
  }
  //end

  
  //start
  //merge sort
  template <typename T>
  void merge(T* left, T* right, T* data, int lenL, int lenR) {
    int li = 0, ri = 0;
    int counter = 0;
    while(counter < lenL + lenR) {
      if (left[li] < right[ri]) 
	data[counter++] = left[li++];
      else
	data[counter++] = right[ri++];

      if(li == lenL)
	while(ri < lenR)
	  data[counter++] = right[ri++];
      else if(ri == lenR)
	while(li < lenL)
	  data[counter++] = left[li++];
    }
  }
  

  template <typename T>
  void mergeSort(T data[], int n) {
    if (n > 1) {
      int leftN = n / 2;
      int rightN = n - n / 2;
      T left[leftN];
      T right[rightN];
      for(int i = 0; i < leftN; i++)
	left[i] = data[i];
      for(int i = 0; i < rightN; i++)
	right[i] = data[i + leftN];
      mergeSort(left, leftN);
      mergeSort(right, rightN);
      merge(left, right, data, leftN, rightN);
    }
  }
  //end


  //  start
  //   select sort 
  template <typename T>
  void selectSort(T data[], int len) {
    for (int i = 0; i < len; i++) {
      int max = 0;
      for(int j = 0; j < len - i; j++) {
	if(data[max] < data[j])
	  max = j;
      }
      Swap(data[max], data[len-i-1]);
    }
  }
  //end

  //start
  //heap sort
  template <typename T>
  void keepHeap(T data[], int heapSize, int k) {
    int left = 2 * k + 1;
    int right = 2 * k + 2;
    int largest = k;

    if(left < heapSize && data[left] > data[largest])
      largest = left;

    if(right < heapSize && data[right] > data[largest])
      largest = right;

    if(largest != k) {
      Swap(data[k], data[largest]);
      keepHeap(data, heapSize, largest);
    }
  }

  template <typename T>
  void buildHeap(T data[], int heapSize) {
    int k = heapSize / 2 - 1;
    while(k >= 0) {
      keepHeap(data, heapSize, k);
      k--;
    }
  }

  template <typename T>
  void heapSort(T data[], int n) {
    int heapSize = n;
    buildHeap(data, heapSize);
    for(int i = heapSize - 1; i > 0; i--){
      Swap(data[i], data[0]);
      heapSize = heapSize - 1;
      keepHeap(data, heapSize, 0);
    }
  }
  //end

  //start
  //quick sort
  template <typename T>
  int partition(T data[], int l, int r) {
    int pivot = l;
    int i = l;
    int j = r;
    while(i < j) {
      while(i < j && data[pivot] > data[i]) {
	i++;
      }
      if(i == r && data[pivot] > data[r]) {
	Swap(data[pivot], data[r]);
	return r;
      }
    
      while(i < j && data[pivot] <= data[j]) {
	j--;
      }
      if(j == l)
	return pivot;
    
      if( i < j && data[i] > data[j])
	Swap(data[i], data[j]);
    }

    Swap(data[i-1], data[pivot]);
    return i-1;
  }

  template <typename T>
  void quick(T data[], int a, int b) {
    int pos = 0;
    if(a < b) {
      pos = partition(data, a, b);
      quick(data, a, pos-1);
      quick(data, pos+1, b);
    }
  }

  template <typename T>
  void quickSort(T data[], int number){
    quick(data, 0, number-1);
  }
  //end

  //start
  //insertion and shell sort
  template <typename T>
  void insertionSort(T data[], int len, int n) {
    for(int i = 0; i < len; i++) {
      for(int j = i + n; j < len; j += n) {
	if (data[i] > data[j]) {
	  T temp = data[j];
	  for(int z = j; z > i; z -= n) {
	    data[z] = data[z-n];
	  }
	  data[i] = temp;
	}
      }
    }
  }

  template <typename T>
  void shellSort(T data[], int len) {
    int n = len / 2;
    while (n >= 1) {
      insertionSort(data, len, n);
      n /= 2;
    }
  }
  //end

  
};//mylib

