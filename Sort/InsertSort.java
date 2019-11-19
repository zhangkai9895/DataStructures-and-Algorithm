package homework;

import homework.SortTestHelper;

public class InsertSort {
	
	private void InsertSort() {
		  
	}

	public  static Integer[] InsertSort1(Integer[] arr) {
		
		for(int i=1;i<arr.length;i++) {
			int temp = arr[i];
			
			int j = i;
			while(j>0 && temp<arr[j-1]) {
				arr[j] = arr[j-1];
				j--;
			}
			if(j != i) {
				arr[j] = temp;
			}
		}
	return arr;
		
	}
	
	
	public static void main(String[] args) {
		Integer[] arr = SortTestHelper.generateRandomArray(50,0 , 999);
		System.out.print("unsorted ");
		for(int num:arr) {
			System.out.print(num+" ");
		}
		System.out.println();
		long startTime = System.nanoTime();
		Integer[] arr2 = InsertSort1(arr);
		long endTime = System.nanoTime();
		System.out.print("sorted ");
		for(int num:arr2) {
			System.out.print(num+" ");
		}
		System.out.println();
		System.out.print("Time: "+(endTime-startTime)+"ns");
		

	}
}





