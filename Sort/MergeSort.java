package homework;
import homework.SortTestHelper;

public class MergeSort {
	public static void MergeSort(Integer[] a,int start,int end) {
		if(start<end) {
			int mid = (start+end)/2;
			MergeSort(a,start,mid);
			MergeSort(a,mid+1,end);
			merge(a, start, mid,end);
		}
	}
	
	public static void merge(Integer[] a,int left,int mid,int right) {
		int[] temp = new int[a.length];
		int p1 = left;
		int p2 = mid+1;
		int k =left;
		
		while(p1<= mid && p2 <=right) {
			if(a[p1]<a[p2]) {
				temp[k++] = a[p1++];
				
			}else {
				temp[k++] = a[p2++];
			}
		}
		
		while(p1<=mid) {
			temp[k++]=a[p1++];
		}
		
		while(p2<=right) {
			temp[k++]=a[p2++];
		}
		
		
		for(int i = left;i<=right;i++) {
			a[i]=temp[i];
		}
		
	}
	
	public static void main(String[] args) {
		Integer[] a = SortTestHelper.generateRandomArray(5, 0, 10);
		System.out.println("unsorted");
		for(int num:a) {
			System.out.print(num+" ");
		}
		System.out.println();
		long starttime = System.nanoTime();
		MergeSort(a, 0, a.length-1);
		long endtime = System.nanoTime();
		System.out.println("sorted");
		for(int num:a) {
			System.out.print(num+" ");
		}
		long time = endtime -starttime;
		System.out.println();
		System.out.println("Time: "+time+"ns");
		
	}
		
		
	
	
	
	

}
