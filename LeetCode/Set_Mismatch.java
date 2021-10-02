class Solution {
    public int[] findErrorNums(int[] nums) {
        sort(nums);
        int arr[] = { -1, -1 };
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                arr[0] = nums[i];
                arr[1] = i + 1;
            }
        }
        return arr;
    }

    static void sort(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[i] != arr[correct]) {
                swap(arr, i, correct);
            } else {
                i++;
            }
        }
    }

    static void swap(int[] arr, int max, int last) {
        int temp = arr[max];
        arr[max] = arr[last];
        arr[last] = temp;
    }
}