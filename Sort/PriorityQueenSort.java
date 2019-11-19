package homework;
import homework.SortTestHelper;

public class PriorityQueenSort {
	private void PriorityQueenSort() {}
	
	public static Integer[] HeapSort(Integer[] arr) {
		int start =(arr.length-1)/2;
		for(int i=start;i>=0;i--) {
			MaxHeap(arr, arr.length, i);
		}
		for(int i = arr.length-1;i>0;i--) {
			int temp =arr[0];
			arr[0] = arr [i];
			arr[i] = temp;
			MaxHeap(arr,i, 0);
		}
		return arr;
		
	}
	
	public static void MaxHeap(Integer[] arr, int size,Integer index) {
		Integer leftNode = 2*index+1;
	    Integer rightNode = 2*index+2;
		Integer max = index;
		if(leftNode < size&&arr[leftNode]>arr[max]) {
			max = leftNode;
		}
		if(rightNode <size&&arr[rightNode]>arr[max]){
			max = rightNode;
		}
		if(max != index) {
			int temp = arr[index];
			arr[index] =arr[max];
			arr[max]=temp;
			MaxHeap(arr, size, max);
		}
				
	}
	
	public static void main(String[] args) {
		Integer[] arr = SortTestHelper.generateRandomArray(10, 20, 50);
		long startTime = System.nanoTime();
		Integer[] arr2 = HeapSort(arr);
		long endTime = System.nanoTime();
		System.out.print("unsorted ");
		for(int num:arr) {
			System.out.print(num+" ");
		}
		System.out.println();
		System.out.print("sorted ");
		for(int num:arr2) {
			System.out.print(num+" ");
		}
		System.out.println();
		System.out.print("Time: "+(endTime - startTime)+"ns");
		
	}
}
