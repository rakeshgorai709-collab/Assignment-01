#include <stdio.h>
#include <string.h>
#define MAX 1000

void main() {
    char S[MAX];
    printf("Enter the string: ");
    scanf("%s", S);
    int n = strlen(S);
    char T[MAX];
    strcpy(T, S);
    strcat(T, S);
    int used[26] = {0};
    int left = 0, sum = 0, maxSum = 0;
    for (int right = 0; right < 2 * n; right++) {
            while (used[T[right] - 'a'] == 1 || (right - left + 1) > n) {
            used[T[left] - 'a'] = 0;
            sum -= (T[left] - 'a' + 1);
            left++;
        }
        used[T[right] - 'a'] = 1;
        sum += (T[right] - 'a' + 1);
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    printf("Maximum Sum = %d\n", maxSum);
}
