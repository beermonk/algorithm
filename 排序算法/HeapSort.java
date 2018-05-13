package alg_sort;

public class HeapSort {
    public static void HeapJudge(int[] arr) {
        int temp = 0;
        // 判断一个数组是不是大顶堆
        for (int i = 0; i < arr.length; i++) {
            // 求第i个节点的父节点的值
            int node = i + 1;
            int parent = arr[node - 1];
            if (2 * node < arr.length) {
                //左孩子
                int left = arr[2 * node - 1];
                //右孩子
                int right = arr[2 * node];
                if (parent > left && parent > right)
                    temp++;
            } else
                break;
        }
        if (temp == arr.length / 2 - 1)
            System.out.println("该数组为大顶堆");
        else
            System.out.println("该数组不是大顶堆");
    }

    // 维护最大堆
    /*
     * @param1: 要维护的数组
     * @param2: 根节点的下标
     * */
    public static void maxHeapify(int[] arr, int i) {
        int left = 2 * i;  // left child
        int right = 2 * i + 1;  // right child
        int max = i;
        if (i <= arr.length && arr[left] > arr[i]) {
            max = left;
        }
        if (i <= arr.length && arr[right] > arr[i]) {
            max = right;
        }
        if (max != i) {
            int temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, left);
            maxHeapify(arr, right);
        }
    }

    // 构建一个数组为大顶堆
    public static int[] buildHeap(int[] arr) {
        int heapsize = arr.length;
        for (int i = 0; i < heapsize / 2; i++) {
            maxHeapify(arr, i + 1);
        }
        return arr;
    }

    // 堆排序算法实现, 从大到小排列
    public static int[] heapSort(int[] arr) {
        // 先将一个数组构建为最大堆
        HeapSort.buildHeap(arr);
        for (int i = arr.length; i > 1; i++) {
            // 将堆顶和最后一个节点交换位置
            int temp = arr[0];
            arr[arr.length] = arr[0];
            arr[0] = temp;
            // 将最后一个节点去掉，得到一个新数组，对该数组重新进行最大堆维护
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] array = {16, 14, 1, 8, 7, 9, 13, 2, 4, 5, 4};
        int[] arr = HeapSort.heapSort(array);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
