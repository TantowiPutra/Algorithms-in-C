void rightRotate(struct Array *arr) {
    if(arr->length > 0) {
        int temp = arr->A[arr->length - 1];
        for(int i = arr->length - 1; i > 0; i--) {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[0] = temp;
    }
}