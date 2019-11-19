package homework;

public class SortTestHelper {
	private SortTestHelper() {}
	
	public static Integer[] generateRandomArray(int n,int rangeL,int rangeR) {
		
		assert rangeL <= rangeR;
		Integer[] arr = new Integer[n];
		
		for(int i = 0;i<n;i++) {
			arr[i] = new Integer((int)(Math.random()*(rangeR-rangeL+1)+rangeL));
			
		}
		return arr;
		
		
	}
	

}
