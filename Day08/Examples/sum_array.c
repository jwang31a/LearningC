#define LEN 100

int sum_array(int [], int); //parameter names can be omitted

int main(void) {
    int b[LEN], total;
    total = sum_array(b, LEN);
}

int sum_array(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

/*
important point: length smaller than array's length will give sum of the first n numbers
length longer than array's length will cause problems
*/