package homework;

import java.awt.datatransfer.StringSelection;

public class BucketSort {
	private int[] buckets;
	private Integer[] array;
	
	public  BucketSort(int range,Integer[] array) {
		this.buckets = new int[range];
		this.array = array;
		
	}
	
	public void sort() {
		if(array != null&&array.length>1) {
			for(int i=0;i<array.length;i++) {
				buckets[array[i]]++;
				}
		
		}
	}
 
	public void sortout() {
		for(int i = 0;i<buckets.length-1;i++) {
			
			for(int j =0;j<buckets[i];j++) {
				System.out.print(i+" ");
			}
			
		}
		
	}
	
	public static void main(String[] args) {
		Integer[] arr = SortTestHelper.generateRandomArray(10, 0, 50);
		
		System.out.print("unsorted ");
		System.out.println();
		for(int num:arr) {
			System.out.print(num+" ");
		}
		System.out.println();
		long startTime = System.nanoTime();
		BucketSort bs =new BucketSort(50, arr);
		bs.sort();
		long endTime = System.nanoTime();
		System.out.println("sorted");
		bs.sortout();
		System.out.println();
		System.out.print("Time: "+(endTime-startTime)+"ns");
	}
}
