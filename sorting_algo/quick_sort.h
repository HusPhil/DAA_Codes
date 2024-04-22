
int partition(int arr[], int si, int ei) {
	int pivot = arr[ei];
	int li = si;
	int ri = ei - 1;

	while(li <= ri) {
		if(arr[li] <= pivot) li++;
		else if(arr[ri] >= pivot) ri--;
		else {
			swap(&arr[ri], &arr[li]);
			li++;
			ri--;
		}
	}
	swap(&arr[ei], &arr[li]);
	return li;
}

void quickSort(int arr[], int si, int ei){
	if(si < ei){
		int pi = partition(arr, si, ei);
		quickSort(arr, si, pi - 1);
		quickSort(arr, pi + 1, ei);
	}
	printf("%d", si);
}
