package homework;

public class QuickSort {
	public static int divide(Integer[] a,int start,int end) {
		
		int base = a[end];
		
		while(start < end){
			while(start < end && a[start] <= base)
				
				start++;
			
			if(start < end){
				
				int temp = a[start];
				a[start] = a[end];
				a[end] = temp;
				
				end--;
			}	
			while(start < end && a[end] >= base)
				
				end--;
			
			if(start < end){
				
				int temp = a[start];
				a[start] = a[end];
				a[end] = temp;
				
				start++;
			}	
			
		}
		
		return end;
		
	}
	public static void sort(Integer[] a, int start, int end){
		if(start > end){
			
			return;
		} 
		else{
		
			int partition = divide(a, start, end);
			sort(a, start, partition-1);
			sort(a, partition+1, end);
		}
			
	}

	
	public static void main(String[] args) {
		Integer[] a = SortTestHelper.generateRandomArray(10, 0, 20);
		System.out.println("unsorted");
		for(int num :a) {
			System.out.print(num+" ");
		}
		System.out.println();
		System.out.println("sorted");
		long startTime = System.nanoTime();
	    sort(a,0,a.length-1);
	    long endTime = System.nanoTime();
		for(int num:a) {
			System.out.print(num+" ");		
		}
		System.out.println();
		System.out.print("Time: "+(endTime-startTime)+"ns");
		
		
		
		
		
	}

}
