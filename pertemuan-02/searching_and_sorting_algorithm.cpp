
bool linear_search(int data[], int n, int x) {
	for ( int i = 0 ; i < n ; i++ ) {
		if (data[i] == x) return true;
	}	
	return false;
}


bool binary_search(int data[], int n, int x) {
	int ki = 0, ka = n - 1;
	while (ki <= ka) {
		int t = ki + (ka - ki) / 2;
		if (data[t] == x) 
			return true;
		else if (data[t] < x) 
			ki = t + 1;
		else 
			ka = t - 1;
	}
	return false;
}


void bubble_sort(int arr[], int n) {
	for ( int i = 0 ; i < n-1; i++ ) {
		// variable untuk mendeteksi apakah ada pertukaran selama iterasi
		bool swap = false;
		// iterasi untuk elemen yang belum terurut
		for ( int j = 0 ; j < n-i-1; j++ ) {
			// bandingkan elemen data yang berdekatan dan tukar jika perlu
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			
				swap = true; // tandai ada pertukaran posisi elemen data
			}
		}
		// jika tidak ada pertukaran, berarti sudah terurut
		if (!swap) 
			break;
	}
}


void insertion_sort(int arr[], int n) {
	for ( int i = 1; i < n ; i++ ) {
		int key = arr[i];
		int j = i - 1;
		// geser elemen - elemen yang lebih besar dari key ke kanan
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		// tempatkan key di posisi yang benar
		arr[j + 1] = key;
	}
}


void selection_sort(int arr[], int n) {
	for ( int i = 0 ; i < n-1 ; i++ ) {
		for ( int j = i + 1 ; j < n ; j++ ) {
			if ( arr[i] > arr[j] ) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	// membuat array sementara
	int *leftarr = (int *)malloc(sizeof(int) * n1);
	int *rightarr = (int *)malloc(sizeof(int) * n2);
	
	// menyalin data ke array sementara
	for ( int i = 0 ; i < n1 ; i++ )
		leftarr[i] = arr[left+i];
	for ( int j = 0 ; j < n2 ; j++)
		rightarr[j] = arr[mid + 1 + j];
		
	// menggabungkan dua array sementara ke dalam array asli 
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftarr[i] <= rightarr[j]) {
			arr[k] = leftarr[i];
			i++;
		} 
		else {
			arr[k] = rightarr[j];
			j++;
		}
		k++;
	}
	
	// menyalin sisa elemen dari leftarr, jika ada
	while (i < n1) {
		arr[k] = leftarr[i];
		i++;
		k++;
	}
	
	// menyalin sisa elemen dari rightarr, jika ada
	while (j < n2) {
		arr[k] = rightarr[j];
		j++;
		k++;
	}
	
	// membebaskan memory sementara
	free(leftarr);
	free(rightarr);
}


// fungsi utama merge sort
void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
	
		// mengurutkan bagian kiri dan kanan 
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		
		// menggabungkan kedua bagian
		merge(arr, left, mid, right);
	}
}


